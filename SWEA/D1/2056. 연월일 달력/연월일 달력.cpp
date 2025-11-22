#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
		string arr; cin>>arr;
        string year = arr.substr(0,4);
        string month = arr.substr(4,2);
        string day = arr.substr(6,2);
        int imonth = stoi(month);
        int iday = stoi(day);
        bool flag = false;
        if(0<imonth && imonth<13){
            if(imonth == 2){
                if(0<iday && iday<29) flag = true;
            }
            else if(imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11){
                if(0<iday && iday<31) flag = true;
            }
            else{
            	if(0<iday && iday<32) flag = true;
            }
        }
        cout<<"#"<<test_case<<" ";
        if(flag)
            cout<<year<<"/"<<month<<"/"<<day<<"\n";
        else
            cout<<"-1"<<"\n";
	}
	return 0;
}