//
//  main.cpp
//  Tarea-3-3
//
//  Created by Javier Curiel on 10/7/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//

// Complejidad de O(n^2)


#include <iostream>
#include <vector>

using namespace std;

template<class T>
vector<T> findLCS(vector<T> x, vector<T> y){
    int i,j;
    long int m = x.size()-1;
    long int n = y.size()-1;
    int temp[m][n];

    for(i = 1;i < m;i++){
        for (j = 1; j < n; j++) {
            if(x[i-1] == y[j-1]){
                temp[i][j] = temp[i-1][j-1] +1;
            }
            else{
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
            }
        }
    }
    int tam = temp[m][n];
    vector<T> secuencia;
    while(m >-1 && n > -1){
        if(x[m] == y [n]){
            secuencia.push_back(x[m]);
            m--;
            n--;
            tam--;
        }
        else if(x[m]>y[n]){
            m--;
        }
        else{
            n--;
        }
    }
    return secuencia;
}


int main(int argc, const char * argv[]) {
    vector<int> x = {1,2,3,4,5};
    vector<int> y = {1,2,3};
    vector<char> xchar = {'a','b','c','d','f'};
    vector<char> ychar = {'a','b','d','f'};
    vector<char> resultadochar = findLCS(xchar, ychar);
    vector<int> resultado = findLCS(x,y);
    cout << "Subsecuencia de Ints: ";
    for(long int i = resultado.size()-1; i >= 0; i--){
        cout << resultado[i];
    }
    cout << endl;
    cout << "Subsecuencia de Chars: ";
    for(long int i = resultadochar.size()-1; i >= 0; i--){
        cout << resultadochar[i];
    }
    cout << endl;
    return 0;
}





