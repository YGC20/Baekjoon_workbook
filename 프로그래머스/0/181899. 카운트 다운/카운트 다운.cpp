#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> result;
    while(start_num>=end_num) {
        result.push_back(start_num--);
    }
    return result;
}