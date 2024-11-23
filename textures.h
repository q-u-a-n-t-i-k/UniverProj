#ifndef TEXTURES_H
#define TEXTURES_H

#include <raylib.h>
#include <vector>
#include <array>

using namespace std;

class Textures{
    private:
        vector<Texture2D> draw_queue;
        vector<array<int,2>> draw_cord;
        Texture2D bed = LoadTexture("resources/textures/bed.png");
        Texture2D ground[6]={
            LoadTexture("resources/textures/1.png"),
            LoadTexture("resources/textures/1.png"),
            LoadTexture("resources/textures/2.png"),
            LoadTexture("resources/textures/3.png"),
            LoadTexture("resources/textures/4.png"),
            LoadTexture("resources/textures/5.png")};

        Texture2D tree[5]={
            LoadTexture("resources/textures/grass.png"),
            LoadTexture("resources/textures/201.png"),
            LoadTexture("resources/textures/202.png"),
            LoadTexture("resources/textures/203.png"),
            LoadTexture("resources/textures/204.png")};
    public:
        Texture2D get_texture(int type){
            if((int)type/100 == 0) return ground[type];
            else if((int)(type/100) == 2) return tree[type%10];
            return bed;
        }

        void add(int type, int x, int y){
            draw_queue.push_back(get_texture(type));
            array<int,2> a = {x,y};
            draw_cord.push_back(a);
        }

        void calculate(){
            draw_queue = {};
        }
        void draw(){
            for (int i = 0; i < (int)draw_queue.size(); i++) {
                DrawTexture(draw_queue[i],draw_cord[i][0],draw_cord[i][1],WHITE);
            }
        }
};

#endif