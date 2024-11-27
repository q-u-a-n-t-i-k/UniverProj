#ifndef PROGRESBAR_H
#define PROGRESBAR_H

#include <raylib.h>
#include <cmath>


using namespace std;
class Progressbar{
    public:
        float pos_x, pos_y;
        int width, height, thickness, fullbar;
        int font_size, len;
        char * text;
        bool  pressed=false, down = true, ishorizon;
        Color color, color_bar1,color_bar2, beg_color, text_color = BLACK;
        Font font = LoadFontEx("resources/fonts/Panoptica.ttf", 40, 0, 0);


        void Draw(){
            

            if (ishorizon == true){
                DrawRectangle(pos_x, pos_y, width, height, color);
                DrawRectangle(pos_x+thickness, pos_y+thickness, width-2*thickness, height-2*thickness, beg_color);
                DrawRectangleGradientH(pos_x+thickness, pos_y+thickness, ((width-2*thickness)/100.0)*fullbar ,height-2*thickness,color_bar1,color_bar2);
                int t_w = MeasureText(text,font_size);
                DrawTextEx(font,text,(Vector2){ pos_x+(width-t_w)/2, pos_y+(height-font.baseSize)/2},font_size,0,text_color);
            }
            else {
                DrawRectangle(pos_x, pos_y, height, width, color);
                DrawRectangle(pos_x+thickness, pos_y+thickness, height-2*thickness,width-2*thickness , beg_color);
                DrawRectangleGradientH(pos_x+thickness, pos_y+thickness, height-2*thickness ,((width-2*thickness)/100.0)*fullbar,color_bar1,color_bar2);
                int t_w = MeasureText(text,font_size);
                DrawTextEx(font,text,(Vector2){ pos_x+(width-t_w)/2, pos_y+(height-font.baseSize)/2},font_size,0,text_color);
            }
            
        }
        Progressbar(float x, float y, int w, int h, int f_s, int th, char t[],  bool hor){
            pos_x = x;
            pos_y = y;
            width = w;
            height = h;
            text = t;
            font_size = f_s;
            ishorizon = hor;
            thickness = th;
        }

};
#endif