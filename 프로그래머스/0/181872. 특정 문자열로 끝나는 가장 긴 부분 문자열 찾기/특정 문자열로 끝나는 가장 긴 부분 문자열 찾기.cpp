#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string myString, string pat)
{
    size_t idx = myString.rfind(pat);
    return myString.substr(0, idx+pat.length());
}