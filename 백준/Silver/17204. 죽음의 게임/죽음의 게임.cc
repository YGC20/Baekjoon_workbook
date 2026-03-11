#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num, pos;
    cin>>num>>pos;
    vector<int> member(num);
    for(int i=0; i<num; ++i) {
        cin>>member[i];
    }

    int point = 0;
    int cnt = 0;
    while(point!=pos) {
        if(cnt>num) {
            cnt = -1;
            break;
        }
        point = member[point];
        cnt++;
    }

    cout<<cnt<<"\n";
    return 0;
}