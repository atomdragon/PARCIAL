#include "pch.h"
#include "Clinica.h"
#include "Entidad.h"
#include "J_Principal.h"
#include "Enemigo.h"
#include "Vida.h"
#include "Paciente.h"
#include "ArrVida.h"
#include "MisFunciones.h"


using namespace System;

int main()
{
    Console::CursorVisible = false;
    srand(time(NULL));
    presentación();
    créditos();
    char c = _getch();
    menu();
    Clinica* Clini_EsMiSa = new Clinica();
    J_Principal* Personaje1 = new J_Principal(38, 3, 3);
    Enemigo* Enemigo1 = new Enemigo(6,15,0,1);
    Enemigo* Enemigo2 = new Enemigo(17,20,0,1);
    Enemigo* Enemigo3 = new Enemigo(58, 18, 0, 1);
    Enemigo* Enemigo4 = new Enemigo(65, 20, 0, 1);
    Enemigo* Enemigo5 = new Enemigo(37, 19, 1, 0);
    ArrVida* arreglo_vidas = new ArrVida();
    Vida* temp;
    Paciente* Paciente_1 = new Paciente(3,2);
    Paciente* Paciente_2 = new Paciente(72,2);

    Clini_EsMiSa->Dibujar_clinica();
    Personaje1->Dibujar();

    temp = new Vida(48, 10);
    arreglo_vidas->anadir(temp);

    temp = new Vida(10, 19);
    arreglo_vidas->anadir(temp);

    temp = new Vida(73,15); 
    arreglo_vidas->anadir(temp);

    while (true)
    {
        arreglo_vidas->dibujar_arr();
        Enemigo1->controlar(Clini_EsMiSa);
        Enemigo2->controlar(Clini_EsMiSa);
        Enemigo3->controlar(Clini_EsMiSa);
        Enemigo4->controlar(Clini_EsMiSa);
        Enemigo5->controlar(Clini_EsMiSa);
        Personaje1->Controlar(Clini_EsMiSa, arreglo_vidas);
        Personaje1->dibujar_vid(53, 2, Enemigo1);
        Personaje1->dibujar_vid(53, 2, Enemigo2);
        Personaje1->dibujar_vid(53, 2, Enemigo3);
        Personaje1->dibujar_vid(53, 2, Enemigo4);
        Personaje1->dibujar_vid(53, 2, Enemigo5);
        Paciente_1->Dibujar();
        Paciente_1->mostrar_suma(Personaje1, 18, 1);
        Paciente_2->Dibujar();
        Paciente_2->mostrar_suma(Personaje1, 18, 1);
        if (Personaje1->get_x() >= 33 && Personaje1->get_y() >= 23) // 33, 23
        {
            print_you_win();
            Personaje1->set_x(38);
            Personaje1->set_y(3);
            ConsoleColor::White;
            Clini_EsMiSa->Dibujar_clinica();
            Personaje1->set_canti_vidas(3);
        }
        if (Personaje1->get_canti_vidas() == 0)
        {
            imprimir_you_lose();
            break;
        }

        _sleep(30);
    }

    salir();
    return 0;
}