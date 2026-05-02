#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    for(auto& ms : myString) {
        if('A'<=ms && ms<='Z')
            ms = ms - 'A' + 'a';
    }
    for(auto& p : pat) {
        if('A'<=p && p<='Z')
            p = p - 'A' + 'a';
    }
    
    return myString.find(pat)!=string::npos;
}