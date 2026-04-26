#include <string>
#include <vector>
using namespace std;

int solution(string my_string, string is_prefix)
{
    int len = my_string.size();
    vector<string> prefix(len);
    for(int i=0; i<len; i++) {
        prefix[i] = my_string.substr(0,i);
    }
    
    bool checkPrefix = false;
    for(auto p : prefix) {
        if(p==is_prefix) checkPrefix = true;
    }
    return checkPrefix;
}