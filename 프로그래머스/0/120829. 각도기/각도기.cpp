#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    return ((90-angle)>=0)?(angle==90?2:1):(angle==180?4:3);
}