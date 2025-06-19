#include <iostream>
using namespace std;

struct EMP{
    int num;
    string nom;
    float ven[12], sal;
};

int main(){
    EMP EMPLEADOS[100];
    int n;
    cout<<"Ingrese la cantidad de empleados: "<<endl;
    cin>>n;
    if(n<1||n>100){
        cout<<"Cantidad inválida. Debe estar entre 1 y 100"<<endl;
        return 1;
    }
    for(int i=0; i<n; i++){
        cout<<"\nEmpleado #"<<i+1<<endl;
        cout<<"Número: ";
        cin>>EMPLEADOS[i].num;
        cin.ignore();
        cout<<"Nombre: ";
        getline (cin, EMPLEADOS[i].nom);
        cout<<"Ventas mensuales (12): "<<endl;
        for (int j=0; j<=11; j++){
            cin>>EMPLEADOS[i].ven[j];
        }
        cout<<"Salario: ";
        cin>>EMPLEADOS[i].sal;
    }
    cout<<"\n==== Datos de los empleados ====\n";
    for (int i=0; i<n; i++){
        cout<<"\nEmpleado #"<<i+1<<endl;
        cout<<"Número: "<<EMPLEADOS[i].num<<endl;
        cout<<"Nombre:"<<EMPLEADOS[i].nom<<endl;
        cout<<"Ventas por mes:"<<endl;
        for (int j=0; j<12; j++){
            cout<<EMPLEADOS[i].ven[j]<<" ";
        }
        cout<<"\nSalario:"<<EMPLEADOS[i].sal<<endl;
    }
    return 0;
}