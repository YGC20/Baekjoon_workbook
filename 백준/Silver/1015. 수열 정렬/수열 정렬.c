#include <stdio.h>

int N, i, j;
void sort(int list[], int index[]){
	int tempV, tempI;
	for(i=N-1; i>0; i--)
		for(j=0; j<i; j++)
			if(list[j] > list[j+1]){
				tempV = list[j];
				list[j] = list[j+1];
				list[j+1] = tempV;

				tempI = index[j];
				index[j] = index[j+1];
				index[j+1] = tempI;
			}
}

void nondecreasing(){
	scanf("%d", &N);
	int values[N], indices[N], result[N];
	for(i=0; i<N; i++){
		scanf("%d", &values[i]);
		indices[i] = i;
	}
	sort(values, indices);
	for(i=0; i<N; i++){ result[indices[i]] = i; }
	for(i=0; i<N; i++){ printf("%d ", result[i]); }
	printf("\n");
}

int main(void){
	nondecreasing();
	return 0;
}