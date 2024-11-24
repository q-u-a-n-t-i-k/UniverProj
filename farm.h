#ifndef FARM_H
#define FARM_H

#include "tile.h"
#include "properties.h"

class Farm{
    public:
    Tile matrix[height][width];
 

    Farm(){
        for(int i = 0; i < 5; i++){
            matrix[5][6+i].type=200;
        }
        for(int i = 0; i < 5; i++){
            matrix[7][6+i].type=100;
        }
        for(int i = 1; i < 6; i++){
            matrix[9][5+i].type=i;
        }
    }

    void draw(){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                matrix[i][j].draw(j*64,i*64);
            }
        }
    }

    void draw_building(){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(building && building_target == 5 && matrix[i][j].type > 5) DrawRectangle(j*64,i*64,64,64,(Color){255,30,30,160});
            }
        }
    }

    void build(int n, int m, int type){
        this->matrix[n][m].type = type;
    }

    void nextDay(){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(rand()%1000 < 2)
                    matrix[i][j].type = 6;
                else if(rand()%1000 < 1)
                    matrix[i][j].type = 7;
                matrix[i][j].grow();
            }
        }

    }

    void calculate(){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                matrix[i][j].calculate();
            }
        }
    }

    

};
#endif