#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2)
{
    int i;
    int lenOne = str1.length();
    int lenTwo = str2.length();
    vector<string> setOne;
    vector<string> setTwo;
    
    for(i=0; i<lenOne; ++i) {
        if(str1[i]>='A' && str1[i]<='Z') {
            str1[i] = (str1[i] - 'A') + 'a';
        }
    }
    for(i=0; i<lenTwo; ++i) {
        if(str2[i]>='A' && str2[i]<='Z') {
            str2[i] = (str2[i] - 'A') + 'a';
        }
    }
    
    for(i=0; i<(lenOne-1); ++i) {
        if((str1[i]<'a' || str1[i]>'z') || (str1[i+1]<'a' || str1[i+1]>'z')) {
            continue;
        }
        setOne.push_back(str1.substr(i,2));
    }
    for(i=0; i<(lenTwo-1); ++i) {
        if((str2[i]<'a' || str2[i]>'z') || (str2[i+1]<'a' || str2[i+1]>'z')) {
            continue;
        }
        setTwo.push_back(str2.substr(i,2));
    }
    
    sort(setOne.begin(), setOne.end());
    sort(setTwo.begin(), setTwo.end());
    
    vector<string> v_inter;
    vector<string> v_union;
    
    set_intersection(setOne.begin(), setOne.end(), setTwo.begin(), setTwo.end(), back_inserter(v_inter));
    set_union(setOne.begin(), setOne.end(), setTwo.begin(), setTwo.end(), back_inserter(v_union));
    
    if(v_union.empty()) {
        return 65536;
    }
    
    double result = (double)v_inter.size() / (double)v_union.size();
    return (int)(result * 65536);
}