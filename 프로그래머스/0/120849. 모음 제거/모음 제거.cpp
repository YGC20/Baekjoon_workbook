#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(auto ms : my_string) {
        if(ms=='a' || ms=='e' || ms=='i' || ms=='o' || ms=='u') continue;
        else answer+=ms;
    }
    return answer;
}