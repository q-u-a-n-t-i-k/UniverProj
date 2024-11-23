#ifndef TILE_H
#define TILE_H

#include <raylib.h>
#include "properties.h"



class Tile{
    public:
    int type = 0;
    int hover = 0;
    void grow(){
        if(100 < type && type < 110){
            type += 10;
        }
        else if(type == 201) type = 202+ rand()%3;
    };
    void calculate(){
        hover = 0;
    }
};

#endif