#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(auto q : quiz) {
        istringstream iss(q);
        string x, y, z;
        string op1, op2;
        iss>>x>>op1>>y>>op2>>z;
        if(op1=="+") {
            int a = stoi(x) + stoi(y);
            if(a==stoi(z)) answer.push_back("O");
            else answer.push_back("X");
        }
        else {
            int a = stoi(x) - stoi(y);
            if(a==stoi(z)) answer.push_back("O");
            else answer.push_back("X");
        }
    }
    return answer;
}