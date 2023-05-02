#include "pch.h"
#include "J_Principal.h"
#include "Entidad.h"
#include "Enemigo.h"
#include "Vida.h"
#include "ArrVida.h"
#include <conio.h>

J_Principal::J_Principal(int _x, int _y, int _cant_vidas) :Entidad(_x, _y, 3)
{

	canti_vidas = _cant_vidas;
	conta = 26;

	System::Random P;

	switch (P.Next(1, 4))
	{
	case 1:
		body[0] = " o ";
		body[1] = "/H\\";
		body[2] = " T ";
		break;

	case 2:
		body[0] = " o ";
		body[1] = "/H\\";
		body[2] = " I ";
		break;
	case 3:
		body[0] = " o ";
		body[1] = "<H>";
		body[2] = " H ";
	case 4:
		body[0] = " o ";
		body[1] = "¡H¡";
		body[2] = " H ";

	default:
		break;
	}

	
}

void J_Principal::Controlar(Clinica* Mapa, ArrVida* _arreglo_vidas)
{
	char tecla;

	if (_kbhit())
	{
		tecla = toupper(_getch());

		switch (tecla)
		{

		case 'A': 
			Mover(-1, 0, Mapa);
			break;
		case 'S':
			Mover(0, 1, Mapa);
			break;
		case 'D':
			Mover(1, 0, Mapa);
			break;
		case'W':
			Mover(0, -1, Mapa);
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < altura_body; i++)
	{
		for (int j = 0; j < body[i].length(); j++)
		{
			for (int z = 0; z < _arreglo_vidas->get_cant_vidas(); z++)
			{
				if (x + j == _arreglo_vidas->get_vida(z)->get_x() && y + i == _arreglo_vidas->get_vida(z)->get_y() && canti_vidas < 3)
				{
					canti_vidas += 1;

					_arreglo_vidas->quitar(z);
				}
			}
		}
	}
}

bool J_Principal::Colision(Enemigo* enemigo)
{
	for (int i = 0; i < altura_body; i++)
	{
		for (int j = 0; j < body->length(); j++)
		{
			for (int ii = 0; ii < enemigo->get_altura(); ii++)
			{
				for (int jj = 0; jj < enemigo->get_body().length(); jj++)
				{
					if (x + j == enemigo->get_x() + jj && y + i == enemigo->get_y() + ii)
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

void J_Principal::dibujar_vid(int _X, int _Y, Enemigo* enemigo)
{
	if (conta > 25)
	{
		if (Colision(enemigo) == true && canti_vidas > 0)
		{
			canti_vidas--;
			conta = 0;
			System::Console::SetCursorPosition(_X, _Y);
			for (int i = 0; i < canti_vidas + 1; i++)
			{
				cout << "  " << "  ";
			}

		}
	}
	else
	{
		conta += 0.5;
	}

	System::Console::SetCursorPosition(_X, _Y);
	for (int i = 0; i < canti_vidas; i++)
	{
		cout << char(3) << "  ";
	}
}

int J_Principal::get_altura()
{
	return altura_body;
}

string J_Principal::get_body()
{
	return *body;
}

int J_Principal::get_x()
{
	return x;
}

int J_Principal::get_y()
{
	return y;
}

int J_Principal::get_canti_vidas()
{
	return canti_vidas;
}


void J_Principal::set_canti_vidas(int valor)
{
	canti_vidas = valor;
}

void J_Principal::set_x(int valor)
{
	x = valor;
}

void J_Principal::set_y(int valor)
{
	y = valor;
}



