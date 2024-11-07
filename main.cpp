#include <iostream>
#include <raylib.h>
#include <cmath>

#include "properties.cpp"
#include "button.cpp"

using namespace std;



int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);
    Button btn(200,100,200,75,40,(char*)"Button");
    while (WindowShouldClose() == false){
    
        btn.Calculate();
        BeginDrawing();
            ClearBackground(LIME);
            btn.Draw();
            /*DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
            DrawRectangle(0,64*15,1920,120,GRAY);
            for(int i = 0; i < 25; i++){
                for(int j = 0; j < 15; j++){
                    if((i+j)%2 == 1) DrawRectangle(i*64,j*64,64,64,ORANGE);
                }
            }*/
            
        EndDrawing();
    }

    CloseWindow();
}