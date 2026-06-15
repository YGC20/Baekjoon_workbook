#include<iostream>
#define MAX_N (10+5)
using namespace std;

int N, result;
int col[MAX_N] = {0};
int up[MAX_N*2] = {0};
int down[MAX_N*2] = {0};

void queenDFS(int row)
{
    if(row>N) {
        result++;
        return;
    }
    for(int i=1; i<=N; ++i) {
        if(col[i] || up[row+i] || down[row-i+N]) continue;
        col[i] = up[row+i] = down[row-i+N] = 1;
        queenDFS(row+1);
        col[i] = up[row+i] = down[row-i+N] = 0;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
        cin>>N;
        result = 0;
        queenDFS(1);
        cout<<"#"<<test_case<<" "<<result<<"\n";
	}
	return 0;
}