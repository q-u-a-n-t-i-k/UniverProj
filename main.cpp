#include <iostream>
#include <raylib.h>
#include <cmath>

#include "properties.cpp"
#include "button.cpp"

using namespace std;



int main () {

    int ball_x = 100;
    int ball_y = 100;
    int ball_speed_x = 5;
    int ball_speed_y = 5;
    int ball_radius = 15;
    int aim_radius = 30;
    int aim_x = rand()%(SCREEN_WIDTH-2*aim_radius)+aim_radius;
    int aim_y = rand()%(SCREEN_HEIGHT-2*aim_radius)+aim_radius;

    Button btn(1000,725,200,75,40,"Right");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        
        btn.Calculate();
        if(btn.down && ball_x + ball_radius + ball_speed_x <= SCREEN_WIDTH)
        ball_x += ball_speed_x;
        if(IsKeyDown(KEY_A) && ball_x - ball_radius - ball_speed_x >= 0)
        ball_x -= ball_speed_x;
        if(IsKeyDown(KEY_W) && ball_y - ball_radius - ball_speed_y >= 0)
        ball_y -= ball_speed_y;
        if(IsKeyDown(KEY_S) && ball_y + ball_radius + ball_speed_y <= SCREEN_HEIGHT)
        ball_y += ball_speed_y;
        
        if(sqrt(pow(ball_x-aim_x,2) + pow(ball_y-aim_y,2))<aim_radius+ball_radius){
            aim_x = rand()%(SCREEN_WIDTH-2*aim_radius)+aim_radius;
            aim_y = rand()%(SCREEN_HEIGHT-2*aim_radius)+aim_radius;
        }
        BeginDrawing();
            ClearBackground(GREEN);
            DrawCircle(ball_x,ball_y,ball_radius, WHITE);
            DrawCircle(aim_x,aim_y,aim_radius, RED);
            btn.Draw();
            /*
            DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
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