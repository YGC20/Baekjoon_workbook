#include <string>
#include <vector>
using namespace std;

int solution(string my_string)
{
    int sum = 0;
    int tmp = 0;
    for(auto ms : my_string) {
        if('0'<=ms && ms<='9') {
            if(tmp!=0) tmp*=10;
            tmp+=(ms-'0');
        }
        else {
            sum += tmp;
            tmp = 0;
        }
    }
    return sum += tmp;
}