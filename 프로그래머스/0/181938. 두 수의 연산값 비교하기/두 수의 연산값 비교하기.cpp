#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int tmp1 = stoi(to_string(a)+to_string(b));
    int tmp2 = 2 * a * b;
    return (tmp1>=tmp2?tmp1:tmp2);
}