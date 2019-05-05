/*
 * Singly Linked List
 */

#include <stdio.h>
#include <stdlib.h>


typedef  struct LIST
{
	int n;
	struct LIST *next;
} LIST;

/*
 * Initialize List Item
 */
LIST* init_list(int n)
{
	LIST *head = malloc(sizeof(LIST));
	head->n = n;
	head->next = NULL;
	return head;
}

// Prepend item to list
LIST* prepend(LIST *head, int n)
{
	LIST *temp = init_list(n);
	temp->next = head;
	return temp;
}

// Append item to list
void append(LIST *head, int n)
{
	LIST *nptr = init_list(n);
	head->next = nptr;
}

// Get length of list
int length(LIST *lst)
{
	int len = 0;
	LIST *f = lst;
	while (f != NULL)
	{
		f = f->next;
		len++;
	}
	return len;
}

// Check if Item in List
int contains(LIST *head, int n)
{
	LIST *lptr = head;
	while(lptr != NULL)
	{
		if (lptr->n == n)
			return 1;
		lptr = lptr->next;
	}
	return 0;
}
// Helper Function
void printlist(LIST *lst)
{
	LIST *l = lst;
	while (l != NULL)
	{
		printf("%d ", l->n);
		l = l->next;
	}
	putchar('\n');
}


// Insert Item in Sorted Linked List
void insert_sort(LIST *head, int n)
{
	// LIST *lst = init_list(n);
	LIST *fl = head;
	while(fl != NULL)
	{
		if (fl->n > n)
		{
			LIST *temp = init_list(fl->n);
			fl->n = n;
			fl->next = temp;
			break;
		}

		fl = fl->next;
	}
}

int main(int argc, char const *argv[])
{
	LIST *head = init_list(0);
	LIST *fptr = head;

	for(int i = 2;i <= 8;i+=2)
	{
		append(fptr, i);
		fptr = fptr->next;
	}

	printlist(head);

	insert_sort(head, 7);

	printlist(head);
	return 0;
}