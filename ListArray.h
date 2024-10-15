#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;		//puntero al inicio del array
	int max;	//tamaño actual
	int n;		//num de elementos
	static const int MINSIZE = 2;	//tamño mínimo


    public:
        // miembros públicos, incluidos los heredados de List<T>
    	
	ListArray(){
		n = 0; // El número de elementos empieza en 0
    	max = MINSIZE; // Capacidad del array
    	arr = new T[max]; // Reservamos memoria para MINSIZE elementos
	}

	~ListArray(){
		delete[] arr;
	}

	T operator[](int pos){
		if (pos < 0 || pos >= n) { // n es el número de elementos, no la capacidad max
        	throw std::out_of_range("Índice fuera de rango");
    	} else {
        	return arr[pos];
    	}
	}

	friend std::ostream&operator<<(std::ostream&out, const ListArray<T> &list){
		for (int i = 0; i < list.n; i++) { // n es el número de elementos en la lista
        	out << list.arr[i] << " "; // Separar los elementos con un espacio
    	}
    	return out; // Devolver el flujo para permitir el encadenamiento
	}

	void resize(int new_size){
	
    	// Crear un nuevo array con la nueva capacidad
    	T* new_arr = new T[new_size];

    	// Copiar los elementos al nuevo array
    	for (int i = 0; i < std::min(n, new_size); ++i) {
        	new_arr[i] = arr[i];
    	}

    	// Eliminar el viejo array
    	delete[] arr;

    	// Asignar el nuevo array
    	arr = new_arr;

    	// Actualizar la capacidad
    	max = new_size;

    	// Ajustar el número de elementos si el nuevo tamaño es más pequeño
    	if (n > new_size) {
        	n = new_size;
    	}

	}

};
