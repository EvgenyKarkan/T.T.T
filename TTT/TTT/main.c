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

void populateGameBoardWithCountOfCells(unsigned int);


int main(int argc, const char * argv[])
{
    populateGameBoardWithCountOfCells(9);
    
    return 0;
}

#pragma mark - Populate gameboard

void populateGameBoardWithCountOfCells(unsigned int count)
{
    assert(count);
    
    struct Board gameBoard;
    
    for (unsigned int i = 0; i < count; i++) {
        struct Cell cell;
        cell.identifier = i + 1;
        
        gameBoard.countOfCells = count;
        gameBoard.cells[i].identifier = cell.identifier;
        printf("Cell has a id ==> %d\n", gameBoard.cells[i].identifier);
    }
}

