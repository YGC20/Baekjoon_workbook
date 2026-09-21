#include <iostream>
#include <string>
#include <vector>
using namespace std;

void threeMusketeers(vector<int>& num, int& group, 
    int idx, int cnt, int sum)
{
    if(cnt == 3) {
        if(sum == 0) { group++; }
        return;
    }
    if(idx >= (int)num.size()) { return; }
    threeMusketeers(num, group, idx+1, cnt+1, sum + num[idx]);
    threeMusketeers(num, group, idx+1, cnt, sum);
    return;
}

int solution(vector<int> num)
{
    int answer = 0;
    threeMusketeers(num, answer, 0, 0, 0);
    return answer;
}