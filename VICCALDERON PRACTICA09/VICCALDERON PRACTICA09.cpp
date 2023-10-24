// VICCALDERON PRACTICA09.cpp 

#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};
 
//funcion agregar elementos a la lista 
void agregarNodo(Nodo*& cabeza, int valor) {
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = nullptr; //nullptr sirve para almacenarlo en el memoria

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
	}
	else {
		Nodo* actual = cabeza;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		actual->siguiente = nuevoNodo;
	}
}

void imprimirlista(Nodo* cabeza){
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->dato << "  ";
		actual = actual->siguiente;
	}
	cout << endl;
}

void borrarlista(Nodo* cabeza) {
	while (cabeza != nullptr) {
		Nodo* siguiente = cabeza->siguiente;
		delete cabeza;
		cabeza = siguiente;
		cout << "elemento borrado ";
	}
}


int main()
{
	cout << "\n"" BIENVENIDO.... has sido Nodado por VIC PAPI CALDERON " << endl;

	Nodo* cabeza = nullptr;
	int tamanolista;
	cout << "ingrese la cantidad de elementos que desea agregar a la lista  ";
	cin >> tamanolista;

	if (tamanolista <= 0) {
		cout << "cantidad de elementos no valida " << endl;
		return 1;
	}
	for (int i = 0; i < tamanolista; i++) {
		int valor;
		cout << "ingrese dato" << i + 1 << ":  ";
		cin >> valor;
		//invocamos el nodo
		agregarNodo(cabeza, valor);
	}
	cout << "Imprimiendo Lista de Numeros " << endl;
	imprimirlista(cabeza);

	borrarlista(cabeza);

	return 0;

}

