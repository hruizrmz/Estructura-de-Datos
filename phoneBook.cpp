#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;
/////////////////////////////////
int main() {
    // VARIABLES
    map<int,string> pb; // es donde se van a guardar todos los telefonos (phoneBook)
    queue<string> queryList; // fila para guardar las consultas a realizar
    int i, // iterador
    N, // numero de consultas al sistema
    phone; // para guardar el numero telefonico
    string fullQuery, // la consulta completa
    queryN, // iterador para las consultas
    query, // tipo de consulta a realizar
    name; // nombre de a quien le pertenece el telefono
    //////////////////////////////////
    // CAPTURA DE DATOS
    cin>>N;
    cin.ignore();
    for (i=0;i<N;i++) { // guarda cada consulta para luego poder tener acceso a ellas
        getline(cin,queryN);
        queryList.push(queryN);
    }
    for (i=0;i<N;i++) {
        fullQuery = queryList.front();
        queryList.pop();
        query = fullQuery.substr(0,fullQuery.find(" ")); // primero separa y guarda el query
        fullQuery.erase(0,fullQuery.find(" ")+1);
        phone = stoi(fullQuery.substr(0,fullQuery.find(" "))); // luego hace lo mismo para el telefono
        fullQuery.erase(0,fullQuery.find(" ")+1);
        // en este punto, lo que todavia queda en fullQuery seria el nombre o un espacio
        // en blanco. por lo cual no se necesita guardar en una variable extra el
        // nombre del contacto en caso de que el query sea 'add'
        //////////////////////////////////
        // SWITCH CASE PARA ACCION/QUERY A REALIZAR
        switch(query[0]) {
            case 'A': // a de 'add'
            case 'a' :
                if ( pb.count(phone) != 0 ) { // busca si ya existe el tel. en caso de que si,
                    pb.erase(phone);            // lo borra para sobreescribir el nombre asociado con el
                    pb.insert({phone,fullQuery});
                } else {
                    pb.insert({phone,fullQuery}); // si no, lo crea como un elemento nuevo
                }
                break;
            case 'F': // f de 'find'
            case 'f':
                if ( pb.count(phone) == 0 ) { // si no se encontraron instancias del tel,
                    cout << "not found" << endl;    // significa que no existe y regresa 'not found'
                } else{
                    cout << pb[phone] << endl; // si si se encontraron, regresa el nombre asociado
                }                               // con ese telefono (key->element)
                break;
            case 'D': // d de 'delete'
            case 'd':
                pb.erase(phone); // borra el tel del phoneBook, junto con el nombre/elemento asociado
                break;
            default:
                break;
        }
    }
    return 0;
}
