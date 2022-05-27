#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

struct point // point struct
{
public:
	int x, y;
};

class stack
{
private:
	int row[1000]; // size of the row
	int column[1000]; // size of the column
	int start;
public:
	int top;
	point arr[1000]; 
	stack() // constructer
	{
		top = 0;
	}

	void push(point p) // push function
	{
		arr[top] = p; 
		top++;
	}

	void pop(int &a, int &b) // pop function
	{
		start--;
		a = row[start];
		b = column[start];
	}
};