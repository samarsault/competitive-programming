#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
	T* A;
	size_t length;
	size_t top; // under the hood top = (length of the stack - 1)
public:
	Stack(size_t size)
	{
		A = new T[size];
		top = -1;
		length = size;
	}
	~Stack()
	{
		delete [] A;
	}
	bool empty()
	{
		return top == -1;
	}
	bool push(T item)
	{
		top++;
		if (top <= length)
		{
			A[top] = item;
			return true;
		}
		return false;
	}
	T pop()
	{
		if (!empty())
		{
			top--;
			return A[top + 1];
		}
		else {
			return NULL;
		}
	}
};

int main(int argc, char const *argv[])
{
	// stack of size 10
	Stack<int> S(10);
	S.push(3);
	S.push(2);
	S.push(9);
	cout << S.pop() << endl;
	return 0;
}