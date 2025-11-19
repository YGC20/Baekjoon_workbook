#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
        int days; cin>>days;
        vector<int> week(days,0);
        for(int i=0;i<days;++i)
            cin>>week[i];
        long long price = 0, bigDay = week[days-1];
        for(int i=days-2;i>=0;--i){
            if(bigDay>week[i])
                price+=(bigDay-week[i]);
            else
                bigDay = week[i];
        }
        cout<<"#"<<test_case<<" "<<price<<"\n";
	}
	return 0;
}