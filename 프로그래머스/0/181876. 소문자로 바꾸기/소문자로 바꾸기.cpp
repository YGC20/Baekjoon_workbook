#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    for(auto& ms : myString) {
        if('A'<=ms && ms<='Z')
            ms = (ms - 'A') + 'a';
    }
    return myString;
}