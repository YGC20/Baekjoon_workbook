#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
		int n,m; cin>>n>>m;
        int flyIndex[n][n];
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                cin>>flyIndex[i][j];
        int smallBox = n-m+1;
        int maxFly = 0;
        for(int i=0;i<smallBox;++i){ 
            for(int j=0;j<smallBox;++j){
                int sum = 0;
                for(int x=i;x<i+m;++x){ 
                    for(int y=j;y<j+m;++y){
                        sum += flyIndex[x][y];
                    }
                }
                if(maxFly<sum) maxFly = sum;
            }
        }
        cout<<"#"<<test_case<<" "<<maxFly<<"\n";
	}
	return 0;
}