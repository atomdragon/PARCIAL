#pragma once
#include <iostream>

using namespace System;

class Item
{
protected:
	
	int x, y, altura, num_forma;
	std::string* forma;
	System::ConsoleColor Color;
public:

	Item(int _x,int _y, int _altura);
	~Item();

	void borrar();
	void dibujar();

};

