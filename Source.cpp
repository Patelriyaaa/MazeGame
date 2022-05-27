#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include"stack.h"
#include"game.h"
using namespace std;
void main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "                                                               " << endl;
	cout << "                                                               " << endl;
	cout << "                                                               " << endl;
	cout << "                                                               " << endl;
	cout << "                                                               " << endl;
	cout << "\t\t\t\t ===================================================== " << endl;
	cout << "\t\t\t\t|                    MAZE ASSIGNMENT                  |" << endl;
	cout << "\t\t\t\t|=====================================================|" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "\t\t\t\t|-----------------------------------------------------|" << endl;
	cout << "\t\t\t\t| THE MOUSE NEEDS TO FIND ITS WAY TO EXIT WITHOUT     |" << endl;
	cout << "\t\t\t\t|                   HITTING THE MINE                  |" << endl;
	cout << "\t\t\t\t|-----------------------------------------------------|" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	cout << "\t\t\t\t|=====================================================|" << endl;
	cout << "\t\t\t\t|           PRESS ENTER KEY TO START THE GAME         |" << endl;
	cout << "\t\t\t\t ===================================================== " << endl;
	_getch();
	system("cls");

	game g;
	while (1)
	{
		g.ShowConsoleCursor(false);
		g.displayboard();
		g.displaymouse(true);
		Sleep(200);
		g.displaymouse(false);
		g.movemouse();
	}
	g.gotoxy(29, 29);
	system("pause");



}