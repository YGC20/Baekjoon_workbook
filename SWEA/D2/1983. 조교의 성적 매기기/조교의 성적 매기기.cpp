#include<iostream>
#include<vector>
#include<algorithm>

void soultion(int testCase) {
    std::string grades[10] = {"A+","A0","A-","B+","B0","B-","C+","C0","C-","D0"};
    
    int studentNum = 0;
    int resultIndex = 0;
    std::cin>>studentNum>>resultIndex;
    resultIndex--;
    
    std::vector<std::pair<double, int>> students;
    for(int i=0; i<studentNum; ++i) {
        int mid = 0;
        int fin = 0;
        int sub = 0;
        std::cin>>mid>>fin>>sub;
        double score = (mid*0.35) + (fin*0.45) + (sub*0.2);
        students.push_back({score, i});
    }
    std::sort(students.begin(), students.end(), std::greater<std::pair<double, int>>());
    for(int i=0; i<studentNum; ++i) {
        if(students[i].second == resultIndex) {
            std::cout<<"#"<<testCase<<" "<<grades[i/(studentNum/10)]<<"\n";
            break;
        }
    }
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int testCase = 0;
    if(std::cin>>testCase) {
        for(int i=1; i<=testCase; ++i) {
            soultion(i);
        }
    }
	return 0;
}