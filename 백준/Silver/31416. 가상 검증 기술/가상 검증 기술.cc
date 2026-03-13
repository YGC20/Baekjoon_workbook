#include <iostream>
#include <algorithm>
using namespace std;

void solution(int test_case);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    if(cin>>test_case) {
        solution(test_case);
    }
    return 0;
}

void solution(int test_case)
{
    for(int i=0; i<test_case; ++i) {
        int ta, tb, va, vb;
        cin>>ta>>tb>>va>>vb;
        int timeA = ta*va;
        int timeB = tb*vb;
        if(timeA>=timeB) {
            while((timeA-timeB)>=ta) {
                timeA-=ta;
                timeB+=ta;
            }
        }
        cout<<max(timeA, timeB)<<"\n";
    }
}