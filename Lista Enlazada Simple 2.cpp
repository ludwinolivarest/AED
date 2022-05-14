#include <iostream>
using namespace std;

template<class T>
class nodo
{
public:
	T dato;
	nodo<T>* next = nullptr;
	nodo(T d = 0) {
		dato = d;
	}
};

template<class T>
class Asc
{
public:
	inline bool operator()(T a, T b) { return a < b; }
};

template<class T, class O>
class Lista
{
public:
	nodo<T>* head = nullptr;
	O mo;
	Lista() {
		head = nullptr;
	}
	bool findd(T x, nodo<T>**& p)
	{
		for (p = &head; *p && mo.operator()((*p)->dato, x); p = &((*p)->next));
		return *p && (*p)->dato == x;
	}
	bool insert(T x) {
		nodo<T>** p;
		if (findd(x, p)) { return false; }
		nodo<T>* temp = new nodo<T>(x);
		temp->next = *p;
		*p = temp;
		return true;
	}
	bool deletee(T x) {
		nodo<T>** p = &head;
		if (!findd(x, p)) { return false; }
		nodo<T>* temp = *p;
		*p = (*p)->next;
		delete temp;
		return true;
	}
	bool print() {
		for (nodo<T>** p = &head; *p; p = &((*p)->next)) {
			cout << (*p)->dato << "->";
		}
		cout << "END" << endl;
		return true;
	}
	~Lista() {
		nodo<T>* p = head;
		while (p) {
			nodo<T>* temp = p;
			p = p->next;
			delete temp;

		}
	}
};

int main()
{

	Lista<int, Asc<int>> a;
	int c;
	int obj = 0;

	menu:
		cout << "ingresar valor (1)para insertar ; (2)para eliminar ; (3)para imprimir :";
		cin >> c;

		if (c == 1)
		{
			cout << "insertar el valor" << endl;
			cin >> obj;
			a.insert(obj);
			goto menu;
		}

		else if (c == 2)
		{
			cout << "eliminar el valor" << endl;
			cin >> obj;
			a.deletee(obj);
			goto menu;
		}

		else if (c == 3)
		{
			cout << "imprimir" << endl;
			a.print();
			goto menu;
		}
	
	return 0;
}