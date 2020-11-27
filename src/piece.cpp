
#include "piece.h"

tetris::Piece::Piece(int len, std::vector<int> shape)
{
	length = len;
    this -> shape = shape;
};

int tetris::Piece::size() {
    return (int) shape.size();
}

void tetris::Piece::rotate()
{
	std::vector<int> result(shape.size());

	float xp = (length-1)/2.0;
	float yp = (length-1)/2.0;

	for (int i = 0; i < shape.size(); ++i) {
		float x = yp - (i / length) + xp;
		float y = (i % length) - xp + yp;

		result[i] = shape[y*length+x];
	}

    shape = result;
};
