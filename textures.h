#ifndef TEXTURES_H
#define TEXTURES_H

#include <raylib.h>
#include <vector>
#include <array>

using namespace std;

class Textures{
    private:
        vector<array<int,3>> draw_queue;
        array<Texture2D,6> plants[2];
        array<Texture2D,8> ground;
        array<Texture2D,5> trees;

        Texture2D get_texture(int type){
            if((int)type/100 == 0) return ground[type];
            else if((int)(type/100) == 1) return plants[(type-100)/10][type%10];
            else if((int)(type/100) == 2) return trees[type%10];
            return ground[0];
        }
    public:
        void Load(){
        plants[0]={
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/bed.png")};
        plants[1]={
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/111.png"),
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/bed.png"),
            LoadTexture("resources/textures/bed.png")};

        ground={
            LoadTexture("resources/textures/1.png"),
            LoadTexture("resources/textures/1.png"),
            LoadTexture("resources/textures/2.png"),
            LoadTexture("resources/textures/3.png"),
            LoadTexture("resources/textures/4.png"),
            LoadTexture("resources/textures/5.png"),
            LoadTexture("resources/textures/6.png"),
            LoadTexture("resources/textures/7.png")};

        trees={
            LoadTexture("resources/textures/grass.png"),
            LoadTexture("resources/textures/201.png"),
            LoadTexture("resources/textures/202.png"),
            LoadTexture("resources/textures/203.png"),
            LoadTexture("resources/textures/204.png")};
        }

        void add(int type, int x, int y){
            array<int,3> a = {type,x,y};
            draw_queue.push_back(a);
        }

        void calculate(){
            draw_queue = {};
        }
        void draw(bool building, int building_target){
            for (int i = 0; i < (int)draw_queue.size(); i++) {
                Color col = WHITE;
                // if(building && not (building_target/100 == draw_queue[i][0]/100 && draw_queue[i][0] <= building_target)) col = (Color){255,80,80,255};
                DrawTexture(get_texture(draw_queue[i][0]),draw_queue[i][1],draw_queue[i][2],col);
            }
        }
};

#endif