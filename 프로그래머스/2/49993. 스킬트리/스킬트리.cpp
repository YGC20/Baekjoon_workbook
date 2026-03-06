#include <string>
#include <vector>

using namespace std;

bool skillCheck(string skill,string skill_tree)
{
    string tmp = "";
    for(int i=0; i<skill_tree.size(); ++i) {
        for(int j=0; j<skill.size(); ++j) {
            if(skill[j]==skill_tree[i]) {
                tmp+=skill_tree[i];
            }
        }
    }
    for(int i=0; i<tmp.size(); ++i) {
        if(skill[i]!=tmp[i]) {
            return false;
        }
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill_trees.size(); ++i) {
        if(skillCheck(skill, skill_trees[i])) {
            answer++;
        }
    }
    return answer;
}