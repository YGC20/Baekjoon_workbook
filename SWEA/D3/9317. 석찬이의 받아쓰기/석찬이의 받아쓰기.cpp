#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int TC;	cin>>TC;
	for(test_case = 1; test_case <= TC; ++test_case)
	{
        int N; cin>>N;
        string correct, answer;
        cin>>correct; cin>>answer;
        int cnt=0;
        for(int i=0;i<N;++i)
        {
            if(correct[i]==answer[i]) cnt++;
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}