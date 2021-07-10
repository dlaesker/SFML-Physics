#ifndef _BALL_H
#define _BALL_H
#include "bouncing.h"

/* ********************** *
 * Author: Denis Laesker  *
 ************************ */

/*
 Description: Header file for the "ball" class which inherits from "bouncing."
 */

#define WIN_SIZE 		 600
#define RADIUS 				32
#define POINT_COUNT 1000

class BBALL : public BOUNCING {
public:

	BBALL(float _dy, float _gravity, float _elasticity)
		: BOUNCING(_dy, _gravity, _elasticity) {}
	
	~BBALL();
	
	void update();
	void reset();
	void draw(sf::RenderWindow& render);
	
	void setPosition(float x, float y);
	void setRadius(int r);
	void setPointCount(int pointCount);
	void setFillColor(sf::Color clr);
	void setElasticity(float elasticity);
	void setOrigin(int x, int y);
};

#endif
