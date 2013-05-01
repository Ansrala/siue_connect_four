#include <iostream>
#include <stdlib.h>
#include "connectfour.h"

using namespace std;

void main ()
{
	int n[6][7];
	int col = -1;

	if ( !getGameBoard( n ) )
	{
		system("pause");
		return;
	}

	while( col == -1 )
	{
		int choice = rand() % 7;
		if ( n[0][choice] == 0 )
		{
			col = choice;
		}
	}

	putMove( col );
	system("pause");
}