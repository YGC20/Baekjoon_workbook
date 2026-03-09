#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int len;
    if(!(cin>>len)) {
        return 0;
    }

    string train;
    cin>>train;
    int cnt = 0;
    for(int i=0; i<len-1; ++i) {
        if(train[i]=='[') {
            cnt+=1;
        }
        else if(train[i]=='2' || train[i]=='5') {
            if(train[i]==train[i+1]) {
                cnt+=1;
            }
            cnt+=1;
        }
        else if(train[i]==']') {
            if(!(train[i+1]=='[')) {
                cnt+=1;
            }
        }
    }

    cout<<cnt<<"\n";
    return 0;
}