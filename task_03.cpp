
//  3. Даны два массива : А[M] и B[N](M и N вводятся с клавиатуры).
//  Необходимо создать третий массив минимально возможного размера, 
//  в котором нужно собрать общие элементы двух массивов(без повторений).

#include <iostream>
using namespace std;

int* minArr(int* arr1, int size1, int* arr2, int size2, int& curent);

void show(int* arr, int size);

int main();



int* minArr(int* arr1, int size1, int* arr2, int size2, int& curent )
{
	int size = size1 < size2 ? size1 : size2;
	int* arr3 = new int[size];
	curent = 0;

	for (int i = 0; i < size1; i++)
	{
		bool allgemeines = false;
		for (int j = 0; j < size2; j++)
			if (arr1[i] == arr2[j]) allgemeines = true;
		if (allgemeines)
		{
			for (int k = 0; k < curent; k++)
				if (arr1[i] == arr3[k])  allgemeines = false;
		}

		if (allgemeines)
		{
			arr3[curent] = arr1[i];
			curent++;
		}
	}

	int* arr4 = new int[curent];

	for (int i = 0; i < curent; i++)
		arr4[i] = arr3[i];

	delete[] arr3;
	arr3 = nullptr;

	return arr4;
}

void show(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ",   ";
	cout << "\n\n";
}


int main()
{
	system("chcp 1251 > 0");
	srand(time(0));

	cout << "введите размер массива 1 : ";
	int M; 
	cin >> M;

	cout << "введите размер массива 2 : ";
	int N;
	cin >> N;

	int* A = new int[M];
	for (int i = 0; i < M; i++)
		A[i] = rand() % 10;

	int* B = new int[N];
	for (int i = 0; i < N; i++)
		B[i] = rand() % 10;

	cout << "\nПервый массив :\n";
	show(A, M);

	cout << "Второй массив :\n";
	show(B, N);

	int K;
	int* C = minArr(A, M, B, N, K);

	cout << "Новый массив :\n";
	show(C, K);
}
