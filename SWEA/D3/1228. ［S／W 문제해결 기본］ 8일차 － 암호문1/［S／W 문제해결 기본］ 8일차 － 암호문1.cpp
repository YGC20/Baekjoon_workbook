#include<iostream>
#include<vector>

void solution(int testCase){
    int passwordIndex = 0;
    std::cin>>passwordIndex;
    
    std::vector<int> passwords(passwordIndex);
    for(int i=0; i<passwordIndex; ++i) {
        std::cin>>passwords[i];
    }
    
    int comandIndex = 0;
    std::cin>>comandIndex;
    
    for(int i=0; i<comandIndex; ++i) {
        char comand;
        std::cin>>comand;
        int startPostion = 0;
        std::cin>>startPostion;
        
        int numIndex = 0;
        std::cin>>numIndex;
        std::vector<int> changeNum(numIndex);
        for(int i=0; i<numIndex; ++i) {
            std::cin>>changeNum[i];
        }
        
        passwords.insert(passwords.begin()+startPostion, changeNum.begin(), changeNum.end());
    }
    std::cout<<"#"<<testCase;
    for(int i=0; i<10; ++i) {
        std::cout<<" "<<passwords[i];
    }
    std::cout<<"\n";
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for(int i=1; i<=10; ++i) {
        solution(i);
    }
    return 0;
}