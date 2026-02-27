#include <iostream>

using namespace std;

void solution(long long test_case)
{
    long long counter = 0;
    long long num = 1;
    
    while(test_case>=num) {
        test_case-=num;
        num++;
        counter++;
    }

    cout<<counter<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long test_case;
    if(cin>>test_case) {
        solution(test_case);
    }

    return 0;
}