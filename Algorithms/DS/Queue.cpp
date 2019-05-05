#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename T>
class Queue {
private:
	T *A;
	size_t length;
	int head;
	int tail;
public:
	// initialize queue with size_t
	Queue(size_t S)
	{
		length = S;
		A = new T[length];
		head = 0;
		tail = 0;
	}
	// free array
	~Queue()
	{
		delete [] A;
	}
	// queue is empty
	bool empty()
	{
		return head == tail;
	}
	void enqueue(T item)
	{
		tail++;
		A[tail] = item;
	}
	T dequeue();
};
int main(int argc, char const *argv[])
{
	return 0;
}