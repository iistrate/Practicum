
#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include "Image.h"
#include "GLOBALS.h"

class Tile : public GameObject {
private:
	int m_type;

public:
	Tile(int x, int y, int w, int h, int t);
	~Tile();

	void setType(int t);
	int getType();
};

#endif // Tile.h