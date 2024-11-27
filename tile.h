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
    void draw(int x, int y){
        DrawRectangle(x+hover,y+hover,64-hover*2,64-hover*2,TileColor);
        if(type != 0){
            int d_y = 0, d_x = 0;

            if(type/100 == 1){
                Img.add(100,x,y);
                d_y = -32;}
            
            else if(type/100 == 2){
                Img.add(200,x,y);
                d_y = -112;
                d_x = -8;
            }
            else if(type/100 == 3){
                Img.add(300,x,y-24);
            }

            if(type%10 != 0) Img.add(type,x+d_x,y+d_y);
        }
    }
    void calculate(){
        hover = 0;
        if(building && building_target/100 == type/100 && (building_target/10)%10 == (type/10)%10 && type <= building_target && building_target > 5) hover = 2;
    }
};

#endif