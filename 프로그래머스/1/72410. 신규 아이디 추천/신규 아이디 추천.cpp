#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string newId; newId.reserve(new_id.size());
    for(char c:new_id) newId.push_back(static_cast<char>(tolower(static_cast<unsigned char>(c))));
    
    {
        string tmp; tmp.reserve(newId.size());
        for(char c:newId)
            if(('a'<=c&&c<='z')||('0'<=c&&c<='9')||c=='-'||c=='_'||c=='.')
                tmp.push_back(c);
        newId.swap(tmp);
    }
    {
        string tmp; tmp.reserve(newId.size());
        bool ld = false;
        for(char c:newId){
            if(c=='.'){
                if(!ld){
                    tmp.push_back('.');
                    ld = true;
                }
            }
            else{
                tmp.push_back(c);
                ld = false;
            }
        }
        newId.swap(tmp);
    }
    if(!newId.empty()&&newId.front()=='.') newId.erase(newId.begin());
    if(!newId.empty()&&newId.back()=='.') newId.pop_back();
    if(newId.empty()) newId = "a";
    if(newId.size()>15) newId.resize(15);
    if(!newId.empty()&&newId.back()=='.') newId.pop_back();
    while(newId.size()<3) newId.push_back(newId.back());
    return newId;
}