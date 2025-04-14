#include <iostream>
#include <string>
using namespace std;
int main(void){
    string text, word;
    getline(cin, text);
    getline(cin, word);
    int count=0;
    for(int i=0; i<text.length(); ++i){
        bool flag=true;
        for(int j=0; j<word.length(); ++j){
            if(text[i+j]!=word[j]){
                flag=false;
                break;
            }
        }
        if(flag){
            count++;
            i+=word.length()-1;
        }
    }
    cout<<count<<endl;
    return 0;
}