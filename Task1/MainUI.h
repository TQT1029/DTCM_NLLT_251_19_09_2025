#pragma once
#include <opencv2/opencv.hpp>
#include <msclr/marshal_cppstd.h>

using namespace cv;
using namespace std;



//=====Config Handle=====
bool isReversed = false;
int checkValue = 128;
Mat img;

namespace Task1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainUI
	/// </summary>
	public ref class MainUI : public System::Windows::Forms::Form
	{
	public:
		MainUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ InputPic;
	private: System::Windows::Forms::CheckBox^ ReverseColorCheck;

	protected:


	private: System::Windows::Forms::Button^ ProgressBtn;



	private: System::Windows::Forms::Button^ ExampleBtn;
	private: System::Windows::Forms::TrackBar^ CheckValue;
	private: System::Windows::Forms::Button^ LoadBtn;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::ComponentModel::IContainer^ components;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputPic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CheckValue))->BeginInit();
			this->SuspendLayout();
			// 
			// InputPic
			// 
			this->InputPic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InputPic.Image")));
			this->InputPic->Location = System::Drawing::Point(292, 12);
			this->InputPic->Name = L"InputPic";
			this->InputPic->Size = System::Drawing::Size(506, 425);
			this->InputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->InputPic->TabIndex = 0;
			this->InputPic->TabStop = false;
			// 
			// ReverseColorCheck
			// 
			this->ReverseColorCheck->AutoSize = true;
			this->ReverseColorCheck->Location = System::Drawing::Point(134, 390);
			this->ReverseColorCheck->Name = L"ReverseColorCheck";
			this->ReverseColorCheck->Size = System::Drawing::Size(116, 20);
			this->ReverseColorCheck->TabIndex = 1;
			this->ReverseColorCheck->Text = L"Reverse Color";
			this->ReverseColorCheck->UseVisualStyleBackColor = true;
			this->ReverseColorCheck->CheckedChanged += gcnew System::EventHandler(this, &MainUI::ReverseColorCheck_CheckedChanged);
			// 
			// ProgressBtn
			// 
			this->ProgressBtn->Location = System::Drawing::Point(12, 360);
			this->ProgressBtn->Name = L"ProgressBtn";
			this->ProgressBtn->Size = System::Drawing::Size(116, 50);
			this->ProgressBtn->TabIndex = 2;
			this->ProgressBtn->Text = L"Progress";
			this->ProgressBtn->UseVisualStyleBackColor = true;
			this->ProgressBtn->Click += gcnew System::EventHandler(this, &MainUI::ProgressBtn_Click);
			// 
			// ExampleBtn
			// 
			this->ExampleBtn->Location = System::Drawing::Point(135, 360);
			this->ExampleBtn->Name = L"ExampleBtn";
			this->ExampleBtn->Size = System::Drawing::Size(115, 23);
			this->ExampleBtn->TabIndex = 4;
			this->ExampleBtn->Text = L"Example";
			this->ExampleBtn->UseVisualStyleBackColor = true;
			this->ExampleBtn->Click += gcnew System::EventHandler(this, &MainUI::ExampleBtn_Click);
			// 
			// CheckValue
			// 
			this->CheckValue->Location = System::Drawing::Point(12, 298);
			this->CheckValue->Maximum = 255;
			this->CheckValue->Name = L"CheckValue";
			this->CheckValue->Size = System::Drawing::Size(238, 56);
			this->CheckValue->TabIndex = 5;
			this->CheckValue->Value = 128;
			this->CheckValue->Scroll += gcnew System::EventHandler(this, &MainUI::CheckValue_Scroll);
			// 
			// LoadBtn
			// 
			this->LoadBtn->Location = System::Drawing::Point(12, 260);
			this->LoadBtn->Name = L"LoadBtn";
			this->LoadBtn->Size = System::Drawing::Size(98, 32);
			this->LoadBtn->TabIndex = 6;
			this->LoadBtn->Text = L"Load File";
			this->LoadBtn->UseVisualStyleBackColor = true;
			this->LoadBtn->Click += gcnew System::EventHandler(this, &MainUI::LoadBtn_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileImage";
			// 
			// MainUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(810, 449);
			this->Controls->Add(this->LoadBtn);
			this->Controls->Add(this->CheckValue);
			this->Controls->Add(this->ExampleBtn);
			this->Controls->Add(this->ProgressBtn);
			this->Controls->Add(this->ReverseColorCheck);
			this->Controls->Add(this->InputPic);
			this->Name = L"MainUI";
			this->Text = L"MainUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputPic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CheckValue))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void ProcessImage(Mat img) {
			const int rows = img.rows, cols = img.cols;

			vector<vector<int>> imgMatrix(rows, vector<int>(cols, 0));

			if (!isReversed)
				for (int y = 0; y < img.rows; y++) {
					for (int x = 0; x < img.cols; x++) {
						if (img.at<uchar>(y, x) >= checkValue) {
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
						if (img.at<uchar>(y, x) >= checkValue) {
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
			imshow("output.png", newImg);

			img.release();
		}

	private: System::Void CheckValue_Scroll(System::Object^ sender, System::EventArgs^ e) {
		checkValue = CheckValue->Value;
	}

	private: System::Void ReverseColorCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (ReverseColorCheck->Checked) isReversed = true;
		else isReversed = false;
	}

	private: System::Void ExampleBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		// Load Image
		InputPic->Image = System::Drawing::Image::FromFile("horseImage.png");

		Mat img = imread("horseImage.png", IMREAD_GRAYSCALE);

		// Process Image
		ProcessImage(img);
	}

	

	private: System::Void LoadBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp";

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// Hiển thị ảnh trong PictureBox
			InputPic->Image = Image::FromFile(ofd->FileName);
			InputPic->SizeMode = PictureBoxSizeMode::Zoom; // co ảnh vừa khung

			// Load ảnh vào OpenCV
			 // Chuyển System::String^ sang std::string
			string path = msclr::interop::marshal_as<string>(ofd->FileName);

			// Đọc ảnh bằng OpenCV
			img = imread(path, IMREAD_COLOR);

			if (img.empty() ) {
				MessageBox::Show("Can't Read!");
			}
			else if ((img.cols > 1920) || (img.rows > 1080)) {
				MessageBox::Show("Image too large! (Max: 1920x1080)");
				img.release();
			}
		}
	}


	private: System::Void ProgressBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (img.empty()) {
			MessageBox::Show("Image not loaded!");
		}
		else {
			ProcessImage(img);
		}
	}
};
}
