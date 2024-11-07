#include <iostream>
#include <raylib.h>
#include <cmath>

#include "properties.cpp"
#include "button.cpp"

using namespace std;



int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);
    Button btn(100,100,200,75,40,(char*)"Button");
    InitAudioDevice();              
    Music music = LoadMusicStream("resources/musik/trasovuna.mp3");
    PlayMusicStream(music);
    float timePlayed = 0.0f;
    
    while (WindowShouldClose() == false){
        UpdateMusicStream(music); 
        btn.Calculate();
        BeginDrawing();
        ClearBackground(LIME);
            btn.Draw();
            DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
            DrawRectangle(0,64*15,1920,120,GRAY);
            for(int i = 0; i < 25; i++){
                for(int j = 0; j < 15; j++){
                    if((i+j)%2 == 1) DrawRectangle(i*64,j*64,64,64,ORANGE);
                }
            }
            
        EndDrawing();
        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);
        if (timePlayed > 1.0f) {
            timePlayed = 1.0f;
             BeginDrawing();
                DrawRectangle(200, 200, (int)(timePlayed*400.0f), 12, MAROON);
             EndDrawing();
        }
         
    return 0;
    }

    UnloadMusicStream(music);   // Unload music stream buffers from RAM
    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)
    CloseWindow();       
}