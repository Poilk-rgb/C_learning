// knight's toor
#include <stdio.h>

int main(void){
    int board[8][8] = {0};
    int horizontal[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int vertical[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int currentRow = 0;
    int currentColumn = 0;
    
    while(1){
        for (size_t moveNumber = 0; moveNumber < 8; moveNumber++){
            if(1){
                currentRow += vertical[moveNumber];
                currentColumn += horizontal[moveNumber];
            }
        }
    }
}