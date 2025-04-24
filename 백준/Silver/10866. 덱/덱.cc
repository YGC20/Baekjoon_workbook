#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int N;
    vector<int> deck;
    string order;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>order;
        if(order=="push_front"){
            int num;
            cin>>num;
            deck.insert(deck.begin(),num);
        }
        else if(order=="push_back"){
            int num;
            cin>>num;
            deck.push_back(num);
        }
        else if(order=="pop_front"){
            if(deck.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<deck.front()<<"\n";
                deck.erase(deck.begin());
            }
        }
        else if(order=="pop_back"){
            if(deck.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<deck.back()<<"\n";
                deck.pop_back();
            }
        }
        else if(order=="size"){
            cout<<deck.size()<<"\n";
        }
        else if(order=="empty"){
            if(deck.empty()){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else if(order=="front"){
            if(deck.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<deck.front()<<"\n";
            }
        }
        else if(order=="back"){
            if(deck.empty()){
                cout<<"-1\n";
            }
            else{
                cout<<deck.back()<<"\n";
            }
        }
    }
    return 0;
}