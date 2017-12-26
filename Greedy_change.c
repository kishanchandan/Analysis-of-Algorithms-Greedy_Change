#include <stdio.h>

int part_2a();
int part_2b();

void main()
{   
	int choice;

	printf("Enter 1 to execute Question 2a or Enter 2 to execute Question 2b : ");
	scanf("%d",&choice);

	if(choice==1)
		part_2a();

	else if (choice == 2)
		part_2b();

	else 
		printf("Not entered a valid input\n");

}


int part_2a()
{
	int quarters, dimes, nickles;
	int amount;
	printf("Enter the valid amount : ");
	scanf("%d",&amount);
 
	if(amount<=0)	{
		printf("Not entered a valid amount\n");
		return 0;
	}
    
	
	do  {
		//caculate number of pennies
		if (amount<5)  {
        		printf("Number of pennies : %d\n",amount);
        		amount=0;
   		}

		//caculate number of nickles
    		else if (amount>=5 && amount<10)  {
        		nickles = amount/5;
      			printf("Number of nickles : %d\n",nickles);
			amount= amount%5;
    		}

		//caculate number of dimes
	    	else if (amount>=10 && amount<25)  {
			dimes = amount/10;
			printf("Number of dimes : %d\n",dimes);
			amount = amount%10;
		}
    	
		//caculate number of quarters
		else if(amount>=25)  {
			quarters = amount/25;
			printf("Number of quarters : %d\n",quarters);
			amount = amount%25;
	    	}
	} while(amount>0);

	return 0;
}

int part_2b()
{
	int c,k,i,temp;
	int result =1;
	int amount;
	
	printf("Enter the valid amount : ");
	scanf("%d",&amount);

	if(amount<=0)  {
		printf("Not entered a valid amount\n");
		return 0;
	}
	
	printf("Enter c such that c>1: ");
	scanf("%d",&c);
	
	if(c<=1)  {
		printf("Not entered a valid c\n");
		return 0;
	}

	printf("Enter k such that k>=1: ");
	scanf("%d",&k);

	if(k<1)  {
		printf("Not entered a valid k\n");		
		return 0;
	}
    
	//calculate c^k
	for(i=1;i<=k;i++)
		result *= c;

	//loop for finding change
	do  {
    		for(i=result;i>=1;i=i/c)  {
			if(amount>=i)  {
				temp = amount/i;
				printf("%d coins of %d denomination\n",temp,i);
				amount = amount % i;
			}
		}
    	}while(amount>0);
    	return 0;
}
