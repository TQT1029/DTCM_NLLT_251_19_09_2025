#pragma once
#include <opencv2/opencv.hpp>
#include <msclr/marshal_cppstd.h>
#include <string> 

using namespace cv;
using namespace std;

//=====Config Handle (Biến toàn cục)=====
bool isReversed = false;
int checkValue = 128;
Mat img; // Ảnh OpenCV toàn cục (dùng để xử lý) - LUÔN LÀ ẢNH MÀU
int selectedChannel = 0; // 0: Gray, 1: Blue, 2: Green, 3: Red

namespace Task1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace msclr::interop;

	public ref class MainUI : public System::Windows::Forms::Form
	{
	public:
		MainUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			// (THÊM MỚI) Đặt giá trị ban đầu cho Label
			this->checkValueLabel->Text = this->CheckValue->Value.ToString();
		}

	protected:
		~MainUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ InputPic;
	private: System::Windows::Forms::CheckBox^ ReverseColorCheck;
	private: System::Windows::Forms::Button^ ProgressBtn;
	private: System::Windows::Forms::Button^ ExampleBtn;
	private: System::Windows::Forms::TrackBar^ CheckValue;
	private: System::Windows::Forms::Button^ LoadBtn;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::ComponentModel::IContainer^ components;

		   // (THÊM MỚI) Các control để chọn kênh và hiển thị giá trị
	private: System::Windows::Forms::GroupBox^ channelBox;
	private: System::Windows::Forms::RadioButton^ grayRadio;
	private: System::Windows::Forms::RadioButton^ blueRadio;
	private: System::Windows::Forms::RadioButton^ greenRadio;
	private: System::Windows::Forms::RadioButton^ redRadio;
	private: System::Windows::Forms::Label^ checkValueLabel;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainUI::typeid));
			   this->InputPic = (gcnew System::Windows::Forms::PictureBox());
			   this->ReverseColorCheck = (gcnew System::Windows::Forms::CheckBox());
			   this->ProgressBtn = (gcnew System::Windows::Forms::Button());
			   this->ExampleBtn = (gcnew System::Windows::Forms::Button());
			   this->CheckValue = (gcnew System::Windows::Forms::TrackBar());
			   this->LoadBtn = (gcnew System::Windows::Forms::Button());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());

			   // (THÊM MỚI) Khai báo các control mới
			   this->channelBox = (gcnew System::Windows::Forms::GroupBox());
			   this->grayRadio = (gcnew System::Windows::Forms::RadioButton());
			   this->blueRadio = (gcnew System::Windows::Forms::RadioButton());
			   this->greenRadio = (gcnew System::Windows::Forms::RadioButton());
			   this->redRadio = (gcnew System::Windows::Forms::RadioButton());
			   this->checkValueLabel = (gcnew System::Windows::Forms::Label());

			   // Tạm dừng layout
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputPic))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CheckValue))->BeginInit();
			   this->channelBox->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // InputPic
			   // 
			   this->InputPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InputPic.Image")));
			   this->InputPic->Location = System::Drawing::Point(219, 10);
			   this->InputPic->Margin = System::Windows::Forms::Padding(2);
			   this->InputPic->Name = L"InputPic";
			   this->InputPic->Size = System::Drawing::Size(380, 420); // (Sửa) Tăng chiều cao
			   this->InputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->InputPic->TabIndex = 0;
			   this->InputPic->TabStop = false;
			   // 
			   // ReverseColorCheck
			   // 
			   this->ReverseColorCheck->AutoSize = true;
			   this->ReverseColorCheck->Location = System::Drawing::Point(100, 390); // (Sửa) Di chuyển xuống
			   this->ReverseColorCheck->Margin = System::Windows::Forms::Padding(2);
			   this->ReverseColorCheck->Name = L"ReverseColorCheck";
			   this->ReverseColorCheck->Size = System::Drawing::Size(93, 17);
			   this->ReverseColorCheck->TabIndex = 1;
			   this->ReverseColorCheck->Text = L"Reverse Color";
			   this->ReverseColorCheck->UseVisualStyleBackColor = true;
			   this->ReverseColorCheck->CheckedChanged += gcnew System::EventHandler(this, &MainUI::ReverseColorCheck_CheckedChanged);
			   // 
			   // ProgressBtn
			   // 
			   this->ProgressBtn->Location = System::Drawing::Point(9, 365); // (Sửa) Di chuyển xuống
			   this->ProgressBtn->Margin = System::Windows::Forms::Padding(2);
			   this->ProgressBtn->Name = L"ProgressBtn";
			   this->ProgressBtn->Size = System::Drawing::Size(87, 41);
			   this->ProgressBtn->TabIndex = 2;
			   this->ProgressBtn->Text = L"Progress";
			   this->ProgressBtn->UseVisualStyleBackColor = true;
			   this->ProgressBtn->Click += gcnew System::EventHandler(this, &MainUI::ProgressBtn_Click);
			   // 
			   // ExampleBtn
			   // 
			   this->ExampleBtn->Location = System::Drawing::Point(101, 365); // (Sửa) Di chuyển xuống
			   this->ExampleBtn->Margin = System::Windows::Forms::Padding(2);
			   this->ExampleBtn->Name = L"ExampleBtn";
			   this->ExampleBtn->Size = System::Drawing::Size(86, 19);
			   this->ExampleBtn->TabIndex = 4;
			   this->ExampleBtn->Text = L"Example";
			   this->ExampleBtn->UseVisualStyleBackColor = true;
			   this->ExampleBtn->Click += gcnew System::EventHandler(this, &MainUI::ExampleBtn_Click);
			   // 
			   // CheckValue
			   // 
			   this->CheckValue->Location = System::Drawing::Point(9, 10); // (Sửa) Di chuyển lên
			   this->CheckValue->Margin = System::Windows::Forms::Padding(2);
			   this->CheckValue->Maximum = 255;
			   this->CheckValue->Name = L"CheckValue";
			   this->CheckValue->Size = System::Drawing::Size(178, 45);
			   this->CheckValue->TabIndex = 5;
			   this->CheckValue->Value = 128;
			   this->CheckValue->Scroll += gcnew System::EventHandler(this, &MainUI::CheckValue_Scroll);
			   // 
			   // LoadBtn
			   // 
			   this->LoadBtn->Location = System::Drawing::Point(101, 335); // (Sửa) Di chuyển xuống
			   this->LoadBtn->Margin = System::Windows::Forms::Padding(2);
			   this->LoadBtn->Name = L"LoadBtn";
			   this->LoadBtn->Size = System::Drawing::Size(86, 26);
			   this->LoadBtn->TabIndex = 6;
			   this->LoadBtn->Text = L"Load File";
			   this->LoadBtn->UseVisualStyleBackColor = true;
			   this->LoadBtn->Click += gcnew System::EventHandler(this, &MainUI::LoadBtn_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileImage";
			   // 
			   // (THÊM MỚI) checkValueLabel
			   // 
			   this->checkValueLabel->AutoSize = true;
			   this->checkValueLabel->Location = System::Drawing::Point(188, 16); // (Sửa) Vị trí bên phải thanh trượt
			   this->checkValueLabel->Name = L"checkValueLabel";
			   this->checkValueLabel->Size = System::Drawing::Size(25, 13);
			   this->checkValueLabel->TabIndex = 7;
			   this->checkValueLabel->Text = L"128";
			   // 
			   // (THÊM MỚI) channelBox
			   // 
			   this->channelBox->Controls->Add(this->redRadio);
			   this->channelBox->Controls->Add(this->greenRadio);
			   this->channelBox->Controls->Add(this->blueRadio);
			   this->channelBox->Controls->Add(this->grayRadio);
			   this->channelBox->Location = System::Drawing::Point(9, 60); // (Sửa) Vị trí mới
			   this->channelBox->Name = L"channelBox";
			   this->channelBox->Size = System::Drawing::Size(200, 130);
			   this->channelBox->TabIndex = 8;
			   this->channelBox->TabStop = false;
			   this->channelBox->Text = L"Processing Channel";
			   // 
			   // (THÊM MỚI) grayRadio
			   // 
			   this->grayRadio->AutoSize = true;
			   this->grayRadio->Checked = true; // Mặc định chọn
			   this->grayRadio->Location = System::Drawing::Point(15, 25);
			   this->grayRadio->Name = L"grayRadio";
			   this->grayRadio->Size = System::Drawing::Size(72, 17);
			   this->grayRadio->TabIndex = 0;
			   this->grayRadio->TabStop = true;
			   this->grayRadio->Text = L"Grayscale";
			   this->grayRadio->UseVisualStyleBackColor = true;
			   this->grayRadio->CheckedChanged += gcnew System::EventHandler(this, &MainUI::Radio_CheckedChanged);
			   // 
			   // (THÊM MỚI) blueRadio
			   // 
			   this->blueRadio->AutoSize = true;
			   this->blueRadio->Location = System::Drawing::Point(15, 48);
			   this->blueRadio->Name = L"blueRadio";
			   this->blueRadio->Size = System::Drawing::Size(46, 17);
			   this->blueRadio->TabIndex = 1;
			   this->blueRadio->Text = L"Blue";
			   this->blueRadio->UseVisualStyleBackColor = true;
			   this->blueRadio->CheckedChanged += gcnew System::EventHandler(this, &MainUI::Radio_CheckedChanged);
			   // 
			   // (THÊM MỚI) greenRadio
			   // 
			   this->greenRadio->AutoSize = true;
			   this->greenRadio->Location = System::Drawing::Point(15, 71);
			   this->greenRadio->Name = L"greenRadio";
			   this->greenRadio->Size = System::Drawing::Size(54, 17);
			   this->greenRadio->TabIndex = 2;
			   this->greenRadio->Text = L"Green";
			   this->greenRadio->UseVisualStyleBackColor = true;
			   this->greenRadio->CheckedChanged += gcnew System::EventHandler(this, &MainUI::Radio_CheckedChanged);
			   // 
			   // (THÊM MỚI) redRadio
			   // 
			   this->redRadio->AutoSize = true;
			   this->redRadio->Location = System::Drawing::Point(15, 94);
			   this->redRadio->Name = L"redRadio";
			   this->redRadio->Size = System::Drawing::Size(45, 17);
			   this->redRadio->TabIndex = 3;
			   this->redRadio->Text = L"Red";
			   this->redRadio->UseVisualStyleBackColor = true;
			   this->redRadio->CheckedChanged += gcnew System::EventHandler(this, &MainUI::Radio_CheckedChanged);
			   // 
			   // MainUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(608, 441); // (Sửa) Tăng chiều cao cửa sổ
			   // (THÊM MỚI) Thêm các control mới vào Form
			   this->Controls->Add(this->channelBox);
			   this->Controls->Add(this->checkValueLabel);

			   this->Controls->Add(this->LoadBtn);
			   this->Controls->Add(this->CheckValue);
			   this->Controls->Add(this->ExampleBtn);
			   this->Controls->Add(this->ProgressBtn);
			   this->Controls->Add(this->ReverseColorCheck);
			   this->Controls->Add(this->InputPic);
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"MainUI";
			   this->Text = L"MainUI";

			   // Tiếp tục layout
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputPic))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CheckValue))->EndInit();
			   this->channelBox->ResumeLayout(false);
			   this->channelBox->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   //=================================================================
		   // HÀM HỖ TRỢ (Giữ nguyên)
		   //=================================================================

		   System::Drawing::Bitmap^ MatToBitmap(const Mat& mat) {
			   if (mat.empty() || mat.type() != CV_8UC1) {
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


		   //=================================================================
		   // HÀM XỬ LÝ ẢNH (VIẾT LẠI)
		   //=================================================================

				   /**
					* @brief Xử lý ảnh đầu vào dựa trên kênh đã chọn
					* @param inputImg Ảnh Mat đầu vào (PHẢI LÀ ẢNH MÀU CV_8UC3)
					* @return Ảnh Mat kết quả (ảnh nhị phân CV_8UC1)
					*/
		   Mat ProcessImage(Mat inputImg) {

			   // 1. Chuẩn bị kênh ảnh xám để xử lý
			   Mat grayToProcess;

			   if (selectedChannel == 0) { // Grayscale
				   cvtColor(inputImg, grayToProcess, COLOR_BGR2GRAY);
			   }
			   else { // Kênh màu
				   vector<Mat> channels;
				   split(inputImg, channels);
				   // selectedChannel: 1=B (index 0), 2=G (index 1), 3=R (index 2)
				   grayToProcess = channels[selectedChannel - 1];
			   }

			   // 2. Xử lý ảnh (logic cũ)
			   const int rows = grayToProcess.rows;
			   const int cols = grayToProcess.cols;
			   Mat newImg(rows, cols, CV_8UC1); // Ảnh đầu ra

			   if (!isReversed) {
				   for (int y = 0; y < rows; y++) {
					   for (int x = 0; x < cols; x++) {
						   newImg.at<uchar>(y, x) = (grayToProcess.at<uchar>(y, x) >= checkValue) ? 255 : 0;
					   }
				   }
			   }
			   else {
				   for (int y = 0; y < rows; y++) {
					   for (int x = 0; x < cols; x++) {
						   newImg.at<uchar>(y, x) = (grayToProcess.at<uchar>(y, x) >= checkValue) ? 0 : 255;
					   }
				   }
			   }

			   return newImg;
		   }


		   //=================================================================
		   // CÁC HÀM SỰ KIỆN (ĐÃ SỬA VÀ THÊM MỚI)
		   //=================================================================

	private: System::Void CheckValue_Scroll(System::Object^ sender, System::EventArgs^ e) {
		checkValue = CheckValue->Value;
		// (THÊM MỚI) Cập nhật Label
		this->checkValueLabel->Text = checkValue.ToString();
	}

	private: System::Void ReverseColorCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		isReversed = ReverseColorCheck->Checked;
	}

		   // (THÊM MỚI) Hàm xử lý chung cho các RadioButton
	private: System::Void Radio_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (grayRadio->Checked) {
			selectedChannel = 0;
		}
		else if (blueRadio->Checked) {
			selectedChannel = 1;
		}
		else if (greenRadio->Checked) {
			selectedChannel = 2;
		}
		else if (redRadio->Checked) {
			selectedChannel = 3;
		}
	}


	private: System::Void ExampleBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		string examplePath = "horseImage.png";

		// 1. Hiển thị ảnh (dùng .NET)
		try {
			InputPic->Image = Image::FromFile(gcnew Task1::String(examplePath.c_str()));
			InputPic->SizeMode = PictureBoxSizeMode::Zoom;
		}
		catch (Task1::Exception^ ex) {
			MessageBox::Show("Không thể tải 'horseImage.png'!");
			return;
		}

		// 2. Tải ảnh (dùng OpenCV)
		// (SỬA) Tải ảnh MÀU
		img = imread(examplePath, IMREAD_COLOR);

		if (img.empty()) {
			MessageBox::Show("OpenCV không thể đọc 'horseImage.png'!");
			return;
		}

		// (SỬA) Xóa dòng xử lý ảnh. Chỉ load.
		// ProgressBtn_Click(sender, e);
	}



	private: System::Void LoadBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp";

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// 1. Hiển thị ảnh trong PictureBox (dùng .NET)
			InputPic->Image = Image::FromFile(ofd->FileName);
			InputPic->SizeMode = PictureBoxSizeMode::Zoom;

			// 2. Tải ảnh vào OpenCV (dùng OpenCV)
			string path = marshal_as<string>(ofd->FileName);

			// (SỬA) Tải ảnh MÀU (IMREAD_COLOR) để có thể xử lý kênh
			img = imread(path, IMREAD_COLOR);

			if (img.empty()) {
				MessageBox::Show("Can't Read!");
			}
			else if ((img.cols > 1920) || (img.rows > 1080)) {
				MessageBox::Show("Image too large! (Max: 1920x1080)");
				img.release(); // Giải phóng ảnh nếu quá lớn
			}
		}
	}


	private: System::Void ProgressBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (img.empty()) {
			MessageBox::Show("Image not loaded!");
			return;
		}

		// (THÊM MỚI) Kiểm tra ảnh có phải là ảnh màu không nếu chọn kênh R,G,B
		if (selectedChannel > 0 && img.channels() != 3) {
			MessageBox::Show("Vui lòng tải ảnh màu để xử lý kênh R, G, B!");
			return;
		}

		// 1. Xử lý ảnh
		Mat processedMat = ProcessImage(img);

		// 2. Chuyển kết quả sang Bitmap
		System::Drawing::Bitmap^ outputBitmap = MatToBitmap(processedMat);

		// 3. Hiển thị kết quả lên PictureBox
		if (outputBitmap != nullptr) {
			// (SỬA) Hiển thị ảnh đã xử lý
			// Nếu bạn muốn giữ ảnh gốc, bạn cần thêm 1 PictureBox thứ 2
			InputPic->Image = outputBitmap;
		}
		else {
			MessageBox::Show("Lỗi chuyển đổi ảnh kết quả.");
		}
	}
	};
}