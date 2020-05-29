#ifndef __RECTANGULAR_HPP__
#define __RECTANGULAR_HPP__

#include <SFML/Graphics.hpp>

/**
 * Abstract Base Class for an object that has a single bounding box (sf::FloatRect)
 */
class Rectangular {
	public:
		virtual sf::FloatRect getBounds() const = 0;
};
#endif//__RECTANGULAR_HPP__