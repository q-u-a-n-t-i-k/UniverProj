#include <iostream>
#include <raylib.h>
#include <cmath>

#include "properties.cpp"
#include "button.cpp"

using namespace std;



int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);

    const Texture2D beet = LoadTexture("resources/textures/plants/beet.png");
    const Texture2D bed = LoadTexture("resources/textures/structers/bed.png");
    const Texture2D rock[3] = {LoadTexture("resources/textures/structers/rock_1.png"),LoadTexture("resources/textures/structers/rock_2.png"),LoadTexture("resources/textures/structers/rock_3.png")};
    const Texture2D ground[2] = {LoadTexture("resources/textures/structers/ground_1.png"),LoadTexture("resources/textures/structers/ground_2.png")};

    Button btn(1920-64*5+60,64*15+25,200,70,40,(char*)"Continue");
    btn.default_color = GREEN;

    int area[15][25];

    while (WindowShouldClose() == false){
    
        btn.Calculate();
        if(btn.pressed){
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 25; j++){
                area[i][j] = 0;
                if (rand()%100<5){
                    area[i][j] = rand()%3+3;
                }
                else if (rand()%100<5){
                    area[i][j] = rand()%2+1;
                }
            }
        }

        }
        BeginDrawing();
            ClearBackground((Color){224,94,65,255});
            
            DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
            DrawRectangle(0,64*15,1920,120,GRAY);
            /*
            for(int i = 0; i < 25; i++){
                for(int j = 0; j < 15; j++){
                    if((i+j)%2 == 0) DrawRectangle(i*64,j*64,64,64,ORANGE);
                }
            }*/
            btn.Draw();
            for(int i = 0; i < 15; i++){
                for(int j = 0; j < 25; j++){
                    if(area[i][j] == 0) continue;
                    else if(area[i][j] == 1) DrawTexture(ground[0],64*j,64*i,WHITE);
                    else if(area[i][j] == 2) DrawTexture(ground[1],64*j,64*i,WHITE);
                    else if(area[i][j] == 3) DrawTexture(rock[0],64*j,64*i,WHITE);
                    else if(area[i][j] == 4) DrawTexture(rock[1],64*j,64*i,WHITE);
                    else if(area[i][j] == 5) DrawTexture(rock[2],64*j,64*i,WHITE);
                }
            }
        EndDrawing();
    }

    CloseWindow();
}