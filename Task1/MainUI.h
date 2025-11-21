#pragma once
#include <msclr/marshal_cppstd.h>
#include <string> 
#include "ImgProcess.h" // Include file xử lý logic

using namespace std;

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
		// ===== KHAI BÁO BIẾN THÀNH VIÊN (Thay thế biến toàn cục) =====
	private:

		// Dùng con trỏ cho Mat vì đây là class unmanaged trong môi trường managed
		Mat* srcImg;       // Ảnh gốc
		Mat* processedImg; // Ảnh sau xử lý


		bool isReversed;
		int checkValue;
		int selectedChannel; // 0: Gray, 1: Blue, 2: Green, 3: Red

	public:
		MainUI(void)
		{
			InitializeComponent();

			// Khởi tạo biến
			srcImg = new Mat();
			processedImg = new Mat();
			isReversed = false;
			checkValue = 128;
			selectedChannel = 0;

			// Đặt giá trị ban đầu cho UI
			this->checkValueLabel->Text = this->CheckValue->Value.ToString();
			this->CheckValue->Value = checkValue;

			// Tự động load ảnh example
			LoadExampleImage();
		}

	protected:
		~MainUI()
		{
			// Giải phóng bộ nhớ thủ công cho biến unmanaged
			if (srcImg) delete srcImg;
			if (processedImg) delete processedImg;

			if (components)
			{
				delete components;
			}
		}

		// ===== CÁC HÀM HỖ TRỢ UI RIÊNG =====
	private:
		void LoadExampleImage() {
			string examplePath = "horseImage.png";

			// 1. Hiển thị ảnh lên PictureBox
			try {
				InputPic->Image = Image::FromFile(gcnew Task1::String(examplePath.c_str()));
				InputPic->SizeMode = PictureBoxSizeMode::Zoom;
			}
			catch (Task1::Exception^) {
				// Không làm gì nếu không tìm thấy file lúc khởi động
				// MessageBox::Show("Không tìm thấy ảnh mặc định horseImage.png");
			}

			// 2. Load vào OpenCV
			*srcImg = imread(examplePath, IMREAD_COLOR);

			if (srcImg->empty()) {
				// Có thể log lỗi nếu cần
			}
			else {
				// Reset ảnh đã xử lý cũ
				if (!processedImg->empty()) processedImg->release();
			}
		}

		// ===== KHAI BÁO UI CONTROLS (GIỮ NGUYÊN) =====
	private: System::Windows::Forms::PictureBox^ InputPic;
	private: System::Windows::Forms::CheckBox^ ReverseColorCheck;
	private: System::Windows::Forms::Button^ ProgressBtn;
	private: System::Windows::Forms::Button^ ExampleBtn;
	private: System::Windows::Forms::TrackBar^ CheckValue;
	private: System::Windows::Forms::Button^ LoadBtn;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::GroupBox^ channelBox;
	private: System::Windows::Forms::RadioButton^ grayRadio;
	private: System::Windows::Forms::RadioButton^ blueRadio;
	private: System::Windows::Forms::RadioButton^ greenRadio;
	private: System::Windows::Forms::RadioButton^ redRadio;
	private: System::Windows::Forms::Label^ checkValueLabel;
	private: System::Windows::Forms::Button^ SaveBtn;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;


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
			   this->channelBox = (gcnew System::Windows::Forms::GroupBox());
			   this->redRadio = (gcnew System::Windows::Forms::RadioButton());
			   this->greenRadio = (gcnew System::Windows::Forms::RadioButton());
			   this->blueRadio = (gcnew System::Windows::Forms::RadioButton());
			   this->grayRadio = (gcnew System::Windows::Forms::RadioButton());
			   this->checkValueLabel = (gcnew System::Windows::Forms::Label());
			   this->SaveBtn = (gcnew System::Windows::Forms::Button());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
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
			   this->InputPic->Size = System::Drawing::Size(380, 420);
			   this->InputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->InputPic->TabIndex = 0;
			   this->InputPic->TabStop = false;
			   // 
			   // ReverseColorCheck
			   // 
			   this->ReverseColorCheck->AutoSize = true;
			   this->ReverseColorCheck->Location = System::Drawing::Point(100, 390);
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
			   this->ProgressBtn->Location = System::Drawing::Point(9, 365);
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
			   this->ExampleBtn->Location = System::Drawing::Point(101, 365);
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
			   this->CheckValue->Location = System::Drawing::Point(9, 10);
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
			   this->LoadBtn->Location = System::Drawing::Point(101, 335);
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
			   // channelBox
			   // 
			   this->channelBox->Controls->Add(this->redRadio);
			   this->channelBox->Controls->Add(this->greenRadio);
			   this->channelBox->Controls->Add(this->blueRadio);
			   this->channelBox->Controls->Add(this->grayRadio);
			   this->channelBox->Location = System::Drawing::Point(9, 60);
			   this->channelBox->Name = L"channelBox";
			   this->channelBox->Size = System::Drawing::Size(200, 130);
			   this->channelBox->TabIndex = 8;
			   this->channelBox->TabStop = false;
			   this->channelBox->Text = L"Processing Channel";
			   // 
			   // redRadio
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
			   // greenRadio
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
			   // blueRadio
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
			   // grayRadio
			   // 
			   this->grayRadio->AutoSize = true;
			   this->grayRadio->Checked = true;
			   this->grayRadio->Location = System::Drawing::Point(15, 25);
			   this->grayRadio->Name = L"grayRadio";
			   this->grayRadio->Size = System::Drawing::Size(72, 17);
			   this->grayRadio->TabIndex = 0;
			   this->grayRadio->TabStop = true;
			   this->grayRadio->Text = L"Grayscale";
			   this->grayRadio->UseVisualStyleBackColor = true;
			   this->grayRadio->CheckedChanged += gcnew System::EventHandler(this, &MainUI::Radio_CheckedChanged);
			   // 
			   // checkValueLabel
			   // 
			   this->checkValueLabel->AutoSize = true;
			   this->checkValueLabel->Location = System::Drawing::Point(188, 16);
			   this->checkValueLabel->Name = L"checkValueLabel";
			   this->checkValueLabel->Size = System::Drawing::Size(25, 13);
			   this->checkValueLabel->TabIndex = 7;
			   this->checkValueLabel->Text = L"128";
			   // 
			   // SaveBtn
			   // 
			   this->SaveBtn->Location = System::Drawing::Point(9, 335);
			   this->SaveBtn->Margin = System::Windows::Forms::Padding(2);
			   this->SaveBtn->Name = L"SaveBtn";
			   this->SaveBtn->Size = System::Drawing::Size(87, 26);
			   this->SaveBtn->TabIndex = 9;
			   this->SaveBtn->Text = L"Save Image";
			   this->SaveBtn->UseVisualStyleBackColor = true;
			   this->SaveBtn->Click += gcnew System::EventHandler(this, &MainUI::SaveBtn_Click);
			   // 
			   // saveFileDialog1
			   // 
			   this->saveFileDialog1->Filter = L"PNG Image|*.png|JPEG Image|*.jpg|Bitmap Image|*.bmp";
			   this->saveFileDialog1->Title = L"Save Processed Image";
			   // 
			   // MainUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(608, 441);
			   this->Controls->Add(this->SaveBtn);
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
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputPic))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CheckValue))->EndInit();
			   this->channelBox->ResumeLayout(false);
			   this->channelBox->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   //=================================================================
		   // EVENT HANDLERS (ĐÃ ĐƯỢC VIẾT LẠI ĐỂ GỌI IMAGEPROCESSOR)
		   //=================================================================

	private: System::Void CheckValue_Scroll(System::Object^ sender, System::EventArgs^ e) {
		checkValue = CheckValue->Value;
		this->checkValueLabel->Text = checkValue.ToString();
	}

	private: System::Void ReverseColorCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		isReversed = ReverseColorCheck->Checked;
	}

	private: System::Void Radio_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (grayRadio->Checked) selectedChannel = 0;
		else if (blueRadio->Checked) selectedChannel = 1;
		else if (greenRadio->Checked) selectedChannel = 2;
		else if (redRadio->Checked) selectedChannel = 3;
	}

	private: System::Void ExampleBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadExampleImage();
	}

	private: System::Void LoadBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp";

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// 1. UI
			InputPic->Image = Image::FromFile(ofd->FileName);
			InputPic->SizeMode = PictureBoxSizeMode::Zoom;

			// 2. Logic: Cập nhật ảnh gốc vào biến thành viên
			string path = marshal_as<string>(ofd->FileName);
			*srcImg = imread(path, IMREAD_COLOR);

			if (srcImg->empty()) {
				MessageBox::Show("Can't Read!");
			}
			else if ((srcImg->cols > 1920) || (srcImg->rows > 1080)) {
				MessageBox::Show("Image too large! (Max: 1920x1080)");
				srcImg->release();
			}
			else {
				// Reset ảnh cũ
				processedImg->release();
			}
		}
	}

	private: System::Void ProgressBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (srcImg->empty()) {
			MessageBox::Show("Image not loaded!");
			return;
		}

		// Check logic
		if (selectedChannel > 0 && srcImg->channels() != 3) {
			MessageBox::Show("Vui lòng tải ảnh màu để xử lý kênh R, G, B!");
			return;
		}

		// 1. GỌI HÀM XỬ LÝ TỪ FILE KHÁC (ImageCore.h)
		// Truyền các tham số cấu hình (threshold, reverse, channel) vào hàm tĩnh
		*processedImg = ImageProcessor::ProcessImageLogic(*srcImg, checkValue, isReversed, selectedChannel);

		// 2. GỌI HÀM CHUYỂN ĐỔI TỪ FILE KHÁC
		System::Drawing::Bitmap^ outputBitmap = ImageProcessor::MatToBitmap(*processedImg);

		// 3. Hiển thị kết quả
		if (outputBitmap != nullptr) {
			InputPic->Image = outputBitmap;
		}
		else {
			MessageBox::Show("Lỗi xử lý hoặc chuyển đổi ảnh.");
		}
	}

	private: System::Void SaveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (processedImg->empty()) {
			MessageBox::Show("Bạn phải nhấn 'Progress' để xử lý ảnh trước khi lưu!");
			return;
		}

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				string savePath = marshal_as<string>(saveFileDialog1->FileName);
				imwrite(savePath, *processedImg);
				MessageBox::Show("Lưu ảnh thành công!");
			}
			catch (Task1::Exception^ ex) {
				MessageBox::Show("Lỗi khi lưu ảnh: " + ex->Message);
			}
		}
	}
	};
}