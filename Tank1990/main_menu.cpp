#include "main_menu.h"
#include "game.h"

#include <Windows.h>

using namespace Tank1990; // пространство имен названия проекта
System::Void main_menu::main_menu_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if ((e->KeyCode == Keys::Up || e->KeyCode == Keys::W) && Decide_pictureBox->Location.Y != 435) {
        Decide_pictureBox->Location = System::Drawing::Point(
            Decide_pictureBox->Location.X,
            Decide_pictureBox->Location.Y - 105);
    }
    else if ((e->KeyCode == Keys::Down || e->KeyCode == Keys::S) && Decide_pictureBox->Location.Y != 750) {
        Decide_pictureBox->Location = System::Drawing::Point(
            Decide_pictureBox->Location.X,
            Decide_pictureBox->Location.Y + 105);
    }
    if (e->KeyCode == Keys::Enter) {
        Decide();
    }
}

void main_menu::Decide() {
    if (Decide_pictureBox->Location.Y == 435) {
        game^ GameForm = gcnew game;
        GameForm->Show();
    }
    else if (Decide_pictureBox->Location.Y == 540) {
        MessageBox::Show("2");
    }
    else if (Decide_pictureBox->Location.Y == 645) {
        MessageBox::Show("opt");
    }
    else if (Decide_pictureBox->Location.Y == 750) {
        this->Close();
    }
}

[STAThread] // Без этого не будет открываться fileDialog

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles(); // Иницализировать Visual Styles
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew main_menu); // Запускаем проект

    return 0;
}
