#include <iostream>
#include <raylib.h>
#include <cmath>

#include "properties.cpp"

using namespace std;

class Button{
    private:
        bool hover = false, pressed=false, down = true;

    public:
        int pos_x, pos_y;
        int width, height;
        int font_size;
        char * text;
        Color color, default_color = GRAY, hover_color = LIGHTGRAY, pressed_color = DARKGRAY, text_color = BLACK;
    
        void BtnPressed(){cout <<"press";};
        void BtnDown(){cout <<"dooown";};

        void Draw(){
            DrawRectangle(pos_x,pos_y,width,height,color);
            DrawText(text,pos_x,pos_y+height/2-font_size/2,font_size,text_color);
        }
        
        void Calculate(){
            pressed = false;
            hover = false;
            down = false;

            if(GetMouseX() > pos_x && GetMouseX() < pos_x+width && GetMouseY() > pos_y && GetMouseY() < pos_y + height){
                hover = true;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) pressed = true;
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) down = true;}

            color = default_color;
            if(hover) color = hover_color;
            if(pressed) BtnPressed();
            if(down){
                color = pressed_color;
                BtnDown();}
                     
        }
};

int main () {

    int ball_x = 100;
    int ball_y = 100;
    int ball_speed_x = 5;
    int ball_speed_y = 5;
    int ball_radius = 15;
    int aim_radius = 30;
    int aim_x = rand()%(SCREEN_WIDTH-2*aim_radius)+aim_radius;
    int aim_y = rand()%(SCREEN_HEIGHT-2*aim_radius)+aim_radius;

    Button btn;
    btn.pos_x = 100;
    btn.pos_y = 100;
    btn.width = 200;
    btn.height = 75;
    btn.font_size = 40;
    btn.text = "Button";

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        
        btn.Calculate();
        if(IsKeyDown(KEY_D) && ball_x + ball_radius + ball_speed_x <= SCREEN_WIDTH)
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
            ClearBackground(LIME);
            DrawCircle(ball_x,ball_y,ball_radius, WHITE);
            DrawCircle(aim_x,aim_y,aim_radius, RED);
            btn.Draw();
        EndDrawing();
    }

    CloseWindow();
}