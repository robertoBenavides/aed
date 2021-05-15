// MatrizDispersa.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
template<class T>
struct Nodo {
	int x, y;
	T val;
	Nodo<T>* hnext=nullptr;
	Nodo<T>* vnext=nullptr;

	Nodo(int x, int y, T val) {
		this->x = x;
		this->y = y;
		this->val = val;
	}
	void transp() {
		int c = x;
		x = y;
		y = c;
		Nodo<T>* h = hnext;
		hnext = vnext;
		vnext = h;

	}
};

template<class A>
struct LE {
	Nodo<A>* head = 0;
	bool findy(int val, Nodo<A>**& p) {
		for (p = &head; *p && (*p)->y< val; p = &((*p)->vnext));
		return *p && (*p)->val == val;
	}
	bool findx(int val, Nodo<A>**& p) {
		for (p = &head; *p && (*p)->x < val; p = &((*p)->hnext));
		return *p && (*p)->val == val;
	}
	bool insertx(Nodo<A>*nodo) {
		Nodo<A>** p;
		if (findx(nodo->x, p))return 0;
		Nodo<A>* c = nodo;
		c->vnext = *p;
		*p = c;
		return 1;
	}
	bool inserty(Nodo<A>* nodo) {
		Nodo<A>** p;
		if (findy(nodo->y, p))return 0;
		Nodo<A>* c = nodo;
		c->vnext = *p;
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
			cout << a->val << " ";
		}
		cout << endl;
	}
};
template<class T>
struct MatDispersa {
	LE<T>* col;
	LE<T>* fil;
	int nfil, ncol;
	MatDispersa(int nfil,int ncol) {
		this->nfil = nfil;
		this->ncol = ncol;
		col = new LE<T> [ncol];
		fil = new LE<T> [nfil];
		for (int i = 0; i < ncol;i++) col[i]=LE<T>();
		for (int i = 0; i < nfil; i++) fil[i] = LE<T>();

	}
	
	void set(int x, int y, T val) {
		Nodo<T>* n = new Nodo<T>(x, y, val);
		LE<T>* c=col+x;
		bool inserted=c->inserty(n);
		if (inserted) {
			c = fil + y;
			c->insertx(n);
		}
		else {
			cout << "Posicion ocupada: desea actualizar el valor?" << endl;
			cout << "0: si       1:no" << endl;
			int opt;
			cin >> opt;
			if (opt) actualizar(x, y, val);
		}
		
	}
	void actualizar( int x,int y, T val) {

		Nodo<T>* f = (fil + y)->head;
		Nodo<T>* a;
		for (a=f;a && a->x != x; a = a->hnext);
		if (a) 	f->val = val;
		else {
			cout << "ubicacion vacia desea insertar el valor?" << endl;
			cout << "0: si       1:no" << endl;
			int opt;
			cin >> opt;
			if (opt==0) {
				set(x, y, val);
			}
		}

	}

	void transpuesta() {
		LE<T>*f = new LE<T>[ncol];
		LE<T>*c = new LE<T>[nfil];
		for (int i = 0; i < ncol; i++) {
			f[i] = *(col+i);
		}
		for (int i = 0; i < nfil; i++) {
			c[i] = *(fil+i);
		}
		col = c;
		fil = f;

		int a = nfil;
		nfil = ncol;
		ncol = a;


		for (int j = 0; j < nfil; j++) {
			Nodo<T>* i = fil[j].head;
			for (i; i; i = i->hnext) {
				i->transp();
			}
		}
	}
	
	void fullPosPrint() {
		for (int j = 0; j < nfil; j++) {
			Nodo<T>* f = fil[j].head;
			for (f; f; f = f->hnext) {
				cout << "(" << f->y << "," << f->x << ") = " << f->val<<endl;
			}
		}
	}
	void fullMatrizPrint() {
		for (int j=0; j <nfil; j++) {
			Nodo<T>* f=fil[j].head;
			for (int i = 0; i < ncol; i++) {
				if (f && f->x == i) {
					cout << f->val << "\t";
					if (f) f = f->hnext;
				}
				else cout << "0" << "\t";
				
			}
			cout << endl;
		}
	}
	void print(int a) {
		if (a == 0) {
			fullPosPrint();
		}
		if (a == 1) {
			fullMatrizPrint();
		}
	}
};

int main()
{
	
	int fil, col;
	cout << "Insertar numero de filas";
	cin >> fil;
	cout << "Insertar numero de columnas";
	cin >> col;
	MatDispersa<int> a(fil, col);
	while (true) {
		cout << "-----Menu-----" << endl;
		cout << "0: Insertar" << endl;
		cout << "1: Actualizar" << endl;
		cout << "2: Imprimir" << endl;
		cout << "3: Transponer" << endl;
		cout << "4: salir" << endl;

		int opt;
		cin >> opt;
		if (opt == 0) {
			int val, colum, fila;
			cout << "Valor de fila" << endl;
			cin >> fila;
			cout << "valor columna" << endl;
			cin >> colum;
			cout << "valor dato" << endl;
			cin >> val;
			a.set(colum, fila, val);
			system("cls");
		}
		if (opt == 1) {
			int val, colum, fila;
			cout << "Valor de fila" << endl;
			cin >> fila;
			cout << "valor columna" << endl;
			cin >> colum;
			cout << "valor dato" << endl;
			cin >> val;
			a.actualizar(colum, fila, val);
			system("cls");
		}
		if (opt == 2) {
			system("cls");
			bool isprinting = false;

			while (!isprinting) {
				int opt1;
				cout << "=======================" << endl;
				cout << "0: Posiciones" << endl;
				cout << "1: Full Matriz" << endl;
				cout << "2: Regresar" << endl;
				cout << "3: Salir" << endl;
				
				cin >> opt1;
				if (opt1 <2) {
					cout << "==========Imprimiendo=============" << endl;
					a.print(opt1);
					system("pause");
				}
				if (opt1 == 2) isprinting=true;
				if (opt1 == 3) exit(0);



				system("cls");
			}
			system("cls");
		}
		if (opt == 3) {
			a.transpuesta();
			cout << "==========Matriz transpuesta=============" << endl;
			a.print(1);
			system("pause");
			system("cls");
		}
		if (opt == 4) {
			exit(0);
			
		}
		
	}
	

    std::cout << "Hello World!\n";
}

