//
//  main.c
//  TTT
//
//  Created by Evgeny Karkan on 25.05.14.
//  Copyright (c) 2014 EvgenyKarkan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Structures.h"


#pragma mark - Declarations

struct EKBoard gameBoardWithMatrix(struct EKMatrix matrix);


#pragma mark - Main

int main(int argc, const char * argv[])
{
    struct EKMatrix matrix = {3, 3};
    struct EKBoard board = gameBoardWithMatrix(matrix); //create gameboard 3*3
    
    printf("Count of cells ==> %lld\n", board.countOfCells);
    
    return 0;
}

#pragma mark - Populate gameboard

struct EKBoard gameBoardWithMatrix(struct EKMatrix matrix)
{
    assert(matrix.width > 0 && matrix.width != 0);
    assert(matrix.height > 0 && matrix.height != 0);
    
    struct EKBoard *gameBoard = (struct EKBoard *)malloc(sizeof(struct EKBoard));
    gameBoard->countOfCells = matrix.width * matrix.height;
    
    int64_t count = 0;
    
    for (int64_t i = 0; i < matrix.width; i++) {
        for (int64_t j = 0; j < matrix.height; j++) {
            ++count;
            
            struct EKCell *gameCell = (struct EKCell *)malloc(sizeof(struct EKCell));
            gameCell->point.row = i + 1;
            gameCell->point.column = j + 1;
            gameCell->identifier = count;
            
            gameBoard->cells[count] = *gameCell;
            
            printf("Cell with ID %lld origin is ==> row %llu _ column %llu\n", gameBoard->cells[count].identifier, gameBoard->cells[count].point.row, gameBoard->cells[count].point.column);
        }
    }
    
    return *gameBoard;
}
