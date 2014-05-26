//
//  Structures.h
//  TTT
//
//  Created by Evgeny Karkan on 25.05.14.
//  Copyright (c) 2014 EvgenyKarkan. All rights reserved.
//

#ifndef TTT_Structures_h
#define TTT_Structures_h


struct Cell {
    int64_t identifier;
    char value;
};

struct Board {
    int64_t countOfCells;
    struct Cell cells[9]; //assume classic tic-tac-toe board 3*3
};

#endif
