#pragma once
#include "Controller.h"
#include "FileManager.h"

namespace ReRepaso {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		FileManager* storage;
		Controller* game;
		Bitmap^ bmpPacman;
		Bitmap^ bmpGhost;
		Bitmap^ bmpBonus;
		Bitmap^ bmpPacDot;
	public:
		MyForm(void)
		{
			InitializeComponent();
			storage = new FileManager();
			game = new Controller(storage->getLives(), storage->getQtyGhosts(), storage->getPacDots());
			bmpPacman = gcnew Bitmap("sprites.png");
			bmpGhost = gcnew Bitmap("sprites.png");
			bmpBonus = gcnew Bitmap("bonus.png");
			bmpPacDot = gcnew Bitmap("pacdot.png");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete storage, game, bmpPacman, bmpGhost, bmpBonus, bmpPacDot;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:


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
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

		bf->Graphics->Clear(Color::White);

		game->gameManagement(bf->Graphics, bmpPacman, bmpGhost, bmpPacDot, bmpBonus);

		bf->Render(g);
		delete g, espacio, bf;

		if (game->isGameOver()) {
			timer1->Enabled = false;
			MessageBox::Show("Puedes ver tu puntuacion en OUTPUT.TXT", "Juego terminado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			storage->saveScore(game->getPoints());
			this->Close();
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Left: game->changeDirection(direccion::left); break;
		case Keys::Right: game->changeDirection(direccion::right);  break;
		case Keys::Up: game->changeDirection(direccion::up);  break;
		case Keys::Down: game->changeDirection(direccion::down);
		}
	}
	};
}
