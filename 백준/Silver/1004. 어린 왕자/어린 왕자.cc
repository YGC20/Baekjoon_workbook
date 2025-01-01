#include <iostream>
using namespace std;

int main(void){
	int t, x1, y1, x2, y2, n;
	int x, y, r, check1, check2, count;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		count = 0;
		for(int j=0; j<n; j++){
			scanf("%d %d %d", &x, &y, &r);
			check1 = (x1-x)*(x1-x)+(y1-y)*(y1-y) < r*r;
			check2 = (x2-x)*(x2-x)+(y2-y)*(y2-y) < r*r;
			if(check1 != check2) count++;
		}
		printf("%d\n", count);
	}
	return 0;
}