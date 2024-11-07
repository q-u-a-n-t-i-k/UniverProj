
#include <raylib.h>
#include <cmath>


using namespace std;
class progressbar{
    public:
        float pos_x, pos_y;
        int width, height, thickness, fullbar;
        int font_size, len;
        char * text;
        bool  pressed=false, down = true;
        Color color, color_bar, beg_color, text_color = BLACK;
        Font font = LoadFontEx("resources/fonts/Panoptica.ttf", 40, 0, 0);


        void Draw(){
            DrawRectangle(pos_x, pos_y, width, height, color);
            DrawRectangle(pos_x+thickness, pos_y+thickness, fullbar ,height-2*thickness,color_bar);
            DrawRectangleLines(pos_x+thickness, pos_y+thickness, width-2*thickness, height-2*thickness, beg_color);
            int t_w = MeasureText(text,font_size);
            DrawTextEx(font,text,(Vector2){ pos_x+(width-t_w)/2, pos_y+(height-font.baseSize)/2},font_size,0,text_color);
        }
        progressbar(float x, float y, int w, int h, int f_s, char t[]){
            pos_x = x;
            pos_y = y;
            width = w;
            height = h;
            text = t;
            font_size = f_s;
        }
};