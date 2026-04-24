#include <string>
#include <vector>

using namespace std;

int solution(string number)
{
    int num = 0;
    for(char n : number) {
        num+=(n-'0');
    }
    return num%9;
}