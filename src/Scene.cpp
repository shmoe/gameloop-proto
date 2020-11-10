#include "Scene.hpp"

Scene::Scene(sf::RenderWindow* window) : quadtree(Quadtree(sf::FloatRect(0,0,0,0),0,0)){
	this->window = window;
	sf::Vector2u size = window->getSize();

	quadtree = Quadtree(sf::FloatRect(0,0,size.x,size.y), 4, 10);
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

Quadtree* Scene::getQuadtree(){
	return &quadtree;
}

void Scene::update(){
	for(Actor* actor : actors){
		actor->update();
		if( not (actor->isStatic()) ){
			quadtree.remove(actor);
			quadtree.insert(actor);
		}
	}
	for(Actor* actor : actors) {
		std::set<Rectangular*> broad_collisions = quadtree.search(actor->getBounds());
		for(Rectangular* rect : broad_collisions){
			//TODO resolve pixel perfect collisions
		}
	}
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
		window->draw( *(actor->getSprite()) );

}

void Scene::render(float steps_ahead){
	std::set<Actor*> toRender = getVisibleActors();

	for(auto actor : toRender)
		window->draw( *(actor->getCurrentSprite(steps_ahead)) );

}