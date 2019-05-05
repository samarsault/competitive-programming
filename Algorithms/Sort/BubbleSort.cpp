#include <iostream>

int counter = 0;

void bubblesort(int arr[], int len)
{
	bool changed;
	do
	{
		changed = false;

		for(int i = 0;i < (len - 1);i++)
		{
			counter++;
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				changed = true;
			}
		}
	} while (changed);
}

int main(int argc, const char *argv[])
{
	int A[] = {3, 15, 16, 50, 8 ,23, 42, 108, 1 };
	int len = sizeof (A) / sizeof(int);
	std::cout << "Array Length: " << len << '\n';
	bubblesort(A, len);
	for(int i = 0;i < len;i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << "\nIterations: " << counter << '\n';
	return 0;
}
