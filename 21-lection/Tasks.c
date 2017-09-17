#include<stdio.h>
#include<stdbool.h>
#include"module.h"
#include<time.h>

void print_m(int array[], int x)
{
	for (int i = 0; i < x; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n\n");
}

// task 1
void task1()
{
	srand(time(NULL));
	int array1[100] = { 0 };
	int array2[100] = { 0 };
	int a = 1;
	int b = 1;

	while (true)
	{
		int ind = 1;
		int array3[100] = { 0 };
		printf("Enter length for first massive ");
		scanf_s("%d", &a);
		printf("Enter length for second massive ");
		scanf_s("%d", &b);
		for (int i = 0; i < a; i++)
		{
			array1[i] = rand() % 10 + 1;
		}
		for (int i = 0; i < b; i++)
		{
			array2[i] = rand() % 10 + 1;
		}
		for (int i = 0; i < a; i++)
		{
			for (int i1 = 0; i1 < b; i1++)
			{
				//printf("i = %d, i1 = %d\n", i , i1);
				if (array1[i] == array2[i1])
				{
					break;
				}
				if (i1 == b - 1)
				{
					for (int i2 = 0; i2 < ind; i2++)
					{
						if (array1[i] == array3[i2])
						{
							//printf("array1[i] = %d  array3[i2] = %d  i = %d  i2 = %d break \n", array1[i], array3[i2], i, i2);
							break;
						}
						if (i2 == ind - 1)
						{
							//printf("array1[i] = %d  i = %d  i2 = %d\n", array1[i], i, i2);
							array3[i2] = array1[i];
							ind++;
							break;
						}
					}
				}
			}
		}
		print_m(array1, a);
		print_m(array2, b);
		print_m(array3, ind - 1);
	}
}



// task 2

/*
void print_m(int array[], int x)
{
	for (int i = 0; i < x; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n\n");
}
*/

void acting(int array1[], int size1, int array2[], int size2, int *p, int *ind)
{
	//printf("\n*p = %d, ind = %d\n", p[1], *ind);
	for (int i = 0; i < size1; i++)
	{
		for (int i1 = 0; i1 < size2; i1++)
		{
			//printf("i = %d, i1 = %d\n", i , i1);
			if (array1[i] == array2[i1])
			{
				break;
			}
			if (i1 == size2 - 1)
			{
				for (int i2 = 0; i2 < *ind; i2++)
				{
					if (array1[i] == p[i2])
					{
						//printf("\narray1[i] = %d  p[i2] = %d  i = %d  i2 = %d break \n", array1[i], p[i2], i, i2);
						break;
					}
					if (i2 == *ind - 1)
					{
						//printf("\narray1[i] = %d  i = %d  i2 = %d   ", array1[i], i, i2);
						p[i2] = array1[i];
						*ind += 1;
						//printf("*ind = %d, p[i2] = %d\n", *ind, p[i2]);
						break;
					}
				}
			}
		}
	}
}

void task2()
{
	srand(time(NULL));
	int array1[100] = { 0 };
	int array2[100] = { 0 };
	int size1 = 1;
	int size2 = 1;
	while (true)
	{
		int index = 1;
		int *ind = &index;
		int array3[10] = { 0 };
		int *p = array3;
		printf("Enter length for first massive (0-exit) ");
		scanf_s("%d", &size1);
		printf("Enter length for second massive (0-exit) ");
		scanf_s("%d", &size2);
		if (size1 == 0 || size2 == 0)
		{
			break;
		}
		else if (0 > size1 || size1 > 100 || size2 < 0 || size2 > 100)
		{
			printf("\nWrong enter.\n");
			continue;
		}
		for (int i = 0; i < size1; i++)
		{
			array1[i] = rand() % 20 + 1;
			printf("%d  ", array1[i]);
		}
		printf("\n\n");
		for (int i = 0; i < size2; i++)
		{
			array2[i] = rand() % 20 + 1;
			printf("%d  ", array2[i]);
		}
		printf("\n\n");
		//printf("First massive \n\n");
		acting(array1, size1, array2, size2, p, ind);
		//printf("Second massive \n\n");
		acting(array2, size2, array1, size1, p, ind);
		//print_m(array1, a);
		//print_m(array2, b);
		print_m(array3, index - 1);
	}
}

// task 3

/*

void print_m(int array[], int x)
{
printf("\n\n");
for (int i = 0; i < x; i++)
{
printf("%d ", array[i]);
}
printf("\n\n");
}

*/

void check_even(int arr[], int *size, int even)
{
	int ind = 0;
	if (even == 2)
	{
		for (int i = 0; i < *size; i++)
		{
			if (arr[i] % 2 == 1)
			{
				arr[ind] = arr[i];
				ind++;
			}
		}
	}
	else
	{
		for (int i = 0; i < *size; i++)
		{
			if (arr[i] % 2 == 0)
			{
				arr[ind] = arr[i];
				ind++;
			}
		}
	}
	*size = ind;
}

void task3()
{
	srand(time(NULL));
	int array[100] = { 0 };
	int size = 1;
	int *arr = array;
	int *s = &size;
	while (true)
	{
		printf("Enter length (0-exit) ");
		scanf_s("%d", &size);
		if (size == 0)
		{
			break;
		}
		else if (0 > size || size > 100)
		{
			printf("\nWrong enter.\n");
			continue;
		}
		printf("\n");
		for (int i = 0; i < size; i++)
		{
			printf("Enter num for index %d ", i);
			scanf_s("%d", &array[i]);
		}
		printf("\n\n");
		int even = 0;
		while (even != 1 && even != 2)
		{
			printf("What do you need to delete?\nOdd num - 1; Even num - 2 ");
			scanf_s("%d", &even);
		}
		check_even(arr, s, even);
		print_m(array, size);
	}
}

// Task 4

void check_even_sequence(int arr[], int size)
{
	int leng = 0;
	int sum = 0;
	int sleng = 0;
	int ssum = 0;
	for (int i = 0; i < size; i++)
	{
		//printf(" arr[i] = %d, i = %d", arr[i], i);
		if (arr[i] % 2 == 0 && arr[i + 1] % 2 == 0 && i != size - 1)
		{
			leng++;
			sum += arr[i];
			//printf(" arr[i+1] = %d", arr[i+1]);
			//printf(" length = %d, sum = %d\n", leng, sum);
		}
		else if ((arr[i] % 2 == 0 && arr[i + 1] % 2 != 0) || (arr[i] % 2 == 0 && i == size - 1))
		{
			if (sleng < leng + 1)
			{
				sleng = leng + 1;
				//printf(" sleng = %d\n", sleng);
			}
			leng = 0;
			if (ssum < sum + arr[i])
			{
				ssum = sum + arr[i];
				//printf(" ssum = %d\n",ssum);
			}
			sum = 0;
		}
		//printf("\n");
	}
	printf("\nLength = %d, Sum = %d\n", sleng, ssum);
}

void task4()
{
	srand(time(NULL));
	int array[100] = { 0 };
	int size = 1;
	int *arr = array;
	while (true)
	{
		printf("Enter length (0-exit) ");
		scanf_s("%d", &size);
		if (size == 0)
		{
			break;
		}
		else if (0 > size || size > 100)
		{
			printf("\nWrong enter.\n");
			continue;
		}
		printf("\n");
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10 + 1;
			printf("%d ", array[i]);
		}
		printf("\n\n");
		check_even_sequence(arr, size);
	}
}

