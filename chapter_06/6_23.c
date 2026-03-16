//Turtle graphics
#include <stdio.h>

enum Pen {UP, DOWN};
enum Status {NORTH, EAST, SOUTH, WEST};

int main(void)
{
    int floor[50][50] = {0};
    int command = 0;
    int steps = 0;
    int location_row = 49;
    int location_column = 0;
    int destination = 0;
    //int pen_up = 1;
    enum Status turtle_direction = NORTH;
    enum Pen pen_status = DOWN;
    
    while(command != 9){
        printf("Enter the command: ");
        scanf("%d", &command);
        
        switch (command)
        {
            case 1: 
                if(pen_status != UP){
                    pen_status = UP;
                }
                printf("Pen status: UP\n");
                break;
                
            case 2:
                if(pen_status != DOWN){
                    pen_status = DOWN;
                }
                printf("Pen status: DOWN\n");
                break;
                
            case 3:
                switch (turtle_direction)
                {
                    case NORTH:
                        turtle_direction = EAST;
                        break;
                    case EAST:
                        turtle_direction = SOUTH;
                        break;
                    case SOUTH:
                        turtle_direction = WEST;
                        break;
                    case WEST:
                        turtle_direction = NORTH;
                        break;    
                    default:
                        break;
                }
                break;
                
            case 4:
                switch (turtle_direction)
                {
                    case NORTH:
                        turtle_direction = WEST;
                        break;
                    case WEST:
                        turtle_direction = SOUTH;
                        break;
                    case SOUTH:
                        turtle_direction = EAST;
                        break;
                    case EAST:
                        turtle_direction = NORTH;
                        break;    
                    default:
                        break;
                }
                break;
                
            case 5:
                printf("%s", "Enter the number of steps");
                scanf("%d", &steps);

                switch (turtle_direction)
                {
                    case NORTH:
                        if(location_row < steps && location_row != 0){
                            printf("%s\n", "Turtle will fall over the table ;( ");
                            printf("%s %d %s\n", "Enter less than ", location_row, "steps");
                        } 
                        else {
                            if(0 == location_row && 0 == location_column){
                                printf("%s\n", "Turn right, you are at the dead end");
                            } 
                            else {
                                if(0 == location_row && 49 == location_column){
                                    printf("%s\n", "Turn left, you are at the dead end");
                                } 
                                else {
                                    destination = location_row - steps;
                                    for (; location_row > (destination); location_row--){
                                        if(pen_status == DOWN){
                                            floor[location_row][location_column] = 1;
                                        } else {
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        break;
                        
                    case EAST:
                        if(location_column > (49 - steps)){
                            printf("%s\n", "Turtle will fall over the table ;( ");
                            printf("%s %d %s\n", "Enter less than ", 49 - location_column, "steps");
                        } 
                        else {
                            if(0 == location_row && 49 == location_column){
                                printf("%s\n", "Turn right, you are at the dead end");
                            } 
                            else {
                                if(49 == location_row && 49 == location_column){
                                    printf("%s\n", "Turn left, you are at the dead end");
                                } 
                                else {
                                    destination = location_column + steps;
                                    for (; location_column < (destination); location_column++){
                                        if(pen_status == DOWN){
                                            floor[location_row][location_column] = 1;
                                        } else {
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                        break;
                        
                    default:
                        break;
                }
                break;
                
            case 6:
                for (size_t i = 0; i < 50; i++)
                {
                    for (size_t j = 0; j < 50; j++)
                    {
                        if(1 == floor[i][j]){
                            printf("%s", "*");
                        } else {
                            printf("%s", " ");
                        }
                        if(49 == j){
                            puts("");
                            break;
                        }
                    }
                }
                break;
                
            default:
                break;
        }
    }
    return 0;
}