#include <iostream>
#include <algorithm>

template<class T>
class Array {
private:
	T *ptr;
	int size;
public:
	Array(T arr[], int s);
	T* begin();
	T* end();
	void print(char=' ');
};

template<class T>
T* Array<T>::begin()
{
	return ptr;
}

template<class T>
T* Array<T>::end()
{
	return ptr + size;
}

template<class T>
void Array<T>::print(char delim) 
{
	for (int i = 0;i < size;i++)
		std::cout << *(ptr + i) << delim;
	std::cout << std::endl;
}

template<class T>
Array<T>::Array(T arr[], int s)
{
	ptr = new T[s];
	size = s;

	for (int i = 0;i < s;i++)
		ptr[i] = arr[i];
}

int main(int argc, char const *argv[])
{
    int arr[5] = {5, 7, 3, 8, 1};
    Array<int> a(arr, 5);
    int *A = new int[3];
    a.print();
    std::sort(a.begin(), a.end());
    a.print();
	return 0;
}
