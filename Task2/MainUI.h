#pragma once
#include "MainCore.h"
#include <msclr/marshal_cppstd.h>
#include <string>

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

			descriptionLabel1->Text = gcnew System::String(_gameLogic->GetDescription().c_str());
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
	private: System::Windows::Forms::ListBox^ historyListBox1;
	private: System::Windows::Forms::Button^ resetBtn1;
	private: System::Windows::Forms::Label^ textBox2;


	private: System::Windows::Forms::Label^ Text1;




#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainUI::typeid));
			   this->inputBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->checkBtn1 = (gcnew System::Windows::Forms::Button());
			   this->Text1 = (gcnew System::Windows::Forms::Label());
			   this->spoilAns1 = (gcnew System::Windows::Forms::Label());
			   this->Text2 = (gcnew System::Windows::Forms::Label());
			   this->descriptionLabel1 = (gcnew System::Windows::Forms::Label());
			   this->trieslabel1 = (gcnew System::Windows::Forms::Label());
			   this->historyListBox1 = (gcnew System::Windows::Forms::ListBox());
			   this->resetBtn1 = (gcnew System::Windows::Forms::Button());
			   this->textBox2 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // inputBox1
			   // 
			   resources->ApplyResources(this->inputBox1, L"inputBox1");
			   this->inputBox1->Name = L"inputBox1";
			   this->inputBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainUI::inputBox1_EnterDown);
			   // 
			   // checkBtn1
			   // 
			   this->checkBtn1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			   resources->ApplyResources(this->checkBtn1, L"checkBtn1");
			   this->checkBtn1->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->checkBtn1->ForeColor = System::Drawing::Color::LightGreen;
			   this->checkBtn1->Name = L"checkBtn1";
			   this->checkBtn1->UseVisualStyleBackColor = false;
			   this->checkBtn1->Click += gcnew System::EventHandler(this, &MainUI::checkBtn1_Click);
			   // 
			   // Text1
			   // 
			   resources->ApplyResources(this->Text1, L"Text1");
			   this->Text1->Name = L"Text1";
			   // 
			   // spoilAns1
			   // 
			   resources->ApplyResources(this->spoilAns1, L"spoilAns1");
			   this->spoilAns1->Name = L"spoilAns1";
			   // 
			   // Text2
			   // 
			   resources->ApplyResources(this->Text2, L"Text2");
			   this->Text2->Name = L"Text2";
			   // 
			   // descriptionLabel1
			   // 
			   resources->ApplyResources(this->descriptionLabel1, L"descriptionLabel1");
			   this->descriptionLabel1->Name = L"descriptionLabel1";
			   // 
			   // trieslabel1
			   // 
			   resources->ApplyResources(this->trieslabel1, L"trieslabel1");
			   this->trieslabel1->Name = L"trieslabel1";
			   // 
			   // historyListBox1
			   // 
			   resources->ApplyResources(this->historyListBox1, L"historyListBox1");
			   this->historyListBox1->FormattingEnabled = true;
			   this->historyListBox1->Name = L"historyListBox1";
			   this->historyListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainUI::historyListBox1_SelectedIndexChanged);
			   // 
			   // resetBtn1
			   // 
			   this->resetBtn1->BackColor = System::Drawing::Color::MediumSeaGreen;
			   resources->ApplyResources(this->resetBtn1, L"resetBtn1");
			   this->resetBtn1->Name = L"resetBtn1";
			   this->resetBtn1->UseVisualStyleBackColor = false;
			   this->resetBtn1->Click += gcnew System::EventHandler(this, &MainUI::resetBtn1_Click);
			   // 
			   // textBox2
			   // 
			   resources->ApplyResources(this->textBox2, L"textBox2");
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Click += gcnew System::EventHandler(this, &MainUI::textBox2_Click);
			   // 
			   // MainUI
			   // 
			   resources->ApplyResources(this, L"$this");
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->resetBtn1);
			   this->Controls->Add(this->historyListBox1);
			   this->Controls->Add(this->trieslabel1);
			   this->Controls->Add(this->descriptionLabel1);
			   this->Controls->Add(this->Text2);
			   this->Controls->Add(this->spoilAns1);
			   this->Controls->Add(this->Text1);
			   this->Controls->Add(this->checkBtn1);
			   this->Controls->Add(this->inputBox1);
			   this->MaximizeBox = false;
			   this->Name = L"MainUI";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion


		   void InputHandle() {
			   String^ input = inputBox1->Text->ToLower();
			   std::string guess = msclr::interop::marshal_as<std::string>(input);

			   bool win = false, lose = false;
			   std::string spoil = _gameLogic->ProcessGuess(guess, win, lose);

			   spoilAns1->Text = gcnew String(spoil.c_str());

			   int triesLeft = _gameLogic->GetTriesLeft();
			   trieslabel1->Text = "Tries left: " + triesLeft.ToString();
			   inputBox1->Clear();
			   inputBox1->Focus();

			   // 🔹 Cập nhật ListBox lịch sử đoán
			   historyListBox1->Items->Clear();
			   for (auto& g : _gameLogic->GetGuessHistory()) {
				   historyListBox1->Items->Add(gcnew System::String(g.c_str()));
			   }

			   if (win) {
				   MessageBox::Show("You Win!");
				   this->Close();
			   }
			   else if (lose) {
				   MessageBox::Show("You Lose! Answer: " + gcnew String(_gameLogic->GetAnswer().c_str()));
				   this->Close();
			   }
		   }

		   void ResetGameHandle() {
			   _gameLogic->ResetGame();

			   inputBox1->MaxLength = _gameLogic->GetAnswer().length();

			   descriptionLabel1->Text = gcnew System::String(_gameLogic->GetDescription().c_str());
			   spoilAns1->Text = gcnew String(_gameLogic->spoilAns.c_str());
			   trieslabel1->Text = "Tries left: " + _gameLogic->GetTriesLeft().ToString();
			   historyListBox1->Items->Clear();
			   inputBox1->Clear();
			   inputBox1->Focus();
		   }

		   // ====== EVENT HANDLERS ======

	private: System::Void checkBtn1_Click(System::Object^ sender, System::EventArgs^ e) {
		InputHandle();
	}
	private: System::Void inputBox1_EnterDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			InputHandle();

			e->Handled = true;
			e->SuppressKeyPress = true;
		}
	}

	private: System::Void resetBtn1_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetGameHandle();
	}
private: System::Void textBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void historyListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
