#include "pch.h"
#include "Enemigo.h"

Enemigo::Enemigo(int _x, int _y,int _dx,int _dy):Entidad(_x, _y, 3)
{
	//Direccion = d

	dy = _dy; 
	dx = _dx;

	tempo = 0;

	System::Random R;

	switch (R.Next(1, 3))
	{
		case 1:
			body[0] = " _ ";
			body[1] = "{ }";
			body[2] = " - ";

			break;
		case 2:
			body[0] = " } ";
			body[1] = "~o~";
			body[2] = " } ";
			break;
		case 3:
			body[0] = " ^ ";
			body[1] = "<O>";
			body[2] = " ° ";
			break;
	default:
		break;
	}
}

void Enemigo::controlar(Clinica* MAPPA)
{
	if (tempo>10)
	{
		if (Colision_wall(MAPPA, 0, dy) == true)
		{
			dy *= -1;
		}

		if (Colision_wall(MAPPA, dx, 0) == true)
		{
			dx *= -1;
		}

		if (Colision_wall(MAPPA, dx, dy) == true)
		{
			dx *= -1;
			dy *= -1;
		}

		Mover(dx, dy, MAPPA);

		tempo = 0;
	}
	else
	{
		tempo++;
	}

}
