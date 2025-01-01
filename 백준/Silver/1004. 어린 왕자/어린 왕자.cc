#include <iostream>
using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		int x1, y1, x2, y2, n, count;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		count = 0;
		for(int j=0; j<n; j++){
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			if(((x1-x)*(x1-x)+(y1-y)*(y1-y) < r*r) != ((x2-x)*(x2-x)+(y2-y)*(y2-y) < r*r)) count++;
		}
		printf("%d\n", count);
	}
	return 0;
}