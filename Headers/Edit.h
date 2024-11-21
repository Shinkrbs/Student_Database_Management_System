#pragma once

#include "Edit_SecPhase.h"
#include "DatabaseConn.h"
#include "Error.h"

namespace StudentDatabaseManagementSystem 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Edit: public System::Windows::Forms::Form
	{
	private:
		DatabaseConn^ dbConn; // For Database Connection

	public:
		Edit(void)
		{
			InitializeComponent();
			dbConn = gcnew DatabaseConn();
			// Add Icon
			this->Icon = gcnew System::Drawing::Icon("Logo\\logo.ico");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Edit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ studentID;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->studentID = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(27, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(641, 339);
			this->dataGridView1->TabIndex = 0;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold));
			this->label8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label8->Location = System::Drawing::Point(302, 366);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(65, 20);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Edit Data";
			// 
			// studentID
			// 
			this->studentID->Location = System::Drawing::Point(207, 400);
			this->studentID->Name = L"studentID";
			this->studentID->Size = System::Drawing::Size(320, 20);
			this->studentID->TabIndex = 18;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label4->Location = System::Drawing::Point(140, 403);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Student ID:";
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button2->Location = System::Drawing::Point(350, 438);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 32);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Edit::button2_Click);
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button1->Location = System::Drawing::Point(232, 438);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 32);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Edit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Edit::button1_Click);
			// 
			// Edit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(690, 499);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->studentID);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Edit";
			this->Text = L"Edit";
			this->Load += gcnew System::EventHandler(this, &Edit::Edit_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// On Load 
private: System::Void Edit_Load(System::Object^ sender, System::EventArgs^ e) 
{
	// Ensure the database connection is successful
	if (dbConn->Connect())
	{
		// Get the student records
		DataTable^ studentRecords = dbConn->GetStudentRecords();

		// Bind the data to the DataGridView
		dataGridView1->DataSource = studentRecords;
	}
	else
	{
		MessageBox::Show("Database connection failed!");
	}
}

//Cancel
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}

//Edit
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ studentId = studentID->Text;

	// Check if the student ID exists in the database
	if (dbConn->StudentExists(studentId))
	{
		// If the student exists, go to the next phase (Edit_SecPhase)
		Edit_SecPhase^ editform = gcnew Edit_SecPhase(studentId);
		editform->Show();
		this->Close();
	}
	else
	{
		// If the student doesn't exist, show an error message
		Error^ errorForm = gcnew Error("Student ID not found. Please enter a valid ID.");
		errorForm->ShowDialog();
	}
}
};
}