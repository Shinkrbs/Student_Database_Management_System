#pragma once

#include "DatabaseConn.h"

namespace StudentDatabaseManagementSystem 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Del
	/// </summary>
	public ref class Del : public System::Windows::Forms::Form
	{
	private:
		DatabaseConn^ dbConn; // For Database Connection
	public:
		Del(void)
		{
			InitializeComponent();
			dbConn = gcnew DatabaseConn();
			//Logo
			this->Icon = gcnew System::Drawing::Icon("Logo\\logo.ico");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Del()
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
			this->dataGridView1->Location = System::Drawing::Point(24, 24);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(641, 339);
			this->dataGridView1->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold));
			this->label8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label8->Location = System::Drawing::Point(291, 377);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(78, 20);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Delete Data";
			// 
			// studentID
			// 
			this->studentID->Location = System::Drawing::Point(204, 409);
			this->studentID->Name = L"studentID";
			this->studentID->Size = System::Drawing::Size(320, 20);
			this->studentID->TabIndex = 20;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label4->Location = System::Drawing::Point(137, 412);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Student ID:";
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button2->Location = System::Drawing::Point(343, 454);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 32);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Del::button2_Click);
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button1->Location = System::Drawing::Point(225, 454);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 32);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Del::button1_Click);
			// 
			// Del
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 513);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->studentID);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Del";
			this->Text = L"Del";
			this->Load += gcnew System::EventHandler(this, &Del::Del_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// Delete
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	String^ studentId = studentID->Text->Trim();

	if (String::IsNullOrWhiteSpace(studentId))
	{
		MessageBox::Show("Please enter a valid Student ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Confirm deletion
	if (MessageBox::Show("Are you sure you want to delete this student?", "Confirm Deletion", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
	{
		if (dbConn->Connect())
		{
			// Delete student from the database
			MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM Students WHERE studentId = @studentId", dbConn->GetConnection());
			cmd->Parameters->AddWithValue("@studentId", studentId);

			try
			{
				int rowsAffected = cmd->ExecuteNonQuery();
				if (rowsAffected > 0)
				{
					MessageBox::Show("Student record deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

					// Refresh the DataGridView
					DataTable^ studentRecords = dbConn->GetStudentRecords();
					dataGridView1->DataSource = studentRecords;
				}
				else
				{
					MessageBox::Show("No student found with the provided ID.", "Not Found", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("An error occurred while deleting the record:\n" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show("Database connection failed!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

// Cancel
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}

// On Load
private: System::Void Del_Load(System::Object^ sender, System::EventArgs^ e) 
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
};
}