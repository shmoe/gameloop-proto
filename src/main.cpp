#include <SFML/Graphics.hpp>

sf::Time MS_PER_UPDATE = sf::milliseconds(500);

int main() {
	short win_width = 1600;
	short win_height = 900;
	sf::RenderWindow window(sf::VideoMode(win_width, win_height), "Main Window");

	sf::Clock clock;
	sf::Time lag = sf::milliseconds(0);
	sf::Time prev = clock.getElapsedTime();
	while(window.isOpen()) {
		sf::Time curr = clock.getElapsedTime();
		lag += curr - prev;
		prev = curr;

		//process events and input
		sf::Event ev;
		while(window.pollEvent(ev)) {
			switch(ev.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::Resized:
					win_width = ev.size.width;
					win_height = ev.size.height;
					break;

				default:
					break;
			}
		}
		if(ev.type == sf::Event::Closed)
			break;

		while (lag >= MS_PER_UPDATE) {
			//update
			lag -= MS_PER_UPDATE;
		}

		window.clear(sf::Color::Black);
		//render scene relative to Window Size
		/*
			extrapolating game object position `lag / MS_PER_UPDATE`
			updates ahead and generating a scene relative to the camera
			should be done in the scope of the game engine
		*/
		window.display();
	}
	return 0;
}
