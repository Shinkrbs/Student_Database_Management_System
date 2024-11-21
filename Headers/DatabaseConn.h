#pragma once

#include "Error.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace StudentDatabaseManagementSystem;

public ref class DatabaseConn
{
private:
    MySqlConnection^ conn;

public:
    DatabaseConn()
    {
        // No Connection Initially
        conn = nullptr;
    }

    bool Connect()
    {
        String^ connStr = "server=127.0.0.1;uid=root;pwd=;database=student_db";
        conn = gcnew MySqlConnection(connStr);

        try
        {
            conn->Open();
            Console::WriteLine("Connection Successful!");
            return true; // Connection Successful
        }
        catch (MySqlException^ ex)
        {
            // Error message
            String^ errorMessage = "Error: " + ex->Message;

            // Debugging output
            Console::WriteLine(errorMessage);

            // Throw Error
            Error^ errorForm = gcnew Error(errorMessage); 
            errorForm->ShowDialog(); 
            return false; // Connection failed
        }
    }

    void Close() // Can Act as destructor..
    {
        if (conn != nullptr && conn->State == System::Data::ConnectionState::Open)
        {
            conn->Close();
            Console::WriteLine("Connection Closed.");
        }
    }

    MySqlConnection^ GetConnection()
    {
        return conn; 
    }

     // Retrieve student records from the database
    DataTable^ GetStudentRecords()
    {
        MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter("SELECT studentId AS 'STUDENT ID', surname AS 'SURNAME', "
           "firstname AS 'FIRSTNAME', birthdate AS 'BIRTHDATE', gender AS 'GENDER', address AS 'ADDRESS' FROM Students", conn); 
        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        return dt;
    }

    // Sort student record by surname from the database
    DataTable^ SortStudentRecord()
    {
        MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter("SELECT studentId AS 'STUDENT ID', surname AS 'SURNAME', "
            "firstname AS 'FIRSTNAME', birthdate AS 'BIRTHDATE', gender AS 'GENDER', address AS 'ADDRESS' FROM Students ORDER BY surname", conn);
        DataTable^ dt = gcnew DataTable();
        adapter->Fill(dt);
        return dt;
    }

    bool StudentExists(String^ studentId)
    {
        // Example SQL query to check if a student exists by ID
        String^ query = "SELECT COUNT(*) FROM Students WHERE StudentID = @StudentID";

        // Use a command and parameters to execute the query safely
        MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
        cmd->Parameters->AddWithValue("@StudentID", studentId);

        // Execute the query and check if any record is found
        int count = Convert::ToInt32(cmd->ExecuteScalar());
        return count > 0;
    }
    public: DataRow^ GetStudentById(String^ id)
    {
        try
        {
            String^ query = "SELECT * FROM students WHERE StudentID = @StudentID";
            MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
            cmd->Parameters->AddWithValue("@StudentID", id);

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
            DataTable^ result = gcnew DataTable();
            adapter->Fill(result);

            if (result->Rows->Count > 0)
            {
                return result->Rows[0];
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error retrieving data: " + ex->Message);
        }
        return nullptr;
    }
};