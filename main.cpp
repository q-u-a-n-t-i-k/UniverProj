#include <iostream>
#include <raylib.h>
#include <cmath>

#include "textures.h"
#include "properties.h"
#include "button.h"
#include "farm.h"

// init val for externs in properties
Textures Img;
bool building = true;
int money, coal, iron, oxugen, temperature, building_target = 200, building_type = 201;

using namespace std;

int main () {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);

    int m_x, m_y;//mouse cord
    Img.Load();//load images
    Button btn(1920-64*5+60,64*15+25,200,70,40,(char*)"Continue");
    btn.default_color = GREEN;
    Farm pole;// game area

    while (WindowShouldClose() == false){
        //update variables
        btn.calculate();
        pole.calculate();
        Img.calculate();
        m_x = (GetMouseX()-GetMouseX()%64)/64;
        m_y = (GetMouseY()-GetMouseY()%64)/64;

        //logic
        if(m_x <= 25 && m_y <= 15){
            pole.matrix[m_y][m_x].hover = 2;// border width (px)
            if(building && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(building_target/100 == pole.matrix[m_y][m_x].type/100 && pole.matrix[m_y][m_x].type <= building_target){
                    pole.build(m_y,m_x,building_type);
                    building = false;}
            }
        }
        else if(btn.down){ pole.nextDay();}

        //drawing
        BeginDrawing();
            ClearBackground(GREEN);
            
            DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
            DrawRectangle(0,64*15,1920,120,GRAY);

            pole.draw();
            Img.draw();
            btn.Draw();
            
        EndDrawing();
        
    }

    CloseWindow();
}

