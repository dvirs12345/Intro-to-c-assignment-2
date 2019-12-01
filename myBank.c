// Author: Dvir Sadon
#include <stdio.h>

#define BALANCE 1
#define CLOSED 0
#define OPEN 1
#define STATUS 0
#define ARRSIZE 50
#define DIFFERENCE 901
 
double arr [ARRSIZE][2] = {0}; // 0:status , 1:balance  
 
// Gets a number from the user and opens an account, also deposits the amount the user inputed
void open()
{
	int flag;
	for(int i=0;i<ARRSIZE;i++)
	{
		if(arr[i][STATUS] == CLOSED)
		{
			flag = i; 
			break;
		}
	}
	if(flag<50&&flag>=0)
	{
		arr[flag][STATUS] = OPEN;
		double x;
		printf("Enter an amount to deposit: \n");
		scanf("%lf", &x);  
		arr[flag][BALANCE] = x;
		printf("The account number is: %d\n", flag+DIFFERENCE);
	}
	else
	{
		printf("Can't create account\n");
	}
}

// Gets an account number from the user and prints the current balace in the account
void balance()
{
	int x;
	printf("Enter the account number: \n");
	scanf("%d", &x);
	if(x<951&&x>=900)
	{
		if(arr[x-DIFFERENCE][STATUS] != CLOSED)
		{
			printf("The current balance is: %.2f\n",arr[x-DIFFERENCE][BALANCE]);
		}
		else
		{
			printf("Account doesn't exist!\n");
		}
	}
	else
	{
		printf("Invalid account number\n");
	}
}

// Gets an account number and the amount the user would like to deposit, deposits into the account and prints the new balance
void deposit()
{
	int x;
	printf("Enter the account number: \n");
	scanf("%d", &x);
	if(x<951&&x>=900)
	{
		if(arr[x-DIFFERENCE][STATUS] != CLOSED)
		{
			double amount;
			printf("Enter the amount you would like to deposit: \n");
			scanf("%lf", &amount);
			arr[x-DIFFERENCE][BALANCE] += amount;
			printf("Your updated balace is: %.2f\n",arr[x-DIFFERENCE][BALANCE]);
		}
		else
		{
			printf("Account doesn't exist!\n");
		}
	}
	else
	{
		printf("Invalid account number\n");
	}
}

//Gets an account number and an amount to witdraw, prints the updated balace 
void withdraw()
{
	int x;
	printf("Enter the account number: \n");
	scanf("%d", &x);
	if(x<951&&x>=900)
	{
		if(arr[x-DIFFERENCE][STATUS] != CLOSED)
		{
			double amount;
			printf("Enter the amount you would like to withdraw: \n");
			scanf("%lf", &amount);
			if(arr[x-DIFFERENCE][BALANCE] >= amount)
			{
				arr[x-DIFFERENCE][BALANCE]-= amount;
				printf("Your updated balace is: %.2f\n", arr[x-DIFFERENCE][BALANCE]);
			}
			else
			{
				printf("Insufficient funds\n");
			}
		}
		else
		{
			printf("Account does not exist!\n");
		}
	}
	else
	{
		printf("Invalid account number\n");
	}
}

// Gets and account number from the user and closes that account
void close()
{
	int x;
	printf("Enter the account number: \n");
	scanf("%d", &x);
	if(x<951&&x>=900)
	{
		if(arr[x-DIFFERENCE][STATUS] != CLOSED)
		{
			arr[x-DIFFERENCE][STATUS] = CLOSED;
			arr[x-DIFFERENCE][BALANCE] = 0;
		}
		else
		{
			printf("Account already closed\n");
		}
	}
	else
	{
		printf("Invalid account number\n");
	}
}

// Gets an intrest rate and adds it to all balaces in the array 
void intrest()
{
	double x;
	printf("Enter the intrest rate by precent: \n");
	scanf("%lf", &x);
	if(x>=0&&x<=100)
	{
		for(int i = 0; i<ARRSIZE;i++)
		{
			if(arr[i][STATUS] == OPEN)
			{
				arr[i][BALANCE]+=arr[i][BALANCE]*(x/100);
			}
		}
	}
	
}

// Prints the balace of all open 
void print()
{
	for(int i = 0; i<ARRSIZE;i++)
	{
		if(arr[i][STATUS] == OPEN)
		{
			printf("The balance of account number %d is: %.2f\n",i+DIFFERENCE,arr[i][BALANCE]);
		}
	}	
}

// Closes all open accounts 
void exit1()
{
	for(int i=0;i<ARRSIZE;i++)
	{
		if(arr[i][STATUS] == OPEN)
		{
			arr[i][STATUS] = CLOSED;
			arr[i][BALANCE] = 0;
		}
	}
	printf("Bye!\n");
}