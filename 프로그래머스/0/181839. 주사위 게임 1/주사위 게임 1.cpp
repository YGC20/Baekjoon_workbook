#include <string>
#include <vector>
using namespace std;

int solution(int a, int b)
{
    bool checkA = (a%2!=0);
    bool checkB = (b%2!=0);
    
    if(checkA && checkB) {
        return (a*a+b*b);
    }
    else if(!checkA && !checkB) {
        return ((a-b)>0?a-b:b-a);
    }
    else {
        return 2*(a+b);
    }
}