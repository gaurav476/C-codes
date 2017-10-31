#include<stdio.h>

int main()
{
	int n;
	printf("\nEnter the siz of array : ");
	scanf("%d", &n);

	if(n <= 0)
	{
		printf("\nSize must be >0...");
		return 1;
	}

	int a[n];
	int i;

	for(i = 0 ; i < n ; i++)
	{
		printf("\nEnter element %d : ", i+1);
		scanf("%d", &a[i]);
	}

	int ct = n - 1;
	int ctswp = 0;
	int loops = 0;
	
	for(i = 0 ; i < ct ; i++)
	{
		if(a[i] > a[i+1])
		{
			int temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
			ctswp++;
		}

		if(i == ct-1)
		{
			loops++;
			ct--;
		
			if(ctswp == 0)
				i = ct;
			else if(ct >= 0)
			{
				ctswp = 0;
				i = -1;
			}
		}
	}

	printf("Loop runs %d times...\n\n", loops);
	for(i = 0 ; i < n ; i++)
		printf("%d ", a[i]);

	printf("\n\n");

	return 0;
}