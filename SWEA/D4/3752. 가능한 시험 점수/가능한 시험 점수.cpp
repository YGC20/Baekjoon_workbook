#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[10001] = {false};

void solution(int testCase)
{
    int n_score = 0;
    cin>>n_score;
    vector<int> scores(n_score);
    fill(visited, visited+10001, false);
    for(int i=0; i<n_score; ++i) {
        cin>>scores[i];
    }

    visited[0] = true;
    int max_score = 0;
    for(int score : scores) {
        for(int i=max_score; i>=0; --i) {
            if(visited[i] && !visited[i+score]) {
                visited[i+score] = true;
            }
        }
        max_score += score;
    }

    int cnt = 0;
    for(int i=0; i<=max_score; ++i) {
        if(visited[i]) {
            cnt++;
        }
    }

    cout<<"#"<<testCase<<" "<<cnt<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    if(cin>>testCase) {
        for(int i=1; i<=testCase; ++i) {
            solution(i);
        }
    }
    return 0;
}