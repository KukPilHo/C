#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printset(int *, int);
int main()
{
	srand((unsigned)time(NULL));
	int num, tmp, rand1, i;
	int* numbers;

	printf("Enter num of elements : ");
	tmp = scanf("%d", &num);
	rewind(stdin);
	int size = num;
	numbers = (int*)malloc(num * sizeof(int));
	if (numbers == NULL)
	{
		printf("Memory allcoation failed");
		return 1;
	}
	else
	{
		printf("\n The numbers that is generated between 1 and 20 **\n");
		for (i = 0; i < num; i++)
		{
			rand1 = rand() % 20 + 1;
			printf("  %d,", rand1);
			numbers[i] = rand1;

		}
		printf("\n");


	}
	printset(numbers, num);
	free(numbers);
	return 1;
}

int printset(int* set, int many)
{
	int* tmps;
	int size = 100, ad = 0, j;
	int* p;
	p = (int*)calloc(size, sizeof(int));
	if (p == NULL)
	{
		printf("Memory allcoation failed");
		return 1;
		
	}
	p[ad] = set[0];
	for (j = 1; j < many  ; j++)
	{
		int result = 0, k = 0;
		for (k = 0; k < ad + 1; k++)
		{
			if (set[j] == p[k])
				result = 1;
		}
		if (result == 1)
		{
			continue;
		}
		else
		{
			p[ad + 1] = set[j];
			ad++;
		}
		if (ad < size)
			continue;
		else
		{
			size += 100;
			tmps = (int*)realloc(p, sizeof(int) * size);
			if (tmps == NULL)
			{
				printf("Memory allcoation failed");
				return 1;
			}
		}
	}
	for (j = 0; j < ad + 1 ; j++)
	{
		int coun = 0;
		int kk;
		for (kk = 0; kk < many; kk++)
		{
			if (p[j] == set[kk])
				coun++;
		}
		printf("Data %d occurs %d\n", p[j], coun);
	}
	free(p);
	
}