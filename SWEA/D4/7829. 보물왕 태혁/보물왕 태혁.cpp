#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case = 1;
	int T;
	cin>>T;
	for(; test_case <= T; ++test_case)
	{
        int P= 0;
        cin>>P;
        long long password = 0;
        if(P<=1)
        {
            int num = 0;
            cin>>num;
            password = num*num;
        }
        else
        {
            int max = 0;
            int min = 1000001;
            for(int i=0; i<P; ++i)
            {
                int tmp = 0;
                cin>>tmp;
                if(tmp>max)
                {
                    max = tmp;
                }
                if(tmp<min)
                {
                    min = tmp;
                }
            }
            password = max*min;
        }
        cout<<"#"<<test_case<<" "<<password<<"\n";
	}
	return 0;
}