#ifndef __DEBUG_H__
#define __DEBUG_H__
#include <SFML/Graphics.hpp>
void sleep(sf::Time, sf::Clock);

class Sprite {
	float dx = 40.f;
	float dy = 80.f;
	float w = 100.f;
	float h = 60.f;

	float x;
	float y;
	short* max_x;
	short* max_y;
	sf::RectangleShape rect;
	sf::RectangleShape extrapolated_rect;
	
	public:
	Sprite(short* win_width, short* win_height);

	void update();

	sf::RectangleShape getShape(float steps_ahead);

    sf::RectangleShape getShape();
};
#endif//__DEBUG_H__