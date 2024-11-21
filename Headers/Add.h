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
	/// Summary for MyForm
	/// </summary>
	public ref class Add : public System::Windows::Forms::Form
	{
	public:
		Add(void)
		{
			InitializeComponent();
			// Add Icon
			this->Icon = gcnew System::Drawing::Icon("Logo\\logo.ico");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Add()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ Fname;
	private: System::Windows::Forms::TextBox^ Sname;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ studentID;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ Bday;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ Gender;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ Address;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Add::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Fname = (gcnew System::Windows::Forms::TextBox());
			this->Sname = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->studentID = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Bday = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Gender = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Address = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &Add::label1_Click);
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->Name = L"label2";
			// 
			// Fname
			// 
			resources->ApplyResources(this->Fname, L"Fname");
			this->Fname->Name = L"Fname";
			this->Fname->TextChanged += gcnew System::EventHandler(this, &Add::textBox1_TextChanged);
			// 
			// Sname
			// 
			resources->ApplyResources(this->Sname, L"Sname");
			this->Sname->Name = L"Sname";
			this->Sname->TextChanged += gcnew System::EventHandler(this, &Add::textBox2_TextChanged);
			// 
			// label3
			// 
			resources->ApplyResources(this->label3, L"label3");
			this->label3->Name = L"label3";
			// 
			// studentID
			// 
			resources->ApplyResources(this->studentID, L"studentID");
			this->studentID->Name = L"studentID";
			this->studentID->TextChanged += gcnew System::EventHandler(this, &Add::textBox3_TextChanged);
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// Bday
			// 
			resources->ApplyResources(this->Bday, L"Bday");
			this->Bday->Name = L"Bday";
			this->Bday->TextChanged += gcnew System::EventHandler(this, &Add::textBox4_TextChanged);
			// 
			// label5
			// 
			resources->ApplyResources(this->label5, L"label5");
			this->label5->Name = L"label5";
			// 
			// Gender
			// 
			resources->ApplyResources(this->Gender, L"Gender");
			this->Gender->Name = L"Gender";
			// 
			// label6
			// 
			resources->ApplyResources(this->label6, L"label6");
			this->label6->Name = L"label6";
			// 
			// Address
			// 
			resources->ApplyResources(this->Address, L"Address");
			this->Address->Name = L"Address";
			this->Address->TextChanged += gcnew System::EventHandler(this, &Add::textBox6_TextChanged);
			// 
			// label7
			// 
			resources->ApplyResources(this->label7, L"label7");
			this->label7->Name = L"label7";
			this->label7->Click += gcnew System::EventHandler(this, &Add::label7_Click);
			// 
			// Save Button
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Add::button1_Click);
			//Border
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->FlatAppearance->BorderSize = 1;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			// 
			// Exit Button
			// 
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Add::button2_Click);
			//Border
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->FlatAppearance->BorderSize = 1;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			// 
			// label8
			// 
			resources->ApplyResources(this->label8, L"label8");
			this->label8->Name = L"label8";
			// 
			// Add
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Address);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->Gender);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->Bday);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->studentID);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Sname);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Fname);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Add";
			this->Load += gcnew System::EventHandler(this, &Add::Add_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
// Save
private:System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Validate inputs
	if (String::IsNullOrWhiteSpace(Fname->Text) ||
		String::IsNullOrWhiteSpace(Sname->Text) ||
		String::IsNullOrWhiteSpace(studentID->Text) ||
		String::IsNullOrWhiteSpace(Bday->Text) ||
		String::IsNullOrWhiteSpace(Gender->Text) ||
		String::IsNullOrWhiteSpace(Address->Text))
	{
		// Show error if any field is empty
		Error^ errorForm = gcnew Error("All fields must be filled out.");
		errorForm->ShowDialog();
		return;
	}

	// Validate studentID format (e.g., 23-1-02186)
	if (!System::Text::RegularExpressions::Regex::IsMatch(studentID->Text, "^\\d{2}-\\d{1}-\\d{5}$"))
	{
		Error^ errorForm = gcnew Error("Student ID must be in the format XX-X-XXXXX.");
		errorForm->ShowDialog();
		return;
	}

	// Validate Gender (must be Male or Female)
	if (Gender->Text != "Male" && Gender->Text != "Female")
	{
		Error^ errorForm = gcnew Error("Gender must be either 'Male' or 'Female'.");
		errorForm->ShowDialog();
		return;
	}

	// Validate Bday format (must be Month/Day/Year)
	DateTime birthDate;
	if (!DateTime::TryParseExact(Bday->Text, "MM/dd/yyyy", nullptr, System::Globalization::DateTimeStyles::None, birthDate))
	{
		// Show error if Bday format is invalid
		Error^ errorForm = gcnew Error("Birthdate must be in the format MM/DD/YYYY.");
		errorForm->ShowDialog();
		return;
	}

	// If all validations pass, save the data to the database
	DatabaseConn^ dbConn = gcnew DatabaseConn();
	if (dbConn->Connect())
	{
		try
		{
			// Prepare the SQL command
			String^ query = "INSERT INTO students (studentId, surname, firstname, birthdate, gender, address) VALUES (@studentId, @surname, @firstname, @birthdate, @gender, @address)";
			MySqlCommand^ cmd = gcnew MySqlCommand(query, dbConn->GetConnection());

			// Add parameters to the command
			cmd->Parameters->AddWithValue("@studentID", studentID->Text);
			cmd->Parameters->AddWithValue("@surname", Sname->Text);
			cmd->Parameters->AddWithValue("@firstName", Fname->Text);
			cmd->Parameters->AddWithValue("@birthdate", birthDate);
			cmd->Parameters->AddWithValue("@gender", Gender->Text);
			cmd->Parameters->AddWithValue("@address", Address->Text);

			// Execute the command
			cmd->ExecuteNonQuery();

			MessageBox::Show("Student information saved successfully!");
			this->Close();
		}
		catch (MySqlException^ ex)
		{
			// Show error if there is a problem with the SQL command
			Error^ errorForm = gcnew Error("Database error: " + ex->Message);
			errorForm->ShowDialog();
		}
		finally
		{
			dbConn->Close(); // Ensure the connection is closed
		}
	}
}

// Cancel 
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}

// On Load
private: System::Void Add_Load(System::Object^ sender, System::EventArgs^ e) {}
};
}