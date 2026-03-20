// knight's toor random jumping
#include <stdio.h>

int main(void){
    
    int board[8][8] = {0};
    int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int currentRow = 0;
    int currentColumn = 0;
    int storeRow = 0;
    int storeColumn = 0;
    int moveNumber = 0;
    
        for (size_t c = 1; c < 100; c++){
            if(moveNumber == 8){
                moveNumber = 0;
            }
            storeRow = currentRow;
            storeColumn = currentColumn;   
            currentRow += vertical[moveNumber];
            currentColumn += horizontal[moveNumber];
            if(currentRow > 7 || currentRow < 0 || currentColumn > 7 
                || currentColumn < 0 || board[currentRow][currentColumn] == 1){
                currentRow = storeRow;
                currentColumn = storeColumn;
                moveNumber++;
                continue;
            }
            board[currentRow][currentColumn] = 1;
            moveNumber++;
        }
        for (size_t i = 0; i < 8; i++){
            for (size_t j = 0; j < 8; j++){
                printf("%d", board[i][j]);
            }
            puts("");
        }
    }