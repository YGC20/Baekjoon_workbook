#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string num = to_string(n);
    int numSize = num.size();
    for(int i=numSize-1;i>=0;--i){
        answer.push_back(num[i]-'0');
    }
    return answer;
}