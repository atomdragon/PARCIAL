#pragma once

class Vida;

class ArrVida 
{
private:
	int cant_vidas;
	Vida** arrvida;

public:
	ArrVida();
	~ArrVida();

	void dibujar_arr();
	void anadir(Vida* vid);
	void quitar(int eliminada);

	int get_cant_vidas();
	Vida* get_vida(int index);
};

