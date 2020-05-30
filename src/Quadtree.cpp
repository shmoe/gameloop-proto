#include "Quadtree.hpp"

enum {
	NORTHEAST=0,
	NORTHWEST=1,
	SOUTHEAST=2,
	SOUTHWEST=3
};

Quadtree::Quadtree(sf::FloatRect bounds, int max_objects, int max_levels){
	this->bounds = bounds;
	this->max_objects = max_objects;
	this->max_levels = max_levels;

	parent = nullptr;
	level = 0;

	children[0] = nullptr;
	children[1] = nullptr;
	children[2] = nullptr;
	children[3] = nullptr;
}

Quadtree::Quadtree(Quadtree* parent, int level, sf::FloatRect bounds, int max_objects, int max_levels){
	this->parent = parent;
	this->level = level;

	this->bounds = bounds;
	this->max_objects = max_objects;
	this->max_levels = max_levels;

	children[0] = nullptr;
	children[1] = nullptr;
	children[2] = nullptr;
	children[3] = nullptr;
}

void Quadtree::split(){
	const float new_width = bounds.width / 2;
	const float new_height = bounds.height / 2;

	children[NORTHEAST] = new Quadtree(this, level + 1, sf::FloatRect(bounds.left + new_width, bounds.top, new_width, new_height), max_objects, max_levels);
	children[NORTHWEST] = new Quadtree(this, level + 1, sf::FloatRect(bounds.left, bounds.top, new_width, new_height), max_objects, max_levels);
	children[SOUTHEAST] = new Quadtree(this, level + 1, sf::FloatRect(bounds.left + new_width, bounds.top + new_height, new_width, new_height), max_objects, max_levels);
	children[SOUTHWEST] = new Quadtree(this, level + 1, sf::FloatRect(bounds.left, bounds.top + new_height, new_width, new_height), max_objects, max_levels);
}

int Quadtree::getIndex(sf::FloatRect bounds){
	int index = -1;//return this if the bounds intersects with more than one child

	double horizontal_divide = this->bounds.top + (this->bounds.height * 0.5f);
	double vertical_divide = this->bounds.left + (this->bounds.width * 0.5f);

	bool north = bounds.top < horizontal_divide && bounds.top + bounds.height < horizontal_divide;
	bool south = bounds.top > horizontal_divide;
	bool east = bounds.left > vertical_divide;
	bool west = bounds.left < vertical_divide && bounds.left + bounds.width < vertical_divide;

	if(east){
		if(north){
			index = NORTHEAST;
		} else if(south){
			index = SOUTHEAST;
		}
	} else if(west){
		if(north){
			index = NORTHWEST;
		} else if(south){
			index = SOUTHWEST;
		}
	}

	return index;
}

void Quadtree::insert(Rectangular* ref){
	if(children[0] != nullptr){
		//insert into appropriate child if this node has been split
		int ref_index = getIndex(ref->getBounds());
		if(ref_index != -1){
			children[ref_index]->insert(ref);
			return;
		}
	}

	bucket.emplace(ref);

	if(bucket.size() > max_objects && level < max_levels && children[0] == nullptr){
		split();
		//move all objects in the bucket into their appropriate child
		std::set<Rectangular*>::iterator iter = bucket.begin();
		while(iter != bucket.end()){
			Rectangular* ref = *iter;
			int index = getIndex(ref->getBounds());

			if(index != -1){
				children[index]->insert(ref);
				iter = bucket.erase(iter);
			} else {
				iter++;
			}
		}
	}
}

void Quadtree::remove(Rectangular* ref){
	int index = getIndex(ref->getBounds());

	if(index == -1 || children[0] == nullptr){
		bucket.erase(ref);
	} else {
		children[index]->remove(ref);
		return;
	}
}

std::set<Rectangular*> Quadtree::search(const sf::FloatRect& bounds){
	std::set<Rectangular*> possibleOverlaps, overlaps;
	search(bounds, possibleOverlaps);

	for(Rectangular* ref : possibleOverlaps){
		if(bounds.intersects(ref->getBounds()))
			overlaps.emplace(ref);
	}

	return overlaps;
}

void Quadtree::search(const sf::FloatRect& bounds, std::set<Rectangular*>& possibleOverlaps){
	possibleOverlaps.insert(bucket.begin(), bucket.end());

	if(children[0] == nullptr){
		int index = getIndex(bounds);

		if(index == -1){
			for(int i = 0; i < 4; i++){
                if(children[i]->getBounds().intersects(bounds))
                {
                    children[i]->search(bounds, possibleOverlaps);
                }
            }
		} else {
			children[index]->search(bounds, possibleOverlaps);
		}
	}
}

sf::FloatRect Quadtree::getBounds() const {
	return bounds;
}

void Quadtree::clear(){
	bucket.clear();

	if(children[0] != nullptr){
		for(int i = 0; i < 4; i++){
			children[i]->clear();
			delete children[i];
			children[i] = nullptr;
		}
	}
}

Quadtree** Quadtree::getChildren() const {
	return (Quadtree**) children;
}

std::set<Rectangular*> Quadtree::getBucket() const{
	return bucket;
}