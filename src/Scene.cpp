#include "Scene.hpp"

Scene::Scene(sf::RenderWindow* window){
	this->window = window;
}

void Scene::setScaleFactor(sf::Vector2f scale_factor){
	this->scale_factor = scale_factor;
}

void Scene::addActor(Actor* actor){
	actors.emplace(actor);
}

void Scene::removeActor(Actor* actor){
	actors.erase(actor);
}

void Scene::clear(){
	actors.clear();
}

std::set<Actor*> Scene::getActors(){
	return std::set<Actor*>(actors);
}

std::set<Actor*> Scene::getVisibleActors(){
	//TODO
	return getActors();
}

void Scene::update(){
	for(auto actor : actors)
		actor->update();
}

void Scene::updateVisible(){
	//TODO
	update();
}

void Scene::updateVisible(float tolerance){
	//TODO
	update();
}

void Scene::render(){
	std::set<Actor*> toRender = getVisibleActors();

	for(auto actor : toRender)
		window->draw( *(actor->getSprite()), viewport_transform.getInverse().scale(scale_factor) );

}

void Scene::render(float steps_ahead){
	std::set<Actor*> toRender = getVisibleActors();

	for(auto actor : toRender)
		window->draw( *(actor->getCurrentSprite(steps_ahead)), viewport_transform.getInverse().scale(scale_factor) );

}