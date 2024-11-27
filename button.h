#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>
#include "properties.h"

class Button{
    public:
        float pos_x, pos_y;
        int w, h;
        int font_size, len;
        char * text;
        bool hover = false, pressed=false, down = true;
        Color color, default_color = GRAY, hover_color = LIGHTGRAY, pressed_color = DARKGRAY, text_color = BLACK;


        void Draw(){
            DrawRectangle(pos_x,pos_y,w,h,color);
            int t_w = MeasureText(text,font_size);
            DrawTextEx(font,text,(Vector2){ pos_x+(w-t_w)/2, pos_y+(h-font.baseSize)/2},font_size,0,text_color);
        }
        
        void calculate(){
            pressed = false;
            hover = false;
            down = false;

            if(GetMouseX() > pos_x && GetMouseX() < pos_x+w && GetMouseY() > pos_y && GetMouseY() < pos_y + h){
                hover = true;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) pressed = true;
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) down = true;}

            color = default_color;
            if(down)color = pressed_color;
            else if(hover) color = hover_color;
                     
        }

        Button(float x, float y, int w, int h, int f_s, char t[]){
            pos_x = x;
            pos_y = y;
            this->w = w;
            this->h = h;
            text = t;
            font_size = f_s;
        }
};
#endif