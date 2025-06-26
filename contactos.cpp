#include<iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);
void modificarContacto(contactoEmail &);

int main(){
    int n, op;
    string nom, user, domain;
    char sex;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    do{
        system("clear");
        cout << "===========================================\n";
        cout << "     📒 AGENDA DE CONTACTOS - KIKI SYSTEM     \n";
        cout << "===========================================\n\n";
        cout << "1. Agregar contacto" << endl;
        cout << "2. Mostrar contactos" << endl;
        cout << "3. Modificar contacto" << endl;
        cout << "0. Salir" << endl;
        cout << "===================================" << endl;
        cout << "Elige una opción: ";cin>>op;
        switch(op){
            case 1:
                cout<<"\n--- Ingrese los datos de un usuario: --- "<<endl;
            cin.ignore();
            cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
            do {
                cout << "Ingrese el sexo (M/F): "; cin >> sex;
                sex = toupper(sex);
                if (sex != 'M' && sex != 'F') {
                    cout<<endl;
                    cout << "Sexo inválido. Solo se permite 'M' o 'F'.\n";
                }
            } while (sex != 'M' && sex != 'F');            
            do {
                cout << "Ingrese la edad (entero positivo): "; cin >> edad;
                if(cin.fail() || edad <= 0){
                    cout<<endl;
                    cout << "Edad inválida. Intente nuevamente.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            } while (edad <= 0);
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                lista[n] = cont;
                n++;
                cin.get();
                break;
            case 2:
                if(n == 0){
                    cout << "No hay contactos registrados.\n";
                } else {
                    cout << "\n======= LISTA DE CONTACTOS =======\n" << endl;
                    for(int i = 0; i < n; i++){
                        cout << "Contacto #" << i + 1 << endl;
                        imprimeContacto(lista[i]);
                        cout << endl;
                    }
                    cout << "Total de contactos: " << n << "\n";
                }
                cin.get();
                break;
            case 0: {
                char confirm;
                cout << "\n¿Estás segura de que deseas salir? (S/N): ";
                cin >> confirm;
                if (confirm == 'S' || confirm == 's') {
                    cout << "¡Hasta pronto!\n";
                    return 0;
                } else {
                    op = -1; // evita que termine el bucle
                }
                break;
            }

            case 3:
                if (n==0){
                    cout<<"No hay contactos para modificar"<<endl;
                }else {
                    int idx;
                    cout << "\n--- Modificación de Contacto ---\n" << endl;
                    cout<<"Ingrese el número del contacto que desea modificar (1 a "<<n<<"): ";
                    cin>>idx;
                    if(idx < 1 || idx > n){
                        cout<<"Número inválido.\n";
                    } else {
                        modificarContacto(lista[idx - 1]);
                    }
                }
                cin.get();
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                cout << "Presiona ENTER para continuar..."; 
                cin.ignore();
                cin.get();
                break;
        }
    } while(op != 0);
    return 0;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout << "---------------------------------------------" << endl;
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
    cout << "---------------------------------------------" << endl;
}

void modificarContacto(contactoEmail &c) {
    string nuevoNom, nuevoUser, nuevoDomain;
    char nuevoSex,sex;
    int nuevaEdad;

    cin.ignore();
    cout << "--- Modificar contacto ---" << endl;
    cout << "Ingrese nuevo nombre: "; getline(cin, nuevoNom);
    do {
        cout << "Ingrese nuevo sexo (M/F): "; cin >> nuevoSex;
        nuevoSex = toupper(nuevoSex);
        if (nuevoSex != 'M' && nuevoSex != 'F') {
            cout<<endl;
            cout << "Sexo inválido. Solo se permite 'M' o 'F'.\n";
        }
    } while (nuevoSex != 'M' && nuevoSex != 'F');
    do {
        cout << "Ingrese nueva edad (entero positivo): "; cin >> nuevaEdad;
        if(cin.fail() || nuevaEdad <= 0){
            cout<<endl;
            cout << "Edad inválida. Intente nuevamente.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (nuevaEdad <= 0);

    cout << "Ingrese nuevo correo electronico (usuario@dominio): " << endl;
    cout << "\tUsuario: "; cin >> nuevoUser;
    cout << "\tDominio: "; cin >> nuevoDomain;

    correo nuevoCorreo;
    leerCorreo(nuevoCorreo, nuevoUser, nuevoDomain);
    leerContacto(c, nuevoNom, nuevoSex, nuevaEdad, nuevoCorreo);
    cout<<endl;
    cout << "\nContacto modificado exitosamente.\n\n";
    cout<<endl;
}