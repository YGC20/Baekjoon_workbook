#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    for(auto& ms : myString) {
        if(ms=='a') ms = ms - 'a' + 'A';
        else if('B'<=ms && ms<='Z') ms = ms - 'A' + 'a';
    }
    return myString;
}