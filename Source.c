#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	run();
}

int run(void)
{
	int taskNum;

	printf("Input task number: "); scanf_s("%d", &taskNum);

	switch (taskNum)
	{
	case 0:
		exit(1);
	case 101:
		ex1(); printf("\n"); run();
	case 102:
		ex2(); printf("\n"); run();
	default:
		printf("wrong number\n"); run();
	}
}

int ex1(void)
{
	int* p;
	int sum = 0, i, n;

	printf("Enter the length of the array:\n");
	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));   	/* выделение памяти для n элементов целого типа */
	
	printf("Array fnd Sum:\n");
	for (i = 0; i < n; i++)
	{
		p[i] = rand() % 10 - 5;
		printf("p[%d] = %d\n", i, p[i]);
		sum += p[i];
	}
	printf("sum = %d\n", sum);
	free(p); 					             /* освобождения выделенной памяти */

	printf("Click on Enter...");
	(void)getch();
}

int ex2(void)
{
	int** matr;
	int n, i, j, sled = 1;

	printf("Enter n:\n");
	scanf("%d", &n);

	matr = (int*)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
		matr[i] = (int*)malloc(n * sizeof(int));

	/* заполним матрицу случайными числами */
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matr[i][j] = rand() % 10;
			//printf("matr[%d][%d] = %d%d\n", i, j, matr[i][j]);
			printf("\t%d", matr[i][j]);
		}
		printf("\n");
	}
	//произведение эл-ов на главной диагонали
	for (i = 0; i < n; i++)
		sled *= matr[i][i];

	printf("sled = %d\n", sled);

	free(matr); // освобождения выделенной памяти

	printf("Click on Enter...");
	(void)getch();
}