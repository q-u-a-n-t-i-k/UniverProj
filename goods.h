#ifndef GOODS_H
#define GOODS_H

#include <raylib.h>
#include "properties.h"
#include <array>

class Goods{
    public:
        
        int type, target, x, y, img,n;
        Color col = GREEN;
        Color sign_col[5] = {YELLOW,BLACK,WHITE,BLUE,ORANGE};
        string sign[5] = {"M","C","I","O","T"};
        bool hover;
        array<int,5> req;
    
        Goods(int x, int y, int target, int type, array<int,5> r, int img){
            this->x = x;
            this->y = y;
            this->target = target;
            this->type = type;
            this->req = r;
            this->img = img;
            for(int i =0; i<5 ;i++) if(req[i]!=0)n++;
        }
        Goods(){
            x=0;
            y=0;
            target = 5;
            type = 100;
            req = {25,0,0,0,0};
        }

        void calculate(){
            hover = false;
            if(GetMouseX() > x && GetMouseX() < x+64 && GetMouseY() > y && GetMouseY() < y + 64){
                hover = true;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) press();
            }
        }

        void draw(){
            if(hover){
                int ar[5]={money,coal,iron,oxygen,temperature};
                DrawRectangle(x-32*(n-1),y-56,64*n,48,(Color){25, 51, 77,255});
                int k = 0;
                for(int i = 0;i<5;i++){
                    if(req[i]==0)continue;
                    col = (Color){0, 204, 102,255};
                    if(req[i]>ar[i]) col = RED;
                    DrawText(TextFormat("%02i", req[i]),x+8-32*(n-1)+k*64,y-42,24,col);
                    DrawText(sign[i].c_str(),x-32*(n-1)+40+k*64,y-42,24,sign_col[i]);
                    k++;
                }
            }
            if(building && building_type != type) Img.add(img,x,y, 160);
            else Img.add(img,x,y);
        }
        void press(){
            if(money >= req[0] && coal >= req[1] && iron >= req[2] && oxygen >= req[3] && temperature >= req[4]){
                building = true;
                building_type = type;
                building_target = target;
                requi[0] = req[0];
                requi[1] = req[1];
                requi[2] = req[2];
            }
            
        }

};

#endif