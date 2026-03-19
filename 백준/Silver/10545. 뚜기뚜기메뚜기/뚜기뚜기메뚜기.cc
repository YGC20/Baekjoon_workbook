#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<char,string> keypads = {
        {'a',"2"},{'b',"22"},{'c',"222"},
        {'d',"3"},{'e',"33"},{'f',"333"},
        {'g',"4"},{'h',"44"},{'i',"444"},
        {'j',"5"},{'k',"55"},{'l',"555"},
        {'m',"6"},{'n',"66"},{'o',"666"},
        {'p',"7"},{'q',"77"},{'r',"777"},{'s',"7777"},
        {'t',"8"},{'u',"88"},{'v',"888"},
        {'w',"9"},{'x',"99"},{'y',"999"},{'z',"9999"}
    };

    vector<int> keyset(9);
    for(int i=0; i<9; ++i) {
        cin>>keyset[i];
    }

    string encode_message = "";
    string message;
    cin>>message;
    for(char m : message) {
        if(encode_message.back()==keypads[m].front()) {
            encode_message += "#";
        }
        encode_message += keypads[m];
    }

    for(int i=0; i<encode_message.size(); ++i) {
        if(encode_message[i]=='#') {
            continue;
        }
        int em = encode_message[i]-'0';
        for(int j=0; j<9; ++j) {
            if(keyset[j]==em) {
                encode_message[i] = (j+1)+'0';
                break;
            }
        }
        
    }

    cout<<encode_message<<"\n";
    return 0;
}