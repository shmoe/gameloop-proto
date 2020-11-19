#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <SFML/Graphics.hpp>

#include "Actor.hpp"

class Camera{
	private:
		sf::RenderWindow* window;				//reference to the window
		sf::View view;							//holds the current portion of the scene to be rendered
		Actor* locked_actor;						//Actor which the Camera follows

		sf::FloatRect bounds;					//holds the current bounds of the camera
	public:
		Camera()=delete;						//camera shouldn't exist without a reference to the RenderWindow
		Camera(sf::RenderWindow* window);		//constructs the Camera with the default view of window
	
		void lock(Actor* actor);				//lock camera movement onto given actor

		sf::FloatRect getBounds() const;		//return the bounds of the camera relative to the Scene
													//TODO doesn't actually return world bounds of camera

		void update();							//update camera position relative to locked Actor's position
		void render();							//sets window view to current view
		void render(float steps_ahead);			//sets window view to locked Actor's position steps_ahead

		void resizeViewport(float aspect_ratio);//shrink viewport horizontally  to fit ratio
};

#endif//__CAMERA_HPP__