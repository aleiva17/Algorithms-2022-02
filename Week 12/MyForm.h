#pragma once
#include "Controller.h"

namespace Horse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->bmpHorse = gcnew Bitmap("Animal.PNG");
			this->game = new Controller();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete game, bmpHorse;
		}
	private: System::ComponentModel::IContainer^ components;
	protected:
	private: System::Windows::Forms::Timer^ timer1;

	private:
		Controller* game;
		Bitmap^ bmpHorse;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Click);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

		bf->Graphics->Clear(Color::White);

		this->game->gameManagement(bf->Graphics, bmpHorse);

		bf->Render(g);
		delete g, espacio, bf;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Up: this->game->moveHorse(direccion::up); break;
		case Keys::Down: this->game->moveHorse(direccion::down); break;
		case Keys::Left: this->game->moveHorse(direccion::left); break;
		case Keys::Right: this->game->moveHorse(direccion::right); break;
		case Keys::B: this->game->changeMainHorseColor(color::white); break;
		case Keys::V: this->game->changeMainHorseColor(color::green); break;
		case Keys::Z: this->game->changeMainHorseColor(color::blue); break;
		case Keys::A: this->game->changeMainHorseColor(color::yellow); break;
		case Keys::Escape: this->Close();
		}
	}

	private: System::Void MyForm_Click(System::Object^ sender, System::EventArgs^ e) {
		this->game->addHorse();
	}
	};
}
