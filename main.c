// Author: Dvir Sadon
#include <stdio.h>
#include "myBank.c"
#include "myBank.h"

int main()
{
	char x = ' ';
	while(1==1)
	{
		printf("What would you like to do? (O,B,D,W,C,I,P,E)\n");
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
			exit1();
			break;
		}
		else
		{
			printf("Enter one of the following next time please: O,B,D,W,C,I,P,E \n");
		}
	}
	
	return 0;
}