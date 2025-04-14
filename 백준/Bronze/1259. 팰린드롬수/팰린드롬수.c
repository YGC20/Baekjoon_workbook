#include <stdio.h>
#include <string.h>
int main(void){
    int input;
    char inputChar[100000];
    while(1){
        scanf("%d", &input);
        if(input==0)
            break;
        sprintf(inputChar, "%d", input);
        int right=strlen(inputChar)-1, check=0;
        for(int left=0; left<strlen(inputChar); left++){
            if(left==right)
                break;
            if(inputChar[left]!=inputChar[right]){
                check=1;
                break;
            }
            right--;
        }
        if(check==1){
            printf("no\n");
        }
        else{
            printf("yes\n");
        }
    }
    return 0;
}