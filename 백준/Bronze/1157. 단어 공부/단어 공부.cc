#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string S;
    cin>>S;
    vector<int> alpha(26,0);
    for(char c:S){
        if(c>='a'&&c<='z')  c=c-('a'-'A');
        alpha[c-'A']++;
    }
    int max=alpha[0];
    int result=0, count=0;
    for(int i=1;i<26;i++){
        if(alpha[i]>max){
            max=alpha[i];
            result=i;
        }    
    }
    for(int i=0;i<26;i++){
        if(max==alpha[i])   count++;
    }
    char answer='A'+result;
    if(count>1) cout<<"?\n";
    else    cout<<answer<<"\n";
    return 0;
}