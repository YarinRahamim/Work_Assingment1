#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
#define N 4
/* Declarations of other functions */
int* powerArray(int n);
int numPower(int num, int exp);
int* aloocArr(int ref);
void mathMatrice(int mat1[][N], int mat2[][N], int rows, int cols);
int checkMatrice(int mat1[][N], int mat2[][N], int rows, int cols);
void initNewMatrice(int** p, int mat1[][N], int mat2[][N], int rowsStaticMat, int colsStaticMat, int rowNewMat, int* refArr);
void free_mat(int** mat, int row);
int* scanArr(int* sizeArr);
void printarr(int*, int);
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 6; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-6 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 4));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;


			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/*.............................*/
void Ex1()
{
	int* newArr = NULL;
	int n;
	printf("Please enter the number of elemnt's for your array :");
	scanf("%d", &n);
	newArr = powerArray(n);
	printarr(newArr, n);
	free(newArr);
}
int* powerArray(int n)
{
	int i;
	int* p = NULL;
	p = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++)
		p[i] = numPower(2, i);
	return p;
}
int numPower(int num, int exp)
{
	int i;
	if (exp == 0)
		return 1;
	if (exp == 1)
		return num;
	for (i = 1; i <= exp; i++)
		num *= num;
	return num;
}
void Ex2()
{
	int mat1[N][N] = { {2, 7, 12, 1},{3,4,5,9},{20,1,11,9},{8,3,210,100}};
	int mat2[N][N] = { {1,7,7,3},{3,4,5,9},{22,1,0,9},{52,3,2,9} };
	int** mat3 = NULL;
	mathMatrice(mat1, mat2, N, N);
}
void mathMatrice(int mat1[][N], int mat2[][N], int rows, int cols)
{
	int flag = 0, count_cols;
	int i=0, j, l=0;
	int** p = NULL;
	int* refArr = NULL;
	int ref;
	if (!(ref = checkMatrice(mat1, mat2, rows, cols)))
		return NULL;
	p = (int**)malloc(ref* sizeof(int*));
	if (!p)
	{
		printf("Allocation Faild!\n");
		return NULL;
	}
	refArr = aloocArr(ref);
	if (!refArr)
		return NULL;
	while(l<ref)
	{
		count_cols = 0;
		for (j = 0; j < cols; j++)
		{
			if (mat1[i][j] > mat2[i][j])
			{
				count_cols++;
			}

		}
		if (!count_cols)
		{
			i++;
			if(i<rows)
				continue;
			break;
		}
		p[l] = aloocArr(count_cols);
		if (!p[l])
		{
			free_mat(p, ref);
			printf("Allocation Faild!\n");
			return NULL;
		}
		refArr[l] = count_cols;
		l++;
		i++;
		if (i < rows)
			continue;
		break;
	}
	initNewMatrice( p, mat1,mat2, rows,cols,ref,refArr);
}
void Ex3()
{

}
void Ex4()
{

}

int* aloocArr(int ref) {
	int* refArr = NULL;
	refArr = (int*)malloc(ref * sizeof(int));
	if (!refArr)
	{
		return NULL;
	}
	return refArr;

}
void initNewMatrice(int** p, int mat1[][N], int mat2[][N], int rowsStaticMat, int  colsStaticMat, int rowNewMat,int* refArr)
{
	int i, j, k, x;
	printf("The new matrice is:\n");
	for (i = 0, k = 0; k < rowNewMat; i++)
	{
		for (j = 0, x = 0; ((j<colsStaticMat) && (x < refArr[k])); j++)
		{
			if (mat1[i][j] > mat2[i][j])
			{
				p[k][x] = mat1[i][j] - mat2[i][j];
				printf("%4d", p[k][x]);
				x++;
			}
		}
		if (x) {
			printf("\n");
			k++;
		}
	}
	free_mat(p, rowNewMat);
	free(refArr);
}
int checkMatrice(int mat1[][N], int mat2[][N], int rows, int cols) 
{
	int i, j;
	int ref = 0, flag = 0;
	for (i = 0; i < rows; i++)
	{
		flag = 0;
		for (j = 0; j < cols; j++)
		{
			if (mat1[i][j] > mat2[i][j])
			{
				flag++;
				break;
			}
		}
		if (flag)
			ref++;
	}
	if (!ref)
	{
		printf("No elemnt's in the new matrice \n");
		return NULL;
	}
	return ref;
}
int* scanArr(int* sizeArr)
{
	int n;
	printf("Please enater how much elements you want in the array (The array must be sorted!):\n");
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	printf("Please enter elemnts to the array:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", (arr + i));
	*sizeArr = n;
	return arr;
}
void printarr(int* arr3, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d\t", *(arr3 + i));
	printf("\n");
	return;
}
void free_mat(int** mat, int row)
{
		int i;
		for (i = 0; i < row; i++) {
			free(mat[i]);
			mat[i] = NULL;
		}
		free(mat);
}
