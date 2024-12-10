#pragma once

namespace Tank1990 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ game
	/// </summary>
	public ref class game : public System::Windows::Forms::Form
	{
	public:
		game(void)
		{
			InitializeComponent();
			this->DoubleBuffered = true;
			movementTimer = gcnew System::Windows::Forms::Timer();
			movementTimer->Interval = 10; // »нтервал 100 миллисекунд
			movementTimer->Tick += gcnew EventHandler(this, &game::OnMovementTimerTick);
			movementTimer->Start();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Timer^ movementTimer;
	private:
		bool moveUp = false;     
		bool moveDown = false; 
		bool moveLeft = false;  
		bool moveRight = false;  

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(game::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1600, 1477);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(860, 983);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(70, 70);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &game::pictureBox1_Click);
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &game::pictureBox2_Paint);
			// 
			// game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"game";
			this->Text = L"TANK1990";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &game::game_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &game::game_KeyUp);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void OnMovementTimerTick(System::Object^ sender, System::EventArgs^ e) {
		if (moveUp) {
			pictureBox2->Location = System::Drawing::Point(pictureBox2->Location.X, pictureBox2->Location.Y - 10);
		}
		else if (moveDown) {
			pictureBox2->Location = System::Drawing::Point(pictureBox2->Location.X, pictureBox2->Location.Y + 10);

		}
		else if (moveLeft) {
			pictureBox2->Location = System::Drawing::Point(pictureBox2->Location.X - 10, pictureBox2->Location.Y);
		}
		else if (moveRight) {
			pictureBox2->Location = System::Drawing::Point(pictureBox2->Location.X + 10, pictureBox2->Location.Y);
		}
		pictureBox2->Refresh();
	}

	private: System::Void game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) {
			moveUp = true;
		}
		else if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) {
			moveDown = true;
		}
		else if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) {
			moveLeft = true;
		}
		else if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) {
			moveRight = true;
		}
	}
	private: System::Void game_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W) {
			moveUp = false;
		}
		else if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S) {
			moveDown = false;
		}
		else if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A) {
			moveLeft = false;
		}
		else if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D) {
			moveRight = false;
		}
	}

	 

	
	private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {


	}
};
}

