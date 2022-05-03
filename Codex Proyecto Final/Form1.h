#pragma once
#include<stdio.h>


namespace CppCLRWinformsProjekt {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	

	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}
		//public variables		
		System::String^ file_content1 = "";
		System::String^ save = "Desea guardar ";
		System::String^ q_mark = " ?";
		System::String^ filename1 = "";

	public:
		System::Windows::Forms::DialogResult result;

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ help;



	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->help = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Abrir";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(255, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Guardar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 41);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(318, 111);
			this->textBox1->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(174, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Cerrar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Archivos de texto |*.txt";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"Archivos de texto |*.txt";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(93, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Encriptar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// help
			// 
			this->help->Location = System::Drawing::Point(0, 0);
			this->help->Name = L"help";
			this->help->Size = System::Drawing::Size(100, 23);
			this->help->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(344, 164);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Codificador";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->HelpButtonClicked += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::Form1_HelpButtonClicked);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		_fcloseall();
		this->openFileDialog1->FileName = "";
		this->openFileDialog1->ShowDialog();
		FILE* file1;
		errno_t FR;
		char c1;
		std::string file_content_c = "";
		std::string file_name_c = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
		filename1 = openFileDialog1->FileName;
		char* file_char1 = const_cast<char*>(file_name_c.c_str());
		FR = fopen_s(&file1, file_char1, "r");
		if (FR == 0)
		{
			MessageBox::Show("Archivo Cargado", "Arhivo Cargado con Exito!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			while (!feof(file1))
			{
				c1 = fgetc(file1);
				if (c1 == EOF)
					break;
				else
				{
					file_content_c.push_back(c1);
				}
			}
			file_content1 = gcnew String(file_content_c.c_str());
			this->textBox1->Text = file_content1;
			FR = fclose(file1);
		}
		else
			MessageBox::Show("Archivo No Cargado", "No se cargo nada", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (filename1 == "" && this->textBox1->Text == "")
			MessageBox::Show("No se ha cargado archivo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else if (filename1 == "")
		{
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(this, save + "achivo nuevo?", "Confirmacion", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				FILE* file1;
				errno_t FR;
				this->saveFileDialog1->FileName = "Nuevo Archivo";
				this->saveFileDialog1->ShowDialog();
				std::string file_name_c = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
				filename1 = saveFileDialog1->FileName;
				std::string file_content_c = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
				char* file_char1 = const_cast<char*>(file_name_c.c_str());
				FR = fopen_s(&file1, file_char1, "w");
				char* file_content_char = const_cast<char*>(file_content_c.c_str());
				fputs(file_content_char, file1);
				FR = fclose(file1);
			}
		}
		else if (filename1 != "")
		{
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(this, save + filename1 + "?", "Confirmacion", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				FILE* file1;
				errno_t FR;
				std::string file_name_c = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
				std::string file_content_c = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
				char* file_char1 = const_cast<char*>(file_name_c.c_str());
				FR = fopen_s(&file1, file_char1, "w");
				char* file_content_char = const_cast<char*>(file_content_c.c_str());
				fputs(file_content_char, file1);
				FR = fclose(file1);
			}
		}

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		_fcloseall();
		this->openFileDialog1->FileName = "";
		this->textBox1->Text = "";
		filename1 = "";
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string file_content_c = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
		std::string file_content_c2 = "";
		unsigned char c;
		for (int i = 0; i < file_content_c.size(); i++)
		{
			c = file_content_c[i];
			c = ~c;
			file_content_c2.push_back(c);
		}
		this->textBox1->Text = gcnew String(file_content_c2.c_str());
	}
	
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void Form1_HelpButtonClicked(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		MessageBox::Show("Encriptador Codex By: \nEmmanuel Chavez 2022A", "Acerca de:", MessageBoxButtons::OK, MessageBoxIcon::None);
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
