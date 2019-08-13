// A01282531
// Helena Ruiz Ramirez
// 12 de agosto de 2019
// Tarea: Spin the Matrix
// Funcion: Girar una matriz 'n' numero de veces, ya sea en contra o en
//          sentido de las manecillas del reloj

#include <iostream>
#include <cmath>
using namespace std;

// funcion para rotar una matriz 90 grados a la derecha
void rotate (int mat[4][4]) {
    int ref; // variable que guarda el 1er valor que se reemplaza
    //primera voltea los numeros que quedan por fuera
    for (int i=0;i<3;i++){
        ref = mat[i][3];
        mat[i][3]=mat[0][i];
        mat[0][i]=mat[3-i][0];
        mat[3-i][0]=mat[3][3-i];
        mat[3][3-i]=ref;
    }
    //luego voltea los que estan adentro
    ref = mat[1][2];
    mat[1][2]=mat[1][1];
    mat[1][1]=mat[2][1];
    mat[2][1]=mat[2][2];
    mat[2][2]=ref;
}

int main() {
    // se pide el numero 'n' de vueltas
    int n;
    cin>>n;
    
    // se crea, llena y muestra la matriz original de 4x4
    int matriz[4][4];
    int ctr = 1; // va contando el numero que escribir
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++,ctr++) {
            cin>>matriz[i][j];
        }
    }
    
    // se calcula el residuo de n/4 para conseguir el numero
    // real de vueltas y la direccion en la cual rotar la matriz
    int spin;
    spin = fmod(n,4);
    
    // una vuelta a la izq == 3 vueltas a la derecha. en caso de que
    // 'spin' sea negativo, se redefine a su equivalente en vueltas positivas
    switch (spin) {
        case -1:
            spin=3;
            break;
        case -2:
            spin=2;
            break;
        case -3:
            spin=1;
            break;
        default:
            break;
    }
    
    // hay 4 casos para cada uno de los diferentes outputs que puede
    // tener el arreglo. cada uno dependiendo de la variable 'spin'
    switch (spin) {
        case 0:
            break;
        case 1:
            // corre la funcion 'Rotate' para girar la matriz
            // una vez a la derecha
            rotate(matriz);
            break;
        case 2:
            // corre la funcion 'Rotate' para girar la matriz
            // dos veces a la derecha
            rotate(matriz);
            rotate(matriz);
            break;
        case 3:
            // corre la funcion 'Rotate' para girar la matriz
            // tres veces a la derecha
            rotate(matriz);
            rotate(matriz);
            rotate(matriz);
            break;
        default:
            break;
    }
    
    //muestra el arreglo ya rotado
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            if (j==3) cout<<matriz[i][j]<<endl;
            else cout<<matriz[i][j]<<" ";
        }
    }
}
