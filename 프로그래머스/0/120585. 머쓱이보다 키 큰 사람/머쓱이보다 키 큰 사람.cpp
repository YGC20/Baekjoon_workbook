#include <string>
#include <vector>
using namespace std;

int solution(vector<int> array, int height)
{
    int cnt = 0;
    for(auto num : array) {
        if(height<num) cnt++;
    }
    return cnt;
}