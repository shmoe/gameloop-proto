#include <stdlib.h>

#include "debug.hpp"
void sleep(sf::Time ms, sf::Clock clock){
	sf::Time curr = clock.getElapsedTime();
	while(clock.getElapsedTime() < curr + ms)
	{
	}
}

//class Sprite
Sprite::Sprite(short* win_width, short* win_height){
	x = 0.f; y = 0.f;
	max_x = win_width;
	max_y = win_height;
	rect = sf::RectangleShape(sf::Vector2f(w, h));
	rect.setFillColor(sf::Color::Green);
	extrapolated_rect =	sf::RectangleShape(rect.getSize());
	extrapolated_rect.setPosition(rect.getPosition());
	extrapolated_rect.setFillColor(sf::Color::Red);
}

void Sprite::update(){
	float new_x = x + dx;
	float new_y = y + dy;

	if(new_x < 0){
		new_x = 0;
		dx = -dx;
	}
	else if(new_x + w > *max_x){
		new_x = *max_x - w;
		dx = -dx;
	}

	if(new_y < 0){
		new_y = 0;
		dy = -dy;
	}
	else if(new_y + h > *max_y){
		new_y = *max_y - h;
		dy = -dy;
	}

	x = new_x;
	y = new_y;
	sf::Vector2f new_pos = sf::Vector2f((float)x, (float)y);
	rect.setPosition(new_pos);
}

sf::RectangleShape Sprite::getShape(float steps_ahead){
	extrapolated_rect.setPosition(rect.getPosition());
	extrapolated_rect.move(sf::Vector2f(dx * steps_ahead, dy * steps_ahead));
	return extrapolated_rect;
}

sf::RectangleShape Sprite::getShape(){
	return rect;
}
//