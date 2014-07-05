//
//  Structures.h
//  TTT
//
//  Created by Evgeny Karkan on 25.05.14.
//  Copyright (c) 2014 EvgenyKarkan. All rights reserved.
//

#ifndef TTT_Structures_h
#define TTT_Structures_h

struct EKOrigin {
    int64_t row;
    int64_t column;
};

struct EKCell {
    struct EKOrigin point;
    int64_t identifier;
    char *value;
    char *leftEdge;
    char *rightEdge;
};

struct EKMatrix {
    int64_t width;
    int64_t height;
};

struct EKGameBoard {
    int64_t countOfCells;
    struct EKCell cells[9]; //assume classic tic-tac-toe board 3*3
    struct EKCell innerCells[3][3];
    struct EKMatrix gameboardMatrix;
};

#endif
