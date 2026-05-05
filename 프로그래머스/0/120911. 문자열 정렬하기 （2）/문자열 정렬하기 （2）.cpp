#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string)
{
    for(auto& ms : my_string) {
        if('A'<=ms && ms<='Z') ms = (ms-'A')+'a';
    }
    sort(my_string.begin(), my_string.end());
    return my_string;
}