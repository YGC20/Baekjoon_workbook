#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int len = num_list.size();
    int a = num_list[len-1];
    int b = num_list[len-2];
    num_list.push_back((a>b?a-b:a*2));
    return num_list;
}