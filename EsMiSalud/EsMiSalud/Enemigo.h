#pragma once
#include "Entidad.h"

class Clinica;

class Enemigo : public Entidad 
{
private:
	int dx, dy;
	int tempo;

public:
	Enemigo(int _x, int _y, int _dx, int _dy);
	void controlar(Clinica* MAPPA);

	int get_y() { return y; }
	int get_x() { return x; }
	string get_body() { return *body; }
	int get_altura() { return altura_body; }
};

