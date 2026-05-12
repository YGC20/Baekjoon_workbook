#include <string>
#include <vector>
using namespace std;

bool isParallel(vector<int> d1, vector<int> d2, vector<int> d3, vector<int> d4) {
    long long dy1 = d2[1]-d1[1];
    long long dx1 = d2[0]-d1[0];
    long long dy2 = d4[1]-d3[1];
    long long dx2 = d4[0]-d3[0];
    return dy1*dx2 == dy2*dx1;
}

int solution(vector<vector<int>> dots)
{
    if(isParallel(dots[0], dots[1], dots[2], dots[3])) return 1;
    if(isParallel(dots[0], dots[2], dots[1], dots[3])) return 1;
    if(isParallel(dots[0], dots[3], dots[1], dots[2])) return 1;
    return 0;
}