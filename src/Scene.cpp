#include "Scene.hpp"

Scene::Scene(sf::RenderWindow* window) : quadtree(Quadtree(sf::FloatRect(0,0,0,0),0,0)), camera(window) {
	this->window = window;
	sf::Vector2u size = window->getSize();

	quadtree = Quadtree(sf::FloatRect(0,0,size.x,size.y), 4, 10);
	
	camera.render();
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

void Scene::lockCamera(Actor* actor){
	camera.lock(actor);
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
	camera.update();//update view based on new locked Actor position
					//only needs to happen when locked actor moves. consider event trigger?
}

void Scene::updateVisible(){
	//TODO update only actors within camera's view
	update();
}

void Scene::updateVisible(float tolerance){
	//TODO update only actors within tolerance of camera's view
	update();
}

void Scene::render(){
	sf::View oldView = window->getView();

	//render objects within scene
	camera.render();

	std::set<Actor*> toRender = getVisibleActors();

	for(auto actor : toRender)
		window->draw( *(actor->getSprite()) );

	//return to old view
	window->setView(oldView);
}

void Scene::render(float steps_ahead){
	sf::View oldView(window->getView());

	//render objects within scene
	camera.render(steps_ahead);

//debug viewport
	sf::RectangleShape bg;
	bg.setFillColor(sf::Color::White);
	bg.setSize(sf::Vector2f(float(window->getSize().x), float(window->getSize().y)));
	bg.setPosition(0.0f, 0.0f);
	window->draw(bg);
//

	std::set<Actor*> toRender = getVisibleActors();

	for(auto actor : toRender)
		window->draw( *(actor->getCurrentSprite(steps_ahead)) );

	//return to old view
	window->setView(oldView);
}

void Scene::resizeViewport(float aspect_ratio){
	camera.resizeViewport(aspect_ratio);
}