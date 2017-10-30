#include<stdio.h> 
#include "CreateMgcSq.h"
#include "GenerateMgcSq.h"
#include "ValidateMgcSq.h"

/*int ** createMS(int);
int ** genMS(int **, int);
int isValidMS(int **, int);*/ 

int main()
{
	int size;
	printf("Enter the size of magic square(positive odd integer) : ");
	scanf("%d", &size);

	if((size < 0)|| (size % 2 == 0))
	{
		printf("\nSize must be positively odd...\n\n");
		return 1;
	}

	int **MS = NULL;

	//create 2D Array dynamically
	MS = createMS(size);
	
	int i, j;

	for(i = 0 ; i < size ; i++)
		for(j = 0 ; j < size ; j++)
			MS[i][j] = 0;

	//Populating the Array
	MS = genMS(MS, size);
	
	printf("\nThe generated Magic square is : ");
	for(i = 0 ; i < size ; i++)
	{
		printf("\n");
		for(j = 0 ; j < size ; j++)
			printf("%d\t", MS[i][j]);
	}

	//Checking the validity
	int res = isValidMS(MS, size);

	if(res == 0)
		printf("\nGenerated Magic Square is valid");
	else
		printf("\nGenerated Magic Square is not valid");

	printf("\n\n");

	return 0;
}
