#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(string my_string)
{
    vector<string> result;
    for(int i=0; i<my_string.size(); i++) {
        result.push_back(my_string.substr(i));
    }
    sort(result.begin(), result.end());
    return result;
}