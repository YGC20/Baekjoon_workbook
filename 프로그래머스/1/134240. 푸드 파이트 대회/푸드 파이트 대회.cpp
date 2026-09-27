#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food)
{
    string str1 = "";
    for(int i=1; i<food.size(); ++i) {
        int l = food[i] / 2;
        for(int n=0; n<l; ++n) {
            str1.push_back((i + '0'));    
        }
    }
    string answer = "";
    answer += str1;
    answer += "0";
    reverse(str1.begin(), str1.end());
    answer += str1;
    return answer;
}