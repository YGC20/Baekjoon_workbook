#include <iostream>
using namespace std;
struct human{
    int w;
    int h;
    int r;
};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int N;
    cin>>N;
    human a[N];
    for(int i=0;i<N;i++){
        cin>>a[i].w>>a[i].h;
        a[i].r=1;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if((a[i].w<a[j].w)&&(a[i].h<a[j].h))
                a[i].r++;
        }
    }
    for(int i=0;i<N;i++){
        cout<<a[i].r<<" ";
    }
    cout<<"\n";
    return 0;
}