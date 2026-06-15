#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* prev;
	struct _node* next;
} Node;

typedef struct _link {
	Node* head;
	Node* tail;
} Link;

void init(Link* ll) {
	ll->head = NULL;
	ll->tail = NULL;
}

void buildFactory()
{

}

void moveAll()
{

}

void moveFront()
{

}

void moveDiv()
{

}

void getPersentInfo()
{

}

void beltInfo()
{

}

int main(void)
{
	Link ll;
	init(&ll);


	return 0;
}
#endif