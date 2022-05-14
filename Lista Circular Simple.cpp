#include <iostream>
using namespace std;
template<class T>
class nodo
{
public:
	T dato = 0;
	nodo* next = nullptr;
	nodo(T a = 0) {
		dato = a;
	}
};

template<class T>
class lista {
public:
	nodo<T>* head = nullptr;
	bool find(T d, nodo<T>*& p)
	{
		for (p = head; p->next != head && d > p->dato; p = p->next);
		return p->next && p->dato == d;
	}
	bool insert(T d) {
		if (head == nullptr) {
			head = new nodo<T>(d);
			head->next = head;
			return true;
		}
		if (d < head->dato) {
			nodo<T>* p;
			for (p = head; p->next != head; p = p->next);
			nodo<T>* temp = new nodo<T>(d);
			temp->next = head;
			head = temp;
			p->next = temp;
			return true;
		}
		nodo<T>* p;
		if (find(d, p)) { return 0; }
		nodo<T>* temp = new nodo<T>(d);
		temp->next = p->next;
		p->next = temp;
		return true;
	}

	bool deletee(T d)
	{
		nodo<T>* temp = head;
		if (head->next == head) {
			delete head;
			head = nullptr;
			return true;
		}
		if (head->dato == d) {
			nodo<T>* temp1 = temp->next;
			nodo<T>* p;
			for (p = head; p->next != head; p = p->next);
			p->next = temp1;
			delete temp;
			head = temp1;
			return true;
		}
		while (temp->next && (temp->next->dato != d)) {
			temp = temp->next;
		}
		if (!temp->next) {
			return 0;
		}
		nodo<T>* temp1 = temp->next;
		temp->next = temp1->next;
		delete temp1;
		return true;
	}
	bool print() {
		if (head == nullptr) {
			cout << "esta vacia" << endl;
			return false;
		}
		nodo<T>* p = head;
		while (p->next != head) {
			cout << p->dato << "->";
			p = p->next;
		}
		cout << p->dato << endl;
		return true;
	}

	~lista()
	{
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

int main()
{

	lista<int> a;
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
