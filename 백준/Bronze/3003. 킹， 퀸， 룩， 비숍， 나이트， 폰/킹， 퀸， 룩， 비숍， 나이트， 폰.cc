#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> blackChesspiece = {1,1,2,2,2,8};
    vector<int> whiteChesspiece(6,0);

    for(int i=0; i<6; ++i) {
        cin>>whiteChesspiece[i];
    }

    for(int i=0; i<6; ++i) {
        cout<<(blackChesspiece[i]-whiteChesspiece[i])<<" ";
    }
    cout<<"\n";

    return 0;
}