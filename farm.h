#ifndef FARM_H
#define FARM_H

#include "tile.h"

class Farm{
    public:
    const static int n = 15, m=25;
    Tile matrix[n][m];
    Color Col = (Color){224,94,65,255};
    const Texture2D bed = LoadTexture("resources/textures/bed.png");
    const Texture2D grass = LoadTexture("resources/textures/grass.png");
    const Texture2D ground[6]={
        LoadTexture("resources/textures/1.png"),
        LoadTexture("resources/textures/1.png"),
        LoadTexture("resources/textures/2.png"),
        LoadTexture("resources/textures/3.png"),
        LoadTexture("resources/textures/4.png"),
        LoadTexture("resources/textures/5.png")};

    const Texture2D tree[5]={
        LoadTexture("resources/textures/201.png"),
        LoadTexture("resources/textures/201.png"),
        LoadTexture("resources/textures/202.png"),
        LoadTexture("resources/textures/203.png"),
        LoadTexture("resources/textures/204.png")};
 

    Farm(){
        for(int i = 0; i < 5; i++){
            matrix[5][6+i].type=200+i;
        }
        for(int i = 0; i < 5; i++){
            matrix[7][6+i].type=111;
        }
        for(int i = 1; i < 6; i++){
            matrix[9][5+i].type=i;
        }
    }

    void draw(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x = j*64,y=i*64,type=matrix[i][j].type,hover = matrix[i][j].hover;
                DrawRectangle(x+hover,y+hover,64-hover*2,64-hover*2,Col);
                if(type != 0){
                    int d_y = 0, d_x = 0;

                    if(type/100 == 1)
                        DrawTexture(bed,x,y,WHITE);
                    
                    else if(type/100 == 2){
                        DrawTexture(grass,x,y,WHITE);
                        d_y = -112;
                        d_x = -8;
                    }

                    if(type%10 != 0) DrawTexture(get_texture(type),x+d_x,y+d_y,WHITE);
                }
            }
        }
    }


    void build(int n, int m, int type){
        this->matrix[n][m].type = type;
    }

    void nextDay(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j].grow();
            }
        }
    }

    void calculate(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j].calculate();
            }
        }
    }

    Texture2D get_texture(int type){
        if((int)type/100 == 0) return ground[type];
        else if((int)(type/100) == 2) return tree[type%10];
        return bed;
    }

};
#endif