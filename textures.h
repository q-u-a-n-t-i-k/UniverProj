#ifndef TEXTURES_H
#define TEXTURES_H

#include <raylib.h>
#include <vector>
#include <array>

using namespace std;

class Textures{
    private:
        vector<array<int,4>> draw_queue;
        Texture2D heater;
        array<Texture2D,6> plants[3];
        array<Texture2D,6> ground;
        array<Texture2D,5> trees;
        array<Texture2D,4> resources;

        Texture2D get_texture(int type){
            if((int)type/100 == 0) return ground[type];
            else if((int)(type/100) == 1) return plants[(type-100)/10][type%10];
            else if((int)(type/100) == 2) return trees[type%10];
            else if((int)(type/100) == 3) return heater;
            else if((int)(type/100) == 4) return resources[type%10-1];
            return ground[0];
        }
    public:
        void Load(){
            heater = LoadTexture("resources/textures/heater.png");
            resources={LoadTexture("resources/textures/6.png"),
                    LoadTexture("resources/textures/7.png"),
                    LoadTexture("resources/textures/pickaxe.png"),
                    LoadTexture("resources/textures/sickle.png")};
            plants[0]={
                LoadTexture("resources/textures/bed.png"),
                LoadTexture("resources/textures/wheat_0.png"),
                LoadTexture("resources/textures/carrot_0.png"),
                LoadTexture("resources/textures/beet_0.png"),
                LoadTexture("resources/textures/corn_0.png"),
                LoadTexture("resources/textures/garlic_0.png")};
            plants[1]={
                LoadTexture("resources/textures/bed.png"),
                LoadTexture("resources/textures/wheat_1.png"),
                LoadTexture("resources/textures/carrot_1.png"),
                LoadTexture("resources/textures/beet_1.png"),
                LoadTexture("resources/textures/corn_1.png"),
                LoadTexture("resources/textures/garlic_1.png")};

            plants[2]={
                LoadTexture("resources/textures/seedbag.png"),
                LoadTexture("resources/textures/seedbag.png"),
                LoadTexture("resources/textures/seedbag.png"),
                LoadTexture("resources/textures/seedbag.png"),
                LoadTexture("resources/textures/seedbag.png"),
                LoadTexture("resources/textures/seedbag.png")};

            ground={
                LoadTexture("resources/textures/1.png"),
                LoadTexture("resources/textures/1.png"),
                LoadTexture("resources/textures/2.png"),
                LoadTexture("resources/textures/3.png"),
                LoadTexture("resources/textures/4.png"),
                LoadTexture("resources/textures/5.png")};

            trees={
                LoadTexture("resources/textures/grass.png"),
                LoadTexture("resources/textures/201.png"),
                LoadTexture("resources/textures/202.png"),
                LoadTexture("resources/textures/203.png"),
                LoadTexture("resources/textures/204.png")};
        }

        void add(int type, int x, int y, int al = 255){
            array<int,4> a = {type,x,y,al};
            draw_queue.push_back(a);
        }

        void calculate(){
            draw_queue = {};
        }
        void draw(bool building, int building_target){
            for (int i = 0; i < (int)draw_queue.size(); i++) {
                Color col = (Color){255,255,255,draw_queue[i][3]};
                DrawTexture(get_texture(draw_queue[i][0]),draw_queue[i][1],draw_queue[i][2],col);
            }
        }
};

#endif