// ListaEnlazada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
template<class T>
struct Asc {
	inline bool operator()(T a,T b){
		return a < b;
	}
};
template<class T>
struct Desc {
	inline bool operator()(T a, T b){
		return a > b;
	}
};
template<class A>
struct Nodo{
	A val;
	Nodo<A>* next;
	Nodo(A val) { this->val = val; next = 0; }
};
template<class A,class C>
struct LE {
	Nodo<A>* head=0;
	C op;
	bool find(A val, Nodo<A>**& p) {
		for (p = &head; *p && op((*p)->val, val); p = &((*p)->next));
		return *p && (*p)->val == val;
	}
	bool insert(A val) {
		Nodo<A>** p;
		if (find(val, p))return 0;
		Nodo<A>* c = new Nodo<A>(val);
		c->next = *p;
		*p = c;
		return 1;
	}

	bool remove(A val) {
		Nodo<A>** p;
		if (!find(val, p))return 0;
		Nodo<A>* c = *p;
		*p = (*p)->next;
		delete c;
		return 1;
	}
	void print() {
		for (Nodo<A>* a = head; a; a = a->next) {
			cout << a->val<<" ";
		}
		cout << endl;
	}
};
int main()
{
	LE<int, Desc<int>> list;
	list.insert(4);
	list.print();
	list.insert(9);
	list.print();
	list.insert(2);
	list.print();
	list.insert(7);
	list.print();
	list.remove(4);
	list.remove(7);
	list.remove(2);
	list.remove(9);
	list.print();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
