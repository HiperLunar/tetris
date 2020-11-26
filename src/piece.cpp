
#include "piece.h"

tetris::Piece::Piece(std::vector<int> shape)
{
    this -> shape = shape;
};

int tetris::Piece::size() {
    return (int) shape.size();
}

void tetris::Piece::rotate()
{
    int len = shape.size();
    std::vector<int> result(len);

	int xp = 1;
	int yp = 1;

	for (int i = 0; i < len; ++i) {
		int x = yp - ( i / 3) + xp;
		int y = (i % 3) - xp + yp;

		result[i] = shape[y * 3 + x];
	}

    shape = result;
};
