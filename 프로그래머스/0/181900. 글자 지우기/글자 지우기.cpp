#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, vector<int> indices) {
    string result = "";
    int idx = 0;
    sort(indices.begin(), indices.end());
    for(int i=0; i<my_string.size(); i++) {
        if(i==indices[idx]) {
            idx++;
        }
        else {
            result+=my_string[i];
        }
    }
    return result;
}