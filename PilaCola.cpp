// PilaCola.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
template<class T>
struct Nodo {
	T val;
	Nodo<T>* next;
	Nodo<T>* prev;
	Nodo() {
		this->val = -1;
		this->next = nullptr;
		this->prev = nullptr;
	}
	Nodo(T val, Nodo<T>* next = 0, Nodo<T>* prev = 0) {
		this->val = val;
		this->next = next;
		this->prev = prev;
	}
};
template <class T>
struct Cola {
	Nodo<T>* head = nullptr;
	Nodo<T>* tail = nullptr;

	void push(T val) {
		if (!head) {
			head = tail = new Nodo<T>(val);
		}
		else {
			tail = new Nodo<T>(val, 0,tail);
			tail->prev->next = tail;
		}

	}
	Nodo<T> pop() {
		if (isEmpty()) return NULL;

		Nodo<T> elim;
		if (head == tail) {
			elim = *head;
			delete head;
			tail = nullptr;
			head = nullptr;
		}
		else {
			elim = *head;
			Nodo<T>* aux = head;
			head = head->next;
			head->prev = nullptr;
			delete aux;
		}

		return elim;
	}
	bool isEmpty() {
		return head == nullptr;
	}
	void print() {
		cout << "head " << "->";
		for (Nodo<T>* a = head; a; a = a->next) {
			cout << a->val << "->";
		}
		cout << "end " << endl;
	}
};


int main()
{
	Cola<int> p;
	while (true) {
		cout << "-----Menu-----" << endl;
		cout << "0: push" << endl;
		cout << "1: pop" << endl;
		cout << "2: imprimir" << endl;
		cout << "3: salir" << endl;


		int opt;
		cin >> opt;
		if (opt == 0) {
			cout << "ingrese el valor" << endl;
			int val;
			cin >> val;
			p.push(val);
			system("cls");
		}
		if (opt == 1) {
			cout << "ingrese el valor" << endl;
			p.pop();
			system("cls");
		}
		if (opt == 2) {
			p.print();
		}
		if (opt == 3) {
			exit(0);
		}

	}

}
