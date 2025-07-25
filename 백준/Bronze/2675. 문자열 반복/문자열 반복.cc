#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T, R;
    string S;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>R>>S;
        for(char s:S)
            for(int j=0;j<R;j++)
                cout<<s;
        cout<<"\n";
    }
    return 0;
}