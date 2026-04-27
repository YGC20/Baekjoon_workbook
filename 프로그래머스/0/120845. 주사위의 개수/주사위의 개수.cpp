#include <string>
#include <vector>
using namespace std;

int solution(vector<int> box, int n) {
    int result = 1;
    for(auto b : box) {
        result *= (b/n);
    }
    return result;
}