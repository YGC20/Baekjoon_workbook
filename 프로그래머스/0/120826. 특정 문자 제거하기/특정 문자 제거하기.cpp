#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my_string, string letter) {
    size_t pos = 0;
    size_t len = letter.size();
    
    while((pos = my_string.find(letter, pos)) != string::npos) {
        my_string.erase(pos, len);
    }
    
    return my_string;
}