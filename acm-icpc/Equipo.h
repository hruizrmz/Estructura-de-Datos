// Clase para los objetos "Equipo" que se construyen con el nombre del equipo,
// el tiempo por respuesta acumulado y sus respuestas correctas acumuladas.
#ifndef Equipo_h
#define Equipo_h
using namespace std;
// struct para cada pregunta del concurso, se construye con el nombre y
// el conteo de respuestas equivocadas enviadas por el equipo
struct Questions {
    char nameQ, names[10];
    int wrong;
    // Constructor
    Questions() {
        nameQ='\0';
        wrong=0;
    }
    // Agrega de uno en uno las respuestas incorrectas de la pregunta
    void addWrong () {
        wrong++;
    }
    // Calcula el tiempo de penalizacion
    int calcExtraTime () {
        return wrong*20;
    }
    // Busca si la pregunta ya existe en el struct
    bool findQuestion(char nameQ){
        bool found=false;
        if (this->nameQ==nameQ) found=true;
        return found;
    }
};
class Equipo{
    public:
        // Constructores
        Equipo();
        Equipo(string,int,int,int);
        // Metodos de Acceso
        string getNameT();
        int getTotalTime();
        int getTotalRight();
        // Metodos de Modificacion
        void setNameT(string);
        void addToTotalTime(int,char);
        void addToTotalRight(char);
        // Metodo Clear
        void clear();
        // Metodos del struct, necesitan un indice
        char getNameQ(int);
        int getWrong(int);
        void setNameQ(int,char);
        void addWrong(int);
        int calcExtraTime(int);
        bool findQuestion(char);
    protected:
        Questions q[10];
        string nameT;
        int totalTime, totalRight;
};
///////////////////////////////////////////////////
// Constructores
Equipo::Equipo(){
    nameT="";
    totalTime=0;
    totalRight=0;
}
Equipo::Equipo(string nameT,int totalTime,int totalRight, int numQuestions){
    this->nameT=nameT;
    this->totalTime=totalTime;
    this->totalRight=totalRight;
}
///////////////////////////////////////////////////
// Metodos de Acceso
string Equipo::getNameT(){
    return nameT;
}
int Equipo::getTotalTime(){
    return totalTime;
}
int Equipo::getTotalRight(){
    return totalRight;
}
///////////////////////////////////////////////////
// Metodos de Modificacion
void Equipo::setNameT(string nameT){
    this->nameT=nameT;
}
void Equipo::addToTotalTime(int time,char answer){
    totalTime+=time;
    if (answer=='W') totalTime+=2; // tiempo de castigo si la respuesta fue incorrecta
}
void Equipo::addToTotalRight(char answer){
    if (answer=='A') totalRight++;
}
///////////////////////////////////////////////////
// Metodo Clear
void Equipo::clear(){
    nameT="";
    totalTime=0;
    totalRight=0;
}
///////////////////////////////////////////////////
// Metodos del Struct
char Equipo::getNameQ(int i){
    return q[i].nameQ;
}
int Equipo::getWrong(int i){
    return q[i].wrong;
}
void Equipo::setNameQ(int i,char nameQ){
    q[i].nameQ=nameQ;
}
void Equipo::addWrong(int i){
    q[i].addWrong();
};
int Equipo::calcExtraTime(int i){
    return q[i].calcExtraTime();
}
bool Equipo::findQuestion(char nameQ){
    bool found=false;
    for (int i=0;i<10;i++){
        found=q[i].findQuestion(nameQ);
        if (found) return found;
    }
    return found;
}
#endif /* Equipo_h */
