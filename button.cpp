#include <raylib.h>

class Button{
    public:
        float pos_x, pos_y;
        int width, height;
        int font_size, len;
        char * text;
        bool hover = false, pressed=false, down = true;
        Color color, default_color = GRAY, hover_color = LIGHTGRAY, pressed_color = DARKGRAY, text_color = BLACK;
        Font font = LoadFontEx("resources/fonts/Panoptica.ttf", 40, 0, 0);


        void Draw(){
            DrawRectangle(pos_x,pos_y,width,height,color);
            int t_w = MeasureText(text,font_size);
            DrawTextEx(font,text,(Vector2){ pos_x+(width-t_w)/2, pos_y+(height-font.baseSize)/2},font_size,0,text_color);
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

        Button(float x, float y, int w, int h, int f_s, char t[]){
            pos_x = x;
            pos_y = y;
            width = w;
            height = h;
            text = t;
            font_size = f_s;
        }
};