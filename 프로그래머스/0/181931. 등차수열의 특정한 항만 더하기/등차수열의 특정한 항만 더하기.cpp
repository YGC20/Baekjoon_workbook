#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int sum = 0;
    for(bool i : included) {
        if(i) {
            sum+=a;
        }
        a+=d;
    }
    return sum;
}