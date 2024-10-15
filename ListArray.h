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


    // Implementación de las funciones virtuales puras
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Índice fuera de rango");
        }

        if (n == max) {
            resize(max * 2);  // Redimensionar si es necesario
        }

        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = e;
        ++n;
    }

    void append(T e) override {
        insert(n, e);  // Insertar al final
    }

    void prepend(T e) override {
        insert(0, e);  // Insertar al principio
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Índice fuera de rango");
        }

        T removedElement = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        --n;

        if (n < max / 4 && max > MINSIZE) {
            resize(max / 2);  // Reducir tamaño si es necesario
        }

        return removedElement;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;  // No encontrado
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

};
