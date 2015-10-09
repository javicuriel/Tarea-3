//
//  main.cpp
//  Tarea-3-1
//
//  Created by Javier Curiel on 10/5/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//

// Complejidad de O(n)

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main(int argc, const char * argv[]) {
    srand((int)time(NULL));

    int gasolina = 100;
    int totalKilometros = 0;
    vector<int> distancias(10);
    bool llego = false;
    
    for(int i = 0; i < 10; i++){
        distancias[i] = rand() % 100;
        totalKilometros += distancias[i];
    }
    
    for (int i = 0; i < 10 ; i++) {
        cout << "Distancia a siguiente gasolinera: " << distancias[i] << "km\n";
    }
    cout << "Total: " << totalKilometros << "km" << endl;
    
    int i = 0;
    while(!llego){
        if(totalKilometros > 0){
            if(gasolina >= distancias[i]){
                gasolina -= distancias[i];
                totalKilometros -= distancias[i];
                i++;
            }
            else{
                cout << "Se paro en la gasolinera " << i << endl;
                gasolina = 100;
                gasolina -= distancias[i];
                totalKilometros -= distancias[i];
                i++;
            }
        }
        
        else{
            cout << "Termino" << endl;
            llego = true;
        }
        
    }
    
    
    
    
    

}
