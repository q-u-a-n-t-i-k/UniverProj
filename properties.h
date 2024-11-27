#ifndef PROP_H
#define PROP_H

#include <string>
#include "textures.h"
//global var
extern Textures Img;
extern bool building, pause;
extern int money, coal, iron, oxygen, temperature, building_type, building_target;
extern int requi[3];
extern Font font;
//const var
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const char WINDOW_NAME[] = "Game";
const static int height = 15, width=25;
const Color TileColor = (Color){224,94,65,255};

#endif