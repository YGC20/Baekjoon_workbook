#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> solution(string s)
{
    int i;
    vector<vector<int>> sets;
    vector<int> currSet;
    string temp = "";
    for(i=1; i<s.length()-1; ++i) {
        char ch = s[i];
        if(ch == '{') { currSet.clear(); }
        else if(isdigit(ch)) { temp += ch; }
        else if(ch == ',' || ch == '}') {
            if(!temp.empty()) {
                currSet.push_back(stoi(temp));
                temp = "";
            }
            if(ch == '}') { sets.push_back(currSet); }
        }
    }
    
    sort(sets.begin(), sets.end(), 
         [](const vector<int>& a, const vector<int>& b)
         { return a.size() < b.size(); });
    
    vector<int> result;
    unordered_set<int> uos;
    for(const auto& vec : sets) {
        for(int num : vec) {
            if(uos.find(num) == uos.end()) {
                uos.insert(num);
                result.push_back(num);
                break;
            }
        }
    }
    return result;
}