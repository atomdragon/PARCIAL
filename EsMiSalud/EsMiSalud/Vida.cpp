#include "pch.h"
#include "Vida.h"
#include "J_Principal.h"

Vida::Vida(int _x, int _y) : Item(_x,_y,1)
{
	forma[0] = char(169);
}

Vida::~Vida()
{
}

int Vida::get_x()
{
	return x;
}

int Vida::get_y()
{
	return y;
}

bool Vida::colision(J_Principal* personaje_p)
{
	for (int i = 0; i < altura; i++)
	{
		for (int j = 0; j <forma->length(); j++)
		{
			for (int ii = 0; ii < personaje_p->get_altura(); ii++)
			{
				for (int jj = 0; jj < personaje_p->get_body().length(); jj++)
				{
					if (x + j == personaje_p->get_x() + jj && y + i == personaje_p->get_y() + ii)
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}


