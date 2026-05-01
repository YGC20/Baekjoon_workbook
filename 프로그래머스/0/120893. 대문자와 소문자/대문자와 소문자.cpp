#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    for(auto& ms : my_string) {
        if('A'<=ms && ms<='Z')
            ms = (ms-'A')+'a';
        else if('a'<=ms && ms<='z')
            ms = (ms-'a')+'A';
    }
    return my_string;
}