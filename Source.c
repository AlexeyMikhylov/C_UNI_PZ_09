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
	case 1:
		task1_8(); printf("\n"); run();
	case 9:
		task9(); printf("\n"); run();
	case 10:
		task10(); printf("\n"); run();
	case 11:
		task11(); printf("\n"); run();
	case 12:
		task12(); printf("\n"); run();
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

int task1_8(void)
{
	int** matrix;
	int* maxCol;
	int i, j, n, m;
	int sumAll = 0, sumRow = 0, sumCol = 0, sumMain = 0, sumSub = 0, sumUpper = 0;
	

	printf("Enter n:\n");
	scanf_s("%d", &n);
	printf("Enter m:\n");
	scanf_s("%d", &m);


	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(m * sizeof(int));

	maxCol = (int*)malloc(m * sizeof(int));

	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;

	//1
	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sumAll += matrix[i][j];
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	//2
	printf("\nsum of elements: %d", sumAll);

	//3
	printf("\n");
	for (int i = 0; i < n; i++) {
		sumRow = 0;
		for (int j = 0; j < m; j++) {
			sumRow += matrix[i][j];
		}
		printf("sum of elements in row %d = %d\n", i, sumRow);
	}

	//4
	printf("\n");
	for (int j = 0; j < m; j++) {
		sumCol = 0;
		for (int i = 0; i < n; i++) {
			sumCol += matrix[i][j];
		}
		printf("sum of elements in columnn %d = %d\n", j, sumCol);
	}

	//5
	printf("\n");
	maxCol[0] = matrix[0][0];

	for (int j = 0; j < m; j++) {
		maxCol[0] = matrix[0][j];
		for (int i = 0; i < n; i++) {
			if (maxCol[j] < matrix[i][j]) {
				maxCol[j] = matrix[i][j];
			}
		}
		printf("greatest in columnn %d = %d\n", j, maxCol[j]);
	}

	//6
	printf("\n");
	for (int i = 0; i < n; i++) {

		sumMain += matrix[i][i];
	}
	printf("sum of main diagonal = %d\n", sumMain);

	//7
	printf("\n");
	for (int i = 0; i < n; i++) {

		sumSub += matrix[i][n - i - 1];
	}
	printf("sum of main diagonal = %d\n", sumSub);

	//8
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i < j)
				sumUpper += matrix[i][j];
		}
	}
	printf("sum of els under main diagonal = %d\n", sumUpper);

	//9
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i < j)
				sumUpper += matrix[i][j];
		}
	}
	printf("sum of els under main diagonal = %d\n", sumUpper);

	free(matrix);
}

task9(void)
{
	int** matrix;
	int i, j, n, m;


	printf("Enter n:\n");
	scanf_s("%d", &n);
	printf("Enter m:\n");
	scanf_s("%d", &m);


	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(m * sizeof(int));

	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;

	//9
	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			matrix[i][j] = 1;
		}
	}

	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	free(matrix);
}

int task10(void)
{
	int** matrix;
	int i, j, n, m;


	printf("Enter n:\n");
	scanf_s("%d", &n);
	printf("Enter m:\n");
	scanf_s("%d", &m);


	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(m * sizeof(int));

	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;

	//9
	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			matrix[i][j] = 1;
		}
	}

	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	free(matrix);
}

int task11(void)
{
	int** matrix;
	int i, j, n, m;


	printf("Enter n:\n");
	scanf_s("%d", &n);
	printf("Enter m:\n");
	scanf_s("%d", &m);


	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(m * sizeof(int));

	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;

	//9
	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-i; j++) {
			matrix[i][j] = 1;
		}
	}

	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	free(matrix);
}

int task12(void)
{
	int** matrix;
	int i, j, n, m;


	printf("Enter n:\n");
	scanf_s("%d", &n);
	printf("Enter m:\n");
	scanf_s("%d", &m);


	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)malloc(m * sizeof(int));

	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 10;

	//9
	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = (n-i-1); j < m; j++) {
			matrix[i][j] = 1;
		}
	}

	printf("\nMATRIX:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}

	free(matrix);
}