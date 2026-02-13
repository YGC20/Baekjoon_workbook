#include <iostream>
#include <string>

void solution(int test_case)
{
    std::string pattern;
    std::cin>>pattern;

    for(int len=1; len<=pattern.size(); ++len) {
        std::string current_pattern = pattern.substr(0,len);
        bool pattern_check = true;

        for(int i=len; i<pattern.size(); ++i) {
            if(pattern[i] != current_pattern[i%len]) {
                pattern_check = false;
                break;
            }
        }

        if(pattern_check) {
            std::cout<<"#"<<test_case<<" "<<current_pattern.size()<<"\n";
            return;
        }
    }
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_case;
    if(std::cin>>test_case) {
        for(int i=1; i<=test_case; ++i) {
            solution(i);
        }
    }
    return 0;
}