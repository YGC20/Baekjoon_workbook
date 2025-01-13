#include <stdio.h>

int repaint(char chessboard[50][50], int start_x, int start_y, char first_color){
    int count = 0;
    char expected_color = first_color;
    for(int i=start_x; i<start_x+8; i++){
        for(int j=start_y; j<start_y+8; j++){
            if(chessboard[i][j]!=expected_color) count++;
            expected_color = (expected_color == 'B') ? 'W' : 'B';
        }
        expected_color = (expected_color == 'B') ? 'W' : 'B';
    }
    return count;
}

int main(void){
    int N, M, i, j;
    int min_count = 64;
    char chessboard[50][50];

    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){ scanf("%s", chessboard[i]); }

    for(i=0; i<N-7; i++) for(j=0; j<M-7; j++){
            int count1 = repaint(chessboard, i, j, 'B');
            int count2 = repaint(chessboard, i, j, 'W');
            if(count1<min_count) min_count = count1;
            if(count2<min_count) min_count = count2;
    }
    printf("%d\n", min_count);
    return 0;
}