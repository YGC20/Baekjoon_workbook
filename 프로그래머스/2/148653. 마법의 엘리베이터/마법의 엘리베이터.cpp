#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int storey)
{
    int lastDigit = 0, nextDigit = 0, cnt = 0;
    while(storey > 0) {
        lastDigit = storey % 10;
        nextDigit = (storey / 10) % 10;
        
        if(lastDigit > 5 || (lastDigit == 5 && nextDigit >= 5)) {
            storey += (10 - lastDigit);
        } else {
            storey -= lastDigit;
        }
        
        storey /= 10;
        cnt += min(lastDigit, 10-lastDigit);
    }
    return cnt;
}