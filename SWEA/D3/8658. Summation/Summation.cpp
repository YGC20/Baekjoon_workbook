#include<iostream>
#include<climits>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int max=INT_MIN, min=INT_MAX;
        for(int i=0;i<10;++i)
        {
            string tmp="";
            cin>>tmp;
            int tmpSum=0;
            for(char t:tmp)
            {
                tmpSum+=t-'0';
            }
            if(tmpSum>max)
            {
                max=tmpSum;
            }
            if(tmpSum<min)
            {
                min=tmpSum;
            }
        }
        cout<<"#"<<test_case<<" "<<max<<" "<<min<<"\n";
	}
	return 0;
}