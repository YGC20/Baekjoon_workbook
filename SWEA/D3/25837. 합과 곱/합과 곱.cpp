#include<iostream>
using namespace std;

void solution(void) {
    bool check = false;
    long long sum, mult;
    cin>>sum>>mult;
    for(long long i=1; i*i<=mult; ++i) {
    	if(mult%i==0) {
        	long long n = i;
            long long m = mult/i;
            if(sum==(n+m)) {
                check = true;
                break;
            }
        }
    }
    cout<<(check ? "Yes\n" : "No\n");
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase;
    if(cin>>testCase) {
        for(int i=0; i<testCase; ++i) {
            solution();
        }
    }
    return 0;
}