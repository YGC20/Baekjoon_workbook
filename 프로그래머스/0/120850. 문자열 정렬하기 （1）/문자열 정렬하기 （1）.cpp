#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for(auto ms : my_string) {
        if('0'<=ms && ms<='9') {
            answer.push_back(ms-'0');
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}