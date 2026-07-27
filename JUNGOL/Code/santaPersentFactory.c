#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_N (100000+5)

int cmd[MAX_N + 5] = { 0 };
Node* belt[MAX_N] = { NULL };

typedef struct _node {
	int data;
	struct _node* next;
} Node;

Node* CreateNode(int data)
{
	Node* nnode = NULL;
	nnode = (Node*)malloc(sizeof(Node));
	nnode->data = data; nnode->next = NULL;
	return nnode;
}

void append(Node* head, int data)
{
	Node* nnode = CreateNode(data);
	Node* curr = head;
	for (; curr->next != NULL; curr = curr->next);
	curr->next = nnode;
}

void delete(Node* head, int data)
{
	Node* curr = head->next;
	Node* prev = head;

	while (curr != NULL && curr->data != data) {
		prev = curr;
		curr = curr->next;
	}

	if (curr != NULL) {
		prev->next = curr->next;
		free(curr);
	}
}

void buildFactory(int n, int m)
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
	int Q; (void)scanf("%d", &Q);
	Link ll;
	init(&ll);

	char command[MAX_N * MAX_N] = { 0 };
	for (int i = 0; i < Q; ++i) {
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\r\n")] = 0;
		int count = 0;
		char* ptr = strtok(command, " ");
		while (ptr != NULL) {
			cmd[count++] = stoi(ptr);
			ptr = strtok(NULL, " ");
		}

		int pcmd = cmd[0];
		if (pcmd == 100) {
			int N = cmd[1], M = cmd[2];

		}
		else if (pcmd == 200) {
			int msrc = cmd[1], mdst = cmd[2];
		}
		else if (pcmd == 300) {
			int msrc = cmd[1], mdst = cmd[2];
		}
		else if (pcmd == 400) {
			int msrc = cmd[1], mdst = cmd[2];
		}
		else if (pcmd == 500) {
			int pnum = cmd[1];
		}
		else if (pcmd == 600) {
			int bnum = cmd[1];
		}

	}

	return 0;
}
#endif