#include <iostream>

using namespace std;

void solution(int test_case, int l, int p, int v)
{
    int tmp1 = v/p*l;
    int tmp2 = v%p;
    if(tmp2!=0 && l<tmp2) {
        tmp2 = l;
    }
    int sum = tmp1 + tmp2;
    cout<<"Case "<<test_case<<": "<<sum<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l,p,v;
    int test_case = 1;
    while(true) {
        cin>>l>>p>>v;
        if(l==0 && p==0 && v==0) {
            break;
        }
        solution(test_case++,l,p,v);
    }

    return 0;
}