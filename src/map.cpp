
#include "map.h"

using namespace tetris;

Map::Map(int w, int h) {
    width = w;
    height = h;
    map = std::vector<int>(width * height);
}

int Map::get(int i) {return map[i];}
int Map::get(int x, int y) {return map[y * width + x];}

void Map::set(int i, int value) {map[i] = value;}
void Map::set(int x, int y, int value) {map[y * width + x] = value;}

int& Map::operator[](int i) {return map[i];}
