//
//  main.cpp
//  Tarea-3-2
//
//  Created by Javier Curiel on 10/7/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//

// Complejidad de O(n)

#include <iostream>
#include <vector>
using namespace std;

class linea{
    int maxTam;
    int b;
    int total;
    vector<int> palabras;
public:
    linea(int maxTam,int b){
        this->maxTam = maxTam;
        this->b = b;
        total = 0;
    }
    bool insertarPalabra(int palabra){
        if(getLongitud()+palabra+b > maxTam){
            if(!pasarSiguiente(palabra)){
                while(b>=2){
                    b--;
                    if (getLongitud()+palabra <= maxTam){
                        palabras.push_back(palabra);
                        total += palabra;
                        return true;
                    }
                }
            }
            else{
                while(getLongitud() != maxTam){
                    b++;
                }
                return false;
            }
        }
        else{
            palabras.push_back(palabra);
            total += palabra;
            return true;
        }
        return false;
    }

    bool pasarSiguiente(int palabra){
        int original = b;
        unsigned long costoAchicar = 0;
        unsigned long costoPasarSiguiente = 0;
        bool cabe = false;
        while(b>=2){
            b--;
            costoAchicar++;
        }
        if (getLongitud()+palabra <= maxTam){
            cabe = true;
        }
        b = original;
        while(getLongitud() != maxTam){
            b++;
            costoPasarSiguiente++;
        }
        costoAchicar = palabras.size()* costoAchicar;
        costoPasarSiguiente = (palabras.size()-1)* costoPasarSiguiente;
        b = original;
        if (cabe == true)
            return costoAchicar > costoPasarSiguiente;
        else
            return true;
    }
    
    void setB(int b){
        this->b = b;
    }
    int getB(){
        return b;
    }
    unsigned long getLongitud(){
        return total+(b*(palabras.size()-1));
    }
    void clear(){
        total = 0;
        palabras.clear();
    }
    void print(){
        for(int i = 0; i < palabras.size();i++){
            cout << palabras[i] << " ";
        }
    }
};


int main(int argc, const char * argv[]) {
    int tamLinea = 26;
    int b = 2;
    vector<int> longitudes = {10,10,4,8,10,12,12};
    
    vector<linea> parrafo;
    linea nueva(tamLinea,b);
    int i = 0;
    while(i<longitudes.size()){
        if(nueva.insertarPalabra(longitudes[i]))
            i++;
        else{
            parrafo.push_back(nueva);
            nueva.clear();
            nueva.setB(b);
        }
    }
    parrafo.push_back(nueva);
    
    for(int j = 0; j < parrafo.size();j++){
        parrafo[j].print();
        cout << " con b: " << parrafo[j].getB() <<endl;
    }

    
}
