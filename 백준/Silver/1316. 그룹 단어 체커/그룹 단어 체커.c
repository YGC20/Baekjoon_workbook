#include <stdio.h>
#include <string.h>
int main(void){
    int N, i, groupWord=0, checkWord[26];
    char word[101];
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%s", word);
        int j=0, checkPoint=1;
        memset(checkWord, 0, sizeof(checkWord));
        while(word[j]!='\0'){
            if(checkWord[word[j]-'a']==1){
                if(j>0 && word[j]!=word[j-1]){
                    checkPoint=0;
                    break;
                }
            } else{ checkWord[word[j]-'a'] = 1; }
            j++;
        }
        if(checkPoint){ groupWord++; }
    }
    printf("%d", groupWord);
    return 0;
}