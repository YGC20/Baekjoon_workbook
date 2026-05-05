#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string binomial)
{
    istringstream iss(binomial);
    string a, b, op;
    iss>>a>>op>>b;
    if(op=="+") {
        return stoi(a)+stoi(b);
    }
    else if(op=="-") {
        return stoi(a)-stoi(b);
    }
    else if(op=="*") {
        return stoi(a)*stoi(b);
    }
}