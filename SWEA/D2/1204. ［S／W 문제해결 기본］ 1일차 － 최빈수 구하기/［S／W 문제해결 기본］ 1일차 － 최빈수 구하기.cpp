#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
        int testNumber; cin>>testNumber;
        cin.ignore(256,'\n');
        map<int,int> num;
        string line; getline(cin,line);
        stringstream ss(line); string token;
        while(ss>>token)
            num[stoi(token)]++;
        int idx = 0, bigNum = 0;
        for(auto m:num){
            if(bigNum<=m.second){
                bigNum = m.second;
                idx = m.first;
            }
        }
        cout<<"#"<<test_case<<" "<<idx<<"\n";
    }
	return 0;
}