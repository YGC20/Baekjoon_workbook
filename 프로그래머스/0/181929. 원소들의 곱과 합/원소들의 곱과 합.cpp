#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int mult = 1;
    int sum = 0;
    for(int n : num_list) {
        mult*=n;
        sum+=n;
    }
    return (mult<(sum*sum));
}