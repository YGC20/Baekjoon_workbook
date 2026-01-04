#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N; cin>>N;
        bool visited[10]={false};
        int visited_cnt=0;
        int upNum=1;
        while(visited_cnt<10)
        {
           	int num_tmp=upNum*N;
            string str_tmp=to_string(num_tmp);
            for(char st:str_tmp)
            {
                int num=st-'0';
                if(!visited[num])
                {
                    visited[num]=true;
                    visited_cnt++;
                }
            }
            upNum++;
        }
        cout<<"#"<<test_case<<" "<<(--upNum)*N<<"\n";
    }
	return 0;
}