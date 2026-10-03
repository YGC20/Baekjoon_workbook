#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> um;
    for(auto& p : participant) { um[p]++; }
    for(auto& c : completion) { um[c]--; }
    
    string answer = "";
    for(auto& pc : um) {
        if(pc.second != 0) { answer = pc.first; }
    }
    return answer;
}