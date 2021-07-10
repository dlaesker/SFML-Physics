#include "ball.h"

/* ********************** *
 * Author: Denis Laesker  *
 ************************ */

/* Description: Implementation file for the "ball" class and its bouncing component. */

BBALL::	~BBALL(){}

/* Updates the position of the ball based on its current position, gravity, and elasticity. */
void BBALL::update(){
	sf::Vector2f pos = ball.getPosition();
	
	// Keep it within the the window bounds.
	if(pos.y + RADIUS < WIN_SIZE && pos.y >= RADIUS){
		pos.y += dy;
		dy += gravity;
	}else{
		dy *= -elasticity;
		pos.y += dy*2;
		if(fabsf(dy) < 0.1){
			dy = 0.0;
		}
	}
	
	ball.setPosition(pos);
}

void BBALL::reset(){dy = 0.0;}

void BBALL::draw(sf::RenderWindow& render){
	render.draw(ball);
}

void BBALL::setPosition(float x, float y){
	// Have we gone out of the window bounds?
	if(x < RADIUS) x += RADIUS;
	if(x >= RADIUS + WIN_SIZE) x -= RADIUS;
	
	if(y < RADIUS) y += RADIUS;
	if(y >= RADIUS + WIN_SIZE) y -= RADIUS;
	
	ball.setPosition((int)x, (int)y);
}

void BBALL::setRadius(int r){
	ball.setRadius(r);
}
void BBALL::setPointCount(int pointCount){
	ball.setPointCount(pointCount);
}

void BBALL::setFillColor(sf::Color clr){
	ball.setFillColor(clr);
}

void BBALL::setElasticity(float elasticity){
	this->elasticity = elasticity;
}

void BBALL::setOrigin(int x, int y){
	ball.setOrigin(x, y);
}

