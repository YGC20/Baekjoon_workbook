#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string result = "";
    
    int len = my_strings.size();
    for(int i=0; i<len; i++) {
        int startIndex = parts[i][0];
        int cutLength = parts[i][1]-parts[i][0]+1;
        result+=my_strings[i].substr(startIndex, cutLength);
    }
    return result;
}