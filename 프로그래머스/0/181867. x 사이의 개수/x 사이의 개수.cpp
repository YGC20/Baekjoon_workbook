#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(string myString)
{
    vector<int> result;
    istringstream iss(myString);
    string token;
    while(getline(iss, token, 'x')) {
        result.push_back(token.length());
    }
    if(token.empty())
        result.push_back(token.length());
    return result;
}