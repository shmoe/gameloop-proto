#ifndef __QUADTREE_HPP__
#define __QUADTREE_HPP__

#include <set>
#include "Rectangular.hpp"

/**
 * Tree that subdivides space into four buckets of rectangular objects
 * and splits into smaller buckets again when a bucket reaches its maximum
 * number.
 * 
 * Used for broad-phase collision detection. A finer pass can be conducted
 * over those returned by search()
 */
class Quadtree : public Rectangular {
	private:
		Quadtree(Quadtree* parent, int level,
				sf::FloatRect bounds, int max_objects, int max_levels);		//Construct a node of the tree

		void  split();														//Split the current node into four child nodes

		int getIndex(sf::FloatRect);										//Return the index of the child an object with the
																				//given bounds would be inserted into

		void search(const sf::FloatRect&, std::set<Rectangular*>&);			//Fills given area with all objects in this nodes bucket and
																				//all objects in the bucket of the child the given
																				//bounds would be placed in

		Quadtree* parent;													//Reference to this node's partent, nullptr for root
		int level;															//Level of this node
		sf::FloatRect bounds;												//Bounds of this node

		Quadtree* children[4];												//Holds the children of this node

		std::set<Rectangular*> bucket;										//Holds the objects of this node

		int max_objects;													//Max number of objects to be hold by bucket
		int max_levels;														//Max number of times node can subdivide
	public:
		Quadtree(sf::FloatRect bounds, int max_objects, int max_levels);	//Construct an empty Quadtree

		void insert(Rectangular*);											//Insert a reference to a rectangular object into 
																				//this node of the tree or one of its children
		void remove(Rectangular*);											//Remove a reference to a rectangular object from
																				//this node of the tree or one of its children
		std::set<Rectangular*> search(const sf::FloatRect&);				//Return a list of rectangular objects held by this
																				//node of the tree, or one of its children, that
																				//is within the given bounding box.

		virtual sf::FloatRect getBounds() const override;					//Get the bounding box for this node

		void clear();														//Completely clear this node and all of its children

		friend void getLeaves(Quadtree*, std::vector<Quadtree*>&);			//for debugging, fills the given vector with all terminal
																				//nodes of the given parent
};
#endif//__QUADTREE_HPP__