#include <string>
#include <vector>
using namespace std;

string solution(string my_string) {
    vector<bool> visited(53, false);
    
    int idx = 0;
    string answer = "";
    for(auto ms : my_string) {
        if('A'<=ms && ms<='Z')
            idx = ms - 'A';
        else if('a'<=ms && ms<='z')
            idx = ms - 'a' + 26;
        else if(ms==' ')
            idx = 52;
        if(!visited[idx]) {
            answer+=ms;
            visited[idx] = true;
        }
    }
    return answer;
}