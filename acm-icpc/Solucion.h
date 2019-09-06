// Clase para los objetos "Solucion" que se construyen con el nombre del equipo,
// nombre de la pregunta (A/B), el tiempo en contestar y si esta bien/mal (A/W).
#ifndef Solucion_h
#define Solucion_h
using namespace std;
class Solucion{
    public:
        // Constructores
        Solucion();
        Solucion(string,char,int,char);
        // Metodos de Acceso
        string getNameT();
        char getNameQ();
        int getTime();
        char getCheck();
        // Metodos de Modificacion
        void setNameT(string);
        void setNameQ(char);
        void setTime(int);
        void setCheck(char);
    protected:
        string nameT;
        char nameQ, check;
        int time;
};
///////////////////////////////////////////////////
// Constructores
Solucion::Solucion(){
    nameT="";
    nameQ='\0';
    time=0;
    check='\0';
}
Solucion::Solucion(string nameT,char nameQ, int time, char check){
    this->nameT=nameT;
    this->nameQ=nameQ;
    this->time=time;
    this->check=check;
}
///////////////////////////////////////////////////
// Metodos de Acceso
string Solucion::getNameT(){
    return nameT;
}
char Solucion::getNameQ(){
    return nameQ;
}
int Solucion::getTime(){
    return time;
}
char Solucion::getCheck(){
    return check;
}
///////////////////////////////////////////////////
// Metodos de Modificacion
void Solucion::setNameT(string nameT){
    this->nameT=nameT;
}
void Solucion::setNameQ(char nameQ){
    this->nameQ=nameQ;
}
void Solucion::setTime(int time){
    this->time=time;
}
void Solucion::setCheck(char check){
    this->check=check;
}
#endif /* Solucion_h */
