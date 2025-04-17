#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string a, string b){
    if(a.length()==b.length())
        return a<b;
    else
        return a.length()<b.length();
}
int main(void){
    int i, N;
    string word;
    set<string> textList;
    cin>>N;
    for(i=0; i<N; i++){
        cin>>word;
        textList.insert(word);
    }
    vector<string> wordList(textList.begin(),textList.end());
    sort(wordList.begin(),wordList.end(),compare);
    for(const string& text : wordList)
        cout<<text<<"\n";
    return 0;
}