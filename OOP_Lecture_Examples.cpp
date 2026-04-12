#include "03_Pointers.h"
using namespace std;
using namespace Unit03;

int* reverse(int list[], int size)
{
	int* left = list;
	int* right = list + size - 1;
	for (; left < right; ++left, --right)
	{
		int temp = *left;
		*left = *right;
		*right = temp;
	}
	return list;
}

void printArray(int list[], int size)
{
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;
}

int main()
{
	Unit03::AudioBufferExample::processSamples();
	return 0;
}
