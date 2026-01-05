#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string num; cin>>num;
        int cnt=0;
        bool visited[10]={false};
        for(char n:num)
        {
            int curNum=n-'0';
            if(!visited[curNum])
            {
                visited[curNum]=true;
                cnt++;
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
    }
	return 0;
}