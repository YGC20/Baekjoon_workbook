#include <iostream>
#include <vector>
using namespace std;

void solution(int testCase)
{
    int nIndex;
    cin>>nIndex;

    vector<vector<int>> box(nIndex, vector<int>(nIndex));
    for(int i=0; i<nIndex; ++i) {
        for(int j=0; j<nIndex; ++j) {
            cin>>box[i][j];
        }
    }

    int cnt = 0;
    vector<string> result(nIndex);
    // 90
    for(int j=0; j<nIndex; ++j) {
        string tmp = "";
        for(int i=(nIndex-1); i>=0; --i) {
            tmp+=to_string(box[i][j]);
        }
        tmp+=" ";
        result[cnt]+=tmp;
        cnt++;
    }
    cnt = 0;
    // 180
    for(int i=(nIndex-1); i>=0; --i) {
        string tmp ="";
        for(int j=(nIndex-1); j>=0; --j) {
            tmp+=to_string(box[i][j]);
        }
        tmp+=" ";
        result[cnt]+=tmp;
        cnt++;
    }
    cnt = 0;
    // 270
    for(int i=(nIndex-1); i>=0; --i) {
        string tmp = "";
        for(int j=0; j<nIndex; ++j) {
            tmp+=to_string(box[j][i]);
        }
        result[cnt]+=tmp;
        cnt++;
    }

    cout<<"#"<<testCase<<"\n";
    for(int i=0; i<nIndex; ++i) {
        cout<<result[i]<<"\n";
    }
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