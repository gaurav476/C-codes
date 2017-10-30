#include "CreateMgcSq.h"

int ** createMS(int s)
{
	int **sq = NULL;

	sq = malloc(s * sizeof(int *));

	for(int i = 0 ; i < s ; i++)
		sq[i] = malloc(s * sizeof(int));

	return sq;
}