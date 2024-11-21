#pragma once

namespace StudentDatabaseManagementSystem
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Error
	/// </summary>
	public ref class Error : public System::Windows::Forms::Form
	{
	public:
		Error(String^ errorMessage)
		{
			InitializeComponent();
			//Logo
			this->Icon = gcnew System::Drawing::Icon("Logo\\logo.ico");

			// Set the error description dynamically
			this->errorDescriptionLabel->Text = errorMessage;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Error()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ errorDescriptionLabel; // New label for error description
	private: System::Windows::Forms::Button^ ret;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->errorDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->ret = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 51.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Firebrick;
			this->label8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label8->Location = System::Drawing::Point(38, 23);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(259, 81);
			this->label8->TabIndex = 28;
			this->label8->Text = L"ERROR!";
			// 
			// errorDescriptionLabel
			// 
			this->errorDescriptionLabel->AutoSize = true;
			this->errorDescriptionLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->errorDescriptionLabel->ForeColor = System::Drawing::Color::Black;
			this->errorDescriptionLabel->Location = System::Drawing::Point(49, 131);
			this->errorDescriptionLabel->MaximumSize = System::Drawing::Size(270, 0);
			this->errorDescriptionLabel->Name = L"errorDescriptionLabel";
			this->errorDescriptionLabel->Size = System::Drawing::Size(111, 16);
			this->errorDescriptionLabel->TabIndex = 30;
			this->errorDescriptionLabel->Text = L"An error occurred.";
			// 
			// ret
			// 
			this->ret->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->ret->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ret->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->ret->Location = System::Drawing::Point(118, 192);
			this->ret->Name = L"ret";
			this->ret->Size = System::Drawing::Size(85, 32);
			this->ret->TabIndex = 29;
			this->ret->Text = L"Return";
			this->ret->UseVisualStyleBackColor = true;
			this->ret->Click += gcnew System::EventHandler(this, &Error::ret_Click);
			// 
			// Error
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(330, 236);
			this->Controls->Add(this->errorDescriptionLabel);
			this->Controls->Add(this->ret);
			this->Controls->Add(this->label8);
			this->Name = L"Error";
			this->Text = L"Error";
			this->Load += gcnew System::EventHandler(this, &Error::Error_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// On Load
	private: System::Void Error_Load(System::Object^ sender, System::EventArgs^ e) {}

	//Return
	private: System::Void ret_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close(); 
	}
};
}
