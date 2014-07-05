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
#include <stdbool.h>
#include "Structures.h"


#pragma mark - Declarations

static struct EKGameBoard gameBoardWithMatrix(struct EKMatrix matrix);
static void printGameboard(struct EKGameBoard boardToPrint, _Bool tutorialMode);


#pragma mark - Main

int main(int argc, const char *argv[])
{
    struct EKMatrix matrix   = { 3, 3 };
    struct EKGameBoard board = gameBoardWithMatrix(matrix); //create gameboard with 3*3 size
    
    printGameboard(board, false);
    
    return 0;
}

#pragma mark - Populate gameboard

static inline struct EKGameBoard gameBoardWithMatrix(struct EKMatrix matrix)
{
    assert(matrix.width > 0 && matrix.width != 0);
    assert(matrix.height > 0 && matrix.height != 0);
    
    struct EKGameBoard *gameBoard = (struct EKGameBoard *)malloc(sizeof(struct EKGameBoard));
    assert(gameBoard != NULL);
    
    gameBoard->countOfCells = matrix.width * matrix.height;
    
    int64_t count = 0;
    
    int64_t matrixWidth  = matrix.width;
    int64_t matrixHeigth = matrix.height;
    
    for (int64_t i = 0; i < matrixWidth; i++) {
        for (int64_t j = 0; j < matrixHeigth; j++) {
            ++count;
            
            struct EKCell *gameCell = (struct EKCell *)malloc(sizeof(struct EKCell));
            assert(gameCell != NULL);
            
            gameCell->point.row    = i + 1;
            gameCell->point.column = j + 1;
            gameCell->identifier   = count;
            gameCell->value        = " ";
            gameCell->leftEdge     = "||";
            gameCell->rightEdge    = "||";
            
            gameBoard->cells[count]     = *gameCell;
            gameBoard->innerCells[i][j] = *gameCell;
            
            printf("Cell with ID %lld origin is ==> row %llu _ column %llu\n",
                   gameBoard->cells[count].identifier,
                   gameBoard->cells[count].point.row,
                   gameBoard->cells[count].point.column);
        }
    }
    
    struct EKMatrix *dummyMatrix = (struct EKMatrix *)malloc(sizeof(struct EKMatrix));
    dummyMatrix->width  = matrix.width;
    dummyMatrix->height = matrix.height;
    
    gameBoard->gameboardMatrix = *dummyMatrix;
    
    return *gameBoard;
}

static inline void printGameboard(struct EKGameBoard boardToPrint, _Bool tutorialMode)
{
    int64_t size = boardToPrint.gameboardMatrix.width;
    
    printf("\n");
    printf("    Use keys:\n");
    
    for (int64_t i = 0; i < size; i++) {
        printf("|| %lld || %lld || %lld ||\t\t\t", 1 + (size * i), 2 + (size * i), 3 + (size * i));
        printf("|| %s || %s || %s ||\n",
               boardToPrint.innerCells[0][i].value,
               boardToPrint.innerCells[1][i].value,
               boardToPrint.innerCells[2][i].value);
    }
    
    printf("\n");
}
