#pragma once
#include "Entidad.h"

class J_Principal;

class Paciente : public Entidad
{
private:
	int resultado;
	int Primer;
	int Segundo;
	float contador;
public:
	Paciente(int _x, int _y);
	bool Colision(J_Principal* Principal_1);

	void mostrar_suma(J_Principal* principal_1, int _x, int _y);
};

