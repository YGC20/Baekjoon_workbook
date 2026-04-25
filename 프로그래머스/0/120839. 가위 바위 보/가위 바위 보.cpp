#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(string rsp) {
    unordered_map<char, string> rspList = {
        {'2',"0"}, {'0',"5"}, {'5',"2"}
    };
    string answer = "";
    for(auto i : rsp) {
        answer+=rspList[i];
    }
    return answer;
}