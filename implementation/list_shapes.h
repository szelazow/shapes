#pragma once

#include <iostream>
#include "shapes.h"

class list_node
{
	shape item;
	list_node* next_node = nullptr;
	list_node();
	list_node(shape new_item, list_node* element = nullptr);
};

class ShapesList
{
	list_node* first_element = nullptr;
public:
	class iterator{};
	void pop();
	void push_back(shape* new_shape);
	void append(shape* element);
	void remove(int location);
	void insert(shape* element, int location);
	ShapesList();
	ShapesList(shape new_shape);
	~ShapesList();
};