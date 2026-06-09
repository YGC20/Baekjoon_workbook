#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char msg[100005] = { 0 };
char tmsg[100005] = { 0 };

int main(void)
{
	int N = 0;
	char cmd;
	(void)scanf("%s", msg);
	(void)scanf("%d", &N);
	(void)getchar();
	
	int mIdx = 0, tIdx = 0;
	while (msg[mIdx] != '\0' && mIdx <= 100000) {
		mIdx++;
	}

	while (N--) {
		(void)scanf("%c", &cmd);
		(void)getchar();
		if (cmd == 'L' && mIdx > 0) {
			tmsg[tIdx++] = msg[--mIdx];
		}
		else if (cmd == 'D' && tIdx > 0) {
			msg[mIdx++] = tmsg[--tIdx];
		}
		else if (cmd == 'B' && mIdx > 0) {
			msg[--mIdx] = '\0';
		}
		else if (cmd == 'P') {
			char ch;
			(void)scanf("%c", &ch);
			(void)getchar();
			msg[mIdx++] = ch;
		}
	}
	for (int i = (tIdx-1); i >= 0; --i) {
		msg[mIdx++] = tmsg[i];
	} msg[mIdx] = '\0';
	printf("%s\n", msg);
	return 0;
}
#endif