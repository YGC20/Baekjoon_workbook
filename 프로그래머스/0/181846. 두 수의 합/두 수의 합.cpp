#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    string result = "";
    int x = a.length() - 1;
    int y = b.length() - 1;
    int digit = 0;
    
    while(x>=0 || y>=0 || digit>0) {
        int sum = digit;
        if(x>=0) sum += a[x--]-'0';
        if(y>=0) sum += b[y--]-'0';
        
        digit = sum/10;
        result += (sum%10) + '0';
    }
    reverse(result.begin(), result.end());
    return result;
}