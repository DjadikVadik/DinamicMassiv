
//  2. Создать заголовочный файл myarray.h с рядом функций для работы с динамическими массивами :
//  a) функция выделения динамической памяти под массив
//  b) функция инициализации динамического массива случайными числами
//  c) функция показа динамического массива на экран консоли
//  d) функция очистки памяти от динамического массива
//  e) функция добавления элемента в начало массива
//  f) функция добавления элемента в конец массива
//  g) функция вставки элемента по указанному индексу
//  h) функция удаления элемента  из начала массива
//  i) функция удаления элемента из конца массива
//  j) функция удаления элемента по указанному индексу

#pragma once
#include <iostream>
using namespace std;


void NewArr(int*& arr, int size)  //  a) функция выделения динамической памяти под массив
{
	arr = new int[size];
}

void SetRandArr(int*& arr, int size)  //  b) функция инициализации динамического массива случайными числами
{
	srand(time(0));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
}

void showArr(int*& arr, int size)  //  c) функция показа динамического массива на экран консоли
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ",   ";
	cout << "\n";
}

void DelArr(int*& arr) //  d) функция очистки памяти от динамического массива
{
	delete[] arr;
	arr = nullptr;
}

void NewStartElement(int*& arr, int& size) //  e) функция добавления элемента в начало массива
{
	int* arr1 = new int[size + 1];
	arr1[0] = 0;

	for (int i = 0; i < size; i++)
		arr1[i + 1] = arr[i];

	delete[] arr;
	size++;
	arr = arr1;
}

void NewFinishElement(int*& arr, int& size)  //  f) функция добавления элемента в конец массива
{
	int* arr1 = new int[size + 1];
	arr1[size] = 0;

	for (int i = 0; i < size; i++)
		arr1[i] = arr[i];

	delete[] arr;
	size++;
	arr = arr1;
}

void NewNumElement(int*& arr, int& size, int num) //  g) функция вставки элемента по указанному индексу
{
	int* arr1 = new int[size + 1];

	for (int i = 0; i < size + 1; i++)
	{
		if (i < num) arr1[i] = arr[i];
		else if (i == num) arr1[i] = 0;
		else if (i > num) arr1[i] = arr[i - 1];
	}

	delete[] arr;
	size++;
	arr = arr1;
}

void DelStartElement(int*& arr, int& size)  //  h) функция удаления элемента  из начала массива
{
	int* arr1 = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
		arr1[i] = arr[i + 1];

	delete[] arr;
	size--;
	arr = arr1;
}

void DelFinishElement(int*& arr, int& size)  //  i) функция удаления элемента из конца массива
{
	int* arr1 = new int[size - 1];

	for (int i = 0; i < size - 1; i++)
		arr1[i] = arr[i];

	delete[] arr;
	size--;
	arr = arr1;
}

void DelNumElement(int*& arr, int& size, int num)  //  j) функция удаления элемента по указанному индексу
{
	int* arr1 = new int[size - 1];

	for (int i = 0; i < size ; i++)
	{
		if (i < num) arr1[i] = arr[i];
		else if (i == num) continue;
		else if (i > num) arr1[i - 1] = arr[i];
	}

	delete[] arr;
	size--;
	arr = arr1;
}