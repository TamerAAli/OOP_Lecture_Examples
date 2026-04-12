#include "03_Pointers.h"
using namespace std;
using namespace Unit03;

void reverse(int list[], int size)
{
	int* left = list;
	int* right = list + size - 1;
	for (; left < right; ++left, --right)
	{
		int temp = *left;
		*left = *right;
		*right = temp;
	}
}

void printArray(int list[], int size)
{
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;
}

int main()
{
	int list[] = { 10, 20, 30, 40, 50 };
	printArray(list, 5);
	reverse(list, 5);
	printArray(list, 5);
	return 0;
}
