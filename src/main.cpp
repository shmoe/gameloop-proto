#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Scene.hpp"

const sf::Time MS_PER_UPDATE = sf::milliseconds(500);
const short WIN_WIDTH = 1600;
const short WIN_HEIGHT = 900;

int main() {
	ResourceManager* resource_manager = ResourceManager::getInstance();//get resource manager
	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Main Window");//initialize window
	Scene scene = Scene(&window);//create empty scene
	
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
					scene.setScaleFactor(sf::Vector2f(WIN_HEIGHT/ev.size.height, WIN_WIDTH/ev.size.width));
					break;

				default:
					break;
			}
		}
		if(ev.type == sf::Event::Closed)
			break;

		while (lag >= MS_PER_UPDATE) {
			//update
			scene.updateVisible(0.0);//update all visible actors, with zero tolerance
			lag -= MS_PER_UPDATE;
		}

		window.clear(sf::Color::Black);//clear screen
		scene.render(lag / MS_PER_UPDATE);//render all actors in scene
		window.display();//blit all draw actions to the render window
	}

	scene.clear();
	resource_manager->clear();
	return 0;
}
