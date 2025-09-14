#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<pair<string,string>> orders;
    map<string,string> users;
    for(string ro:record){
        stringstream ss(ro);
        string word;
        vector<string> words;
        while(ss>>word) words.push_back(word);
        orders.push_back({words[0],words[1]});
        if(words.size()>=3) users[words[1]]=words[2];
    }
    vector<string> answer;
    for(pair<string,string> ou:orders){
        if(ou.first=="Enter"){
            answer.push_back(users[ou.second]+"님이 들어왔습니다.");
        }
        else if(ou.first=="Leave"){
            answer.push_back(users[ou.second]+"님이 나갔습니다.");
        }
    }
    return answer;
}