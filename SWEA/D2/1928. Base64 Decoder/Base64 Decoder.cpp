#include <iostream>
using namespace std;

int toBase64(char unicode){
    if(unicode>=65 && unicode<=90) return (unicode-65);
    else if(unicode>=97 && unicode<=122) return (unicode-71);
    else if(unicode>=48 && unicode<=57) return (unicode+4);
    else return 63;
}

void solution(int testCase)
{
    string chiperText;
    string plainText;
    cin>>chiperText;

    for(int i=0; i<chiperText.size(); i+=4){
        int buffer = 0;
        for(int x=0; x<4; ++x){
            buffer |= (toBase64(chiperText[i+x])<<(18-x*6));
        }

        for(int x=0; x<3; ++x){
            plainText += (buffer>>(16-x*8)) & 0xFF;
        }
    }

    cout<<"#"<<testCase<<" "<<plainText<<"\n";
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase;
    if(cin>>testCase){
        for(int i=1; i<=testCase; ++i){
            solution(i);
        }
    }
    return 0;
}