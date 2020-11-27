
#include <vector>

namespace tetris
{
    class Piece
    {
        private:
            int length;
        public:
            std::vector<int> shape;
            Piece(int len, std::vector<int> shape);

            int size();
            int len() {return length;}
            void rotate();
    };

    static Piece pieces[] = {
        Piece(4, {
            0, 0, 0, 0,
            1, 1, 1, 1,
            0, 0, 0, 0,
            0, 0, 0, 0
        }),
        Piece(3, {
            0, 0, 0,
            1, 1, 1,
            1, 0, 0
        }),
        Piece(3, {
            0, 0, 0,
            1, 1, 1,
            0, 0, 1
        }),
        Piece(2, {
            1, 1,
            1, 1
        }),
        Piece(3, {
            0, 0, 0,
            1, 1, 0,
            0, 1, 1
        }),
        Piece(3, {
            0, 0, 0,
            1, 1, 1,
            0, 1, 0
        }),
        Piece(3, {
            0, 0, 0,
            0, 1, 1,
            1, 1, 0
        })
    };
}
