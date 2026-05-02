#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int num = 0;
    int len = num_list.size();
    if(len>10) {
        for(auto nl : num_list) {
            num+=nl;
        }
    }
    else {
        num = 1;
        for(auto nl : num_list) {
            num*=nl;
        }
    }
    return num;
}