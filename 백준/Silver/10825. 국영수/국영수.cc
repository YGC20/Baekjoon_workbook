#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef struct socre{
    string name;
    int korean;
    int english;
    int math;
}score;
bool compare(const score &a, const score &b){
    if(a.korean!=b.korean) return a.korean>b.korean;
    if(a.english!=b.english) return a.english<b.english;
    if(a.math!=b.math) return a.math>b.math;
    return a.name<b.name;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<score> students(N);
    for(int i=0; i<N; i++)
        cin>>students[i].name>>students[i].korean>>students[i].english>>students[i].math;
    sort(students.begin(),students.end(),compare);
    for(const auto& s:students)
        cout<<s.name<<'\n';
    return 0;
}