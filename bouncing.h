#ifndef _BOUNCING_H
#define _BOUNCING_H

/* ********************** *
 * Author: Denis Laesker  *
 ************************ */

/* Description: abstract class component to implement "bounciness" */

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
#include <math.h>

class BOUNCING {
protected:
	sf::CircleShape ball;
	float dy;
	const float gravity;
	float elasticity;

public:
	BOUNCING(float _dy, float _gravity, float _elasticity)
		: dy(_dy), gravity(_gravity), elasticity(_elasticity) {}
	
	virtual ~BOUNCING() = default;
	virtual void update(){};
	virtual void reset(){};
	virtual void draw(sf::RenderWindow& render){};
	
	virtual void setPosition(){};
	virtual void setRadius(){};
	virtual void setPointCount(){};
	virtual void setFillColor(){};
	virtual void setElasticity(){};
	virtual void setOrigin(){};
};

#endif
