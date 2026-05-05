#include <string>
#include <vector>
using namespace std;

int solution(string myString, string pat)
{
    for(auto& ms : myString) {
        if(ms=='A') ms='B';
        else ms='A';
    }
    return (myString.find(pat)!=string::npos);
}