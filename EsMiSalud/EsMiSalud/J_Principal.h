#pragma once
#include "Entidad.h"

class Enemigo;
class Clinica;
class ArrVida;

class J_Principal : public Entidad
{
protected:
	int canti_vidas;
	float conta;
public:
	J_Principal(int _x,int _y, int _cant_vidas);
	void Controlar(Clinica* Mapa, ArrVida* _arreglo_vidas);

	bool Colision(Enemigo* enemigo);
	
	void dibujar_vid(int _X, int _Y, Enemigo* enemigo);

	int get_altura();
	string get_body();
	int get_x();
	int get_y();
	int get_canti_vidas();
	
	void set_canti_vidas(int valor);
	void set_x(int valor);
	void set_y(int valor);

};

