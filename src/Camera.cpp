#include "Camera.hpp"

Camera::Camera(sf::RenderWindow* window){
	this->window = window;
	view = sf::View(window->getDefaultView());
	locked_actor = nullptr;
}

void Camera::lock(Actor* actor){
	locked_actor = actor;
}

sf::FloatRect Camera::getBounds() const {
	sf::Vector2f center = view.getCenter(), size = view.getSize();
	
	return 	sf::FloatRect(
		center.x - size.x / 2,
		center.y - size.y / 2,
		size.x,
		size.y
	);
}

void Camera::render(){
	window->setView(view);
}

void Camera::render(float steps_ahead){
	if(locked_actor){
		sf::View ahead_view(view);

		Vector actor_speed = locked_actor->getVelocity();

		ahead_view.move(steps_ahead * actor_speed.getX(), steps_ahead * actor_speed.getY());

		window->setView(ahead_view);
	}
}

void Camera::update(){
	if(locked_actor){
		//TODO smooth camera movement

		//temporary
		Vector actor_speed = locked_actor->getVelocity();
		view.move(actor_speed.getX(), actor_speed.getY());
	}
}

void Camera::resizeViewport(float aspect_ratio){
	//shrink viewport to fit ratio (letterboxing)
    float windowRatio = window->getSize().x / (float) window->getSize().y;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float width_scale_factor = 1;
    float height_scale_factor = 1;
    float offset_width_scale_factor = 0;
    float offset_height_scale_factor = 0;

    if (windowRatio > viewRatio) {
        width_scale_factor = viewRatio / windowRatio;
        offset_width_scale_factor = (1 - width_scale_factor) / 2.f;
    }

    else {
        height_scale_factor = windowRatio / viewRatio;
        offset_height_scale_factor = (1 - height_scale_factor) / 2.f;
    }

    view.setViewport( sf::FloatRect(
									offset_width_scale_factor, offset_height_scale_factor,
									width_scale_factor, height_scale_factor
								) );
	window->setView(view);
}