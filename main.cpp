#include <iostream>
#include <raylib.h>
#include <cmath>
#include <array>

#include "properties.h"
#include "textures.h"
#include "button.h"
#include "farm.h"
#include "goods.h"

// init val for externs in properties
Textures Img;
bool building = false;
int money = 200, coal = 0, iron = 0, oxygen = 0, temperature = 0, building_target = 5, building_type = 200;

using namespace std;

int main () {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);

    Farm pole;// game area(its init must be first)

    int m_x, m_y;//mouse cord

    Img.Load();//load images
    
    Button btn(1920-64*5+60,64*15+25,200,70,40,(char*)"Continue");
    btn.default_color = GREEN;

    array<int,5> ar = {25,0,0,0,0};
    Goods g(20,980,5,200,ar,(char*)"Continue");

    while (WindowShouldClose() == false){
        //update variables
        pole.calculate();//(must be first)
        
        btn.calculate();
        g.calculate();
        Img.calculate();
        m_x = (GetMouseX()-GetMouseX()%64)/64;
        m_y = (GetMouseY()-GetMouseY()%64)/64;

        //logic
        if(m_x <= 25 && m_y <= 15){
            if(!building || building_target == 5) pole.matrix[m_y][m_x].hover = 2;// border width (px)
            if(building && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(building_target/100 == pole.matrix[m_y][m_x].type/100 && pole.matrix[m_y][m_x].type <= building_target){
                    pole.build(m_y,m_x,building_type);
                    building = false;}
            }
        }
        else if(btn.pressed){ pole.nextDay();}

        //drawing
        BeginDrawing();
            ClearBackground(GREEN);
            if(building) ClearBackground(YELLOW);
            
            DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
            DrawRectangle(0,64*15,1920,120,GRAY);

            pole.draw();
            Img.draw(building,building_target);
            pole.draw_building();

            btn.Draw();
            g.draw();
            
        EndDrawing();
        
    }

    CloseWindow();
}

