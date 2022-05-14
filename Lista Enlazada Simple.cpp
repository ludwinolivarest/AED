#include <iostream>
int main();
using namespace std;

class Nodo
{
public:
	int valor;
	Nodo* NEXT;
};

Nodo* lista = NULL;

void agregar(Nodo*& lista, int n)
{
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->valor = n;

	Nodo* aux1 = lista;
	Nodo* aux2 = NULL;

	while ((aux1 != NULL) && (aux1->valor < n))
	{
		aux2 = aux1;
		aux1 = aux1->NEXT;
	}
	if ((aux1 == NULL) || ((aux1 != NULL) && (aux1->valor > n))) {

		if (lista == aux1)
		{
			lista = nuevo_nodo;
		}

		else
		{
			aux2->NEXT = nuevo_nodo;
		}

		nuevo_nodo->NEXT = aux1;
		aux1 = nuevo_nodo;
		cout << "el elemento fue insertado a la lista" << endl;
	}
	else {
		cout << "el elemento ya esta insertado en la lista" << endl;
	}
}

void mostrar(Nodo* lista)
{
	Nodo* actual = new Nodo();
	actual = lista;

	while (actual != NULL)
	{
		cout << actual->valor << "-->";
		actual = actual->NEXT;
	}
}

void borrar(Nodo*& lista, int n)
{
	if (lista != NULL)
	{
		Nodo* aux_borrar;
		Nodo* ant = NULL;
		aux_borrar = lista;

		while ((aux_borrar != NULL) && (aux_borrar->valor != n))
		{
			ant = aux_borrar;
			aux_borrar = aux_borrar->NEXT;
		}
		if (aux_borrar == NULL)
		{
			cout << "elemento no existente" << endl;
		}
		else if (ant == NULL)
		{
			lista = lista->NEXT;
			delete aux_borrar;
		}
		else
		{
			ant->NEXT = aux_borrar->NEXT;
			delete aux_borrar;
		}
		cout << "Se ah eliminado el elemento deseado" << endl;
	}


}

void buscar(Nodo*& lista, int n)
{
	Nodo* aux_buscar;
	Nodo* ant = NULL;
	aux_buscar = lista;

	while ((aux_buscar != NULL) && (aux_buscar->valor != n))
	{
		ant = aux_buscar;
		aux_buscar = aux_buscar->NEXT;
	}
	if (aux_buscar == NULL)
	{
		cout << "elemento no existente" << endl;
	}
	else if (ant == NULL)
	{
		lista = lista->NEXT;
		cout << "el elemento se encuentra" << endl;
	}
	else
	{
		ant->NEXT = aux_buscar->NEXT;
		cout << "el elemento se encuentra" << endl;
	}
}

int main()
{

	int c = 1;
	int obj = 0;

	menu:
	{
		cout << "ingresar valor (1)para insertar ; (2)para eliminar ; (3)para imprimir :";
		cin >> c;

		if (c == 1)
		{
			cout << "insertar el valor" << endl;
			cin >> obj;
			agregar(lista, obj);
			goto menu;
		}

		else if (c == 2)
		{
			cout << "eliminar el valor" << endl;
			cin >> obj;
			borrar(lista, obj);
			goto menu;
		}

		else if (c == 3)
		{
			cout << "imprimir" << endl;
			mostrar(lista);
			goto menu;
		}
		

	}
	return 0;
}