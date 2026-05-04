#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist)
{
    vector<int> answer;
    for(auto nl : numlist) {
        if(nl%n==0) answer.push_back(nl);
    }
    return answer;
}