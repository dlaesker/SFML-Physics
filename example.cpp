#include "ball.h"

/* ********************** *
 * Author: Denis Laesker  *
 ************************ */

/* Description: A visual ilustration of bounciness using SFML. Use the mouse to control where the circle/ball spawns and watch it bounce :)
 */

// BBAL ball(dy, gravity, elasticity
BBALL ball(0.0, 0.04, 0.5);

int main(){
	sf::RenderWindow window(sf::VideoMode(WIN_SIZE,WIN_SIZE), "Bouncing");
		
	// Initialize bouncing ball object
	ball.setOrigin(RADIUS, RADIUS);
	ball.setPointCount(POINT_COUNT);
	ball.setFillColor(sf::Color::Blue);
	ball.setRadius(RADIUS);
	ball.setPosition(WIN_SIZE/2, WIN_SIZE/2);
	ball.setElasticity(0.5);
	
	
	sf::Time elapsedTime, deltaTime;
	
	sf::Event ev;
	sf::Clock clock;
	while(window.isOpen()){
		while(window.pollEvent(ev)){
			if(ev.type == sf::Event::Closed)
				window.close();
		}
		
		deltaTime = clock.restart();
		elapsedTime += deltaTime;
		float timeAsMilliseconds = elapsedTime.asMilliseconds();
		
		if(timeAsMilliseconds >= 10.0){
			window.clear(sf::Color::White);
			
			// If the left mouse button has been clicked
			if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
				// Update the position of the ball
				sf::Vector2i mpos = sf::Mouse::getPosition(window);
				ball.setPosition(mpos.x, mpos.y);
				
				// Reset dy
				ball.reset();
			}
			
			ball.update(); 
			ball.draw(window);
			elapsedTime = sf::Time::Zero;
			window.display();
		}
		
	}
	return 0;
}

