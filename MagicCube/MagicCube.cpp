#include <iostream>
#include <time.h>
using namespace std;

int printArr(int**, unsigned);
int fillMagic(int **, unsigned);
int main()
{
	int size;
	cout << "Enter size of array : ";
	cin >> size;

	int **arr = new int*[size];     //init array
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = new int[size];
	}


	cout << endl;
	//
	srand(time(NULL));

	int *sborRed = new int[size];
	int *sborKolona = new int[size];
	int sborDiagonal[2];
	bool isMagic = false;





	while (isMagic == false)
	{

		//initialize sbors with 0s (so we can use arithmetic operations)
		for (int i = 0; i < size; i++)
		{
			sborRed[i] = 0;
			sborKolona[i] = 0;

		}
		sborDiagonal[0] = 0;
		sborDiagonal[1] = 0;

		//generate randoms
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				*(*(arr + i) + j) = 1 + rand() % 3;




		//calculate sbors
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				sborRed[i] = sborRed[i] + arr[i][j];
				sborKolona[i] = sborKolona[i] + arr[j][i];

			}
		}
		for (int i = 0; i < size; i++)
		{
			sborDiagonal[0] = sborDiagonal[0] + arr[i][i];
			sborDiagonal[1] = sborDiagonal[1] + arr[i][size - i - 1];

		}

		/*cout << "Sborove na redove : ";
		for (int i = 0; i < size; i++)
		{
		cout << *(sborRed+i);
		cout << " ";


		}
		cout << endl;
		cout << "Sborove na koloni : ";

		for (int i = 0; i < size; i++)
		{
		cout << *(sborKolona + i);
		cout << " ";
		}

		*/
		/*cout << "Sbor na diagonal 1 : ";
		cout << sborDiagonal[0];
		cout << sborDiagonal[1];
		*/
		for (int i = 1; i < size; i++)
		{
			if (sborDiagonal[0] != sborDiagonal[1])break;
			if (sborRed[i] != sborRed[i - 1])break;
			if (sborKolona[i] != sborKolona[i - 1])break;
			isMagic = true;
		}


	}


	//
	printArr(arr, size);


	cout << endl;


	for (int i = 0; i < size; i++) //delete array
	{
		delete[]arr[i];
	}
	delete[]arr;

	return 0;
}

int fillMagic(int **arr, unsigned size)
{
	srand(time(NULL));

	int *sborRed = new int[size];
	int *sborKolona = new int[size];
	int sborDiagonal[2];
	bool isMagic = false;



	//initialize sbors with 0s (so we can use arithmetic operations)
	for (int i = 0; i < size; i++)
	{
		sborRed[i] = 0;
		sborKolona[i] = 0;

	}
	sborDiagonal[0] = 0;
	sborDiagonal[1] = 0;



	while (isMagic == false)
	{

		//generate randoms
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				*(*(arr + i) + j) = 1 + rand() % 10;




		//calculate sbors
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				sborRed[i] = sborRed[i] + arr[i][j];
				sborKolona[i] = sborKolona[i] + arr[j][i];

			}
		}
		for (int i = 0; i < size; i++)
		{
			sborDiagonal[0] = sborDiagonal[0] + arr[i][i];
			sborDiagonal[1] = sborDiagonal[1] + arr[i][size - i - 1];

		}

		/*cout << "Sborove na redove : ";
		for (int i = 0; i < size; i++)
		{
		cout << *(sborRed+i);
		cout << " ";


		}
		cout << endl;
		cout << "Sborove na koloni : ";

		for (int i = 0; i < size; i++)
		{
		cout << *(sborKolona + i);
		cout << " ";
		}

		*/
		/*cout << "Sbor na diagonal 1 : ";
		cout << sborDiagonal[0];
		cout << sborDiagonal[1];
		*/
		for (int i = 1; i < size; i++)
		{
			if (sborDiagonal[0] != sborDiagonal[1])break;
			if (sborRed[i] != sborRed[i - 1])break;
			if (sborKolona[i] != sborKolona[i - 1])break;
			isMagic = true;
		}


	}


	return 0;
}

int printArr(int **arr, unsigned size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << *(*(arr + i) + j);
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}