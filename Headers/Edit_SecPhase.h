#pragma once

#include "Error.h"
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
	/// Summary for Edit_SecPhase
	/// </summary>
	public ref class Edit_SecPhase : public System::Windows::Forms::Form
	{
	private:
		String^ studentId;
	public:
		Edit_SecPhase(String^ id)
		{
			InitializeComponent();
			// Initialize Id for editing
			this->studentId = id;
			//Logo
			this->Icon = gcnew System::Drawing::Icon("Logo\\logo.ico");
			LoadStudentData();
		}

	// Pre-Fill fields with student data based on student Id
	protected:
		void LoadStudentData()
		{
			DatabaseConn^ dbConn = gcnew DatabaseConn();
			if (dbConn->Connect())
			{
				DataRow^ studentData = dbConn->GetStudentById(studentId);
				if (studentData != nullptr)
				{
					Fname->Text = studentData["Firstname"]->ToString();
					Sname->Text = studentData["Surname"]->ToString();

					// Format Birthdate to exclude the time component
					DateTime birthDate;
					if (DateTime::TryParse(studentData["Birthdate"]->ToString(), birthDate))
					{
						Bday->Text = birthDate.ToString("MM/dd/yyyy");
					}
					else
					{
						Bday->Text = "Invalid Date";
					}

					Gender->Text = studentData["Gender"]->ToString();
					Address->Text = studentData["Address"]->ToString();
				}
				else
				{
					MessageBox::Show("Student data not found.");
				}
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Edit_SecPhase()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ Address;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ Gender;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ Bday;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ Sname;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ Fname;
	private: System::Windows::Forms::Label^ label1;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Address = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Gender = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Bday = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Sname = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Fname = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Cancel Button
			// 
			this->button2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button2->Location = System::Drawing::Point(248, 263);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 32);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Edit_SecPhase::button2_Click);
			//Border
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->FlatAppearance->BorderSize = 1;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			// 
			// Save Button
			// 
			this->button1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button1->Location = System::Drawing::Point(130, 263);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 32);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Edit_SecPhase::button1_Click);
			//Border
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->FlatAppearance->BorderSize = 1;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			// 
			// Address
			// 
			this->Address->Location = System::Drawing::Point(113, 210);
			this->Address->Name = L"Address";
			this->Address->Size = System::Drawing::Size(320, 20);
			this->Address->TabIndex = 20;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label7->Location = System::Drawing::Point(46, 213);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Address:";
			// 
			// Gender
			// 
			this->Gender->Location = System::Drawing::Point(112, 175);
			this->Gender->Name = L"Gender";
			this->Gender->Size = System::Drawing::Size(320, 20);
			this->Gender->TabIndex = 18;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label6->Location = System::Drawing::Point(45, 178);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Gender:";
			// 
			// Bday
			// 
			this->Bday->Location = System::Drawing::Point(112, 149);
			this->Bday->Name = L"Bday";
			this->Bday->Size = System::Drawing::Size(320, 20);
			this->Bday->TabIndex = 26;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label5->Location = System::Drawing::Point(45, 152);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 13);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Birth Date:";
			// 
			// Sname
			// 
			this->Sname->Location = System::Drawing::Point(112, 113);
			this->Sname->Name = L"Sname";
			this->Sname->Size = System::Drawing::Size(320, 20);
			this->Sname->TabIndex = 24;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label3->Location = System::Drawing::Point(45, 116);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Last Name:";
			// 
			// Fname
			// 
			this->Fname->Location = System::Drawing::Point(112, 79);
			this->Fname->Name = L"Fname";
			this->Fname->Size = System::Drawing::Size(320, 20);
			this->Fname->TabIndex = 22;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(45, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"First Name:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold));
			this->label8->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label8->Location = System::Drawing::Point(188, 36);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(110, 20);
			this->label8->TabIndex = 27;
			this->label8->Text = L"Edit Information";
			// 
			// Edit_SecPhase
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 327);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->Bday);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Sname);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Fname);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Address);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->Gender);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Edit_SecPhase";
			this->Text = L"Edit";
			this->Load += gcnew System::EventHandler(this, &Edit_SecPhase::Edit_SecPhase_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// On Load
private: System::Void Edit_SecPhase_Load(System::Object^ sender, System::EventArgs^ e) {}

//Exit
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}

// Save
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{	
	// Validate Inputs
	if (String::IsNullOrWhiteSpace(Fname->Text) ||
		String::IsNullOrWhiteSpace(Sname->Text) ||
		String::IsNullOrWhiteSpace(Bday->Text) ||
		String::IsNullOrWhiteSpace(Gender->Text) ||
		String::IsNullOrWhiteSpace(Address->Text))
	{
		// Show error if any field is empty
		Error^ errorform = gcnew Error("All fields must be filled.");
		errorform->ShowDialog();
		return; // Exit function
	}

	// Validate Gender Format
	if (Gender->Text != "Male" && Gender->Text != "Female")
	{
		Error^ errorform = gcnew Error("Gender must be either 'Male' or 'Female'.");
		errorform->ShowDialog();
		return;
	}

	// Validate Birthdate Format
	DateTime birthDate;
	if (!DateTime::TryParseExact(Bday->Text, "MM/dd/yyyy", nullptr, System::Globalization::DateTimeStyles::None, birthDate))
	{
		Error^ errorform = gcnew Error("Birthdate must be in the format MM/DD/YYYY.");
		errorform->ShowDialog();
		return;
	}

	// All validations pass
	DatabaseConn^ dbConn = gcnew DatabaseConn();
	if (!dbConn->Connect())
	{
		Error^ errorForm = gcnew Error("Unable to establish database connection.");
		errorForm->ShowDialog();
		return;
	}

	try
	{
		// Define the SQL query to update the record
		String^ query = "UPDATE students SET "
			"surname = @surname, "
			"firstname = @firstname, "
			"birthdate = @birthdate, "
			"gender = @gender, "
			"address = @address "
			"WHERE studentID = @studentID";

		// Create a MySQL command object
		MySqlCommand^ cmd = gcnew MySqlCommand(query, dbConn->GetConnection());

		// Add parameters
		cmd->Parameters->AddWithValue("@surname", Sname->Text);
		cmd->Parameters->AddWithValue("@firstname", Fname->Text);
		cmd->Parameters->AddWithValue("@birthdate", birthDate);
		cmd->Parameters->AddWithValue("@gender", Gender->Text);
		cmd->Parameters->AddWithValue("@address", Address->Text);
		cmd->Parameters->AddWithValue("@studentID", studentId); 

		// Execute the query
		int rowsAffected = cmd->ExecuteNonQuery();

		// Provide feedback on the operation
		if (rowsAffected > 0)
		{
			MessageBox::Show("Student record updated successfully!");
			this->Close();
		}
		else
		{
			MessageBox::Show("No record was updated. Please check the student ID.");
		}
	}
	catch (Exception^ ex)
	{
		Error^ errorForm = gcnew Error("Error: " + ex->Message);
		errorForm->ShowDialog();
	}
	finally
	{
		dbConn->Close();
	}
}
};
}