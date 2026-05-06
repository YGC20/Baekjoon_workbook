#include <string>
#include <vector>
using namespace std;

int solution(vector<int> array)
{
    int cnt = 0;
    for(int num : array) {
        string tmp = to_string(num);
        for(auto n : tmp)
            if(n=='7') cnt++;
    }
    return cnt;
}