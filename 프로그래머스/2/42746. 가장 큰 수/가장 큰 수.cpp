#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    vector<string> num;
    for(auto n:numbers)
        num.push_back(to_string(n));
    sort(num.begin(),num.end(),cmp);
    if(num.at(0)=="0") return "0";
    string answer = "";
    for(auto n:num)
        answer+=n;
    return answer;
}