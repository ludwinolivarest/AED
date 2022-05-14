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
	bool operator()(T a, T b) { return a > b; }
};
template<class T, class O>
class Lista {
public:
	nodo<T>* head = nullptr;
	O mo;
	Lista() {
		head = nullptr;
	}
	bool find(T d, nodo<T>**& p) {
		for (p = &head; (*p)->next != head && mo(d, (*p)->dato); p = &((*p)->next));
		return (*p)->dato == d;
	}
	bool insert(T x) {
		nodo<T>** p = &head;
		if (head == nullptr) {
			nodo<T>* temp = new nodo<T>(x);
			temp->next = *p;
			(*p) = temp;
			(*p)->next = head;
			return true;
		}
		if (x < head->dato) {
			nodo<T>** p;
			nodo<T>* q = new nodo<T>(x);
			for (p = &head; (*p)->next != head; p = &((*p)->next));
			q->next = head;
			head = q;
			(*p)->next = q;
		}
		if (find(x, p)) { return false; }
		nodo<T>* temp = new nodo<T>(x);
		temp->next = (*p)->next;
		(*p)->next = temp;
		return true;
	}
	bool deletee(T x) {
		if (x == head->dato) {
			nodo<T>* temp = head;
			nodo<T>* temp1 = temp->next;
			nodo<T>* p;
			for (p = head; p->next != head; p = p->next);
			p->next = temp1;
			delete temp;
			head = temp1;
			return true;
		}
		nodo<T>** p = &head;
		if (!find(x, p)) { return false; }
		nodo<T>* temp = *p;
		*p = (*p)->next;
		delete temp;
		return true;
	}
	bool print() {
		nodo<T>** p = &head;
		while ((*p)->next != head && (*p)->next) {
			cout << (*p)->dato << "->";
			p = &((*p)->next);
		}
		cout << (*p)->dato;
		p = &((*p)->next);
		cout << "->" << (*p)->dato;
		return true;
	}
	~Lista() {
		nodo<T>* p = head;
		int i = 0;
		while (i < 5) {
			nodo<T>* temp = p;
			p = p->next;
			delete temp;
			i++;
		}
	}
};
int main() {
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