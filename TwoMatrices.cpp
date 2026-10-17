#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int iGetRandNum(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void vGenerateRandomMatrix(int Arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			Arr[i][j] = iGetRandNum(0, 9);
		}
	}
}

void vPrintArray(int Arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			printf(" %d    ", Arr[i][j]);
		}
		cout << endl;
	}
}

bool bIsNumberExistInArray(int Arr[3][3], short Rows, short Cols, int Number)
{
	for (short i = 0; i < Cols; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			if (Number == Arr[i][j])
				return 1;
		}
	}

	return 0;
}

void vCheckRepeatedElementsInTwoArrays(int Arr1[3][3], int Arr2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		for (short j = 0; j < Rows; j++)
		{
			if (bIsNumberExistInArray(Arr1, Rows, Cols, Arr2[i][j]))
				cout << Arr2[j][j] << "   ";
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr1[3][3], Arr2[3][3];
	short Rows = 3, Cols = 3;

	vGenerateRandomMatrix(Arr1, Rows, Cols);
	cout << "-Matrix:\n";
	vPrintArray(Arr1, Rows, Cols);

	vGenerateRandomMatrix(Arr2, Rows, Cols);
	cout << "-Matrix:\n";
	vPrintArray(Arr2, Rows, Cols);

	cout << "\nRepeated Number in Two matrices: ";
	vCheckRepeatedElementsInTwoArrays(Arr1, Arr2, Rows, Cols);
	cout << endl;

	return 0;
}