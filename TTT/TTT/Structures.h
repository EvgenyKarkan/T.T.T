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
    unsigned int identifier;
    char value;
};

struct Board {
    struct Cell cells[9];
};

#endif
