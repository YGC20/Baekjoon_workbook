#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string S,B,T;
    cin>>S>>B;
    int B_len=B.length();
    for(char s:S){
        T.push_back(s);
        if(T.length()>=B_len){
            bool flag=true;
            for(int i=0;i<B_len;i++){
                if(T[T.length()-B_len+i]!=B[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)    T.erase(T.end()-B_len,T.end());
        }
    }
    if(T.empty())   cout<<"FRULA\n";
    else    cout<<T<<"\n";
    return 0;
}