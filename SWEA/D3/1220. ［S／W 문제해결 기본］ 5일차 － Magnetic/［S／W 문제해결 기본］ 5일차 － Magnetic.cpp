#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n = 0;
        cin>>n; // n은 100으로 고정
        vector<vector<int>> maps(n,vector<int>(n));
        for(int j=0;j<n;++j)
        {
            for(int i=0;i<n;++i)
            {
                cin>>maps[i][j];
            }
        }
        int cnt = 0;
        for(int i=0;i<n;++i)
        {
            bool flag = false;
            for(int j=0;j<n;++j)
            {
                if(maps[i][j]==2 && flag)
                {
                    cnt++;
                    flag = false;
                }
                else if(maps[i][j]==1)
                {
                    flag = true;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}