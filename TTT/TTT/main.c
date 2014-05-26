//
//  main.c
//  TTT
//
//  Created by Evgeny Karkan on 25.05.14.
//  Copyright (c) 2014 EvgenyKarkan. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "Structures.h"

#pragma mark - Declarations

void populateGameBoardWithCountOfCells(int64_t count);


int main(int argc, const char * argv[])
{
    populateGameBoardWithCountOfCells(9); //create gameboard 3*3
    
    return 0;
}

#pragma mark - Populate gameboard

void populateGameBoardWithCountOfCells(int64_t count)
{
    assert(count != 0);
    assert(count > 0);
    
    struct Board gameBoard;
    
    for (unsigned int i = 0; i < (int64_t)count; i++) {
        struct Cell cell;
        cell.identifier = i + 1;
        
        gameBoard.countOfCells = count;
        gameBoard.cells[i].identifier = cell.identifier;
        printf("Cell has a id ==> %llu\n", gameBoard.cells[i].identifier);
    }
}

