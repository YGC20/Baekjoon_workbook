#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n)
{
    int num = sqrt(n);
    if(n==(num*num)) return 1;
    else return 2;
}