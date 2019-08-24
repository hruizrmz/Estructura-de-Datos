// A01282531
// Helena Ruiz Ramirez
// 25 de agosto de 2019
// Tarea: Sudoku Check
// Funcion: Checar si el cuadro de Sudoku escrito es válido

#include <iostream>
#include <cmath>
using namespace std;

// funcion que recibe un arreglo de 3x3
// es para checar el sudoku por cuadros
bool checkSquare(int arr[3][3], int ref, bool foundRef, bool endCycle){
    int row,col; // contadores para la fila y columna del arreglo 'sudokuSq'
    bool check=false; // valor booleano que regresa la funcion
    // ciclo para buscar el numero 'ref', una vez que lo encuentra
    // le suma uno y vuelve a empezar la busqueda
     while (!endCycle && ref<10) {
        foundRef=false;
        for (row=0;row<3 && !foundRef;row++) {
            for (col=0;col<3 && !foundRef;col++) {
                if (ref==arr[row][col]) {
                    ref++;
                    foundRef=true;
                }
            }
        }
        // si no encuentra 'ref', 'foundRef' se va a quedar en falso 'endCycle' se
        // va a cambiar a true, significando que el sudoku es invalido y puede
        // terminar antes el ciclo while.
        if (!foundRef) endCycle = true;
    }
    // si el ciclo while no termino por causa de 'endCycle', o que no fue interrumpido,
    // significa que se encontraron todos los numeros del 1-9 y el cuadro es valido.
    // asi entonces cambia 'check' a un valor verdadero.
    if (!endCycle) check = true;
    return check;
}

int main() {
    // variables generales
    int i,j, // contadores generales
    row,col, // contadores para la fila y columna
    ref=1; // variable para guardar el numero que se va a buscar en la columna
    bool foundRef=false, // indica si se encontro el numero 'ref'
    endCycle = false; // indica si debe interrumpirse el ciclo
    int sudoku[9][9], // arreglo para el sudoku a checar
    sudokuSq[3][3]; // arreglo temporal para checar el sudoku por cuadros
    ///////////////////////////////////////////////////////////////////////////////
    for (i=0;i<9;i++) { // guarda el sudoku del usuario
        for (j=0;j<9;j++) {
            cin>>sudoku[i][j];
        }
    }
    ///////////////////////////////////////////////////////////////////////////////
    // CUADRO CHICO
    bool validSquare=true; // variable de validacion para este chequeo
    int countCol=0, countRow=0; // indican el origen de la busqueda para cada ciclo
    while (countRow<9 && validSquare) {
        // al terminar de checar todas las columnas de las primeras 3 filas, 'countCol'
        // vuelve a ser 0 para empezar de nuevo pero 3 filas abajo. ambas se suman de 3 en 3.
        countCol=0;
        while (countCol<9 && validSquare) {
            // guarda en arreglos de 3x3 cada cuadro individual dentro del sudoku
            for (i=countRow,row=0;i<3+countRow;i++,row++) {
                for (j=countCol,col=0;j<3+countCol;j++,col++) {
                    sudokuSq[row][col]=sudoku[i][j];
                }
            }
            countCol+=3;
            // ese arreglo lo pone como parametro para la funcion 'checkSquare'
            validSquare = checkSquare(sudokuSq,ref,foundRef,endCycle);
        }
        countRow+=3;
    }
    // si la variable de validacion se quedo como falsa, imprime 'NO'
    if (!validSquare) {
        cout<<"NO"<<endl;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // COLUMNAS
    bool validColumns=true; // variable de validacion para este chequeo
    int numFound=0; // cuenta cuantos numeros ya se encontraron en la columna
    endCycle=false;
    for (col=0;col<9 && !endCycle;col++) { // recorre toda la columna antes de seguir
        // siempre se regresa la ref al numero '1', y el contador a 0
        // antes de comenzar otra busqueda
        ref=1;
        numFound=0;
        // checa de fila en fila el numero 'ref'.
        for (row=0;row<9 && ref<10;row++) {
            // si lo encuentra, 'row' hace un reset para buscar al nuevo 'ref' desde el origen
            if (sudoku[row][col] == ref) {
                ref++;
                row=-1;
                numFound++;
            }
        }
        // si no se encontraron los numeros del 1-9, se interrumpe el ciclo y se
        // concluye que el sudoku no es valido, imprimiendo 'NO' en la consola
        if (numFound!=9) endCycle=true;
    }
    if (endCycle) validColumns = false;
    if (!validColumns) {
        cout<<"NO"<<endl;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // FILAS
    bool validRows=true; // variable de validacion para este chequeo
    endCycle=false;
    numFound=0;
    for (row=0;row<9 && !endCycle;row++) { // recorre toda la columna antes de seguir
        // siempre se regresa la ref al numero '1', y el contador a 0
        // antes de comenzar otra busqueda
        ref=1;
        numFound=0;
        // checa de fila en fila el numero 'ref'.
        for (col=0;col<9 && ref<10;col++) {
            // si lo encuentra, 'row' hace un reset para buscar al nuevo 'ref' desde el origen
            if (sudoku[row][col] == ref) {
                ref++;
                col=-1;
                numFound++;
            }
        }
        // si no se encontraron los numeros del 1-9, se interrumpe el ciclo y se
        // concluye que el sudoku no es valido, imprimiendo 'NO' en la consola
        if (numFound!=9) endCycle=true;
    }
    if (endCycle) validRows = false;
    if (!validRows) {
        cout<<"NO"<<endl;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // si el programa no fue interrumpido por un 'return', siginifica que los tres
    // chequeos dieron por valido el sudoku y se imprime 'YES' en la consola
    cout<<"YES"<<endl;
    
}
