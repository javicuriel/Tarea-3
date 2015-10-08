//
//  main.cpp
//  Tarea-3-3
//
//  Created by Javier Curiel on 10/7/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int numsLCS[10][10];
char flechasLCS[5][5];




int findLCS(char x[],char y[]){
    int i,j;
    long int m = strlen(x)+1;
    long int n = strlen(y)+1;
    int temp[m][n];

    int max = 0;
    for(i = 1;i < m;i++){
        for (j = 1; j < n; j++) {
            temp[i][j] = std::__1::max(temp[i][j-1],temp[i-1][j]);
            if(x[i-1] == y[j-1]){
                temp[i][j] = temp[i-1][j-1] +1;
                if(temp[i][j] >max){
                    max = temp[i][j];
                }
            }
        }
    }
    return max;
}

//int findLCS(char x[],char y[]){
//    int i,j;
//    long int m = strlen(x)+1;
//    long int n = strlen(y)+1;
//    int temp[m][n];
//
//    for(i = 1;i <= m;i++)
//        numsLCS[i][0] = 0;
//    for(i = 0;i <= n;i++)
//        numsLCS[0][i] = 0;
//    
//    for(i = 1;i <= m;i++){
//        for (j = 1; j <= n; j++) {
//            if(x[i]==y[j]){
//                numsLCS[i][j] = 1 + numsLCS[i-1][j-1];
//            }
//            else{
//                if(numsLCS[i-1][j] >= numsLCS[i][j-1])
//                    numsLCS[i][j] = numsLCS[i-1][j];
//                
//                else
//                    numsLCS[i][j] = numsLCS[i][j-1];
//            }
//        }
//    }
//    return max;
//}


int main(int argc, const char * argv[]) {
    char x[] = {'A','B','C','D','G','H','L','Q','R'};
    char y[] = {'A','E','D','P','H','R'};

    //char y[] = {'1','2'};
    cout << findLCS(x,y);

    return 0;
}





