#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp)
{
    for(auto& ms : my_string) {
        if(ms==alp[0]) ms = ms - 'a' + 'A';
    }
    return my_string;
}