#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    int startIndex = my_string.size()-n;
    return my_string.substr(startIndex);
}