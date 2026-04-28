#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    while(n%2==0) {
        n/=2;
        answer.push_back(2);
    }
    for(int i=3; i*i<=n; i+=2) {
        while(n%i==0) {
            n/=i;
            answer.push_back(i);
        }
    }
    if(n>2) {
        answer.push_back(n);
    }
    answer.erase(unique(answer.begin(), answer.end()),answer.end());
    return answer;
}