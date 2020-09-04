//
//  Busqueda.h
//  Act_Algoritmos_de_busqueda
//
//  Created by inigo guerra on 30/08/20.
//  Copyright © 2020 inigo guerra. All rights reserved.
//

#ifndef Busqueda_h
#define Busqueda_h

#include <iostream>
#include <vector>
#include "Ordenamiento.h"
using namespace std;

template <class T>
class Busqueda
{
private:
    vector<T> e;
    
public:
    Busqueda();
    void ordenar();
    int buscar(T);
    int busquedaS(T);
    int busquedaSMovimientoAlFrente(T);
    int busquedaSTransposicion(T);
    int busquedaSOrdenamiento(T);
    int busquedaBinaria(T);
};

template <class T>
Busqueda<T>::Busqueda(){
    
    srand((unsigned int) time(0));
    const int n = 100000;
    vector<int> numeros(n);
    generate(numeros.begin(), numeros.end(), [](){return rand() % 10000;});
    e = numeros;
}

template <class T>
void Busqueda<T>::ordenar(){
    e = Ordenamiento<int>::burbuja(e, Ordenamiento<int>::asc);
}

template <class T>
int Busqueda<T>::buscar(T valor){
    
    int i = 0;
    int encontrado = -1;
    long int size = e.size();
    
    while (encontrado == -1 && i < size){
        if (e[i] == valor){
            encontrado = i;
        }
        i++;
    }
    return encontrado;
}

template <class T>
int Busqueda<T>::busquedaS(T valor){
    int result = buscar(valor);
    
    if (result == -1){
        cout << "Valor no encontrado. " << endl;
    }
    
    else{
        cout << "El valor está en el índice: " << result << endl;
    }
    
    return result;
}

template <class T>
int Busqueda<T>::busquedaSMovimientoAlFrente(T valor){
    int result = buscar(valor);
    
    if (result == -1){
        cout << "Valor no encontrado. " << endl;
    }
    
    else{
        cout << "El valor está en el índice: " << result << endl;
        int temp = e[result];
        for (int i = 0; i < result ; i ++){
            e[i+1] = e[i];
            e[0] = temp;
        }
    }
    
    return result;
}

template <class T>
int Busqueda<T>::busquedaSTransposicion(T valor){
    int temp;
    int result = buscar(valor);
    
    if (result == -1){
        cout << "Valor no encontrado. " << endl;
    }
    
    else{
        cout << "El valor está en el índice: " << result << endl;
        if (e[result] != e[0]){
            temp = e[result];
            e[result] = e[0];
            e[0] = temp;
        }
    }
    
    return result;
}

template <class T>
int Busqueda<T>::busquedaSOrdenamiento(T valor){
    
    int i = 0;
    int encontrado = -1;
    long int size = e.size();
    
    while (encontrado == -1 && i < size && valor < e[i]){
        if (e[i] == valor){
            encontrado = i;
        }
        i++;
    }
    
    if (encontrado == -1){
        cout << "Valor no encontrado. " << endl;
    }
    
    else{
        cout << "El valor está en el índice: " << encontrado << endl;
    }
    
    return encontrado;
}

template <class T>
int Busqueda<T>::busquedaBinaria(T valor){
    
    int i = 0;
    int encontrado = -1;
    long int size = e.size();
    int mitad;
    
    while (encontrado == -1 && i <= size && valor < e[i]){
        
        mitad = (int)((i + size)/2);
        if (valor == e[mitad]){
            encontrado = mitad;
        }
        
        else if(valor < e[mitad]){
            size = mitad - 1;
        }
        else{
            i = mitad + 1;
        }
    }
    
    if (encontrado == -1){
        cout << "Valor no encontrado. " << endl;
    }
    
    else{
        cout << "El valor está en el índice: " << encontrado << endl;
    }
    
    return encontrado;
}


#endif /* Busqueda_h */
