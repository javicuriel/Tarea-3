//
//  main.cpp
//  Tarea-3-4
//
//  Created by Javier Curiel on 10/8/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.


// Complejidad de O(n^2)

#include <iostream>
#include <vector>

using namespace std;

bool pref(vector<vector<int>> gustos, int x, int mujer, int y, int n){
    for (int i = 0; i < n; i++){
        if (gustos[mujer][i] == y){
            return true;
        }
        if (gustos[mujer][i] == x){
            return false;
        }
    }
    return true;
}


void juntaPareja(vector<vector<int>> gustos, int total){
    vector<int> mujeresDisp;
    vector<bool> emparejados;
    
    for (int i = 0; i < total; i++){
        emparejados.push_back(false);
        mujeresDisp.push_back(-1);
    }
    
    int homLibres = total;
    
    while (homLibres > 0){
        int hombre = 0;
        for (int i = 0; i < total; i++){
            if (emparejados[i] == false){
                hombre = i;
                i = total;
            }
        }
        for (int i = 0; i < total && emparejados[hombre] == false; i++){
            int mujer = gustos[hombre][i];
            if (mujeresDisp[mujer - total] == -1){
                mujeresDisp[mujer - total] = hombre;
                emparejados[hombre] = true;
                homLibres--;
            }
            else{
                int hombreDos = mujeresDisp[mujer - total];
                if (pref(gustos, hombre, mujer, hombreDos, total) == false){
                    mujeresDisp[mujer - total] = hombre;
                    emparejados[hombre] = true;
                    emparejados[hombreDos] = false;
                }
            }
        }
    }
    
    
    for (int i = 0; i < total; i++){
        cout << "Hombre " << mujeresDisp[i] << " con Mujer " << i + total << endl;
    }
    
}



int main(int argc, const char * argv[]) {
    vector<vector<int>> gustos = {
        { 4, 7, 5, 6 },{ 5, 4, 6, 7 },{ 7, 5, 4, 6 },{ 6, 4, 7, 5 },
        { 1, 2, 3, 0 },{ 1, 3, 2, 0 },{ 3, 0, 1, 2 },{ 2, 1, 3, 0 },
    };
    juntaPareja(gustos, 4);
    
    return 0;
}
