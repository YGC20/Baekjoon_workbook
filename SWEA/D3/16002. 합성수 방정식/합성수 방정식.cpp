#include<iostream>
#include<cmath>
using namespace std;

int solution(int testCase) {
    int N;
    cin>>N;
    
    int x = 0, y = 0;
    if(N%2==0) {
        y = 4;
        x = 4+N;
    }
    else {
        y = 9;
        x = 9+N;
    }
    
    cout<<"#"<<testCase<<" "<<x<<" "<<y<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase;
    if(cin>>testCase) {
        for(int i=1; i<=testCase; ++i) {
            solution(i);
        }
    }
    return 0;
}