//
//  main.c
//  TTT
//
//  Created by Evgeny Karkan on 25.05.14.
//  Copyright (c) 2014 EvgenyKarkan. All rights reserved.
//

#include <stdio.h>
#include "Structures.h"

#pragma mark - Declarations

void populateGameBoard();


int main(int argc, const char * argv[])
{
    populateGameBoard();
    
    return 0;
}

#pragma mark - Populate gameboard

void populateGameBoard()
{
    struct Board gameBoard;
    
    for (unsigned int i = 0; i < 9; i++) {
        struct Cell cell;
        cell.identifier = i + 1;
        gameBoard.cells[i].identifier = cell.identifier;
        printf("Cell has a id ==> %d\n", gameBoard.cells[i].identifier);
    }
}

