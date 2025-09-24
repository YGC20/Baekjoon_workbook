#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
string solution(string s) {
    vector<int> S;
    stringstream ss;
    string num;
    ss.str(s);
    while(ss>>num) S.push_back(stoi(num));
    sort(S.begin(),S.end());
    string answer = "";
    answer+=to_string(S.front());
    answer+=" ";
    answer+=to_string(S.back());
    return answer;
}