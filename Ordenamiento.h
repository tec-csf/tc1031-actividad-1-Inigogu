//
//  Ordenamiento.h
//  Act_Algoritmos_de_busqueda
//
//  Created by inigo guerra on 02/09/20.
//  Copyright © 2020 inigo guerra. All rights reserved.
//

#ifndef Ordenamiento_hpp
#define Ordenamiento_hpp

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Ordenamiento{
public:
    static vector<T> burbuja(vector<T>, bool(*)(T, T));
    
    static bool asc(T, T);
    static bool desc(T, T);
};


//Los métodos que son de templates tienen que estar definidos en el header

template <class T>
bool Ordenamiento<T>::asc(T a, T b)
{
    return a < b;
}

template <class T>
bool Ordenamiento<T>::desc(T a, T b)
{
    return a > b;
}

template <class T>
vector<T> Ordenamiento<T>::burbuja(vector<T> e, bool compara (T, T))
{
    int n = (int) e.size();
    
    for (int i = 0; i < n; ++i){
        for (int j = n-1; j > i; --j){
            if (compara(e[j], e[j-1])){
                swap(e[j], e[j-1]);
            }
        }
    }
    
    return e;
}



#endif /* Ordenamiento_hpp */
