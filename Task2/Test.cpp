#pragma once
#include <string>
#include <vector>
#include <random>
#include <msclr/marshal_cppstd.h>   

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;

public ref class MainUI : public Form
{
private:
    TextBox^ inputBox;
    Button^ checkButton;
    Label^ resultLabel;
    Label^ triesLabel;


public:
    MainUI(void)
    {
        InitializeComponent();
    }

protected:
    ~MainUI()
    {
        if (components) delete components;
    }

private:
    System::ComponentModel::Container^ components;

    void InitializeComponent(void)
    {
        this->Text = L"Word Guess Game";
        this->ClientSize = System::Drawing::Size(400, 200);

        inputBox = gcnew TextBox();
        inputBox->Location = Point(30, 30);
        inputBox->Width = 200;

        checkButton = gcnew Button();
        checkButton->Text = L"Check";
        checkButton->Location = Point(250, 30);
		checkButton->Click += gcnew EventHandler(this, &MainUI::OnCheckButtonClick);


        resultLabel = gcnew Label();
        resultLabel->Text = L"*****";
        resultLabel->Font = gcnew Drawing::Font("Consolas", 20);
        resultLabel->Location = Point(30, 80);
        resultLabel->AutoSize = true;

        triesLabel = gcnew Label();
        triesLabel->Text = L"Tries left: 5";
        triesLabel->Location = Point(30, 130);
        triesLabel->AutoSize = true;

        this->Controls->Add(inputBox);
        this->Controls->Add(checkButton);
        this->Controls->Add(resultLabel);
        this->Controls->Add(triesLabel);
    }

    
};
