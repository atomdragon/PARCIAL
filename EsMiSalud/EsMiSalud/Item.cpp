#include "pch.h"
#include "Item.h"

Item::Item(int _x, int _y,int _altura)
{
	x = _x;
	y = _y;
	altura = _altura;

	forma = new std::string[altura];

}

Item::~Item()
{
}

void Item::borrar()
{
	for (int y = 0; y < altura; y++)
	{
		for (int x = 0; x < forma[y].length(); x++)
		{
			System::Console::SetCursorPosition(x, y); std::cout << " ";
		}
	}
}

void Item::dibujar()
{
	for (int i = 0; i < altura; i++)
	{

		System::Console::SetCursorPosition(x, y + i); std::cout << forma[i];

	}
}
