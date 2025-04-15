#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main(void){
    string sona;
    cin>>sona;
    regex pattern("(100+1+|01)+");
    if(regex_match(sona,pattern))
        cout<<"SUBMARINE"<<endl;
    else
        cout<<"NOISE"<<endl;
    return 0;
}