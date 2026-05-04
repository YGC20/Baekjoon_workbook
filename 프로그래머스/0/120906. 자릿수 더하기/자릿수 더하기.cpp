#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    for(auto num : to_string(n)) {
        answer+=(num-'0');
    }
    return answer;
}