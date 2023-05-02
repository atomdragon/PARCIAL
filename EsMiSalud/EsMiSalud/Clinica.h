#pragma once
#include <iostream>

const int ALTO = 25;
const int ANCHO = 80;

class Clinica
{
private:

	int Mapa_clini[ALTO][ANCHO];

public:
	Clinica();
	~Clinica();

	int get_value(int index1, int index2);

	void Dibujar_clinica();
};

