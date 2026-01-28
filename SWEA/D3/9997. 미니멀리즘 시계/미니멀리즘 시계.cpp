#include<iostream>

void solution(int testCaseIndex) {
    int clockDegree = 0;
    std::cin>>clockDegree;
    
    int hour = clockDegree / 30;
    int minute = clockDegree % 30 * 2;
    
    std::cout<<"#"<<testCaseIndex<<" "<<hour<<" "<<minute<<"\n";
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
	int testCase = 0;
    if(std::cin>>testCase) {
        for(int i=1; i<=testCase; ++i) {
            solution(i);
        }
    }
	return 0;
}