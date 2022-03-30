
//  4. Написать функцию, вставляющую / удаляющую строку / столбец 
//  двумерного динамического массива по указанному номеру.

#include <iostream>
using namespace std;

void delRows(int**& arr, int& row, int col, int num);

void plusRows(int**& arr, int& row, int col, int num);

void delCol(int**& arr, int row, int& col, int num);

void plusCol(int**& arr, int row, int& col, int num);

void show(int* arr[], int row, int col);

int main();





void delRows(int**& arr, int& row, int col, int num)
{
	int** arr1 = new int* [row - 1];


	for (int i = 0; i < row; i++)
	{
		if (i < num) arr1[i] = arr[i];
		else if (i == num) continue;
		else if (i > num) arr1[i - 1] = arr[i];
	}
	delete[] arr[num];
	delete[] arr;
	arr = arr1;
	row--;
}

void plusRows(int**& arr, int& row, int col, int num)
{
	int** arr1 = new int* [row + 1];
	int* ar = new int[col] {};

	for (int i = 0; i < row + 1; i++)
	{
		if (i < num) arr1[i] = arr[i];
		else if (i == num) arr1[i] = ar;
		else if (i > num) arr1[i] = arr[i - 1];
	}

	delete[] arr;
	arr = arr1;
	row++;
}

void delCol(int**& arr, int row, int& col, int num)
{
	int** arr1 = new int* [row];

	for (int i = 0; i < row; i++)
		arr1[i] = new int[col - 1];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (j < num) arr1[i][j] = arr[i][j];
			else if (j == num) continue;
			else if (j > num) arr1[i][j - 1] = arr[i][j];
		}

	for (int i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
	col--;
	arr = arr1;
}

void plusCol(int**& arr, int row, int& col, int num)
{
	int** arr1 = new int* [row];

	for (int i = 0; i < row; i++)
		arr1[i] = new int[col + 1];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col + 1; j++)
		{
			if (j < num) arr1[i][j] = arr[i][j];
			else if (j == num) arr1[i][j] = 0;
			else if (j > num) arr1[i][j] = arr[i][j - 1];
		}

	for (int i = 0; i < row; i++)
		delete[] arr[i];
	delete[] arr;
	col++;
	arr = arr1;
}

void show(int* arr[], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << "\t";
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	system("chcp 1251 > 0");
	int row = 5;
	int col = 7;
	int** arr = new int* [row];

	for (int i = 0; i < row; i++)
		arr[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = rand() % 10 + 1;

	cout << "изначальный массив : \n";
	show(arr, row, col);

	plusCol(arr, row, col, 3);

	cout << "измененный массив : \n";
	show(arr, row, col);
}
