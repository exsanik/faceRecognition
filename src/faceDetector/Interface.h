#pragma once
#include "Libs.h"
#include "Save.h"

namespace FaceRecognition {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Interface
	/// </summary>
	public ref class Interface : public System::Windows::Forms::Form
	{
	public:
		Interface(void)
		{
			InitializeComponent();

			//------------------
		
			addNewPeople();
		}

		void addNewPeople()
		{
			std::vector<int> ind = newFilePaths();
			for (auto &i : ind)
			{
				Person temp;
				temp.readFromFile(files[i]);
				pers.emplace_back(temp);

				std::vector<std::string> pic = temp.getImages();
				std::string name = temp.getFullName();
				for (int j = 0; j < pic.size(); j++)
					pictures.emplace_back(pic[j], name);
			}
		}
		std::vector<int> newFilePaths()
		{
			std::string path = "people/";
			std::stringstream p;
			for (const auto & entry : fs::directory_iterator(path))
				p << entry.path() << std::endl;
		
			std::vector<int> ind;
			while (!p.eof())
			{
				std::string tmp;
				getline(p, tmp);
				if (tmp == "")
					break;
				if (std::find(files.begin(), files.end(), tmp) == files.end())
				{
					ind.push_back(files.size());
					files.push_back(tmp);
				}
			}
			return ind;
		}
		
	protected:
		/// <summary>
		///
		/// </summary>
		~Interface()
		{
			face.stopDetection();
			if (components)
			{
				delete components;
			}
		}






			 //--------------------------------
	private:
		faceDetection &face = faceDetection();
		std::vector<std::pair<std::string, std::string>> &pictures = std::vector<std::pair<std::string, std::string>>();
		std::vector<Person> &pers = std::vector<Person>();
		std::vector<std::string> &files = std::vector<std::string>();

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Button^  button18;
private: System::Windows::Forms::TabPage^  tabPage5;
private: System::Windows::Forms::Button^  button19;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::Button^  button21;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::Button^  button22;
private: System::Windows::Forms::Button^  button23;











	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Interface::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->tabPage5->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->ItemSize = System::Drawing::Size(0, 1);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(974, 880);
			this->tabControl1->TabIndex = 4;
			this->tabControl1->SizeMode = TabSizeMode::Fixed;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(131)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->tabPage1->Controls->Add(this->button18);
			this->tabPage1->Controls->Add(this->button17);
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->button6);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Location = System::Drawing::Point(4, 14);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(966, 862);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button18->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button18->Location = System::Drawing::Point(898, 6);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(60, 60);
			this->button18->TabIndex = 4;
			this->button18->Text = L"⚙";
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &Interface::button18_Click);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button17->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(308, 440);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(350, 75);
			this->button17->TabIndex = 3;
			this->button17->Text = L"Сравнить лица";
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &Interface::button17_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(308, 550);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(350, 75);
			this->button7->TabIndex = 2;
			this->button7->Text = L"Выход";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Interface::button7_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(308, 330);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(350, 75);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Галерея";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Interface::button6_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(308, 220);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(350, 75);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Добавить нового человека";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Interface::button4_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(131)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->tabPage2->Controls->Add(this->button23);
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->pictureBox2);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Location = System::Drawing::Point(4, 14);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(966, 862);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			// 
			// button23
			// 
			this->button23->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button23->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button23->Location = System::Drawing::Point(898, 6);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(60, 60);
			this->button23->TabIndex = 9;
			this->button23->Text = L"⚙";
			this->button23->UseVisualStyleBackColor = false;
			this->button23->Click += gcnew System::EventHandler(this, &Interface::button23_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(383, 665);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(185, 50);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Сохранить";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Interface::button5_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(368, 762);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(220, 69);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Вернутся в главное меню";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Interface::button3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->Location = System::Drawing::Point(56, 55);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(854, 590);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(615, 665);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(185, 50);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Остановить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Interface::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(146, 665);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(185, 50);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Начать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Interface::button1_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(131)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Controls->Add(this->button10);
			this->tabPage3->Controls->Add(this->button9);
			this->tabPage3->Controls->Add(this->button8);
			this->tabPage3->Controls->Add(this->pictureBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 14);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(966, 862);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"tabPage3";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(420, 580);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 25);
			this->label1->TabIndex = 9;
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button10->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(372, 666);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(220, 69);
			this->button10->TabIndex = 8;
			this->button10->Text = L"Вернутся в главное меню";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &Interface::button10_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button9->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(82, 282);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(93, 90);
			this->button9->TabIndex = 2;
			this->button9->Text = L"<";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Interface::button9_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button8->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(773, 282);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(93, 90);
			this->button8->TabIndex = 1;
			this->button8->Text = L">";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Interface::button8_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(282, 70);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(391, 488);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(131)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->tabPage4->Controls->Add(this->label5);
			this->tabPage4->Controls->Add(this->label4);
			this->tabPage4->Controls->Add(this->label3);
			this->tabPage4->Controls->Add(this->label2);
			this->tabPage4->Controls->Add(this->button16);
			this->tabPage4->Controls->Add(this->button15);
			this->tabPage4->Controls->Add(this->button13);
			this->tabPage4->Controls->Add(this->button14);
			this->tabPage4->Controls->Add(this->pictureBox4);
			this->tabPage4->Controls->Add(this->button11);
			this->tabPage4->Controls->Add(this->button12);
			this->tabPage4->Controls->Add(this->pictureBox3);
			this->tabPage4->Location = System::Drawing::Point(4, 14);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(966, 862);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"tabPage4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(610, 482);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 25);
			this->label5->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(116, 482);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 25);
			this->label4->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(531, 544);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 15);
			this->label3->TabIndex = 12;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(238, 509);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 25);
			this->label2->TabIndex = 11;
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button16->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(369, 719);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(220, 69);
			this->button16->TabIndex = 10;
			this->button16->Text = L"Вернутся в главное меню";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &Interface::button16_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button15->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(369, 564);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(220, 69);
			this->button15->TabIndex = 9;
			this->button15->Text = L"Сравнить";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &Interface::button15_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button13->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button13->Location = System::Drawing::Point(527, 266);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(50, 54);
			this->button13->TabIndex = 8;
			this->button13->Text = L"<";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &Interface::button13_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button14->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button14->Location = System::Drawing::Point(883, 266);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(50, 54);
			this->button14->TabIndex = 7;
			this->button14->Text = L">";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &Interface::button14_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(615, 118);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(234, 344);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button11->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->Location = System::Drawing::Point(39, 266);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(50, 54);
			this->button11->TabIndex = 5;
			this->button11->Text = L"<";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &Interface::button11_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button12->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button12->Location = System::Drawing::Point(390, 266);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(50, 54);
			this->button12->TabIndex = 4;
			this->button12->Text = L">";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &Interface::button12_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(121, 118);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(234, 344);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(131)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->tabPage5->Controls->Add(this->button22);
			this->tabPage5->Controls->Add(this->button21);
			this->tabPage5->Controls->Add(this->button20);
			this->tabPage5->Controls->Add(this->button19);
			this->tabPage5->Controls->Add(this->label12);
			this->tabPage5->Controls->Add(this->label11);
			this->tabPage5->Controls->Add(this->textBox5);
			this->tabPage5->Controls->Add(this->textBox4);
			this->tabPage5->Controls->Add(this->textBox3);
			this->tabPage5->Controls->Add(this->textBox2);
			this->tabPage5->Controls->Add(this->textBox1);
			this->tabPage5->Controls->Add(this->label10);
			this->tabPage5->Controls->Add(this->label9);
			this->tabPage5->Controls->Add(this->label8);
			this->tabPage5->Controls->Add(this->label7);
			this->tabPage5->Controls->Add(this->label6);
			this->tabPage5->Location = System::Drawing::Point(4, 14);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(966, 862);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"tabPage5";
			// 
			// button22
			// 
			this->button22->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button22->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button22->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button22->Location = System::Drawing::Point(445, 438);
			this->button22->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(105, 31);
			this->button22->TabIndex = 15;
			this->button22->Text = L"Очистить";
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &Interface::button22_Click);
			// 
			// button21
			// 
			this->button21->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button21->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(382, 497);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(220, 47);
			this->button21->TabIndex = 14;
			this->button21->Text = L"Сохранить";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &Interface::button21_Click);
			// 
			// button20
			// 
			this->button20->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button20->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(382, 562);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(220, 69);
			this->button20->TabIndex = 13;
			this->button20->Text = L"Вернутся в главное меню";
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &Interface::button20_Click);
			// 
			// button19
			// 
			this->button19->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button19->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button19->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button19->Location = System::Drawing::Point(813, 409);
			this->button19->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(75, 30);
			this->button19->TabIndex = 12;
			this->button19->Text = L"Обзор";
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &Interface::button19_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(655, 293);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(33, 26);
			this->label12->TabIndex = 11;
			this->label12->Text = L"В:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(461, 294);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(38, 26);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Ш:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(699, 298);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(108, 22);
			this->textBox5->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(445, 413);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(362, 22);
			this->textBox4->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(445, 356);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(138, 22);
			this->textBox3->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(445, 251);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 22);
			this->textBox2->TabIndex = 6;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(505, 298);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(108, 22);
			this->textBox1->TabIndex = 5;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(72, 409);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(239, 26);
			this->label10->TabIndex = 4;
			this->label10->Text = L"Источник видео/фото:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(72, 351);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(246, 26);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Источник вэб-камеры: ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(72, 298);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(365, 26);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Разрешение кадра для обработки:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(72, 246);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(259, 26);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Коэффициент схожести:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(403, 130);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(139, 33);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Настройки";
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(974, 880);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(992, 827);
			this->Name = L"Interface";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FaceRecognizer";
			this->Load += gcnew System::EventHandler(this, &Interface::Interface_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		void save_Closed(Object^ sender, EventArgs^ e)
		{
			this->button5->Visible = true;
		}

		private:
			System::Void Interface_Load(System::Object^  sender, System::EventArgs^  e) {}
			System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (!face.getState())
					face.detectFace(pictureBox2);
			}
			System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
			{
				face.stopDetection();
				this->pictureBox2->Image = nullptr;
			}
			System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				face.stopDetection();
				this->pictureBox2->Image = nullptr;
				this->tabControl1->SelectedIndex = 0;
			}
			System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				this->tabControl1->SelectedIndex = 1;
			}
			System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (face.getState())
				{
					this->button5->Text = "Захват лица...";
					face.saveFace();
					face.detectFace(pictureBox2);
					this->button5->Text = "Сохранить";
					if (face.getSaveState() == 1)
					{
						Save^ f2 = gcnew Save;
						f2->Show(this);

						f2->setPictureBox(face.getTempMat());
						this->button5->Visible = false;
						f2->Closed += gcnew EventHandler(this, &Interface::save_Closed);
					}
					else
					{
						MessageBox::Show("Не удалось распознать лицо. Попробуйте ещё раз.");
						face.detectFace(pictureBox2);
					}
					
				}
				else
					MessageBox::Show("Для начала запустите распознавание!");
			}
			System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				this->Close();
			}

			int index = 0;
			System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				addNewPeople();
				this->tabControl1->SelectedIndex = 2;
				
				if (index == 0)
					button9->BackColor = System::Drawing::SystemColors::GrayText;
				if(index == pictures.size()-1)
					button8->BackColor = System::Drawing::SystemColors::GrayText;
				if (!pictures.empty())
				{
					pictureBox1->Image = Image::FromFile(gcnew System::String(pictures.at(index).first.c_str()));
					label1->Text = gcnew System::String(pictures.at(index).second.c_str());
				}
				else
				{
					MessageBox::Show("Фотографии еще не были добавлены");
					button8->BackColor = System::Drawing::SystemColors::GrayText;
				}
			}
			
			System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				button8->BackColor = System::Drawing::SystemColors::HotTrack;
				button9->BackColor = System::Drawing::SystemColors::HotTrack;
				if (index < pictures.size() - 1 && !pictures.empty())
				{
					index++;
					pictureBox1->Image = Image::FromFile(gcnew System::String(pictures.at(index).first.c_str()));
					label1->Text = gcnew System::String(pictures.at(index).second.c_str());
				}
				else
				{
					if(pictures.empty())
						button9->BackColor = System::Drawing::SystemColors::GrayText;
					button8->BackColor = System::Drawing::SystemColors::GrayText;
				}
			}
			System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				button9->BackColor = System::Drawing::SystemColors::HotTrack;
				button8->BackColor = System::Drawing::SystemColors::HotTrack;
				if (index > 0 && !pictures.empty())
				{
					index--;
					pictureBox1->Image = Image::FromFile(gcnew System::String(pictures.at(index).first.c_str()));
					label1->Text = gcnew System::String(pictures.at(index).second.c_str());
				}
				else
				{
					if (pictures.empty())
						button8->BackColor = System::Drawing::SystemColors::GrayText;
					button9->BackColor = System::Drawing::SystemColors::GrayText;
				}
			}
			System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				this->tabControl1->SelectedIndex = 0;
				index = 0;
				pictureBox1->Image = nullptr;
			}

			int ind1 = 0, ind2 = 0;
			System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				addNewPeople();
				this->tabControl1->SelectedIndex = 3;

				if(ind1 == 0)
					button11->BackColor = System::Drawing::SystemColors::GrayText;
				if(ind2 == 0)
					button13->BackColor = System::Drawing::SystemColors::GrayText;
				if (ind1 == pictures.size()-1)
					button12->BackColor = System::Drawing::SystemColors::GrayText;
				if (ind2 == pictures.size() - 1)
					button14->BackColor = System::Drawing::SystemColors::GrayText;
				
				if (!pictures.empty())
				{
					label4->Text = gcnew System::String(pictures.at(ind1).second.c_str());
					label5->Text = gcnew System::String(pictures.at(ind2).second.c_str());

					pictureBox3->Image = Image::FromFile(gcnew System::String(pictures.at(ind1).first.c_str()));
					pictureBox4->Image = Image::FromFile(gcnew System::String(pictures.at(ind2).first.c_str()));
				}
				else
				{
					MessageBox::Show("Фотографии еще не были добавлены");
					button14->BackColor = System::Drawing::SystemColors::GrayText;
					button12->BackColor = System::Drawing::SystemColors::GrayText;
				}
			}
			System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				button11->BackColor = System::Drawing::SystemColors::HotTrack;
				button12->BackColor = System::Drawing::SystemColors::HotTrack;
				if (ind1 > 0 && !pictures.empty())
				{
					ind1--;
					pictureBox3->Image = Image::FromFile(gcnew System::String(pictures.at(ind1).first.c_str()));
					label4->Text = gcnew System::String(pictures.at(ind1).second.c_str());
				}
				else
				{
					if (pictures.empty())
						button12->BackColor = System::Drawing::SystemColors::GrayText;
					button11->BackColor = System::Drawing::SystemColors::GrayText;
				}
			}
			System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				button12->BackColor = System::Drawing::SystemColors::HotTrack;
				button11->BackColor = System::Drawing::SystemColors::HotTrack;
				if (ind1 < pictures.size() - 1 && !pictures.empty())
				{
					ind1++;
					pictureBox3->Image = Image::FromFile(gcnew System::String(pictures.at(ind1).first.c_str()));
					label4->Text = gcnew System::String(pictures.at(ind1).second.c_str());
				}
				else
				{
					if (pictures.empty())
						button11->BackColor = System::Drawing::SystemColors::GrayText;
					button12->BackColor = System::Drawing::SystemColors::GrayText;
				}
			}
			System::Void button13_Click(System::Object^  sender, System::EventArgs^  e)
			{
				button13->BackColor = System::Drawing::SystemColors::HotTrack;
				button14->BackColor = System::Drawing::SystemColors::HotTrack;
				if (ind2 > 0 && !pictures.empty())
				{
					ind2--;
					pictureBox4->Image = Image::FromFile(gcnew System::String(pictures.at(ind2).first.c_str()));
					label5->Text = gcnew System::String(pictures.at(ind2).second.c_str());
				}
				else
				{
					if (pictures.empty())
						button14->BackColor = System::Drawing::SystemColors::GrayText;
					button13->BackColor = System::Drawing::SystemColors::GrayText;
				}
			}
			System::Void button14_Click(System::Object^  sender, System::EventArgs^  e)
			{
				button14->BackColor = System::Drawing::SystemColors::HotTrack;
				button13->BackColor = System::Drawing::SystemColors::HotTrack;
				if (ind2 < pictures.size() - 1 && !pictures.empty())
				{
					ind2++;
					pictureBox4->Image = Image::FromFile(gcnew System::String(pictures.at(ind2).first.c_str()));
					label5->Text = gcnew System::String(pictures.at(ind2).second.c_str());
				}
				else
				{
					if (pictures.empty())
						button13->BackColor = System::Drawing::SystemColors::GrayText;
					button14->BackColor = System::Drawing::SystemColors::GrayText;
				}
			}
			System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (!pictures.empty())
				{
					std::string command = "dlibFace.exe " + pictures.at(ind1).first + " " + pictures.at(ind2).first;
					system(command.c_str());
					std::ifstream res("res.txt");
					std::string coeff;
					std::getline(res, coeff, ' ');
					res.close();
					double icoeff = atof(coeff.c_str());
					if (icoeff <= face.getCoeffSimil())
						label2->Text = "На фотографиях вероятно один и тот же человек!";
					else
						label2->Text = "На фотографиях вероятно разные люди.";
					label3->Text = gcnew System::String(coeff.c_str());
				}
			}
			System::Void button16_Click(System::Object^  sender, System::EventArgs^  e)
			{
				this->tabControl1->SelectedIndex = 0;
			}
			System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				char str[10];
				sprintf(str, "%f", face.getCoeffSimil());
				this->textBox2->Text = gcnew System::String(str);
				sprintf(str, "%u", face.getWidth());
				this->textBox1->Text = gcnew System::String(str);
				sprintf(str, "%u", face.getHeight());
				this->textBox5->Text = gcnew System::String(str);
				sprintf(str, "%i", face.getCamId());
				this->textBox3->Text = gcnew System::String(str);
				this->textBox4->Text = gcnew System::String(face.getSource().c_str());

				this->tabControl1->SelectedIndex = 4;
			}
			System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				this->tabControl1->SelectedIndex = 0;
			}
			System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				this->openFileDialog1->Filter = "Image Files(*.jpg;*.mp4)|*.jpg;*.mp4";
				if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					this->textBox4->Text = openFileDialog1->FileName;
			}
			System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				std::string str;
				MarshalString(this->textBox2->Text, str);
				face.setCoeffSimil(atof(str.c_str()));
				MarshalString(this->textBox1->Text, str);
				face.setWidth(atoi(str.c_str()));
				MarshalString(this->textBox5->Text, str);
				face.setHeight(atoi(str.c_str()));
				MarshalString(this->textBox3->Text, str);
				face.setCamId(atoi(str.c_str()));
				MarshalString(this->textBox4->Text, str);
				face.setSource(str);
				MessageBox::Show("Успешно сохранено!");
			}
			System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				this->textBox4->Text = "";
			}
			System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				face.stopDetection();
				this->pictureBox2->Image = nullptr;
				char str[10];
				sprintf(str, "%f", face.getCoeffSimil());
				this->textBox2->Text = gcnew System::String(str);
				sprintf(str, "%u", face.getWidth());
				this->textBox1->Text = gcnew System::String(str);
				sprintf(str, "%u", face.getHeight());
				this->textBox5->Text = gcnew System::String(str);
				sprintf(str, "%i", face.getCamId());
				this->textBox3->Text = gcnew System::String(str);
				this->textBox4->Text = gcnew System::String(face.getSource().c_str());
				this->tabControl1->SelectedIndex = 4;
			}
};

}