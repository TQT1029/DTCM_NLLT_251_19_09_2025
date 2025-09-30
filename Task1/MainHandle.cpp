#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main() {

	bool readyRun = true;
	if (readyRun) {
		Mat img = imread("horseImage.png", IMREAD_GRAYSCALE);

		if (img.empty()) {
			cout << "Can't Read!" << endl;

			return -1;
		}
		int defaultCheck = 64;//Ranh giới phân chia giữa độ sáng các pixel
		bool reverseColor = false;


		const int rows = img.rows, cols = img.cols;

		vector<vector<int>> imgMatrix(rows, vector<int>(cols, 0));

		if (!reverseColor)
			for (int y = 0; y < img.rows; y++) {
				for (int x = 0; x < img.cols; x++) {
					if (img.at<uchar>(y, x) >= defaultCheck) {
						imgMatrix[y][x] = 1;
					}
					else
					{
						imgMatrix[y][x] = 0;
					}
				}
			}
		else
			for (int y = 0; y < img.rows; y++) {
				for (int x = 0; x < img.cols; x++) {
					if (img.at<uchar>(y, x) >= defaultCheck) {
						imgMatrix[y][x] = 0;
					}
					else
					{
						imgMatrix[y][x] = 1;
					}
				}
			}

		Mat newImg(rows, cols, CV_8UC1);

		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < cols; x++) {
				newImg.at<uchar>(y, x) = imgMatrix[y][x] == 1 ? 255 : 0;
			}
		}
	}
	return 0;
}
