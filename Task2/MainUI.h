#pragma once
#include "MainCore.h"
#include <msclr/marshal_cppstd.h>

namespace Task2 {

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
	private:
		GameLogic* _gameLogic;// Pointer to the game logic

	public:
		MainUI(void)
		{
			InitializeComponent();
			_gameLogic = new GameLogic();


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
			if (_gameLogic) delete _gameLogic;
		}

	protected:

	private:

		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::TextBox^ inputBox1;
	private: System::Windows::Forms::Button^ checkBtn1;
	private: System::Windows::Forms::Label^ spoilAns1;
	private: System::Windows::Forms::Label^ Text2;
	private: System::Windows::Forms::Label^ descriptionLabel1;
	private: System::Windows::Forms::Label^ trieslabel1;

	private: System::Windows::Forms::Label^ Text1;




#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->inputBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->checkBtn1 = (gcnew System::Windows::Forms::Button());
			   this->Text1 = (gcnew System::Windows::Forms::Label());
			   this->spoilAns1 = (gcnew System::Windows::Forms::Label());
			   this->Text2 = (gcnew System::Windows::Forms::Label());
			   this->descriptionLabel1 = (gcnew System::Windows::Forms::Label());
			   this->trieslabel1 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // inputBox1
			   // 
			   this->inputBox1->Location = System::Drawing::Point(16, 205);
			   this->inputBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->inputBox1->MaxLength = 5;
			   this->inputBox1->Name = L"inputBox1";
			   this->inputBox1->Size = System::Drawing::Size(132, 22);
			   this->inputBox1->TabIndex = 0;
			   // 
			   // checkBtn1
			   // 
			   this->checkBtn1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->checkBtn1->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->checkBtn1->ForeColor = System::Drawing::Color::SpringGreen;
			   this->checkBtn1->Location = System::Drawing::Point(160, 205);
			   this->checkBtn1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->checkBtn1->Name = L"checkBtn1";
			   this->checkBtn1->Size = System::Drawing::Size(27, 25);
			   this->checkBtn1->TabIndex = 1;
			   this->checkBtn1->UseVisualStyleBackColor = false;
			   this->checkBtn1->Click += gcnew System::EventHandler(this, &MainUI::checkBtn1_Click);
			   // 
			   // Text1
			   // 
			   this->Text1->AutoSize = true;
			   this->Text1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Text1->Location = System::Drawing::Point(16, 180);
			   this->Text1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->Text1->Name = L"Text1";
			   this->Text1->Size = System::Drawing::Size(146, 20);
			   this->Text1->TabIndex = 2;
			   this->Text1->Text = L"Input your answer:";
			   // 
			   // spoilAns1
			   // 
			   this->spoilAns1->AutoSize = true;
			   this->spoilAns1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->spoilAns1->Location = System::Drawing::Point(17, 277);
			   this->spoilAns1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->spoilAns1->Name = L"spoilAns1";
			   this->spoilAns1->Size = System::Drawing::Size(75, 36);
			   this->spoilAns1->TabIndex = 3;
			   this->spoilAns1->Text = L"*****";
			   // 
			   // Text2
			   // 
			   this->Text2->AutoSize = true;
			   this->Text2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Text2->Location = System::Drawing::Point(17, 246);
			   this->Text2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->Text2->Name = L"Text2";
			   this->Text2->Size = System::Drawing::Size(155, 20);
			   this->Text2->TabIndex = 4;
			   this->Text2->Text = L"Correct characters:";
			   // 
			   // descriptionLabel1
			   // 
			   this->descriptionLabel1->AutoSize = true;
			   this->descriptionLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->descriptionLabel1->Location = System::Drawing::Point(13, 13);
			   this->descriptionLabel1->Name = L"descriptionLabel1";
			   this->descriptionLabel1->Size = System::Drawing::Size(166, 25);
			   this->descriptionLabel1->TabIndex = 5;
			   this->descriptionLabel1->Text = L"Description object";
			   // 
			   // trieslabel1
			   // 
			   this->trieslabel1->AutoSize = true;
			   this->trieslabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->trieslabel1->Location = System::Drawing::Point(200, 205);
			   this->trieslabel1->Name = L"trieslabel1";
			   this->trieslabel1->Size = System::Drawing::Size(94, 20);
			   this->trieslabel1->TabIndex = 6;
			   this->trieslabel1->Text = L"Tries left: 5";
			   this->trieslabel1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // MainUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(512, 543);
			   this->Controls->Add(this->trieslabel1);
			   this->Controls->Add(this->descriptionLabel1);
			   this->Controls->Add(this->Text2);
			   this->Controls->Add(this->spoilAns1);
			   this->Controls->Add(this->Text1);
			   this->Controls->Add(this->checkBtn1);
			   this->Controls->Add(this->inputBox1);
			   this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Name = L"MainUI";
			   this->Text = L"MainUI";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	protected:
		virtual bool ProcessCmdKey(Message% msg, Keys keyData) override {
			if (keyData == Keys::Enter || keyData == Keys::Escape) {
				// Chặn tiếng ding toàn cục
				return true; // báo là đã xử lý phím này
			}
			return Form::ProcessCmdKey(msg, keyData);
		}



		// ====== EVENT HANDLERS ======

	private: System::Void checkBtn1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ input = inputBox1->Text;
		std::string guess = msclr::interop::marshal_as<std::string>(input);

		bool win = false, lose = false;
		std::string spoil = _gameLogic->ProcessGuess(guess, win, lose);

		spoilAns1->Text = gcnew String(spoil.c_str());

		if (win) {
			MessageBox::Show("You Win!");
			this->Close();
		}
		else if (lose) {
			MessageBox::Show("You Lose! Answer: " + gcnew String(_gameLogic->GetAnswer().c_str()));
			this->Close();
		}
	}
	};
}
