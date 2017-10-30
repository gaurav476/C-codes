#include "GenerateMgcSq.h"

int ** genMS(int **sq, int s)
{
	int i = 0;
	int j = s / 2;
	int fi = 0;
	int fj = 0;
	int ssq = s * s;
	int c = 1;

	sq[i][j] = c;

	while(c != ssq)
	{
		fi = 0;
		fj = 0;
		i = i - 1;
		j = j + 1;

		if( i == -1 && j == s)
		{
			fi = 1;
			fj = 1;
		}
		else
		{
			if(i == -1)
				i = s - 1;
			else if(j == s)
				j = 0;
		}

		if((fi == 1 && fj == 1) || (sq[i][j] != 0))
		{
			i = i + 2;
			j = j - 1;
		}

		sq[i][j] = ++c;
	}
	return sq;
}