#include <iostream>
using namespace std;

void solution(void);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin>>n;
    for(int i=0; i<n; ++i) {
        solution();
    }
    return 0;
}

void solution(void)
{
    int x, y, z;
    cin>>x>>y>>z;
    
    int a=-1, b=-1, c=-1;
    if(x==y && x==z && y==z) {
        a=x; b=x; c=x;
    }
    else {
        if(x==z && x>y) {
            a=x; b=y; c=y;
        }
        else if(x==y && x>z) {
            a=z; b=x; c=z-1;
        }
        else if(y==z && y>x) {
            a=x; b=x-1; c=y;
        }
    }
    cout<<a<<" "<<b<<" "<<c<<"\n";
}