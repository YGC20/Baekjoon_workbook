#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string)
{
    vector<int> result(52, 0);
    for(auto ms : my_string) {
        if('A'<=ms && ms<='Z') {
            result[ms-'A']++;
        }
        if('a'<=ms && ms<='z') {
            result[ms-'a'+26]++;
        }
    }
    return result;
}