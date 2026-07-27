#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200010

int N;
int len = 0;
char msg[MAX_N] = { 0 };
char stk[MAX_N] = { 0 };

void inputData(void)
{
	(void)scanf("%s", msg);
	(void)scanf("%d", &N);
	while (getchar() != '\n');
	len = strlen(msg);
}

void printData(void)
{
	for (int i = 0; i < 100; ++i) {
		printf("%c", msg[i]);
	} printf("\n");
	for (int i = 0; i < 100; ++i) {
		printf("%c", stk[i]);
	} printf("\n");
}

void editor(void)
{
	int mIdx = len, sIdx = -1;
	char command[10] = { 0 };
	for (int i = 0; i < N; ++i) {
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\r\n")] = 0;
		char cmd = command[0];
		if (cmd == 'L') {
			if (mIdx > 0) {
				stk[++sIdx] = msg[--mIdx];
			}
		}
		else if (cmd == 'D') {
			if (sIdx >= 0) {
				msg[mIdx++] = stk[sIdx--];
			}
		}
		else if (cmd == 'B') {
			if (mIdx > 0) {
				msg[--mIdx] = 0;
			}
		}
		else if (cmd == 'P') {
			char ch = command[2];
			msg[mIdx++] = ch;
		}
	}
	while (sIdx >= 0) {
		msg[mIdx++] = stk[sIdx--];
	}
	msg[mIdx] = '\0';
}

int main(void)
{
	inputData();
	editor();
	printf("%s\n", msg);
	return 0;
}
#endif