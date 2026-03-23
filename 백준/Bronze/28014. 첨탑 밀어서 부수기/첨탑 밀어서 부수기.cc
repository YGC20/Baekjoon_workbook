#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cnt = 0, last = 0;
    cin>>n;
    for(int i=0; i<n; ++i) {
        int tower;
        cin>>tower;

        if(tower>=last) {
            cnt++;
        }
        last = tower;
    }
    cout<<cnt<<"\n";
    return 0;
}