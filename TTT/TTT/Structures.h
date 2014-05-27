//
//  Structures.h
//  TTT
//
//  Created by Evgeny Karkan on 25.05.14.
//  Copyright (c) 2014 EvgenyKarkan. All rights reserved.
//

#ifndef TTT_Structures_h
#define TTT_Structures_h


struct EKCell {
    int64_t identifier;
    char* value;
};

struct EKMatrix {
    int64_t width;
    int64_t height;
};

struct EKBoard {
    int64_t countOfCells;
    struct EKCell cells[3][3]; //assume classic tic-tac-toe board 3*3
};

#endif
