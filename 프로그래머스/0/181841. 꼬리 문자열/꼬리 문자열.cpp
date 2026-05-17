#include <string>
#include <vector>
using namespace std;

string solution(vector<string> str_list, string ex)
{
    string answer = "";
    for(auto sl : str_list) {
        if(sl.find(ex)==string::npos) {
            answer+=sl;
        }
    }
    return answer;
}