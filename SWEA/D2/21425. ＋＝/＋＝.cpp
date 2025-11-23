#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
		int x, y, N; cin>>x>>y>>N;
        int cnt = 0;
        while(true){
            if(x>N||y>N) break;
            if(x<y) x+=y;
            else y+=x;
            cnt++;
        }
        cout<<cnt<<"\n";
	}
	return 0;
}