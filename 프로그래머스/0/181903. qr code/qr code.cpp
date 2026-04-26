#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code)
{
    string result = "";
    for(int i=0; i<code.size(); i+=q) {
        if(i+r<code.size())
            result+=code[i+r];
    }
    return result;
}