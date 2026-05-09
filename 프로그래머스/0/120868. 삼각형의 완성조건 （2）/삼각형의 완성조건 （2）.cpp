#include <string>
#include <vector>
using namespace std;

int solution(vector<int> sides)
{
    int cnt = 0;
    int b = sides[0]>sides[1]?sides[0]:sides[1];
    int s = sides[0]<sides[1]?sides[0]:sides[1];
    
    for(int i=1; i<=b; i++) {
        if(b<i+s) cnt++;
    }
    for(int i=b+1; i<(b+s); i++) {
        cnt++;
    }
    
    return cnt;
}