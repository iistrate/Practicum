#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
private:
	//location on screen
	int m_ix;
	int m_iy;
	//image attributes
	int m_iwidth;
	int m_iheight;
	//layer; z-index
	int m_ilayer;
	//animated
	bool m_banimated;
	int m_icurrentFrame;
	int m_itotalFrames;
	//file name
	const char* m_sfname;
	//image location
	int m_ispriteX;
	int m_ispriteY;
	//is flipped
	bool m_bflipped;

public:
	Image();
	Image(const char* fname, int x, int y, int width, int height, int sX, int sY, int layer, bool a, int cf, int tf);
	~Image();
	
	//setter
	void load(const char* fname, int x, int y, int width, int height, int sX, int sY, int layer, bool a, int cf, int tf);
	void setX(int);
	void setY(int);
	void setFlipped(bool b);
	void setCurrentFrame(int i);
	//getters
	bool isFlipped();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	int getLayer();
	bool isAnimated();
	int getFrame();
	int getTotalFrames();
	const char* getFileName();
	int getSpriteX();
	int getSpriteY();
};

#endif // Image.h