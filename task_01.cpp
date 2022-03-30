
//  1. Написать функцию, которая в качестве аргументов принимает указатель 
//  на целочисленный одномерный динамический массив, а также его количество 
//  элементов, и ВОЗВРАЩАЕТ(в параметрах - указателях) 4 значения:
//  минимальный и максимальный элемент, сумму и произведение всех чисел.

#include <iostream>
using namespace std;

void function(int* arr, int size, int* min, int* max, int* sum, int* product);

int main();


void function(int* arr, int size, int* min, int* max, int* sum, int* product)
{
	*min = arr[0];
	*max = arr[0];
	*sum = 0;
	*product = 1;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < *min) *min = arr[i];
		if (arr[i] > *max) *max = arr[i];
		*sum += arr[i];
		*product *= arr[i];
	}
}

int main()
{
	system("chcp 1251 > 0");

	int size = 5;
	int* arr = new int[size] {1, 2, 3, 4, 5};

	int min,
		max,
		sum,
		product;

	function(arr, size, &min, &max, &sum, &product);

	cout << "минимальный элемент массива = " << min << "\n";
	cout << "максимальный элемент массива = " << max << "\n";
	cout << "сумма всех элементов массива = " << sum << "\n";
	cout << "произведение всех элементов массива = " << product << "\n";
}
