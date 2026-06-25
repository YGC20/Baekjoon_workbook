#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    int len = s.length();
    int minLen = len;
    int i, j, k;
    string str = "";
    for (i = 1; i <= len; ++i) {
        string temp = "";
        int cNum = 0, cnt = 1;
        for (j = 0; j < (len-i); j += i) {
            for (k = j; k < (j + i); ++k) {
                str += s[k];
            }
            if (temp != str) {
                if (cnt != 1) cNum += to_string(cnt).length();
                cNum += temp.length();
                cnt = 1;
                temp = str;
            } else {
                cnt++;
            }
            str.clear();
        }
        for (k = j; k < len; ++k) {
            str += s[k];
        }
        if (temp != str) cNum += str.length();
        else cnt++;
        if (cnt != 1) cNum += to_string(cnt).length();
        cNum += temp.length();
        str.clear();

        if (cNum < minLen) minLen = cNum;
        temp.clear();
    }
    return minLen;
}