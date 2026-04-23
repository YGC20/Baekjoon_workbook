#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    int len = end_num - start_num + 1;
    vector<int> answer(len);
    for(int i=0; i<len; i++) {
        answer[i] = start_num++;
    }
    return answer;
}