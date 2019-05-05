/*
 * Queue in C
 * FIFO (First In First Out)
 */
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 80

typedef struct Queue {
	int head;
	int data[CAPACITY];
	int size;
} Queue;

void enqueue (Queue *q, int n)
{
	if (q->size < CAPACITY)
	{
		q->data[(q->head + q->size) % CAPACITY] = n;
		q->size++;
	}
}

void dequeue (Queue *q)
{
	if (q->size > 0)
	{
		q->head++;
		q->size--;
	}
}

void printqueue(Queue *q)
{
	for(int i = q->head;i < q->size;i++)
	{
		printf("%d ", q->data[i]);
	}
	putchar('\n');
}

int main(int argc, char const *argv[])
{
	/* Initialize Queue */
	Queue *q = (Queue*) malloc(sizeof(Queue));
	q->head = 0;
	q->size = 0;

	for(int i = 0;i < 8;i++)
		enqueue(q, i);

	printqueue(q);

	dequeue(q);

	printqueue(q);
	return 0;
}