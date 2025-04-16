#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct USER{
    int num;
    int age;
    string name;
}user;
bool compare(const user &a, const user &b){
    if(a.age!=b.age)
        return a.age < b.age;
    return a.num<b.num;
}
int main(void){
    int N;
    cin>>N;
    vector<user> array(N);
    for(int i=0; i<N; i++){
        array[i].num = i;
        cin>>array[i].age>>array[i].name;
    }
    stable_sort(array.begin(),array.end(),compare);
    for(int i=0; i<N; i++){
        cout<<array[i].age<<" "<<array[i].name<<endl;
    }
    return 0;
}