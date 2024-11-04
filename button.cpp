#include <raylib.h>

class Button{
    public:
        int pos_x, pos_y;
        int width, height;
        int font_size;
        char * text;
        bool hover = false, pressed=false, down = true;
        Color color, default_color = GRAY, hover_color = LIGHTGRAY, pressed_color = DARKGRAY, text_color = BLACK;


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
            if(down)color = pressed_color;
            else if(hover) color = hover_color;
                     
        }

        Button(int x, int y, int w, int h, int f_s, char t[]){
            pos_x = x;
            pos_y = y;
            width = w;
            height = h;
            font_size = f_s;
            text = t;
        }
};