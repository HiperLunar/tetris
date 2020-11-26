
#include <vector>

namespace tetris
{
    class Map
    {
        private:
            int width, height;
            std::vector<int> map;

        public:
            Map(int w, int h);
            
            int getWidth() {return width;}
            int getHeight() {return height;}
            
            int get(int i);
            int get(int x, int y);

            void set(int i, int value);
            void set(int x, int y, int value);

            int& operator[](int i);
    };
}