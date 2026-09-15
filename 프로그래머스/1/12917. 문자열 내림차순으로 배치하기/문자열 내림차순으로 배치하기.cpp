#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s)
{
    string temp1 = "", temp2 = "";
    for(auto& ch : s) {
        if(ch>='A' && ch<='Z') {
            temp1 += ch;
        } else {
            temp2 += ch;
        }
    }
    sort(temp1.rbegin(), temp1.rend());
    sort(temp2.rbegin(), temp2.rend());
    string answer = temp2 + temp1;
    return answer;
}