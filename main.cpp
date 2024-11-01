#include <iostream>
#include <raylib.h>
#include <cmath>

using namespace std;

int main () {

    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 800;
    int ball_x = 100;
    int ball_y = 100;
    int ball_speed_x = 5;
    int ball_speed_y = 5;
    int ball_radius = 15;
    int aim_radius = 30;
    int aim_x = rand()%(SCREEN_WIDTH-2*aim_radius)+aim_radius;
    int aim_y = rand()%(SCREEN_HEIGHT-2*aim_radius)+aim_radius;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Prog");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        
        if(IsKeyDown(KEY_D) && ball_x + ball_radius + ball_speed_x <= SCREEN_WIDTH)
        ball_x += ball_speed_x;
        if(IsKeyDown(KEY_A) && ball_x - ball_radius - ball_speed_x >= 0)
        ball_x -= ball_speed_x;
        if(IsKeyDown(KEY_W) && ball_y - ball_radius - ball_speed_y >= 0)
        ball_y -= ball_speed_y;
        if(IsKeyDown(KEY_S) && ball_y + ball_radius + ball_speed_y <= SCREEN_HEIGHT)
        ball_y += ball_speed_y;
        
        if(sqrt(pow(ball_x-aim_x,2) + pow(ball_y-aim_y,2))<aim_radius){
            aim_x = rand()%(SCREEN_WIDTH-2*aim_radius)+aim_radius;
            aim_y = rand()%(SCREEN_HEIGHT-2*aim_radius)+aim_radius;
        }
        BeginDrawing();
            ClearBackground(GRAY);
            DrawCircle(ball_x,ball_y,ball_radius, WHITE);
            DrawCircle(aim_x,aim_y,aim_radius, RED);
        EndDrawing();
    }

    CloseWindow();
}