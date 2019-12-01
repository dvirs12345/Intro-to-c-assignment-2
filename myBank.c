// Author: Dvir Sadon
#include <stdio.h>

#define BALANCE 1
#define CLOSED 0
#define OPEN 1
#define STATUS 0

double arr [50][2] = {0}; // 0:status , 1:balance  
 
// Gets a number from the user and opens an account, also deposits the amount the user inputed
void open()
{
	int flag;
	for(int i=0;i<50;i++)
	{
		if(arr[i][STATUS] == CLOSED)
		{
			flag = i; 
			break;
		}
	}
	if(flag<50)
	{
		arr[flag][STATUS] = OPEN;
		double x;
		printf("Enter an amount to deposit: \n");
		scanf("%lf", &x);  
		arr[flag][BALANCE] = x;
		printf("The account number is: %d\n", flag+901);
	}
	else
	{
		printf("Can't create account when 50 are already open\n");
	}
}

// Gets an account number from the user and prints the current balace in the account
void balance()
{
	int x;
	printf("Enter the account number: \n");
	scanf("%d", &x);
	if(arr[x-901][STATUS] != CLOSED)
	{
		printf("The current balance is: %.2f\n",arr[x-901][BALANCE]);
	}
	else
	{
		printf("Account doesn't exist!\n");
	}
}

// Gets an account number and the amount the user would like to deposit, deposits into the account and prints the new balance
void deposit()
{
	int x;
	printf("Enter the account number: \n");
	scanf("%d", &x);
	double amount;
	printf("Enter the amount you would like to deposit: \n");
	scanf("%lf", &amount);
	if(arr[x-901][STATUS] != CLOSED)
	{
		arr[x-901][BALANCE] += amount;
		printf("Your updated balace is: %.2f\n",arr[x-901][BALANCE]);
	}
	else
	{
		printf("Account doesn't exist!\n");
	}
}

//Gets an account number and an amount to witdraw, prints the updated balace 
void withdraw()
{
	int x;
	printf("Enter the account number: \n");
	scanf("%d", &x);
	double amount;
	printf("Enter the amount you would like to withdraw: \n");
	scanf("%lf", &amount);
	if(arr[x-901][STATUS] != CLOSED)
	{
		if(arr[x-901][BALANCE] >= amount)
		{
			arr[x-901][BALANCE]-= amount;
			printf("Your updated balace is: %.2f\n", arr[x-901][BALANCE]);
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

//
void close()
{
	int x;
	printf("Enter the account number: \n");
	scanf("%d", &x);
	if(arr[x-901][STATUS] != CLOSED)
	{
		arr[x-901][STATUS] = CLOSED;
		arr[x-901][BALANCE] = 0;
	}
	else
	{
		printf("Account already closed\n");
	}
}

void intrest()
{
	double x;
	printf("Enter the intrest rate: \n");
	scanf("%lf", &x);
	for(int i = 0; i<sizeof(arr);i++)
	{
		arr[i][BALANCE]+=arr[i][BALANCE]*x;
	}
}

void print()
{
	for(int i = 0; i<sizeof(arr);i++)
	{
		if(arr[i][STATUS] == OPEN)
		{
			printf("The balance of account number %d is: %.2f\n",i+901,arr[i][BALANCE]);
		}
	}	
}


void exit1()
{
	for(int i=0;i<50;i++)
	{
		if(arr[i][STATUS] == OPEN)
		{
			arr[i][STATUS] = CLOSED;
			arr[i][BALANCE] = 0;
		}
	}
}