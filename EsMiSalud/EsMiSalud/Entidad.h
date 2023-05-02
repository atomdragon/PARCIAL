#pragma once
#include <iostream>

using namespace std;

class Clinica;

class Entidad
{
protected:
	string* body; //Cabeza, Cuerpo, Pies
	int altura_body;
	int x, y;

public:
	Entidad(int _x, int _y, int _altura_body);
	~Entidad();

	void Borrar();
	void Mover(int _dx, int _dy, Clinica* Mapa);
	void Dibujar();

	bool Colision_wall(Clinica* mapa, int _dx, int _dy);

};

