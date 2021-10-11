#include <stdio.h>
#include <malloc.h>

struct slink
{
	int info;
	struct slink *next; //self referential pointer
};

struct slink *start;

//Function prototypes
void insertFirst(struct slink *, int);		    //Function to Insert at the Beginning
void insertLast(struct slink *, int);		    //Function to Insert at the End
void insertPosition(struct slink *, int, int);  //Function to Insert at a Particular Location
void insertAfter(struct slink *, int, int);	    //Function to Insert after a given node
void deleteLoc(struct slink *, int);            //Function to Delete from a given location
void deleteVal(struct slink *, int);            //Function to Delete by a given value
void reverse(struct slink *);                   //Function to Reverse the linked list
void sort(struct slink *);                      //Function to Sort the linke list
int count(struct slink *);	                    //Function to count number of nodes
void display(struct slink *);                   //Function to display all the nodes

int main()
{
	struct slink *node = NULL;
	int choice, x, loc, val, c;

	do
	{
		printf("\n 1. Insert at the Beginning");
		printf("\n 2. Insert at the End");
		printf("\n 3. Insert at a Particular Location");
		printf("\n 4. Insert after a given node");
		printf("\n 5. Delete from a given location");
		printf("\n 6. Delete by a given value");
		printf("\n 7. Reverse the linked list");
		printf("\n 8. Sort the linked list");
		printf("\n 9. Display the count of nodes");
		printf("\n 10. Display");
		printf("\n 11. Exit!");

		printf("\n Enter the choice: ");
		scanf("%d", &choice);
		
		switch (choice)
		{
		case 1:
			printf("\n Enter the element to be inserted: ");
			scanf("%d", &x);
			insertFirst(node, x);
			node = start;
			break;

		case 2:
			printf("\n Enter the element to be inserted: ");
			scanf("%d", &x);
			insertLast(node, x);
			break;

		case 3:
			printf("\n Enter the element to be inserted: ");
			scanf("%d", &x);
			printf("\n Enter the location: ");
			scanf("%d", &loc);
			insertPosition(node, loc, x);
			break;

		case 4:
			printf("\n Enter the element to be inserted: ");
			scanf("%d", &x);
			printf("\n Enter the node value after which new node is to be inserted: ");
			scanf("%d", &val);
			insertAfter(node, val, x);
			break;

		case 5:
			printf("\n Enter the location of element to be deleted: ");
			scanf("%d", &loc);
			deleteLoc(node, loc);
			if (loc == 1)
			{
				node = start;
			}
			break;

		case 6:
			printf("\n Enter the value of element to be deleted: ");
			scanf("%d", &val);
			deleteLoc(node, val);
			break;

		case 7:
			reverse(node);
			node = start;
			break;

		case 8:
			sort(node);
			break;
			
		case 9:
		    c = count(node);
		    printf("\nThere are %d nodes in the linked list\n", c);
		    break;
		
		case 10:
			display(node);
			break;
			
		case 11:
		    printf("\n---------- EXIT ----------");
		    exit(0);
		    break;

		default:
			printf("\n Invalid choice...Please try again");
			break;
		}

	} while (choice != 11);
}

void insertFirst(struct slink *node, int x)
{
	struct slink *curr;
	curr = (struct slink *)malloc(sizeof(struct slink));
	curr->info = x;
	curr->next = node;
	start = curr;
}

void insertLast(struct slink *node, int x)
{
	struct slink *curr;
	curr = (struct slink *)malloc(sizeof(struct slink));
	curr->info = x;
	curr->next = NULL;

	while (node->next != NULL)
	{
		node = node->next;
	}
	node->next = curr;
}

void insertPosition(struct slink *node, int loc, int x)
{
	struct slink *curr, *prev, *temp;
	int i = 1;
	curr = (struct slink *)malloc(sizeof(struct slink));
	curr->info = x;
	curr->next = NULL;

	if (node == NULL)
	{
		printf("\n List is Empty");
		return;
	}

	int cnt;
	cnt = count(node);
	if (loc > cnt)
	{
		printf("\n Location exceeds the number of nodes in list... :(");
		return;
	}

	while (i < loc)
	{
		prev = node;
		node = node->next;
		i++;
	}
	prev->next = curr;
	curr->next = node;
}

int count(struct slink *node)
{
	int i = 0;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return i;
}

void insertAfter(struct slink *node, int val, int x)
{
	struct slink *curr;
	curr = (struct slink *)malloc(sizeof(struct slink));
	curr->info = x;
	curr->next = NULL;

	while (node != NULL)
	{
		if (val == node->info)
		{
			break;
		}
		if (node == NULL)
		{
			printf("\n The value does not exist");
			return;
		}
		node = node->next;
	}
	curr->next = node->next;
	node->next = curr;
}

void display(struct slink *node)
{
	printf("\n Linked List is as follows...\n");
	while (node != NULL)
	{
		printf("%d\t", node->info);
		node = node->next;
	}
	printf("\n");
}

void deleteLoc(struct slink *node, int loc)
{
	struct slink *prev;
	int i = 1;
	int cnt;
	cnt = count(node);

	if (loc == 1)
	{
		start = node->next;
		node->next = NULL;
		free(node);
		return;
	}

	if (loc > cnt)
	{
		//check how to display since
		printf("\n Location exceeds the number of nodes in list... :(");
		return;
	}

	while (i < loc)
	{
		prev = node;
		node = node->next;
		i++;
	}
	if (loc == cnt)
	{
		prev->next = NULL;
	}
	else
	{
		prev->next = node->next;
	}
}

void deleteVal(struct slink *node, int val)
{
	struct slink *prev;
	while (node != NULL)
	{
		if (val == node->info)
		{
			break;
		}
		if (node == NULL)
		{
			printf("\n The value does not exist");
			return;
		}
		prev = node;
		node = node->next;
	}
	prev->next = node->next;
}

void reverse(struct slink *node)
{
	struct slink *behind, *current, *ahead;
	current = node;
	behind = NULL;
	ahead = NULL;
	while (current != NULL)
	{
		ahead = current->next;
		current->next = behind;
		behind = current;
		current = ahead;
	}
	start = behind;
}

void sort(struct slink *node)
{
	int temp;
	int cnt = count(node);
	for (int i = 0; i < cnt - 1; i++)
	{
		node = start;
		for (int j = 0; j < cnt - i - 1; j++)
		{
			if (node->info > node->next->info)
			{
				temp = node->next->info;
				node->next->info = node->info;
				node->info = temp;
			}
			node = node->next;
		}
	}
}
