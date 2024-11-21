#pragma once

#include "Add.h"
#include "Edit.h"
#include "Del.h"
//#include "DatabaseConn.h"

namespace StudentDatabaseManagementSystem
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Student_Database_Management_System
	/// </summary>
	public ref class Student_Database_Management_System : public System::Windows::Forms::Form
	{
	private:
		DatabaseConn^ dbConn; // For Database Connection
	
	public:
		Student_Database_Management_System(void)
		{
			InitializeComponent();
			dbConn = gcnew DatabaseConn();
			
			// Add Icon
			this->Icon = gcnew System::Drawing::Icon("Logo\\logo.ico");\
			// Check connection
			if (dbConn->Connect())
			{
				MessageBox::Show("Database connection successful!");
			}
			else
			{
				MessageBox::Show("Database connection failed!");
				this->Close();
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Student_Database_Management_System()
		{
			if (components)
			{
				if (dbConn != nullptr)
				{
					dbConn->Close();
					delete dbConn;
				}
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ add;
	private: System::Windows::Forms::Button^ edit;
	private: System::Windows::Forms::Button^ sort;
	private: System::Windows::Forms::Button^ delt;
	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PrintPreviewDialog^ printPreviewDialog1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label8;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Student_Database_Management_System::typeid));
			this->add = (gcnew System::Windows::Forms::Button());
			this->edit = (gcnew System::Windows::Forms::Button());
			this->sort = (gcnew System::Windows::Forms::Button());
			this->delt = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->printPreviewDialog1 = (gcnew System::Windows::Forms::PrintPreviewDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// add
			// 
			this->add->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add->Location = System::Drawing::Point(60, 47);
			this->add->Name = L"add";
			this->add->Size = System::Drawing::Size(153, 32);
			this->add->TabIndex = 1;
			this->add->Text = L"Add ";
			this->add->UseVisualStyleBackColor = true;
			this->add->Click += gcnew System::EventHandler(this, &Student_Database_Management_System::button1_Click);
			// 
			// edit
			// 
			this->edit->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->edit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->edit->Location = System::Drawing::Point(60, 85);
			this->edit->Name = L"edit";
			this->edit->Size = System::Drawing::Size(153, 32);
			this->edit->TabIndex = 2;
			this->edit->Text = L"Edit";
			this->edit->UseVisualStyleBackColor = true;
			this->edit->Click += gcnew System::EventHandler(this, &Student_Database_Management_System::button2_Click);
			// 
			// sort
			// 
			this->sort->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->sort->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sort->Location = System::Drawing::Point(60, 123);
			this->sort->Name = L"sort";
			this->sort->Size = System::Drawing::Size(153, 32);
			this->sort->TabIndex = 3;
			this->sort->Text = L"Sort";
			this->sort->UseVisualStyleBackColor = true;
			this->sort->Click += gcnew System::EventHandler(this, &Student_Database_Management_System::button3_Click);
			// 
			// delt
			// 
			this->delt->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->delt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delt->Location = System::Drawing::Point(60, 161);
			this->delt->Name = L"delt";
			this->delt->Size = System::Drawing::Size(153, 32);
			this->delt->TabIndex = 5;
			this->delt->Text = L"Delete";
			this->delt->UseVisualStyleBackColor = true;
			this->delt->Click += gcnew System::EventHandler(this, &Student_Database_Management_System::button5_Click);
			// 
			// exit
			// 
			this->exit->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit->Location = System::Drawing::Point(60, 271);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(153, 32);
			this->exit->TabIndex = 6;
			this->exit->Text = L"Exit";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &Student_Database_Management_System::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(54, 338);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 31);
			this->label1->TabIndex = 0;
			// 
			// printPreviewDialog1
			// 
			this->printPreviewDialog1->AutoScrollMargin = System::Drawing::Size(0, 0);
			this->printPreviewDialog1->AutoScrollMinSize = System::Drawing::Size(0, 0);
			this->printPreviewDialog1->ClientSize = System::Drawing::Size(400, 300);
			this->printPreviewDialog1->Enabled = true;
			this->printPreviewDialog1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"printPreviewDialog1.Icon")));
			this->printPreviewDialog1->Name = L"printPreviewDialog1";
			this->printPreviewDialog1->Visible = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(259, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(638, 357);
			this->dataGridView1->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(60, 199);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(153, 32);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Refresh Data";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Student_Database_Management_System::button1_Click_1);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label8->Location = System::Drawing::Point(12, 360);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(80, 16);
			this->label8->TabIndex = 18;
			this->label8->Text = L"V.1.0.0_Dolamos";
			// 
			// Student_Database_Management_System
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(913, 385);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->delt);
			this->Controls->Add(this->sort);
			this->Controls->Add(this->edit);
			this->Controls->Add(this->add);
			this->Controls->Add(this->label1);
			this->Name = L"Student_Database_Management_System";
			this->Text = L"Student Database Management System";
			this->Load += gcnew System::EventHandler(this, &Student_Database_Management_System::Student_Database_Management_System_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// Functions Implementation
// Sort
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	DataTable^ sortedRec = dbConn->SortStudentRecord();
	dataGridView1->DataSource = sortedRec;
}

// Edit 
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Edit^ editform = gcnew Edit();
	editform->Show();
}

// Add
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Add^ addform = gcnew Add();
	addform->Show();
}

// Delete
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Del^ delform = gcnew Del();
	delform->Show();
}

// Exit
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
{
	// Ensures that the program disconnects to database after exit button is clicked
	dbConn->Close();
	this->Close();
}

// On Load
private: System::Void Student_Database_Management_System_Load(System::Object^ sender, System::EventArgs^ e) 
{
	// Ensure the database connection is successful
	if (dbConn->Connect())
	{
		DataTable^ studentRecords = dbConn->GetStudentRecords();
		// Bind the data to the DataGridView
		dataGridView1->DataSource = studentRecords;
	}
	else
	{
		MessageBox::Show("Database connection failed!");
	}
}

// Refreshes Data After or Before Sorting 
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) 
{
	Student_Database_Management_System_Load(sender, e);
}
};
}