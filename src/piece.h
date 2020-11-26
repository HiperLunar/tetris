
#include <vector>

namespace tetris
{
    class Piece
    {
        public:
            std::vector<int> shape;
            Piece(std::vector<int> shape);

            int size();
            void rotate();
    };

    static Piece pieces[] = {
        Piece({
            0, 0, 0, 0,
            1, 1, 1, 1,
            0, 0, 0, 0,
            0, 0, 0, 0
        }),
        Piece({
            0, 0, 0,
            1, 1, 1,
            1, 0, 0
        }),
        Piece({
            0, 0, 0,
            1, 1, 1,
            0, 0, 1
        }),
        Piece({
            1, 1,
            1, 1
        }),
        Piece({
            0, 0, 0,
            1, 1, 0,
            0, 1, 1
        }),
        Piece({
            0, 0, 0,
            1, 1, 1,
            0, 1, 0
        }),
        Piece({
            0, 0, 0,
            0, 1, 1,
            1, 1, 0
        })
    };
}
