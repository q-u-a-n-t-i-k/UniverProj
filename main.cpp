/*#include <iostream>
#include <raylib.h>
#include <cmath>

#include "properties.cpp"
#include "button.cpp"

using namespace std;



int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    SetTargetFPS(60);
    Button btn(100,100,200,75,40,(char*)"Button");

    while (WindowShouldClose() == false){
    
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
    }

    CloseWindow();
}*/

/*#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input mouse wheel");

    int boxPositionY = screenHeight/2 - 40;
    int scrollSpeed = 4;            // Scrolling speed in pixels

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        boxPositionY -= (int)(GetMouseWheelMove()*scrollSpeed);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangle(screenWidth/2 - 40, boxPositionY, 80, 80, MAROON);

            DrawText("Use mouse wheel to move the cube up and down!", 10, 10, 20, GRAY);
            DrawText(TextFormat("Box position Y: %03i", boxPositionY), 10, 40, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}*/
#include "raylib.h"
#include "Counter.h"

int main() {
    // Ініціалізація вікна
    InitWindow(800, 600, "Multiple Counters Example");
    SetTargetFPS(60);

    // Створення двох лічильників
    Counter goldCounter(50, 1000, {50, 50}, 30, GOLD, "gold");     // Лічильник для золота
    Counter coalCounter(0, 1000, {50, 100}, 30, DARKGRAY, "coal"); // Лічильник для вугілля

    while (!WindowShouldClose()) { // Головний цикл програми
        // Логіка для золота
        if (IsKeyPressed(KEY_W)) {
            goldCounter.increment(5); // Збільшуємо золото
        }
        if (IsKeyPressed(KEY_S)) {
            goldCounter.decrement(4); // Зменшуємо золото
        }

        // Логіка для вугілля
        if (IsKeyPressed(KEY_E)) {
            coalCounter.increment(5); // Збільшуємо вугілля
        }
        if (IsKeyPressed(KEY_D)) { 
            coalCounter.decrement(4); // Зменшуємо вугілля
        }

        // Візуалізація
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Відображення лічильників
        goldCounter.draw(); // Малюємо лічильник золота
        coalCounter.draw(); // Малюємо лічильник вугілля

        // Підказки для користувача
        DrawText("Gold (W/S): Increment/Decrement", 50, 500, 20, DARKBLUE);
        DrawText("Coal (E/D): Increment/Decrement", 50, 530, 20, DARKBLUE);

        EndDrawing();
    }

    // Закриття вікна
    CloseWindow();
    return 0;
}