#include <iostream>
#include <raylib.h>
#include <cmath>

#include "textures.h"
#include "properties.h"
#include "button.h"
#include "farm.h"

Textures Img;
using namespace std;

int main () {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);

    int m_x, m_y;
    Button btn(1920-64*5+60,64*15+25,200,70,40,(char*)"Continue");
    btn.default_color = GREEN;
    Farm pole;

    while (WindowShouldClose() == false){
    
        btn.calculate();
        pole.calculate();
        Img.calculate();

        m_x = (GetMouseX()-GetMouseX()%64)/64;
        m_y = (GetMouseY()-GetMouseY()%64)/64;
        if(m_x <= 25 && m_y <= 15){
            pole.matrix[m_y][m_x].hover = 2;
        }
        if(btn.down){ pole.nextDay();}

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