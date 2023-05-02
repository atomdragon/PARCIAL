#include "pch.h"
#include "Paciente.h"
#include "J_Principal.h"
#include "Entidad.h"
#include <conio.h>


Paciente::Paciente(int _x, int _y) : Entidad(_x, _y ,3)
{
	altura_body = 3;
	contador = 20;

	body[0] = " n ";
	body[1] = "[ ]";
	body[2] = " T ";
}

bool Paciente::Colision(J_Principal* Principal_1)
{
	for (int i = 0; i < Principal_1->get_altura(); i++)
	{
		for (int j = 0; j < Principal_1->get_body().length(); j++)
		{
			for (int ii = 0; ii < altura_body; ii++)
			{
				for (int jj = 0; jj < body[ii].length(); jj++)
				{
					if (x + jj == Principal_1->get_x() + j && y + ii == Principal_1->get_y() + i)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Paciente::mostrar_suma(J_Principal* principal_1, int _x, int _y)
{
	char tecla;
	bool acti = true;
	bool correcto[3] = {};
	

	if (Colision(principal_1) == true)
	{
		System::Random Sumando;
		System::Random ran;

		Primer = Sumando.Next(1, 10);
		Segundo = Sumando.Next(11, 20);

		resultado = Primer + Segundo;

		if (contador > 19)
		{
			contador = 0;

		System::Console::SetCursorPosition(_x, _y);
		cout << Primer << " + " << Segundo;
		
		principal_1->Borrar();
		principal_1->set_x(_x - 4);
		principal_1->set_y(_y + 1);
		principal_1->Dibujar();
		}
		else
		{
			contador += 0.5;
		}

		switch (ran.Next(1,3))
		{
		case 1:
			System::Console::SetCursorPosition(_x, _y + 1);
			cout << "1) " << Sumando.Next(1, 10) << " " << endl;
			System::Console::SetCursorPosition(_x, _y + 2);
			cout << "2) " << Sumando.Next(11, 20) << " " << endl;
			System::Console::SetCursorPosition(_x, _y + 3);
			cout << "3) " << resultado << " ";
			correcto[0] = false;
			correcto[1] = false;
			correcto[2] = true;
			break;
		case 2:
			System::Console::SetCursorPosition(_x, _y + 1);
			cout << "1) " << Sumando.Next(1, 10) << " " << endl;
			System::Console::SetCursorPosition(_x, _y + 2);
			cout << "2) " << resultado << " " << endl;
			System::Console::SetCursorPosition(_x, _y + 3);
			cout << "3) " << Sumando.Next(11, 20) << " ";
			correcto[0] = false;
			correcto[1] = true;
			correcto[2] = false;
			break;
		case 3:								 
			System::Console::SetCursorPosition(_x, _y + 1);
			cout << "1) " << resultado << " " << endl;
			System::Console::SetCursorPosition(_x, _y + 2);
			cout << "2) " << Sumando.Next(1, 10) << " " << endl;
			System::Console::SetCursorPosition(_x, _y + 3);
			cout << "3) " << Sumando.Next(11, 20) << " ";
			correcto[0] = true;
			correcto[1] = false;
			correcto[2] = false;
			break;
		default:
			break;
		}
		do
		{
			if (_kbhit())
			{
				tecla = _getch();

				switch (tecla)
				{
				case '1':
					if (resultado && correcto[0] == true)
					{
						System::Console::SetCursorPosition(_x - 4, _y + 5);
						cout << "Parte de la cura";
						
						principal_1->Borrar();
						principal_1->set_x(38);
						principal_1->set_y(3);
						principal_1->Dibujar();
						break;
					}
					else
					{
						System::Console::SetCursorPosition(_x - 4, _y + 5);
						principal_1->set_canti_vidas(0);
						cout << "No logrado";
						acti = false;
						break;
					}
				case '2':
					if (resultado && correcto[1] == true)
					{
						System::Console::SetCursorPosition(_x - 4, _y + 5);
						cout << "Parte de la cura";						
						principal_1->Borrar();
						principal_1->set_x(38);
						principal_1->set_y(3);
						principal_1->Dibujar();
						break;
					}
					else
					{
						System::Console::SetCursorPosition(_x - 4, _y + 5);
						cout << "No logrado";
						principal_1->set_canti_vidas(0);
						acti = false;
						break;
					};
				case '3':
					if (resultado && correcto[2] == true)
					{
						System::Console::SetCursorPosition(_x - 4, _y + 5);
						cout << "Parte de la cura";
						principal_1->Borrar();
						principal_1->set_x(38);
						principal_1->set_y(3);
						principal_1->Dibujar();
						break;
					}
					else
					{
						System::Console::SetCursorPosition(_x - 4, _y + 5);
						cout << "No logrado";
						principal_1->set_canti_vidas(0);
						acti = false;
						break;
					}

				}
			}

		} while (acti == true);
		
	}

}
