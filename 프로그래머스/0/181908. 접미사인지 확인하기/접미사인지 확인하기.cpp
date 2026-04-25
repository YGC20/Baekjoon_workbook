#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix)
{
    vector<string> lastStr;
    for(int i=0; i<my_string.size(); i++)
        lastStr.push_back(my_string.substr(i));
    
    bool result = false;
    for(auto ls : lastStr) {
        if(ls==is_suffix) result = true;
    }
    return result;
}