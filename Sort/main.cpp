#include <iostream>
#include <time.h>

using namespace std;

void printArr(int* arr, int size);
void bubbleSort(int* arr, int size);
void selectionStor(int size, int* arr);
void insertSort(int* arr, int size);
int* makeArr(int size);
void mySwap(int& a, int& b);

int main()
{
	//bubbleSort  //Пузырьковая сортировка
	srand(time(NULL));
	int size = 10;
	int* arr = makeArr(size);
	cout << "Initial array: " << endl;
	printArr(arr, size);
	bubbleSort(arr, size);
	cout << "Array after sorting: " << endl;
	printArr(arr, size);


	//selectionStor //Сортировка выбором
	srand(time(NULL));
	int size1 = 10;
	int* arr1 = makeArr(size1);
	cout << "Initial array: " << endl;
	printArr(arr1, size1);
	selectionStor(size1,arr1);
	cout << "Array after sorting: " << endl;
	printArr(arr1, size1);


	 //insertion  //Сортировка вставками
	srand(time(NULL));
	int size2 = 10;
	int* arr2 = makeArr(size2);
	cout << "Initial array: " << endl;
	printArr(arr2, size2);
	insertSort(arr2, size2);
	cout << "Array after sorting: " << endl;
	printArr(arr2, size2);


	delete arr;
	return 0;
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				mySwap(arr[j], arr[j + 1]);
			}
		}
	}
}

void selectionStor(int size, int* arr)
{
	for (int i = 0; i < size - 1; i++)
	{
		int tmp = arr[i];
		int index = i;
		for (int j = i; j < size; j++)
		{
		    if (arr[j] < tmp)
			{
				tmp = arr[j];
				index = j;
		    }
		}
		mySwap(arr[i], arr[index]);
	}
}

void insertSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int j = i + 1;
		int tmp = arr[j];
		for (; j >= 0 && tmp < arr[j - 1]; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}

int* makeArr(int size)
{
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101;
	}
	return arr;
}

void mySwap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}