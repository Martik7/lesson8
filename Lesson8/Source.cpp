#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <ctime>
using namespace std;

const int n = 4;
const int m = 5;
int a[10][10] = { {1,0,0,0,0}, {1,0,0,0,0}, {1,1,0,0,0}, {0,1,1,1,1} };
int b[100] = { 0 };

void FillArray(int a[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		a[i] = 1 + rand() % 100;
	}
}

template<typename T>
void SortArray(T arr[][30], int n, int m, char sorting_order = 'a');


template<typename myType>

//Selection 
void selectionSort(myType arr[], int n)
{
	int min, min_pos;
	for (size_t i = 0; i < n - 1; i++)
	{
		min = INT_MAX;
		for (size_t j = 1; j < n; j++)
		{
			min = arr[j];
			min_pos = j;
		}
		swap(arr[i], arr[min_pos]);
	}
}


//Insertion сортировка
template<typename myType>
void InsertionSort(myType arr[], myType size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
	}
}

// Сортировка выбором
template<typename myType>
void choicesSort(int* arrayPtr, int length_array)
{
	for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
	{
		int temp = arrayPtr[0]; // âðåìåííàÿ ïåðåìåííàÿ äëÿ õðàíåíèÿ çíà÷åíèÿ ïåðåñòàíîâêè
		for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
		{
			if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
			{
				temp = arrayPtr[repeat_counter];
				arrayPtr[repeat_counter] = arrayPtr[element_counter];
				arrayPtr[element_counter] = temp;
			}
		}
	}
}

//BubbleSort
template<typename myType> //÷òîáû òèï áûë è double è int
void bubbleSort(myType* arrayPtr, myType length_array)
{
	myType temp = 0;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
			if (arrayPtr[int_counter] > arrayPtr[int_counter + 1])
			{
				temp = arrayPtr[int_counter];
				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
				arrayPtr[int_counter + 1] = temp;
				exit = false;
			}
	}
}
/* Вывод массива */

template<typename T>
void printArray(T arr[], int size)
{
	T i;
	for (i = 0; i < size; i++)
		cout << arr[i] << endl;
	cout << endl;
}

//1
template<typename myType>
bool checkBrackets(char c[])
{
	myType k = 0;
	for (size_t i = 0; i < strlen(c); i++)
	{
		if (c[i] == '(') k++;
		else if (c[i] == ')') k--;
		if (c[i] == '[') k++;
		else if (c[i] == ']') k--;
		if (c[i] == '{') k++;
		else if (c[i] == '}') k--;
		if (k < 0) return false;
	}
	if (k == 0) return true;
	else return false;
}

void SortByChoice(int a[], int size, char type)
{
	switch (type)
	{
	case 'i':
		InsertionSort(a, size);
		break;
	case 's':
		selectionSort(a, size);
		break;
	case 'b':
		bubbleSort(a, size);
		break;
	default:
		cout << "Wrong selection type!" << endl;
		break;
	}
}

template<typename T>
void PRINT_Array(T a[][30], int n, int m);


int sumArray(int a[], int n)
{
	static int sum = 0;
	if (n == 1) return a[n - 1];
	return a[n - 1] + sumArray(a, n - 1);
}

int maxArray(int a[], int n)
{
	static int max = a[0];
	if (n == 1)
		return a[n - 1];
	if (a[n - 1] > max)
		max = a[n - 1];
	maxArray(a, n - 1);
	return max;
}

int maxA(int a[], int low, int high)
{
	if (low == high)
		return a[low];
	int middle = (low + high) / 2;
	int right = maxA(a, low, middle);
	int left = maxA(a, middle + 1, high);
	return right > left ? right : left;
}

void swapArray(int a[], int low, int high)
{
	if (low > high) return;
	swap(a[low], a[high]);
	swapArray(a, low + 1, high - 1);
}

int cells(int i, int j)
{
	static int sum = 0;
	if (i >= 0 && i < n && j >= 0 && j < m)
	{
		if (a[i][j] == 1)
		{
			a[i][j] = 2;
			sum++;
			if (a[i-1][j-1] == 1)
				cells(i - 1, j - 1);
			if (a[i - 1][j + 1] == 1)
				cells(i - 1, j + 1);
			if (a[i + 1][j - 1] == 1)
				cells(i + 1, j - 1);
			if (a[i + 1][j + 1] == 1)
				cells(i + 1, j + 1);
			if (a[i - 1][j] == 1)
				cells(i - 1, j);
			if (a[i + 1][j] == 1)
				cells(i + 1, j);
			if (a[i][j - 1] == 1)
				cells(i, j - 1);
			if (a[i][j + 1] == 1)
				cells(i, j + 1);
		}
	}
	return sum;
}

bool labirint(int i, int j)
{
	static bool flag = 0;
	if (i == n - 1 && j == n - 1) {
		flag = true;
		return true;
	}

	if (i >= 0 && i < n && j >= 0 && j < m)
	{
		if (a[i][j] == 1)
		{
			a[i][j] = 2;
			if (a[i - 1][j] == 1)
				labirint(i - 1, j);
			if (a[i + 1][j] == 1)
				labirint(i + 1, j);
			if (a[i][j - 1] == 1)
				labirint(i, j - 1);
			if (a[i][j + 1] == 1)
				labirint(i, j + 1);
		}
	}
	return flag;
}

/*
Напишите рекурсивную функцию, 
которая принимает одномерный массив из 100 целых чисел заполненных случайным образом 
и находит позицию, 
с которой начинается последовательность из 10 чисел, 
сумма которых минимальна.
*/

int functionArr(int c[100], int n, int &p)
{
	int s = 0;
	for (int i = n; i < n + 10; ++i) s += c[i];
	cout << "n: " << n << "; s: " << s << endl;
	if (100 - n == 10)
	{
		p = n;
		return s;
	}
	else
	{
		int s1 = functionArr(c, n + 1, p);
		if (s <= s1)
		{
			p = n;
			return s;
		}
		else return s1;
	}
}

void elka(int h)
{
	if (h == 0) return;
	static int n = 1;
	for (size_t i = 1; i < h; i++)
		cout << " ";
	for (size_t i = 0; i < n; i++)
		cout << "*";
	cout << endl;
	n += 2;
	elka(h - 1);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	/*int a[n];
	FillArray(a, n);
	printArray(a, n);
	cout << sumArray(a, n) << endl;
	cout << maxA(a, 0, 4) << endl;*/
	
	/*int a[n] = { 1,2,3,4,5 };
	printArray(a, n);
	swapArray(a, 0, 4);
	printArray(a, n);*/

	/*cout << cells(1, 2) << endl;
	cout << labirint(0, 0) << endl;*/

	/*int c[100] = {0};
	int p;
	FillArray(c, n);
	printArray(c, n);
	functionArr(c, n , p);
	cout << "Minimum position: " << p << endl << endl;*/

	elka(5);

	system("pause");
	return 0;
}

int maxA(int a[], int low, int high);

template<typename T>
void SortArray(T arr[][30], int n, int m, char sorting_order)
{
	if (sorting_order == 'a')
	{
		for (size_t i = 0; i < n; i++)
		{
			for (int pass = 0; pass < n - 1; pass++)
			{
				for (size_t j = i; j < n - 1; j++)
				{
					if (arr[i][j] > arr[i][j + 1])
						swap(arr[i][j], arr[i][j + 1]);
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			for (int pass = 0; pass < n - 1; pass++)
			{
				for (size_t j = i; j < n - 1; j++)
				{
					if (arr[i][j] < arr[i][j + 1])
						swap(arr[i][j], arr[i][j + 1]); //перестановка элементов массива
				}
			}
		}
	}
}

template<typename T>
void PRINT_Array(T a[][30], int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}