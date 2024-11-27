#include <iostream>
#include <raylib.h>
#include <cmath>
#include <array>
#include <fstream>
#include "properties.h"
#include "progresbar.h"
#include "textures.h"
#include "button.h"
#include "farm.h"
#include "goods.h"
#include "Counter.h"
// init val for externs in properties
Textures Img;
bool building = false, pause =false, win = false;
int money = 50, coal = 0, iron = 0, oxygen = 0, temperature = 0, building_target = 5, building_type = 200, requi[3];
Font font;
Farm pole;// game area(its init must be first)
using namespace std;

void savefile()
{
    ofstream file("Save.txt");
    file << money << '\n' << coal << '\n' << iron << '\n';
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            file << pole.matrix[i][j].type << ' ';
    file.close();
}

void loadsave()
{
    ifstream file("Save.txt");
    if(!(file >> money))
    {
        money = 50;
        coal = 0;
        iron = 0;
        pole = Farm();
    }
    else
    {
        file >> coal >> iron;
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
                file >> pole.matrix[i][j].type;
        file.close();
    }
}

void newgame(){
    ofstream file("Save.txt");
    file.close();
    pause = false;
    loadsave();
}

void OXG(){
    oxygen=0;
    for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if (pole.matrix[i][j].type == 200)
                    oxygen+=0;
                else if (pole.matrix[i][j].type == 201)
                    oxygen+=1;
                else if (pole.matrix[i][j].type == 202)
                    oxygen+=2;
                else if (pole.matrix[i][j].type == 203)
                    oxygen+=2;
                else if (pole.matrix[i][j].type == 204)
                    oxygen+=2;
            }
        }
        if (oxygen>20) oxygen =20;
}

void T(){
    temperature = 0;
    for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if (pole.matrix[i][j].type == 300)
                    temperature +=10;
            }
        }
    if (temperature>100) temperature =100;
}

int main () {
    InitAudioDevice();              
    Music music = LoadMusicStream("resources/musik/trasovuna.mp3");
    PlayMusicStream(music);
    SetMusicVolume(music, 0);
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);
    SetExitKey(KEY_K);
    font =  LoadFontEx("resources/fonts/Panoptica.ttf", 40, 0, 0);
    int m_x, m_y;//mouse cord
    Img.Load();//load images

    Button btn(1660,985,200,70,40,(char*)"Continue");
    btn.default_color = GREEN;
    Button cancel(40,980,64,64,40,(char*)"X");
    cancel.default_color = RED;

    Counter goldCounter(0, 10000, {1640, 50}, 40, WHITE,  "resources/icons/coin.png");     // Лічильник для золота

    Counter coalCounter(0, 1000, {1640, 100}, 40, WHITE,  "resources/icons/coal.png"); // Лічильник для вугілля

    Counter steelCounter(0, 1000, {1640, 150}, 40, WHITE,  "resources/icons/steel.png");     // Лічильник для золота
   
    Progressbar O2(1660,840,200,50,40,5,(char*)"O2",1);
    O2.color_bar1 = SKYBLUE;
    O2.color_bar2 = BLUE ;
    O2.beg_color = LIGHTGRAY;
    O2.color = DARKGRAY;

    Progressbar Temp(1660,910,200,50,40,5,(char*)"T(K)",1);
    Temp.color_bar1 = RED;
    Temp.color_bar2 = YELLOW;
    Temp.beg_color = LIGHTGRAY;
    Temp.color = DARKGRAY;

    array<int,5> ar;
    Goods shop[11];

    Button Cont(700,350,500,145,40,(char*)"Continue");
    Cont.default_color = DARKGRAY;
    Button NewG(700,500,500,145,40,(char*)"New Game");
    NewG.default_color = DARKGRAY;
    Button Save(700,650,500,145,40,(char*)"Save");
    Save.default_color = DARKGRAY;
    loadsave();

    ar = {20,0,0,0,0};
    shop[0] = Goods(200,980,5,100,ar,100);
    ar = {25,0,0,0,0};
    shop[1] = Goods(300,980,5,200,ar,200);
    ar = {30,4,2,0,0};
    shop[2] = Goods(400,980,5,300,ar,300);
    ar = {5,0,0,0,0};
    shop[3] = Goods(550,980,100,101,ar,121);
    ar = {10,0,0,0,10};
    shop[4] = Goods(650,980,100,102,ar,122);
    ar = {16,0,0,4,20};
    shop[5] = Goods(750,980,100,103,ar,123);
    ar = {20,0,0,9,50};
    shop[6] = Goods(850,980,100,104,ar,124);
    ar = {24,0,0,20,80};
    shop[7] = Goods(950,980,100,105,ar,125);
    ar = {30,0,0,0,20};
    shop[8] = Goods(1050,980,200,201,ar,121);
    ar = {15,0,0,0,0};
    shop[9] = Goods(1200,980,402,0,ar,403);
    ar = {0,0,0,0,0};
    shop[10] = Goods(1300,980,115,100,ar,404);

    while (WindowShouldClose() == false){
        //update variables
        UpdateMusicStream(music); 
        if(pause){
            Cont.calculate();
            NewG.calculate();
            Save.calculate();
            if(Cont.pressed)
                pause = false;
            else if(NewG.pressed)
            {
                newgame();
            }
            else if(Save.pressed)
            {
                savefile();
                break;
            }
        }
        else{
            pole.calculate();
            Img.calculate();
            OXG();
            O2.fullbar=oxygen*5;
            T();
            Temp.fullbar=temperature;
            goldCounter.reset(money);
            coalCounter.reset(coal);
            steelCounter.reset(iron);
            m_x = (GetMouseX()-GetMouseX()%64)/64;
            m_y = (GetMouseY()-GetMouseY()%64)/64;

            if(!building){
                btn.calculate();
                if(temperature==100 && oxygen ==20&&money >= 1000){
                    win = true;
                    newgame();
                }
                if(IsKeyPressed(KEY_ESCAPE)) pause = true;
                for(int i = 0; i < 11;i++) shop[i].calculate();
                
                if(m_x < 25 && m_y < 15)
                    pole.matrix[m_y][m_x].hover = 2;// border width (px)
                else if(btn.pressed){ pole.nextDay();}
            }
            else{
                
                cancel.calculate();
                if(m_x < 25 && m_y < 15){
                    if(building_target == 5) pole.matrix[m_y][m_x].hover = 2;// border width (px)
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        if(building_target/100 == pole.matrix[m_y][m_x].type/100 && (building_target/10)%10 == (pole.matrix[m_y][m_x].type/10)%10 && pole.matrix[m_y][m_x].type <= building_target){
                            if(money >= requi[0] && coal >= requi[1] && iron >= requi[2]){
                            pole.build(m_y,m_x,building_type);
                            money -= requi[0];
                            coal -= requi[1];
                            iron -= requi[2];}
                        }
                    }
                }
                else if(cancel.pressed){building = false;}
            }
            
        }
        
        //drawing
        BeginDrawing();
            if (win){
                ClearBackground(DARKGRAY);
                DrawTextEx(font,"You Win", (Vector2){620, 444}, 192, 0, WHITE);
            }
            else if(pause){
                DrawRectangle(700,200,500,600,GRAY);
                DrawRectangle(700,200,500,145,LIGHTGRAY);
                DrawTextEx(font,"MENU", (Vector2){775, 175}, 150, 0, DARKGRAY);
                Cont.Draw();
                NewG.Draw();
                Save.Draw();
            }
            else{
            ClearBackground(GREEN);
            if(building)ClearBackground(YELLOW);
            
            DrawRectangle(1920-64*5,0,64*5,1080,GRAY);
            DrawRectangle(0,64*15,1920,120,GRAY);

            pole.draw();
            
            pole.draw_building();
            for(int i = 0; i < 11;i++) shop[i].draw();
            Img.draw(building,building_target);       

            
            if(building) cancel.Draw();
            else btn.Draw();
            O2.Draw();
            Temp.Draw();
            goldCounter.draw(); 
            coalCounter.draw();
            steelCounter.draw();
            }
            
        EndDrawing();
        
    }
  UnloadMusicStream(music);   // Unload music stream buffers from RAM
    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)
    CloseWindow();
    
}