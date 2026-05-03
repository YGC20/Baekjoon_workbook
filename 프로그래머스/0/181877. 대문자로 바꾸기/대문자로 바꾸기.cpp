#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for(auto& ms : myString) {
        if('a'<=ms && ms<='z')
            ms = (ms - 'a') + 'A';
    }
    return myString;
}