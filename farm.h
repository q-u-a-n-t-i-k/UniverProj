#ifndef FARM_H
#define FARM_H

#include "tile.h"
#include "properties.h"

class Farm{
    public:
    Tile matrix[height][width];
 

    Farm(){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(rand()%100 < 5)
                    matrix[i][j].type = 1+rand()%5;
            }
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
                if(building && building_target == 5 && matrix[i][j].type > 5) DrawRectangle(j*64,i*64,64,64,RED);
            }
        }
    }

    void build(int n, int m, int type){
        if(matrix[n][m].type == 401)coal += 1+rand()%3;
        if(matrix[n][m].type == 402)iron += 1+rand()%2;
        if(matrix[n][m].type/100==1&&matrix[n][m].type>110)money += 8*matrix[n][m].type%10;
        this->matrix[n][m].type = type;
    }

    void nextDay(){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(rand()%1000 < 2)
                    matrix[i][j].type = 401;
                else if(rand()%1000 < 1)
                    matrix[i][j].type = 402;
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