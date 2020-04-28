#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Main Window");

	while(window.isOpen()){
		sf::Event ev;
		while(window.pollEvent(ev)){
			if(ev.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}
	return 0;
}
