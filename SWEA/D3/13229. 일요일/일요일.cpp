#include<iostream>
#include<map>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;	cin>>T;
    map<string,int> m = {{"MON",1},{"TUE",2},{"WED",3},{"THU",4},{"FRI",5},{"SAT",6},{"SUN",7}};
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string S; cin>>S;
        int cnt=0;
        auto idx=m.find(S); 
        if(idx!=m.end())
        {
            int s=idx->second;
            cnt=7-s;
        }
        if(cnt==0) cnt=7;
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}