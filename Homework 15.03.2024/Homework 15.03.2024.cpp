// Homework 15.03.2024.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void AllocateMemory(int** ar, unsigned int count);

void RandomFillArray(int* ar, unsigned int count);

void PrintArray(int* ar, unsigned int count);

void AddElement(int*& ar, int& size);

void DeleteLastElement(int** ar, int* count);

int main()
{
    ////////////////////////////////////////////////////////////////////           Z A D A N I E 1           ///////////////////////////////////////////////////////////////////////////
	int a = 25;
    int* ptrA = &a;
    int** ptrA2 = &ptrA;
    int*** ptrA3 = &ptrA2;
    int**** ptrA4 = &ptrA3;
    int***** ptrA5 = &ptrA4;

    cout << "Variable 'a' address: " << &a << "        by using ptrA5: " << ****ptrA5 << "\n";
    cout << "Pointer address:      " << &ptrA << "        by using ptrA5: " << ***ptrA5 << "\n";
    cout << "2x pointer address:   " << &ptrA2 << "        by using ptrA5: " << **ptrA5 << "\n";
    cout << "3x pointer address:   " << &ptrA3 << "        by using ptrA5: " << *ptrA5 << "\n";
    cout << "4x pointer address:   " << &ptrA4 << "        by using ptrA5: " << ptrA5 << "\n";
    cout << "5x pointer address:   " << &ptrA5 << "        by using ptrA5: " << &ptrA5 << "\n";
    cout << "\n\n\n";
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	

	
	
	int size = 5;
	int* ar =  nullptr;
	AllocateMemory(&ar, size); 
	RandomFillArray(ar, size);
	PrintArray(ar, size);
	AddElement( ar, size);
	PrintArray(ar, size);
	DeleteLastElement(&ar, &size);
	PrintArray(ar, size);
}

void AllocateMemory(int** ar, unsigned int count)
{
	if (count > 100000) count = 100000;
	(*ar) = new int[count];
	cout << "AllocateMemory\n";
}

void RandomFillArray(int* ar, unsigned int count) 
{
	if (ar == nullptr) {
		cout << "Null pointer! RandomFillArray Exit...\n";
		return;
	}
	cout << "RandomFillArray START!\n";
	for (size_t i = 0; i < count; i++)
	{
		ar[i] = rand() % 100;
	}
	cout << "RandomFillArray DONE!\n";
}

void PrintArray(int* ar, unsigned int count) 
{
	if (ar == nullptr) {
		cout << "Array is empty...\n";
		return;
	}
	cout << "PrintArray START!\n";
	for (size_t i = 0; i < count; i++)
	{
		cout << ar[i] << " ";
	}
	cout << "\nPrintArray DONE!\n";
}
////////////////////////////////////////////////////////////////////           Z A D A N I E 2           ///////////////////////////////////////////////////////////////////////////
void AddElement(int*& ar, int& size)
{

	int* newAr = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newAr[i] = ar[i];
	}

	newAr[size] = 15;
	size++;

	delete[] ar;
	ar = newAr;
}

void DeleteLastElement(int** ar, int* count)
{
	int size = *count;
	if (size <= 0)
	{
		return;
	}

	if (*ar != nullptr)
	{
		int* temp = new int[size - 1];
		for (int i = 0; i < size - 1; ++i)
			temp[i] = (*ar)[i];

		delete[](*ar);
		*ar = temp;
		*count = size - 1;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
