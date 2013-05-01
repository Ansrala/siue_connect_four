#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define ROWS 6
#define COLS 7

using namespace std;

bool getGameBoard(int iGameBoard[ROWS][COLS])
{
	cout << "Retrieving board . . .\n";
	char input;

	ifstream in("board.txt");

	if (in.is_open())
	{
		for(int cur = 0; cur < ROWS * COLS; cur++)
		{
			input = in.get();
			switch( input )
			{
			case '\n':
				cur--;
				break;
			case '-':
				iGameBoard[cur / COLS][cur % COLS] = -1;
				break;
			case '+':
				iGameBoard[cur / COLS][cur % COLS] = 1;
				break;
			case '.':
				iGameBoard[cur / COLS][cur % COLS] = 0;
				break;
			default:
				in.close();
				cout << "Invalid character in board: " << input << "!\n\n";
				return false;
			}
		}
	}
	else
	{
		cout << "Board does not exist!\n\n";
		return false;
	}

	in.close();
	cout << "Board successfully retrieved!\n\n";
	return true;
}

bool putMove( int iMoveCol )
{
	cout << "Making move . . .\n";
	ofstream out( "move.txt" );

	if(iMoveCol>=COLS || iMoveCol<0)
	{
		cout << "Move incomplete, column is outside of range!\n\n";
		return false;
	}

	out << iMoveCol << endl;
	out.close();

	cout << "Move complete!\n\n";
	return true;
}