#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

void ubicar(int x, int y)
{
	Console::SetCursorPosition(x, y);
}
void color(int c) {
	switch (c)
	{
	case 1: Console::ForegroundColor = ConsoleColor::Black; break;
	case 2: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
	case 3: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
	case 4: Console::ForegroundColor = ConsoleColor::DarkRed; break;
	case 5: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
	case 6: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
	case 7: Console::ForegroundColor = ConsoleColor::Gray; break;
	case 8: Console::ForegroundColor = ConsoleColor::DarkGray; break;
	case 9: Console::ForegroundColor = ConsoleColor::Blue; break;
	case 10: Console::ForegroundColor = ConsoleColor::Green; break;
	case 11: Console::ForegroundColor = ConsoleColor::Cyan; break;
	case 12: Console::ForegroundColor = ConsoleColor::Red; break;
	case 13: Console::ForegroundColor = ConsoleColor::Magenta; break;
	case 14: Console::ForegroundColor = ConsoleColor::Yellow; break;
	case 15: Console::ForegroundColor = ConsoleColor::White; break;
	}
}

void pintar_límites() {
	color(6);
	for (int i = 2; i < 118; ++i) {
		ubicar(i, 3); cout << (char)205;
		ubicar(i, 28); cout << (char)205;
	}
	for (int i = 4; i < 29; ++i) {
		ubicar(2, i); cout << (char)186;
		ubicar(117, i); cout << (char)186;
	}
	ubicar(2, 3); cout << (char)201;
	ubicar(2, 28); cout << (char)200;
	ubicar(117, 3); cout << (char)187;
	ubicar(117, 28); cout << (char)201;
	color(7);
}
void presentación() {
	pintar_límites();
	color(4);
	_sleep(150);
	ubicar(44, 8); cout << "**********   **********";
	_sleep(150);
	ubicar(44, 9); cout << "**********   ***    ***";
	_sleep(150);
	ubicar(44, 10); cout << "   ****      ***    ***";
	_sleep(150);
	ubicar(44, 11); cout << "   ****      **********";
	_sleep(150);
	ubicar(44, 12); cout << "   ****      ***";
	_sleep(150);
	ubicar(44, 13); cout << "   ****      ***";
	_sleep(150);
	ubicar(44, 15); cout << "Algoritmos I - Trabajo Parcial";
	_sleep(150);
	color(7);
	char c = _getch();
	system("cls");
}
void nueva_partida() {
	system("cls");
}
void créditos() {
	system("cls");
	pintar_límites();
	color(2);
	_sleep(150);
	ubicar(40, 10); cout << "***   ***   ***   **     ***   ***   ***";
	_sleep(150);
	ubicar(40, 11); cout << "*     * *   *     * *     *     *    *";
	_sleep(150);
	ubicar(40, 12); cout << "*     ***   ***   *  *    *     *    ***";
	_sleep(150);
	ubicar(40, 13); cout << "*     **    *     * *     *     *      *";
	_sleep(150);
	ubicar(40, 14); cout << "***   * *   ***   **     ***    *    ***";
	_sleep(150);
	ubicar(40, 17); cout << "- Juan Miguel Quijano Calderon - U202221068";
	ubicar(40, 18); cout << "- Italo Sebastian Verona Flores - U20221E617";
	ubicar(40, 19); cout << "- Linares Bernable César Alejandro - U202019409";
	color(7);
}
void instrucciones() {
	system("cls");
	pintar_límites();
	color(5);
	_sleep(150);
	ubicar(25, 10); cout << "**** *   * **** **** *** *  * **** **** **** **** *   * **** ****";
	_sleep(150);
	ubicar(25, 11); cout << " **  **  * *     **  * * *  * *    *     **  *  * **  * *    *";
	_sleep(150);
	ubicar(25, 12); cout << " **  * * * ****  **  *** *  * *    *     **  *  * * * * **** ****";
	_sleep(150);
	ubicar(25, 13); cout << " **  *  **    *  **  **  *  * *    *     **  *  * *  ** *       *";
	_sleep(150);
	ubicar(25, 14); cout << "**** *   * ****  **  * * **** **** **** **** **** *   * **** ****";
	_sleep(150);
	ubicar(25, 16); cout << "- Se va a mostrar una operacion en pantalla";
	_sleep(150);
	ubicar(25, 18); cout << "- Debe moverse con las teclas W,A,S y D";
	_sleep(150);
	ubicar(25, 20); cout << "- Recuperas una vida cuando recoges el corazon en el suelo";
	_sleep(150);
	ubicar(25, 20); cout << "- Esquiva a los enemigos para llegar a la respuesta correcta";
	color(7);
}
void jugar() {
	system("cls");
}
void salir() {
	system("cls");
	cout << "Hasta la proxima!";
}

void menu() {
	int opcion;
	do {
		do {
			system("cls");
			cout << "\t\tMenu de opciones\n";
			cout << "\t\t----------------\n";
			cout << "\t1. Nueva partida\n";
			cout << "\t2. Creditos\n";
			cout << "\t3. Instrucciones\n";
			cout << "\t4. Jugar\n";
			cout << "\t5. Salir\n\n";
			cout << "\tSeleccione una opción del 1 al 5: "; cin >> opcion;
			if (opcion < 1 || opcion>5) {
				cout << "\tError. Ingrese un número del rango establecido";
				char c = _getch();
			}
		} while (opcion < 1 || opcion>5);
		switch (opcion) {
		case 1:nueva_partida(); break;
		case 2:créditos(); break;
		case 3:instrucciones(); break;
		case 4:jugar(); break;
		case 5:salir(); break;
		default:break;
		}
		char c = _getch();
		system("cls");
	} while (opcion != 5 && opcion!=4 && opcion!=1);
}

void imprimir_you_lose()
{

	Console::Clear();

	color(9);

	cout << " __     __ ____   _    _   _       ____    _____  ______              _ " << endl;
	cout << " \\ \\   / // __ \\ | |  | | | |     / __ \\  / ____||  ____|            | |" << endl;
	cout << "  \\ \\_/ /| |  | || |  | | | |    | |  | || (___  | |__               | |" << endl;
	cout << "   \\   / | |  | || |  | | | |    | |  | | \\___ \\ |  __|              | |" << endl;
	cout << "    | |  | |__| || |__| | | |____| |__| | ____) || |____  _  _  _  _ |_|" << endl;
	cout << "    |_|   \\____/  \\____/  |______|\\____/ |_____/ |______|(_)(_)(_)(_)(_)" << endl;

	cout << endl;

	system("pause");
	menu();
}

void print_you_win()
{

	Console::Clear();

	color(14);

	cout << " _  _  _  __     __                       _          _  _  _  " << endl;
	cout << "(_)(_)(_) \\ \\   / /                      (_)        | || || |  " << endl;
	cout << "| || || |  \\ \\_/ /___   _   _  __      __ _  _ __   | || || |  " << endl;
	cout << "| || || |   \\   // _ \\ | | | | \\ \\ /\\ / /| || '_ \\  | || || |  " << endl;
	cout << "| || || |    | || (_) || |_| |  \\ V  V / | || | | | |_||_||_| " << endl;
	cout << "|_||_||_|    |_| \\___/  \\__,_|   \\_/\\_/  |_||_| |_| (_)(_)(_) " << endl;

	cout << endl;

	system("pause");
	menu();
}