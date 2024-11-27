#ifndef COUNTER_H
#define COUNTER_H

#include "raylib.h"
#include <string>

class Counter {
private:
    int value;       // Поточне значення
    int maxValue;    // Максимальне значення
    Vector2 position; // Позиція для відображення на екрані
    int fontSize;    // Розмір тексту
    Color textColor; // Колір тексту
   std::string customText;     // текст
   Texture2D resourceImage;
   float scale;
   int spacing = 10;
public:
    Counter(int initialValue, int maxValue, Vector2 position, int fontSize, Color textColor, const char *resourceImageFile)
        : value(initialValue), maxValue(maxValue), position(position), fontSize(fontSize), textColor(textColor) {
            resourceImage = LoadTexture(resourceImageFile);
            scale = (float)fontSize/resourceImage.height;
        }

    // Збільшити лічильник(amount треба тільки потрібний поставити)
    void increment(int amount) {
        if (maxValue != -1 && value + amount > maxValue) {
            value = maxValue;
        } else {
            value += amount;
        }
    }

    // Зменшити лічильник(amount треба тільки потрібний поставити)
    void decrement(int amount) {
        if (value - amount < 0) {
            value = 0;
        } else {
            value -= amount;
        }
    }

    // Скинути лічильник
    void reset(int newValue = 0) {
        value = newValue;
    }

    // Отримати поточне значення
    int getValue() const {
        return value;
    }

    // Встановити значення
    void setValue(int newValue) {
        if (newValue > maxValue && maxValue != -1) {
            value = maxValue;
        } else {
            value = newValue;
        }
    }

    // Відобразити лічильник на 
    void draw() const {
        Vector2 origin =(Vector2){ 0, 0 };

        DrawTextureEx(resourceImage, position, 0.0f, scale, textColor);

        DrawText(std::to_string(value).c_str(), position.x + fontSize + spacing, position.y, fontSize, textColor);
    }
};

#endif // COUNTER_H