#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int arr[6] = {0};
        int sum = 0, max = 0;
        for(int i=0;i<6;++i) {
            cin>>arr[i];
            sum+=arr[i];
            if(max<arr[i])
                max = arr[i];
        }
        int h = sum+max+1;
        while(true) {
            if(h%7==0) {
                cout<<h-sum<<"\n";
                break;
            }
            h++;
        }
	}
	return 0;
}