#include "ValidateMgcSq.h"

int isValidMS(int **sq, int s)
{
	int i, j;
	int sum1, sum2 = 0;
	int flag = 0;

	for(i = 0 ; i < s ; i++)
	{
		sum1 = 0;

		for(j = 0 ; j < s ; j++)
			sum1 += sq[i][j];
		
		if(sum2 == 0)
			sum2 = sum1;
		else if(sum2 != sum1)
		{
			flag = 1;
			break;
		}	
	}

	if(flag != 1)
	{
		for(j = 0 ; j < s ; j++)
		{
			sum1 = 0;
			
			for(i = 0 ; i < s ; i++)
				sum1 += sq[i][j];

			if(sum2 != sum1)
			{
				flag = 1;
				break;	
			}
		}

		if(flag != 1)
		{
			sum1= 0;

			for(i = 0 ; i < s ; i++)
				sum1 += sq[i][i];

			if(sum2 == sum1)
			{
				sum1 = 0;
				for(i = 0 ; i < s ; i++)
					sum1 += sq[i][s - i - 1];

				if(sum2 != sum1)
					flag = 1;
			}
			else
				flag = 1;	
		}

		return flag;	
	}
	
	return flag;
}