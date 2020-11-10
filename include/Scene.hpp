#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <SFML/Graphics.hpp>
#include <set>
#include "Actor.hpp"
#include "Quadtree.hpp"

/**
 * holds all of the Actors in the current world
 * as well as the current viewport
*/
class Scene {
	private:
		sf::RenderWindow* window;				//pointer to the RenderWindow
		sf::Vector2f scale_factor;				//scale factor for the sprites relative to the viewport size
		std::set<Actor*> actors;				//set of actors, sorted by z-axis postion

		Quadtree quadtree;						//for broad-phase collision detection
	public:
		Scene()=delete;							//a Scene should not exist without bounds
		Scene(sf::RenderWindow*);				//default constructor

		void setScaleFactor(sf::Vector2f);		//set current viewport scale factor

		void addActor(Actor*);					//add an actor to the scene
		void removeActor(Actor*);				//remove an actor from the scene
		void clear();							//remove all actors from scene

		std::set<Actor*> getActors();			//get all actors in the scene
		std::set<Actor*> getVisibleActors();	//get all actors within the viewport

		Quadtree* getQuadtree();				//return a reference to the Scene's quadtree

		void update();							//update all actors in the scene by one step of the physics engine
		void updateVisible();					//update all actors within the viewport by one step of the physics engine
		void updateVisible(float tolerance);	//update all actors within viewport with a tolerance of *tolerance*

		void render();							//render the part of the scene visible from the viewport
		void render(float steps_ahead);			//render the part of the scene visible from the viewport, 
													//interpolated *steps_ahead* physics engine steps in the future
};

#endif//__SCENE_HPP__