#ifndef GOODS_H
#define GOODS_H

#include <raylib.h>
#include "properties.h"
#include <array>

class Goods{
    public:
        
        int type, target, x, y;
        Texture2D icon;
        Color col = GREEN;
        Color sign_col[5] = {YELLOW,BLACK,WHITE,BLUE,ORANGE};
        string sign[5] = {"M","C","I","O","T"};
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
            if(hover && !building){
                int ar[5]={money,coal,iron,oxygen,temperature};
                DrawRectangle(x-128,y-56,320,48,(Color){25, 51, 77,255});
                for(int i = 0;i<5;i++){
                    col = (Color){0, 204, 102,255};
                    if(req[i]>ar[i]) col = RED;
                    DrawText(TextFormat("%02i", req[i]),x-120+i*64,y-42,24,col);
                    DrawText(sign[i].c_str(),x-88+i*64,y-42,24,sign_col[i]);
                }
            }
            DrawRectangle(x,y,64,64,VIOLET);
        }
        void press(){
            if(money >= req[0] && coal >= req[1] && iron >= req[2] && oxygen >= req[3] && temperature >= req[4]){
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