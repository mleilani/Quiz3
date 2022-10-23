#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the square
void printSquare(int square[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		printf("[");
		for (int j = 0; j < 3; j++)
		{
			if (j == 2)
			{
				printf("%d]", square[i][j]);
				break;
			}
			printf("%d ", square[i][j]);
		}
		printf("\n");
	}
}

// function to fill the square with random numbers using time

// function to check if it is a magic square
int isMagicSquare(int square[3][3])
{
	// Storing sum of first row in val, and comparing it with all the other values
	int val = 0, tempVal = 0;
	// Checking first row
	for (int i = 0; i < 3; i++)
	{
		val = val + square[0][i];
	}

	// Checking 2nd and 3rd row
	for (int i = 1; i < 3; i++)
	{
		tempVal = 0;
		for (int j = 0; j < 3; j++)
		{
			tempVal = tempVal + square[i][j];
		}
		if (tempVal != val)
		{
			return 0;
		}
	}

	// Checking all columns
	for (int i = 0; i < 3; i++)
	{
		tempVal = 0;
		for (int j = 0; j < 3; j++)
		{
			tempVal = tempVal + square[j][i];
		}
		if (tempVal != val)
		{
			return 0;
		}
	}

	// Checking diagonals
	if ((square[0][2] + square[1][1] + square[2][0]) != val || square[0][0] + square[1][1] + square[2][2] != val)
	{
		return 0;
	}

	return 1;
}

int main()
{

	// initiate a 2 x 2.. 2d array
	int magicSquare[3][3];
	int count = 0;
	time_t t;

	srand((unsigned)time(&t)); // Changing seed , so that we get new values each time

	// do while loop while the function magic square is not true
	do
	{
		count++;
		int used[10] = {0};

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int n = rand() % 9 + 1; // random number between 1 - 9
				while (used[n])			// generating random numbers until all of the possible numbers are used
				{
					n = rand() % 9 + 1;
				}
				magicSquare[i][j] = n;
				used[n] = 1;
			}
		}
	} while (isMagicSquare(magicSquare) != 1);

	// have a counter for the number of squares generated
	printf("No. of squares generated : %d\n", count);

	// at the end print the grid
	printSquare(magicSquare);

	return EXIT_SUCCESS;
}