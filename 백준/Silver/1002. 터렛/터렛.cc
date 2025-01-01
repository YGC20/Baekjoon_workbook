#include <iostream>
using namespace std;
int main(void){
	int t, x1, y1, r1, x2, y2, r2, result;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int distance = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
		int pr = (r1+r2)*(r1+r2);
		int mr = (r1-r2)*(r1-r2);
		if(distance==0 && r1==r2) result = -1;
		else if(distance==pr) result = 1;
		else if(distance==mr) result = 1;
		else if(mr<distance && distance<pr) result = 2;
		else result = 0;
		printf("%d\n", result);
	}
	return 0;
}