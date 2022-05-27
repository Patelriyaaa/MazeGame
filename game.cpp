#include<conio.h>
#include "game.h"
#include <Windows.h>
void game::displayboard()
{
	for (int i = 0; i < 30; i++) // for loop to create the game board for x axis
	{
		for (int j = 0; j < 30; j++) // for loop to create the game board for y axis
		{
			gotoxy(j, i);
			if (board[i][j] == 1) // 1 is a wall
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // function for color change
				cout << char(219); // displays the asci symbol
			}
			 else if (board[i][j] == 0) // 0 is a blank space
				cout << " "; // displays the asci symbol
			if (board[i][j] == 3) // 3 is a exit
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); // function for color change
				cout << ' '; // displays space
			}
			if (board[i][j] == 2) // 2 is a mine
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // function for color change
				cout << char(234); // displays the asci symbol
			}
		}
	}
}

void game::displaymouse(bool flag)
{
	gotoxy(xmouse, ymouse); // identifies the x snd y position and puts the mouse there
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // function for color change
	flag ? cout << char(237) : cout << " " ; // displays the mouse
}

void game::gotoxy(int column, int line) // identify x and y position
{
		COORD coord;
		coord.X = column;
		coord.Y = line;
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);
	}

void game :: ShowConsoleCursor(bool cursorVisible) // makes the cursor invisible
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = cursorVisible; // making the cursor visible
	SetConsoleCursorInfo(out, &cursorInfo);
}

void game::movemouse() // moves the  mouse
{
	stack s;
	// R D L U
  if (board[ymouse][xmouse+1] == 0 && board[ymouse][xmouse+1] != 1)  // checks for right
  { 
	  point p;
	  p.x = xmouse;
	  p.y = ymouse;
	  mystack.push(p); 
	  xmouse++;
  }
  else if (board[ymouse + 1][xmouse] == 0 && board[ymouse+1][xmouse] != 1) // checks for down
  {
	  point p;
	  p.x = xmouse;
	  p.y = ymouse;
	  mystack.push(p);
	  ymouse++;
  }
  else if (board[ymouse][xmouse - 1] == 0 && board[ymouse][xmouse - 1] != 1) // checks for left
  {
	  point p;
	  p.x = xmouse;
	  p.y = ymouse;
	  mystack.push(p);
	  xmouse--;
  }
  else if (board[ymouse - 1][xmouse] == 0 && board[ymouse - 1][xmouse] != 1)// checks for up
  {
	  point p;
	  p.x = xmouse;
	  p.y = ymouse;
	  mystack.push(p);
	  ymouse--;
  }
  else
  { // moves the mouse back one position
	  gotoxy(xmouse, ymouse);
	  cout << ' ';
	  s.pop(xmouse, ymouse);
	  gotoxy(xmouse, ymouse);
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	  cout << '*';
	  prevx = xmouse;
	  prevy = ymouse;

  }
  if (board[ymouse][xmouse + 1] == 3) // 3 is the exit
  {
	  system("cls");
	  gameover = true; //if the mouse has finished
	  cout << "MOUSE FOUND IT'S WAY OUT" << endl;
	  exit(0);
  }

  if (board[ymouse +1][xmouse] == 2) // 2  is the mine
  {
	  system("cls");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	  gotoxy(10, 10);
	  cout << "MOUSE HIT THE MINE" << endl;
	  gotoxy(10, 11);
	  cout << "SORRY YOU LOST" << endl;
	  gotoxy(10, 12);
	  cout << "PRESS ENTER TO EXIT" << endl;
	  _getch();
	  exit(0);
  }


}
