#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal(10, vector<int>(10));
void makePascal(void)
{
    for(int i=0; i<10; ++i) {
        for(int j=0; j<=i; ++j) {
            if(j==0 || i==j) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }
}
void solution(int testCase)
{
    int nSize = 0;
    cin>>nSize;
    
    cout<<"#"<<testCase<<"\n";
    for(int i=0; i<nSize; ++i) {
        for(int j=0; j<=i; ++j) {
            cout<<pascal[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    if(cin>>testCase) {
        makePascal();
        for(int i=1; i<=testCase; ++i){
            solution(i);
        }
    }
    return 0;
}