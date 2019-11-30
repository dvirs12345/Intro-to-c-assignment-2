// Author: Dvir Sadon
#include <stdio.h>
#include "myBank.c"
#include "myBank.h"

int main()
{
	//Enter code here ↓↓
	
	char x;
	while(true)
	{
		printf("What would you like to do? (O,B,D,W,C,I,P,E) ");
		scanf(" %c", &x);
		if(x == 'O')
		{
			open();
		}
		else if(x == 'B')
		{
			balance();
		}
		else if(x == 'D')
		{
			deposit();
		}
		else if(x == 'W')
		{
			withdraw();
		}
		else if(x == 'C')
		{
			close();
		}
		else if(x == 'I')
		{
			intrest();
		}
		else if(x == 'P')
		{
			print();
		}
		else if(x == 'E')
		{
			exit();
			break;
		}
	}
	
	return 0;
}