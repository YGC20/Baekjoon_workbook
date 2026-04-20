#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int result = 1;
    while((6*result)%n!=0) {
        result++;
    }
    return result;
}