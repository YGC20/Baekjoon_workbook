#include <string>
#include <vector>
using namespace std;

void makeNum(vector<int>& numbers, int& target, int sum, int idx, int& count)
{
    if(idx >= static_cast<int>(numbers.size())) {
        if(sum == target) { count++; }
        return;
    }
    makeNum(numbers, target, sum + numbers[idx], idx + 1, count);
    makeNum(numbers, target, sum - numbers[idx], idx + 1, count);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    makeNum(numbers, target, 0, 0, answer);
    return answer;
}