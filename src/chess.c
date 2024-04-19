/*
    DIMITRIS GAVOURAS
    03145
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Chess {
    int **table;
}chess_t;

typedef struct position {
    int N;
    int col;
    int row;
    int move;
}position_t;

int moveKnight (chess_t *chess, position_t *position){
    int result;

    if (((position->col+2 <= position->N-1) && (position->row+1 <= position->N-1)) && (chess->table[position->col+2][position->row+1] == 0)){
        position->move++;
        position->col += 2;
        position->row += 1;
        chess->table[position->col][position->row] = position->move;
        result = moveKnight (chess, position);
        if (result == 0){
            chess->table[position->col][position->row] = 0;
            position->move--;
            position->col-= 2;
            position->row-= 1;
        }
        else {
            return 1;
        }
    }
    if (((position->col+1 <= position->N-1) && (position->row+2 <= position->N-1)) && (chess->table[position->col+1][position->row+2] == 0)){
        position->move++;
        position->col += 1;
        position->row += 2;
        chess->table[position->col][position->row] = position->move;
        result = moveKnight (chess, position);
        if (result == 0){
            chess->table[position->col][position->row] = 0;
            position->move--;
            position->col-= 1;
            position->row-= 2;
        }
        else {
            return 1;
        }
    }
    if (((position->col-1 >= 0) && (position->row+2 <= position->N-1)) && (chess->table[position->col-1][position->row+2] == 0)){
        position->move++;
        position->col -= 1;
        position->row += 2;
        chess->table[position->col][position->row] = position->move;
        result = moveKnight (chess, position);
        if (result == 0){
            chess->table[position->col][position->row] = 0;
            position->move--;
            position->col+= 1;
            position->row-= 2;
        }
        else {
            return 1;
        }
    }
    if (((position->col-2 >= 0) && (position->row+1 <= position->N-1)) && (chess->table[position->col-2][position->row+1] == 0)){
        position->move++;
        position->col -= 2;
        position->row += 1;
        chess->table[position->col][position->row] = position->move;
        result = moveKnight (chess, position);
        if (result == 0){
            chess->table[position->col][position->row] = 0;
            position->move--;
            position->col += 2;
            position->row -= 1;
        }
        else {
            return 1;
        }
    }
    if (((position->col-2 >= 0) && (position->row-1 >= 0)) && (chess->table[position->col-2][position->row-1] == 0)){
        position->move++;
        position->col -= 2;
        position->row -= 1;
        chess->table[position->col][position->row] = position->move;
        result = moveKnight (chess, position);
        if (result == 0){
            chess->table[position->col][position->row] = 0;
            position->move--;
            position->col += 2;
            position->row += 1;
        }
        else {
            return 1;
        }
    }
    if (((position->col-1 >= 0) && (position->row-2 >= 0)) && (chess->table[position->col-1][position->row-2] == 0)){
        position->move++;
        position->col -= 1;
        position->row -= 2;
        chess->table[position->col][position->row] = position->move;
        result = moveKnight (chess, position);
        if (result == 0){
            chess->table[position->col][position->row] = 0;
            position->move--;
            position->col+= 1;
            position->row+= 2;
        }
        else {
            return 1;
        }
    }
    if (((position->col+1 <= position->N-1) && (position->row-2 >= 0)) && (chess->table[position->col+1][position->row-2] == 0)){
        position->move++;
        position->col += 1;
        position->row -= 2;
        chess->table[position->col][position->row] = position->move;
        result = moveKnight (chess, position);
        if (result == 0){
            chess->table[position->col][position->row] = 0;
            position->move--;
            position->col-= 1;
            position->row+= 2;
        }
        else {
            return 1;
        }
    }
    if (((position->col+2 <= position->N-1) && (position->row-1 >= 0)) && (chess->table[position->col+2][position->row-1] == 0)){
        position->move++;
        position->col += 2;
        position->row -= 1;
        chess->table[position->col][position->row] = position->move;
        result = moveKnight (chess, position);
        if (result == 0){
            chess->table[position->col][position->row] = 0;
            position->move--;
            position->col-= 2;
            position->row+= 1;
        }
        else {
            return 1;
        }
    }

    if (position->move == position->N*position->N){
        return 1;
    }
    else {
        return 0;
    }
    
}

int main (int argc, char* argv[]){
    int i=0;
    chess_t chess;
    position_t position;


    position.col = 0;
    position.move = 1;
    position.N = 0;
    position.row = 0;

    position.N = atoi (argv[1]);
    if (position.N < 4){
        printf ("Invalid size\n");
        return -42;
    }
    position.row = atoi (argv[2]);
    position.col = atoi (argv[3]);
    if (((position.col < 0) || (position.col > position.N-1)) || ((position.row < 0) || (position.row > position.N-1))){
        printf ("Invalid start position\n");
        return -42;
    }

    chess.table = (int**)calloc(1, position.N * (sizeof(int*)));
    if (chess.table == NULL){
        printf ("ERROR");
        return -42;
    }

    for (i=0; i < position.N; i++){
        chess.table[i] = (int*)calloc (1, position.N * sizeof(int));
    }

    chess.table[position.col][position.row] = position.move;
    i=0;
    i = moveKnight (&chess, &position);
    if (i == 0){
        printf ("No route\n");
        for (i=0; i < position.N; i++){
            free(chess.table[i]);
        }
        free(chess.table);
        return 1;
    }

    for (position.move = 1; position.move <= position.N * position.N; position.move++){
        for (position.col = 0; position.col < position.N;position.col++){
            for (position.row = 0; position.row < position.N;position.row++){
                if (chess.table[position.col][position.row] == position.move){
                    printf ("(%d, %d) ", position.col, position.row);
                }
            }
        }
    }
    for (i=0; i < position.N; i++){
        free(chess.table[i]);
    }
    free(chess.table);
    printf ("\n");

    return 1;
}
