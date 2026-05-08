#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> dots)
{
    int x1 = dots[0][0], x2 = dots[0][0];
    int y1 = dots[0][1], y2 = dots[0][1];
    
    for(auto dot : dots) {
        x1 = min(x1, dot[0]);
        x2 = max(x2, dot[0]);
        y1 = min(y1, dot[1]);
        y2 = max(y2, dot[1]);
    }
    return (x2-x1) * (y2-y1);
}