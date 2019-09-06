// A01282531
// Helena Ruiz Ramirez
// 4 de septiembre de 2019
// Tarea: ACM-ICPC Score
// Funcion: Mostrar los resultados de un concurso de programacion basandose en
//          la cantidad de preguntas acertadas y luego en el tiempo en contestar.
#include <iostream>
#include "Solucion.h"
#include "Equipo.h"
using namespace std;
int main() {
    // VARIABLES
    int numTeams=0, numQuestions=0, numSolutions=0, // num de equipos, preguntas y soluciones
    time, // tiempo tardado en dar la solucion
    penaltyTime, // tiempo de penalizacion
    i,j,k; // contadores
    string completeSol, // para guardar todo el input de la solucion
    nameT; // nombre del equipo
    char nameQ, check; // nombre de la pregunta y si la solucion estuvo bien/mal
    ///////////////////////////
    cin>>numTeams;
    // si el num. de equipos no es valido, se termina el programa
    if (numTeams<1 || numTeams>20) return 0;
    cin>>numQuestions;
    // si el num. de preguntas no es valido, se termina el programa
    if (numQuestions<1 || numQuestions>10) return 0;
    Equipo e[numTeams]; // se crea un arreglo para el nombre de los equipos
    for (i=0;i<numTeams;i++){
        cin>>nameT;
        e[i].setNameT(nameT);
    }
    ///////////////////////////
    cin>>numSolutions;
    // si el num. de soluciones no es valido, se termina el programa
    if (numSolutions<1 || numSolutions>1000) return 0;
    Solucion s[numSolutions]; // se crea un arreglo para las soluciones enviadas
    for (i=0;i<numSolutions;i++){
        cin>>nameT;
        s[i].setNameT(nameT);
        cin>>nameQ;
        s[i].setNameQ(nameQ);
        cin>>time;
        s[i].setTime(time);
        cin>>check;
        s[i].setCheck(check);
    }
    ///////////////////////////
    // Calculo de tiempo y respuestas correctas por equipo
    for (i=0;i<numSolutions;i++){
        nameT = s[i].getNameT();
        nameQ = s[i].getNameQ();
        for (j=0;j<numTeams;j++){ // busca el arreglo del equipo correspondiente por nombre
            if (nameT==e[j].getNameT()) {
                for (k=0;k<numQuestions;k++){
                    if (e[j].getNameQ(k)=='\0') {
                        if (!(e[j].findQuestion(nameQ))) e[j].setNameQ(k,nameQ);
                    }
                }
                check = s[i].getCheck();
                if (check=='W') {           // si tuvieron un error, se agrega 1 al conteo de respuestas
                    for (k=0;k<numQuestions;k++){   // incorrectas del equipo para esa pregunta
                        if (s[i].getNameQ()==e[j].getNameQ(k)) e[j].addWrong(k);
                    }
                } else if (check=='A'){     // si acertaron, se checa primero si ya habian subido
                    time = s[i].getTime();  // respuestas para esa pregunta y se calcula el tiempo
                    for (k=0;k<numQuestions;k++){   // de penalizacion para sumarlo
                        if (s[i].getNameQ()==e[j].getNameQ(k)) {
                            if (e[j].getWrong(k)>0) {
                                penaltyTime = e[j].calcExtraTime(k);
                                time+=penaltyTime;
                            }
                        }
                    }
                    e[j].addToTotalTime(time,check);
                    e[j].addToTotalRight(check);
                }
            }
        }
    }
    ///////////////////////////
    // Resultados Finales
    int bestTime=10000,bestScore=0,score=0, // guardan temporalmente el mejor tiempo y puntaje
    ctr = 1, // cuanto cuantos lugares/equipos quedan por ordenar
    ready = 0; // indica cual equipo se le acaba de asignar un lugar y puede borrarse
    bool matchFound=false;
    // ciclo while para buscar de lugar en lugar para ordenar de manera descendiente
    // los equipos por sus preguntas acertadas y su total de tiempo.
    while (ctr<numTeams+1) {
        bestScore=0; // se resetean el mejor puntaje y tiempo antes de volver a buscar
        bestTime=10000;
        matchFound=false; // indica si se encontraron dos tiempos iguales
        for (i=0;i<numTeams;i++){
            score=e[i].getTotalRight();
            time=e[i].getTotalTime();
            if (score>bestScore) { // si el puntaje del equipo es mayor al previo,
                bestScore=score;    // los datos de este sobreescriben los previos
                bestTime=time;
                ready = i;
            } else if (score==bestScore) { // si el puntaje del equipo es igual al previo,
                if (time<bestTime) {       // se comparan los tiempos y se escoge el menor
                    if (time==0 && !matchFound){ // en caso de tiempo=0, agarra al primer equipo que encuentra
                        if (e[i].getNameT()!="") { // no va a entrar si tiempo=0 solo porque el objeto esta vacio
                            bestTime=time;
                            ready = i;
                            matchFound=true; // se marca true para saber que el lugar ya esta asignado
                        }
                    } else {
                        bestScore=score;
                        bestTime=time;
                        ready = i;
                    }
                } else if (time==bestTime && !matchFound){ // en caso de tener el mismo tiempo, se agarra
                    ready = i;                                  // el primer equipo que encuentra
                    matchFound=true;
                }
            }
        }
        nameT=e[ready].getNameT();
        // muestra los resultados finales del concurso
        if (bestTime==0) {
            cout<<ctr<<" - "<<nameT<<" "<<bestScore<<" -"<<endl;
        } else {
            cout<<ctr<<" - "<<nameT<<" "<<bestScore<<" "<<bestTime<<endl;
        }
        e[ready].clear(); // borra del arreglo de equipos aquel que ya se evaluo como el mas alto
        ctr++;
    }
    return 0;
}
