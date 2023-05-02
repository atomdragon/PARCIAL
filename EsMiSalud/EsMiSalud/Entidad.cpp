#include "pch.h"
#include "Entidad.h"
#include "Clinica.h"

using namespace System;

Entidad::Entidad(int _x,int _y,int _altura_body)
{
	x = _x;
	y = _y;
	
	altura_body = _altura_body;

	body = new string[altura_body];
}

Entidad::~Entidad()
{
}

void Entidad::Borrar()
{

	for (int i = 0; i < altura_body; i++)
	{
		for (int z = 0; z < body[i].length(); z++)
		{
			Console::SetCursorPosition(x + z, y + i); cout << " ";
		}
	}
}


void Entidad::Mover(int _dx,int _dy, Clinica* Mapa)
{
	if (Colision_wall(Mapa,_dx,_dy) == false)
	{
		Borrar();
		x += _dx;
		y += _dy;
		Dibujar();
	}
}

void Entidad::Dibujar()
{
	for (int i = 0; i < altura_body; i++)
	{
		Console::SetCursorPosition(x, y + i); cout << body[i];
	}
}

bool Entidad::Colision_wall(Clinica* mapa, int _dx, int _dy)
{
	for (int i = 0; i < altura_body; i++)
	{
		for (int z = 0; z < body[i].length(); z++)
		{
			if (mapa->get_value(y + i + _dy, x + z + _dx) == 1)
			{
				return true;
			}
		}
	}

	return false;
}