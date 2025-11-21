#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

namespace Task1 {

	// Class này chịu trách nhiệm xử lý logic ảnh, tách biệt hoàn toàn với UI
	public ref class ImageProcessor {
	public:

		// Hàm chuyển đổi Mat (OpenCV) sang Bitmap (.NET) để hiển thị lên PictureBox
		static System::Drawing::Bitmap^ MatToBitmap(const Mat& mat) {
			if (mat.empty()) {
				return nullptr;
			}

			// Chỉ xử lý ảnh xám (1 kênh) theo logic cũ của bạn
			// Nếu muốn hiển thị ảnh màu, cần thêm logic check CV_8UC3
			if (mat.type() != CV_8UC1) {
				return nullptr;
			}

			int width = mat.cols;
			int height = mat.rows;

			System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(
				width, height, PixelFormat::Format8bppIndexed
			);

			ColorPalette^ palette = bmp->Palette;
			for (int i = 0; i < 256; i++) {
				palette->Entries[i] = System::Drawing::Color::FromArgb(i, i, i);
			}
			bmp->Palette = palette;

			System::Drawing::Rectangle rect(0, 0, width, height);
			BitmapData^ bmpData = bmp->LockBits(
				rect, ImageLockMode::WriteOnly, bmp->PixelFormat
			);

			uchar* bmpPtr = (uchar*)bmpData->Scan0.ToPointer();
			int stride = bmpData->Stride;

			for (int y = 0; y < height; y++) {
				memcpy(bmpPtr + y * stride, mat.data + y * mat.step, width);
			}

			bmp->UnlockBits(bmpData);
			return bmp;
		}

		// Hàm xử lý ảnh chính (Tách kênh -> Nhị phân hóa)
		// Trả về: cv::Mat kết quả
		static Mat ProcessImageLogic(Mat inputImg, int thresholdVal, bool isReversed, int channel) {
			if (inputImg.empty()) return Mat();

			Mat grayToProcess;

			// 1. Xử lý chọn kênh
			if (channel == 0) { // Grayscale
				// Nếu ảnh gốc là màu thì chuyển xám, nếu là xám rồi thì giữ nguyên
				if (inputImg.channels() == 3)
					cvtColor(inputImg, grayToProcess, COLOR_BGR2GRAY);
				else
					grayToProcess = inputImg.clone();
			}
			else { // Kênh màu (Blue, Green, Red)
				if (inputImg.channels() == 3) {
					vector<Mat> channels;
					split(inputImg, channels);
					// channel: 1=Blue(idx 0), 2=Green(idx 1), 3=Red(idx 2)
					grayToProcess = channels[channel - 1];
				}
				else {
					// Nếu chọn tách kênh màu mà ảnh đầu vào là ảnh xám thì trả về rỗng
					return Mat();
				}
			}

			// 2. Xử lý Nhị phân hóa (Threshold)
			// Tối ưu hóa: Dùng hàm threshold của OpenCV thay vì vòng lặp 2 chiều thủ công (nhanh hơn nhiều)
			Mat newImg;
			int type = isReversed ? THRESH_BINARY_INV : THRESH_BINARY;

			// Cú pháp: threshold(src, dst, thresh, maxval, type)
			cv::threshold(grayToProcess, newImg, thresholdVal, 255, type);

			return newImg;
		}
	};
}