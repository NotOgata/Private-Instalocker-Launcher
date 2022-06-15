// Menu example for tjnapster
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int, int); // function defined below if this is new to you.

int main()
{
	int menu_item = 0, run, x = 2;
	bool running = true;

	gotoXY(3, 0); cout << "Main Menu";
	gotoXY(1, 2); cout << "->";

	while (running)
	{
		gotoXY(3, 2);  cout << "1) NA";
		gotoXY(3, 3);  cout << "2) JP";
		gotoXY(3, 4); cout << "Quit Program";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 4) //down button pressed
		{
			gotoXY(1, x); cout << "  ";
			x++;
			gotoXY(1, x); cout << "->";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x != 2) //up button pressed
		{
			gotoXY(1, x); cout << "  ";
			x--;
			gotoXY(1, x); cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) { // Enter key pressed

			switch (menu_item) {

			case 0: {

				gotoXY(0, 0);
				cout << "You chose NA...     ";
				ShellExecute(NULL, "open", "C:\\Users\\ogata\\Documents\\Valorant tools\\Instalock\\VALORANT Instalocker by Mr. SOSA v4.0.exe", NULL, NULL, SW_SHOWDEFAULT);
				break;
			}


			case 1: {
				gotoXY(0, 0);
				cout << "You chose JP...     ";
				ShellExecute(NULL, "open", "C:\\Users\\ogata\\Documents\\Valorant tools\\Instalock jp\\VALORANT Instalocker by Mr. SOSA v4.0.exe", NULL, NULL, SW_SHOWDEFAULT);
				break;
			}

			case 2: {
				gotoXY(0, 0);
				cout << "The program has now terminated!!";
				running = false;
			}

			}

		}

	}

	gotoXY(1, 1);
	return 0;
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}