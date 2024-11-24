#ifndef GOODS_H
#define GOODS_H

#include <raylib.h>
#include "properties.h"
#include <array>

class Goods{
    public:
        
        int type, target, x, y;
        Texture2D icon;
        Color col = WHITE;
        bool hover;
        array<int,5> req;
    
        Goods(int x, int y, int target, int type, array<int,5> r, char[]){
            this->x = x;
            this->y = y;
            this->target = target;
            this->type = type;
            this->req = r;
            cout<<endl;
        }

        void calculate(){
            hover = false;
            if(GetMouseX() > x && GetMouseX() < x+64 && GetMouseY() > y && GetMouseY() < y + 64){
                hover = true;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && ! building) press();
            }
        }

        void draw(){
            DrawRectangle(x,y,64,64,col);
        }
        void press(){
            col = RED;
            if(money >= req[0] && coal >= req[1] && iron >= req[2] && oxygen >= req[3] && temperature >= req[4]){
                col = GREEN;
                building = true;
                building_type = type;
                building_target = target;
                money -= req[0];
                coal -= req[1];
                iron -= req[2];
            }
        }

};

#endif