#include <iostream>
#include <raylib.h>
#include <cmath>
#include <array>

#include "properties.h"
#include "progresbar.h"
#include "textures.h"
#include "button.h"
#include "farm.h"
#include "goods.h"

// init val for externs in properties
Textures Img;
bool building = false, pause =false;
int money = 2000, coal = 100, iron = 100, oxygen = 0, temperature = 0, building_target = 5, building_type = 200, requi[3];

using namespace std;

void OXG(Farm pole){
    oxygen=0;
    for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if (pole.matrix[i][j].type == 200)
                    oxygen+=0;
                else if (pole.matrix[i][j].type == 201)
                    oxygen+=1;
                else if (pole.matrix[i][j].type == 202)
                    oxygen+=2;
                else if (pole.matrix[i][j].type == 203)
                    oxygen+=2;
                else if (pole.matrix[i][j].type == 204)
                    oxygen+=2;
            }
        }
        if (oxygen>20) oxygen =20;
}
void T(Farm pole){
    temperature = 0;
    for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if (pole.matrix[i][j].type == 300)
                    temperature +=10;
            }
        }
    if (temperature>100) temperature =100;
}

int main () {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);
    Farm pole;// game area(its init must be first)
    int m_x, m_y;//mouse cord
    Img.Load();//load images

    Button btn(1920-64*5+60,64*15+25,200,70,40,(char*)"Continue");
    btn.default_color = GREEN;

    Button cancel(40,980,64,64,40,(char*)"X");
    cancel.default_color = RED;
   
    Progressbar O2(1140,965,175,100,40,25,"O2",1);
    O2.color_bar = BLUE;
    O2.beg_color = LIGHTGRAY;
    O2.color = DARKGRAY;

    Progressbar Temp(1365,965,175,100,40,25,"T(K)",1);
    Temp.color_bar = RED;
    Temp.beg_color = LIGHTGRAY;
    Temp.color = DARKGRAY;

    array<int,5> ar;
    Goods shop[11];
    ar = {25,0,0,0,0};
    shop[0] = Goods(160,980,5,100,ar,100);
    shop[1] = Goods(240,980,5,200,ar,200);
    ar = {50,4,1,0,0};
    shop[2] = Goods(320,980,5,300,ar,300);
    ar = {25,0,0,0,0};
    shop[3] = Goods(440,980,100,101,ar,121);
    shop[4] = Goods(520,980,100,102,ar,122);
    shop[5] = Goods(600,980,100,103,ar,123);
    shop[6] = Goods(680,980,100,104,ar,124);
    shop[7] = Goods(760,980,100,105,ar,125);
    shop[8] = Goods(840,980,200,201,ar,121);

    shop[9] = Goods(960,980,402,0,ar,403);
    ar = {0,0,0,0,0};
    shop[10] = Goods(1040,980,115,100,ar,404);

    while (WindowShouldClose() == false){
        if(pause){
            
        }
        else{
            pole.calculate();
            Img.calculate();
            OXG(pole);
            O2.fullbar=oxygen*5;
            T(pole);
            Temp.fullbar=temperature;
            m_x = (GetMouseX()-GetMouseX()%64)/64;
            m_y = (GetMouseY()-GetMouseY()%64)/64;

            if(!building){
                btn.calculate();
                for(int i = 0; i < 11;i++) shop[i].calculate();
                
                if(m_x < 25 && m_y < 15)
                    pole.matrix[m_y][m_x].hover = 2;// border width (px)
                else if(btn.pressed){ pole.nextDay();}
            }
            else{
                cancel.calculate();
                if(m_x < 25 && m_y < 15){
                    if(building_target == 5) pole.matrix[m_y][m_x].hover = 2;// border width (px)
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        if(building_target/100 == pole.matrix[m_y][m_x].type/100 && (building_target/10)%10 == (pole.matrix[m_y][m_x].type/10)%10 && pole.matrix[m_y][m_x].type <= building_target){
                            if(money >= requi[0] && coal >= requi[1] && iron >= requi[2]){
                            pole.build(m_y,m_x,building_type);
                            money -= requi[0];
                            coal -= requi[1];
                            iron -= requi[2];}
                        }
                    }
                }
                else if(cancel.pressed){building = false;}
            }
            
        }
        
        //drawing
        BeginDrawing();
            if(pause){
            
            }
            else{
            ClearBackground(GREEN);
            if(building)ClearBackground(YELLOW);
            
            DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
            DrawRectangle(0,64*15,1920,120,GRAY);

            pole.draw();
            for(int i = 0; i < 11;i++) shop[i].draw();
            pole.draw_building();
            Img.draw(building,building_target);       

            
            if(building) cancel.Draw();
            else btn.Draw();
            O2.Draw();
            Temp.Draw();
            }
            
        
        EndDrawing();
        
        
    }

    CloseWindow();
}

