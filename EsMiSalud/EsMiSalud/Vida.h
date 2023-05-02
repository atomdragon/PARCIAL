#pragma once
#include "Item.h"

class J_Principal;

class Vida : public Item
{
public:
	Vida(int _x, int _y);
	~Vida();

	int get_x();
	int get_y();

	bool colision(J_Principal* personaje_p);
};

