#include <string>
#include <vector>
#include <charconv>
#include <string_view>
using namespace std;

string solution(int n, int t, int m, int p)
{
    char buffer[20];
    int i, num = 0;
    string nNum = "", temp = "";
    int len = 0, tmLen = t * m;
    while(len < tmLen) {
        auto [ptr, ec] = to_chars(buffer, buffer + sizeof(buffer), num, n);
        string_view temp(buffer, ptr);
        nNum += temp;
        len += temp.length();
        num++;
    }
    
    string result = "";
    for(i=p-1; i<(t*m+1); i+=m) {
        if(!isdigit(nNum[i])) { nNum[i] = toupper(nNum[i]); }
        result += nNum[i];
    }
    result.resize(t);
    return result;
}