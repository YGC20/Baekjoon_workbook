#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction)
{
    int len = numbers.size();
    vector<int> result(len);
    for(int i=0; i<len; i++) {
        if(direction=="right") {
            result[(i+1)%len] = numbers[i];
        }
        else {
            result[(i-1+len)%len] = numbers[i];
        }
    }
    return result;
}