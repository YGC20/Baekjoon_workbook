#include <string>
#include <vector>
using namespace std;

int solution(string num_str)
{
    int sum = 0;
    for(auto ns : num_str) {
        sum += (ns-'0');
    }
    return sum;
}