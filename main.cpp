
#include "raylib.h"
#include "Counter.h"

int main() {
    // Ініціалізація вікна
    InitWindow(800, 600, "Multiple Counters Example");
    SetTargetFPS(60);

    // Створення двох лічильників
    Counter goldCounter(50, 1000, {50, 50}, 30, GOLD,  "resources/textures/coal.png");     // Лічильник для золота
    Counter coalCounter(0, 1000, {50, 200}, 60, DARKGRAY,  "resources/textures/coal.png"); // Лічильник для вугілля

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