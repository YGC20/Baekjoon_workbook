#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr)
{
    for(int i=0; i<strArr.size(); i++) {
        if((i+1)%2==0) {
            for(auto& sa : strArr[i]) {
                if('a'<=sa && sa<='z')
                    sa = sa - 'a' + 'A';
            }
        }
        else {
            for(auto& sa : strArr[i]) {
                if('A'<=sa && sa<='Z')
                    sa = sa - 'A' + 'a';
            }
        }
    }
    return strArr;
}