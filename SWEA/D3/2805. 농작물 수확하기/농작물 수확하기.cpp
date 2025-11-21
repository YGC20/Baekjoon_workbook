#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
        int n; cin>>n;
        vector<string> farm(n);
        for(int i=0;i<n;++i)
            cin>>farm[i];
        int midX = n/2, midY =n/2;
        int sum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int dist = abs(i-midX) + abs(j-midY);
                if(dist <= n/2) sum+= (farm[i][j]-'0');
            }
        }
        cout<<"#"<<test_case<<" "<<sum<<"\n";
    }
	return 0;
}