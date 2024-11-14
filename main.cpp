#include <iostream>
#include <raylib.h>
#include <cmath>
#include "progresbar.cpp"
#include "properties.cpp"
#include "button.cpp"

using namespace std;



int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);
    Button btn(100,100,200,75,40,(char*)"Button");
    Progressbar pr(200, 200, 200, 75, 40, 25, (char*)"LALA",0);
    pr.color =  GRAY;
    pr.beg_color =  LIGHTGRAY;
    pr.color_bar =  RED;
    pr.fullbar = 50;
    InitAudioDevice();              
    Music music = LoadMusicStream("resources/musik/trasovuna.mp3");
    PlayMusicStream(music);
    float timePlayed = 0.0f;
    
    while (WindowShouldClose() == false){
        UpdateMusicStream(music); 
        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);
        btn.Calculate();
        BeginDrawing();
        ClearBackground(LIME);
            btn.Draw();
            pr.Draw();/*
            DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
            DrawRectangle(0,64*15,1920,120,GRAY);
            for(int i = 0; i < 25; i++){
                for(int j = 0; j < 15; j++){
                    if((i+j)%2 == 1) DrawRectangle(i*64,j*64,64,64,ORANGE);
                }
            }
            */
        
        EndDrawing();
         
    }

    UnloadMusicStream(music);   // Unload music stream buffers from RAM
    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)
    CloseWindow();    
    return 0;   
}