// knight's toor random jumping
#include <stdio.h>

int main(void){
    int accessibility[8][8] = {
    {2, 3, 4, 4, 4, 4, 3, 2},
    {3, 4, 6, 6, 6, 6, 4, 3},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {4, 6, 8, 8, 8, 8, 6, 4},
    {3, 4, 6, 6, 6, 6, 4, 3},
    {2, 3, 4, 4, 4, 4, 3, 2}
};
    int board[8][8] = {0};
    int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int nextRow = 0;
    int nextColumn = 0;
    int potentialRow = 1;
    int potentialColumn = 1;
    int currentRow = 0;
    int currentColumn = 0;
    int moveNumber = 0;
    int lowest = 20;
    
        for (size_t c = 1; c < 64; c++){
            for (size_t moveNumber = 0; moveNumber < 8; moveNumber++){
                currentRow = potentialRow;
                currentColumn = potentialColumn; 
                potentialRow += vertical[moveNumber];
                potentialColumn += horizontal[moveNumber];
                if(currentRow > 7 || currentRow < 0 || currentColumn > 7 
                        || currentColumn < 0 || board[currentRow][currentColumn] == 1){
                        potentialRow = currentRow;
                        potentialColumn = currentColumn;
                        continue;
                } 
                else {
                    if(lowest > accessibility[potentialRow][potentialColumn]){
                        lowest = accessibility[potentialRow][potentialColumn];
                        nextRow = potentialRow;
                        nextColumn = potentialColumn;
                    }
                }
            }
                board[nextRow][nextColumn] = 1;
            }
        for (size_t i = 0; i < 8; i++){
            for (size_t j = 0; j < 8; j++){
                printf("%d", board[i][j]);
            }
            puts("");
        }
    }