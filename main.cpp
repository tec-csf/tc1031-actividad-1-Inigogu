//
//  main.cpp
//  Act_Algoritmos_de_busqueda
//
//  Created by inigo guerra on 30/08/20.
//  Copyright © 2020 inigo guerra. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Busqueda.h"
using namespace std;


int main(int argc, const char * argv[]) {
    
    
    Busqueda<int> b1;
    Busqueda<int> b2;
    Busqueda<int> b3;
    Busqueda<int> bo1;
    //bo1.ordenar();
    Busqueda<int> bo2;
    bo2.ordenar();
    
    
    
    for (int i = 1; i <= 10; ++i){
        auto start = chrono::steady_clock::now();
        bo2.busquedaBinaria(600);
        auto end = chrono::steady_clock::now();
        cout << i << "- Elapsed time in microseconds : "
            << chrono::duration_cast<chrono::microseconds>(end - start).count()
            << " µs" << endl;
        cout << endl;
    }
    
    
    
    
    return 0;
}
