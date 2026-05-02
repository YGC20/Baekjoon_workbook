#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    char first = my_string[num1];
    char second = my_string[num2];
    my_string[num1] = second;
    my_string[num2] = first;
    return my_string;
}