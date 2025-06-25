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
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Mostrar contactos"<<endl;
        cout<<"3. Modificar contacto"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
                cout<<"--- Ingrese los datos de un usuario: --- "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                //imprimeContacto(cont);

                lista[n] = cont;
                n++;
                cin.get ();
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i+1<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 0:
                cout<<"Esta seguro de salir? (S/N): ";
                break;
            case 3:
                if (n==0){
                    cout<<"No hay contactos para modificar"<<endl;
                }else {
                    int idx;
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
                system("pause");
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
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}

void modificarContacto(contactoEmail &c) {
    string nuevoNom, nuevoUser, nuevoDomain;
    char nuevoSex;
    int nuevaEdad;

    cin.ignore();
    cout << "--- Modificar contacto ---" << endl;
    cout << "Ingrese nuevo nombre: "; getline(cin, nuevoNom);
    cout << "Ingrese nuevo sexo (M/F): "; cin >> nuevoSex;
    cout << "Ingrese nueva edad: "; cin >> nuevaEdad;
    cout << "Ingrese nuevo correo electronico (usuario@dominio): " << endl;
    cout << "\tUsuario: "; cin >> nuevoUser;
    cout << "\tDominio: "; cin >> nuevoDomain;

    correo nuevoCorreo;
    leerCorreo(nuevoCorreo, nuevoUser, nuevoDomain);
    leerContacto(c, nuevoNom, nuevoSex, nuevaEdad, nuevoCorreo);
    cout<<endl;
    cout << "Contacto modificado exitosamente.\n";
    cout<<endl;
}
