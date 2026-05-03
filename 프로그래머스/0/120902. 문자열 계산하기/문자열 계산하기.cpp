#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(string my_string) {
    istringstream iss(my_string);
    
    
    string tmp;
    int result = 0;
    
    iss>>result;
    
    string op;
    int nextNum;
    while(iss>>op>>nextNum) {
        if(op=="+") {
            result+=nextNum;
        }
        else if(op=="-") {
            result-=nextNum;
        }
    }
    
    return result;
}