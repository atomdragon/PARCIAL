#include "pch.h"
#include "Vida.h"
#include "ArrVida.h"


ArrVida::ArrVida() 
{
	cant_vidas = 0;

	arrvida = new Vida * [cant_vidas];
}

ArrVida::~ArrVida()
{
}

void ArrVida::dibujar_arr()
{
	for (int i = 0; i < cant_vidas; i++)
	{
		arrvida[i]->dibujar();
	}
}

void ArrVida::anadir(Vida* vid)
{
	Vida** aux = new Vida * [cant_vidas + 1];

	for (int i = 0; i < cant_vidas; i++)
	{
		aux[i] = arrvida[i];
	}

	aux[cant_vidas] = vid;
	arrvida = aux;

	cant_vidas++;

}

int ArrVida::get_cant_vidas()
{
	return cant_vidas;
}

Vida* ArrVida::get_vida(int index)
{
	return arrvida[index];
}

void ArrVida::quitar(int eliminada)
{
	Vida** aux = new Vida * [cant_vidas - 1];

	for (int i = 0; i < cant_vidas; i++)
	{
		if (i<eliminada)
		{
			aux[i] = arrvida[i];
		}
		else
		{
			aux[i] = arrvida[i + 1];
		}
	}

	arrvida = aux;

	cant_vidas--;
}