// Trbol.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;


template <class T>
struct Nodo {
	T val;
	Nodo<T>* nodos[2];
	int estado=0;
	Nodo(T a) {
		val = a;
		nodos[0] = nodos[1] = 0;
	}
	
};

template <class T>
struct Arbol {
	Nodo<T>* raiz = 0;
	int cantnodos = 0;

	bool find(T val, Nodo<T>**& p) {
		p = &raiz;
		for (p;	*p && (*p)->val != val;	p = &((*p)->nodos[val > (*p)->val]));
		return *p;
	}
	bool insert(T val) {
		Nodo<T>** p;
		if (find(val, p)) return 0;
		*p = new Nodo<T>(val);
		cantnodos++;
		return 1;
	}
	bool remove(T val) {

		Nodo<T>** p;
		if (!find(val, p)) return 0;
		if ((*p)->nodos[0] && (*p)->nodos[1]) {
			Nodo<T>** q=p;
			menorRigth(q);

			(*p)->val = (*q)->val;
			p = q;
		}
		Nodo<T>* t = *p;
		*p = (*p)->nodos[(*p)->nodos[1] != 0];
		delete t;
		return 1;
		
	}

	void menorRigth( Nodo<T>**& p) {
		for (p = &((*p)->nodos[0]);(*p)->nodos[0];p = &((*p)->nodos[0]));
		
	}
	void mayorLeft(Nodo<T>* a, Nodo<T>**& p) {
		Nodo<T>* test = a->nodos[0];
		while (test && test->nodos[1]) {
			test = test->nodos[1];
		}
		*p = test;
	}
	void recorrerInorden(stack<Nodo<T>*> s) {
		while (!s.empty())
		{
			if (s.top()->estado == 0) {
				s.top()->estado += 1;
				if ((s.top()->nodos[0])) s.push(s.top()->nodos[0]);

			}
			else if (s.top()->estado == 1) {
				s.top()->estado += 1;
				cout << s.top()->val << " ";
			}
			else if (s.top()->estado == 2) {
				s.top()->estado += 1;
				if ((s.top()->nodos[1])) s.push(s.top()->nodos[1]);
			}
			else if (s.top()->estado == 3) {
				s.top()->estado = 0;
				s.pop();
			}
		}
		cout << '\n';
	}
	void centerLine(string& a, int maxsize,vector<string> nodos,int tamespace) {
		if (nodos.size() == 1) {
			a = nodos[0];
		}
		else {
			vector<string>::iterator ini;
			for (ini = nodos.begin();ini < nodos.end()-1; ini++) {
				a += *ini + string(tamespace, ' ');
			}
			a += *(nodos.end() - 1);
		}
				
		if (a.length() < maxsize) {
			int leftspaces = (maxsize  - a.length())/2;
			a = string(leftspaces, ' ') + a;
		}
		
	}
	void recorrerpostorden(stack<Nodo<T>*> s) {
		
		while (!s.empty())
		{
			if (s.top()->estado == 0) {
				s.top()->estado += 1;
				if ((s.top()->nodos[0])) s.push(s.top()->nodos[0]);
			}
			else if (s.top()->estado == 1) {
				s.top()->estado += 1;
				if ((s.top()->nodos[1])) s.push(s.top()->nodos[1]);
				
			}
			else if (s.top()->estado == 2) {
				s.top()->estado += 1;
				cout << s.top()->val << endl;
			}
			else if (s.top()->estado == 3) {
				s.top()->estado = 0;
				s.pop();
			}
		}
		cout << '\n';
		
	}
	void recorrerPreorden(stack<Nodo<T>*> s) {
		while (!s.empty())
		{
			if (s.top()->estado == 0) {
				s.top()->estado += 1;
				cout << s.top()->val << " ";
			}
			else if (s.top()->estado == 1) {
				s.top()->estado += 1;
				if ((s.top()->nodos[0])) s.push(s.top()->nodos[0]);
			}
			else if (s.top()->estado == 2) {
				s.top()->estado += 1;
				if ((s.top()->nodos[1])) s.push(s.top()->nodos[1]);
			}
			else if (s.top()->estado == 3) {
				s.top()->estado =0;
				s.pop();
			}
		}
		cout << '\n';
		
		
		
	}
	void recorrerReverse(stack<Nodo<T>*> s) {
		while (!s.empty())
		{
			if (s.top()->estado == 0) {
				s.top()->estado += 1;
				if ((s.top()->nodos[1])) s.push(s.top()->nodos[1]);
			}
			else if (s.top()->estado == 1) {
				s.top()->estado += 1;
				cout << s.top()->val << " ";
			}
			else if (s.top()->estado == 2) {
				s.top()->estado += 1;
				if ((s.top()->nodos[0])) s.push(s.top()->nodos[0]);
			}
			else if (s.top()->estado == 3) {
				s.top()->estado =0;
				s.pop();
			}
		}
		cout << '\n';
	}
	void recorrerNiveles(stack<Nodo<T>*> s) {
		int niveles = 0,altura=niveles;
		while (!s.empty())
		{
			if (s.top()->estado == 0) {
				s.top()->estado += 1;
				niveles++;
				if ((s.top()->nodos[0])) s.push(s.top()->nodos[0]);

			}
			else if (s.top()->estado == 1) {
				s.top()->estado += 1;
				altura = (niveles > altura) ? niveles : altura;
				//cout << s.top()->val << " ";
			}
			else if (s.top()->estado == 2) {
				s.top()->estado += 1;
				if ((s.top()->nodos[1])) s.push(s.top()->nodos[1]);
			}
			else if (s.top()->estado == 3) {
				niveles--;
				s.top()->estado = 0;
				s.pop();
			}
		}
		int finalAlt = altura - 1;
		int maxval;
		Nodo<T>* max = raiz;
		while (max->nodos[1]) {
			max = max->nodos[1];
		}
		maxval = max->val;
		
		queue<Nodo<T>*> q;
		q.push(raiz);

		vector<string> levelarbol;
		int l=0,maxhojas= pow(2, finalAlt);
		int maxspaceline = to_string(maxval).length();
		int maxAncho = maxhojas*maxspaceline + (maxhojas - 1) * maxspaceline;
		int altto1 = altura;


		while (!q.empty())
		{
			string lvl;
			int numNodes = pow(2, l);
			int tam = pow(2, altto1) - 1;
			while (numNodes && l<=finalAlt && !q.empty()) {
				if (q.front() != nullptr) {
					if (q.front()->nodos[0] != nullptr) {
						q.push(q.front()->nodos[0]);
					}
					else
					{
						q.push(nullptr);
					}
					if (q.front()->nodos[1] != nullptr) {
						q.push(q.front()->nodos[1]);
					}
					else
					{
						q.push(nullptr);
					}

					levelarbol.push_back(to_string(q.front()->val));
					
				}
				else {
					levelarbol.push_back(string(maxspaceline, ' '));
					q.push(nullptr);
					q.push(nullptr);
				}
				q.pop();
				numNodes--;
			}
			if (l > finalAlt) {
				while (!q.empty()) q.pop();
			}
			if(levelarbol.size()!=0) centerLine(lvl,maxAncho,levelarbol,tam);
			cout << lvl << endl;
			l++;
			altto1--;
			levelarbol.clear();
			
			
		}
		cout << '\n';

	}
	void print(int caso) {
		if (!raiz) {
			cout << "el arbol esta vacio" << endl;
			return;
		}
		stack<Nodo<T>*> s;
		s.push(raiz);
		if (caso == 4) {
			recorrerNiveles(s);
		}
		else {
			
			if (caso == 0) {
				recorrerInorden(s);
			}
			if (caso == 1) {
				recorrerpostorden(s);
			}
			if (caso == 2) {
				recorrerPreorden(s);
			}
			if (caso == 3) {
				recorrerReverse(s);
			}
		}
 		
			
		cout << endl;
	}
	void contarHojas() {
		if (!raiz) {
			cout << "arbol vacío" << endl;
			return;
		}
		queue<Nodo<T>*> s;
		s.push(raiz);
		int number = 0;
		while (!s.empty())
		{
			if ((s.front()->nodos[0])) s.push(s.front()->nodos[0]);
			if ((s.front()->nodos[1])) s.push(s.front()->nodos[1]);
			
			if (s.front() != raiz && !(s.front()->nodos[0]) && !(s.front()->nodos[1])) {
				number++;
			}
			s.pop();
		}
		cout <<"cantidad de hojas: "<< number<< '\n';

	}
	void contarRamas() {
		if (!raiz) {
			cout << "arbol vacío" << endl;
			return;
		}
		queue<Nodo<T>*> s;
		s.push(raiz);
		int number = 0;
		while (!s.empty())
		{
			if ((s.front()->nodos[0])) s.push(s.front()->nodos[0]);
			if ((s.front()->nodos[1])) s.push(s.front()->nodos[1]);

			if (s.front() != raiz && (s.front()->nodos[0] || s.front()->nodos[1])) {
				number++;
			}
			s.pop();
		}
		cout << "cantidad de ramas: " << number << '\n';
		
	}
};

int main()
{	
	Arbol<int> a;
	while (true) {
		cout << "-----Menu-----" << endl;
		cout << "0: Insertar" << endl;
		cout << "1: Eliminar" << endl;
		cout << "2: Imprimir" << endl;
		cout << "3: Contar hojas" << endl;
		cout << "4: Contar ramas" << endl;
		cout << "5: salir" << endl;

		int opt;
		cin >> opt;
		if (opt == 0) {
			cout << "ingrese el valor" << endl;
			int val;
			cin >> val;
			a.insert(val);
			system("cls");
		}
		if (opt == 1) {
			int val;
			cout << "valor a eliminar: ";
			cin >> val;
			a.remove(val);
			system("cls");
		}
		if (opt == 2) {
			system("cls");
			bool isprinting = false;
			
			while (!isprinting) {
				int opt1;
				cout << "=======================" << endl;
				cout << "0: InOrden" << endl;
				cout << "1: PostOrden" << endl;
				cout << "2: Preorden" << endl;
				cout << "3: Reverse" << endl;
				cout << "4: PorNiveles" << endl;
				cout << "5: Regresar" << endl;
				cout << "6: cerrar" << endl;
				cin >> opt1;
				if (opt1 < 5) {
					cout << "==========Imprimiendo=============" << endl;
					a.print(opt1);
					system("pause");
				}
				if (opt1 == 5) isprinting = true;
				if (opt1 == 6) exit(0);
				
				

				system("cls");
			}
			system("cls");
		}
		if (opt == 5) {
			exit(0);
		}
		if (opt == 3) {
			a.contarHojas();
			system("pause");
			system("cls");
		}
		if (opt == 4) {
			a.contarRamas();
			system("pause");
			system("cls");
		}
	}
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración


// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Tgregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Tgregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Trchivo > Tbrir > Proyecto y seleccione el archivo .sln
