#include <string>
#include <vector>
using namespace std;

int solution(int num, int k)
{
    string number = to_string(num);
    for(int i=0; i<number.size(); i++) {
        int result = number[i]-'0';
        if(k==result) return i+1;
    }
    return -1;
}