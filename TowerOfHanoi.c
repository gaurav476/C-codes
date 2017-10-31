#include<stdio.h>

void print(int [], int [], int [], int, int, int);

int main()
{
	int n;
	
	printf("\nEnter the no. of disks:");
	scanf("%d", &n);
	
	if(n <= 0)
	{
		printf("\nNo. of disks must be >0...");
		return 1;
	}

	int A[n+1], B[n+1], C[n+1];
	A[0] = B[0] = C[0] = -1;

	int i;
	
	for(i = 1 ; i <= n ; i++)
	{
		A[i] = i;
		B[i] = 0;
		C[i] = 0;
	}

	int ctra = n;
	int ctrb = 0, ctrc = 0;
	int fa, fb, fc;
	int valmov = 0;
	int pmov = 0;

	printf("\n\tInitial state:");
	print(A, B, C, ctra, ctrb, ctrc);

	//First move
	if(n % 2 == 0)
	{
		printf("\n\tMove from A to B");
		B[++ctrb] = A[ctra--];
	}
	else
	{
		printf("\n\tMove from A to C");
		C[++ctrc] = A[ctra--]; 
	}

	print(A, B, C, ctra, ctrb, ctrc);

	//Subsequent moves 
	while(ctra > 0 || ctrb > 0)
	{
		//Move from tower A(source tower) to any other  tower
		do
		{
			fb = 0;
			fc = 0;
			valmov = 0;	

			if(ctrb == 0 || ( ( (A[ctra] % 2 == 0 && B[ctrb] % 2 != 0) || (A[ctra] % 2 != 0 && B[ctrb] % 2 == 0) ) && B[ctrb] < A[ctra] && pmov != 21 ) )
				fb = 1;
			if(ctrc == 0 || ( ( (A[ctra] % 2 == 0 && C[ctrc] % 2 != 0) || (A[ctra] % 2 != 0 && C[ctrc] % 2 == 0) ) && C[ctrc] < A[ctra] && pmov != 31 ) )
				fc = 1;

			if(fb == 1 && fc == 1)
			{
				if(ctrb != 0)
				{
					printf("\n\tMove from A to B");
					B[++ctrb] = A[ctra--];
					valmov = 1;
					pmov = 12;
				}
				else
				{
					printf("\n\tMove from A to C");
					C[++ctrc] = A[ctra--];
					valmov = 1;
					pmov = 13;
				}
			}
			else if(fb == 1)
			{
				if(pmov != 21)
				{
					printf("\n\tMove from A to B");
					B[++ctrb] = A[ctra--];
					valmov = 1;
					pmov = 12;
				}
			}
			else if(fc == 1)
			{
				if(pmov != 31)
				{
					printf("\n\tMove from A to C");
					C[++ctrc] = A[ctra--];
					valmov = 1;
					pmov = 13;
				}
			}

			if(valmov == 1)
				print(A, B, C, ctra, ctrb, ctrc);
			
			if(ctra == 0 && ctrb == 0)
				break;			
		}while(valmov == 1);

		if(ctra == 0 && ctrb == 0)
			break;
		
		//Move from tower B(auxiliary tower) to any other tower
		do
		{
			fa = 0;
			fc = 0;
			valmov = 0;

			if(ctra == 0 || ( ( (A[ctra] % 2 == 0 && B[ctrb] % 2 != 0) || (A[ctra] % 2 != 0 && B[ctrb] % 2 == 0) ) && A[ctra] < B[ctrb] && pmov != 12 ) )
				fa = 1;
			if(ctrc == 0 || ( ( (B[ctrb] % 2 == 0 && C[ctrc] % 2 != 0) || (B[ctrb] % 2 != 0 && C[ctrc] % 2 == 0) ) && C[ctrc] < B[ctrb] && pmov != 32 ) )
				fc = 1;

			if(fa == 1 && fc == 1)
			{
				if(ctra != 0)
				{
					printf("\n\tMove from B to A");
					A[++ctra] = B[ctrb--];
					valmov = 1;
					pmov = 21;
				}
				else
				{
					printf("\n\tMove from B to C");
					C[++ctrc] = B[ctrb--];
					valmov = 1;
					pmov = 23;
				}
			}
			else if(fa == 1)
			{
				if(pmov != 12)
				{
					printf("\n\tMove from B to A");
					A[++ctra] = B[ctrb--];
					valmov = 1;
					pmov = 21;
				}
			}
			else if(fc == 1)
			{
				if(pmov != 32)
				{
					printf("\n\tMove from B to C");
					C[++ctrc] = B[ctrb--];
					valmov = 1;
					pmov = 23;
				}
			}

			if(valmov == 1)
				print(A, B, C, ctra, ctrb, ctrc);

			if(ctrb == 0 && ctra == 0)
				break;
		}while(valmov == 1);

		if(ctra == 0 && ctrb == 0)
			break;
		
		//Move from tower C(destination tower) to any other tower
		do
		{
			fa = 0;
			fb = 0;
			valmov = 0;

			if(ctra == 0 || ( ( (A[ctra] % 2 == 0 && C[ctrc] % 2 != 0) || (A[ctra] % 2 != 0 && C[ctrc] % 2 == 0) ) && A[ctra] < C[ctrc] && pmov != 13 ) )
				fa = 1;
			if(ctrb == 0 || ( ( (B[ctrb] % 2 == 0 && C[ctrc] % 2 != 0) || (B[ctrb] % 2 != 0 && C[ctrc] % 2 == 0) ) && B[ctrb] < C[ctrc] && pmov != 23 ) )
				fb = 1;

			if(fa == 1 && fb == 1)
			{
 				if(ctra != 0)
				{
					printf("\n\tMove from C to A");
					A[++ctra] = C[ctrc--];
					valmov = 1;
					pmov = 31;
				}
				else
				{
					printf("\n\tMove from C to B");
					B[++ctrb] = C[ctrc--];
					valmov = 1;
					pmov = 32;
				}
			}
			else if(fa == 1)
			{
				if(pmov != 13)
				{
					printf("\n\tMove from C to A");
					A[++ctra] = C[ctrc--];
					valmov = 1;
					pmov = 31;
				}
			}
			else if(fb == 1)
			{
				if(pmov != 23)
				{
					printf("\n\tMove from C to B");
					B[++ctrb] = C[ctrc--];
					valmov = 1;
					pmov = 32;
				}
			}

			if(valmov == 1)
				print(A, B, C, ctra, ctrb, ctrc);

			if(ctra == 0 && ctrb == 0)
				break;	
		}while(valmov == 1);

		if(ctra == 0 && ctrb == 0)
			break;
	}
	
	return 0;
}

void print(int a[], int b[], int c[], int na, int nb, int nc)
{
	int max = -1;

	if(max < na)
		max = na;
	if(max < nb)
		max = nb;
	if(max < nc)
		max = nc;

	while(max> 0)
	{
		printf("\n");
		if(max <= na)
			printf("%d\t", a[max]);
		else
			printf(" \t");
		if(max <= nb)
			printf("%d\t", b[max]);
		else
			printf(" \t");
		if(max <= nc)
			printf("%d\t", c[max]);
		else
			printf(" \t");
		max--;
	}

	printf("\n\n");	
}