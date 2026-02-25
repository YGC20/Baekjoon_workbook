#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string.substr(0, s);
    string tmp = my_string.substr(s+overwrite_string.size());
    answer = answer+overwrite_string+tmp;
    return answer;
}