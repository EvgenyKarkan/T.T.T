//
//  main.c
//  TTT
//
//  Created by Evgeny Karkan on 25.05.14.
//  Copyright (c) 2014 EvgenyKarkan. All rights reserved.
//

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
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
    
    struct EKBoard gameBoard;
    gameBoard.countOfCells = matrix.width * matrix.height;
    
    int64_t count = 0;
    
    for (int64_t i = 0; i < matrix.width; i++) {
        for (int64_t j = 0; j < matrix.height; j++) {
            gameBoard.cells[i][j].identifier = ++count;
            printf("Cell has a id ==> %llu\n", gameBoard.cells[i][j].identifier);
        }
    }
    
//    for (unsigned int i = 0; i < (int64_t)count; i++) {
//        struct EKCell cell;
//        cell.identifier = i + 1;
//        
//        gameBoard.countOfCells = count;
//        gameBoard.cells[i].identifier = cell.identifier;
//        printf(ANSI_COLOR_RED "Cell has a id ==> %llu" ANSI_COLOR_RESET "\n", gameBoard.cells[i].identifier);
//    }
    
    return gameBoard;
}
