#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    istringstream iss(my_string);
    string tmp;
    while(iss>>tmp)
        answer.push_back(tmp);
    return answer;
}