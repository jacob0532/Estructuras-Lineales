#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Estudiantes{
    
    int carnet;
    string nombre;
    string apellido;
    int cedula;
    int edad;
    string lugarResidencia;
    list<struct Cursos> matricula;
};

struct Cursos{
    string nombre;
    string codigo;
    int creditos;
    
};

struct TipoComponente {
    int codigo;
    string nombre;
    string descripcion;
    string uso;
    int cantidad;
};

struct ComponentesElectronicos{
    string nombre;
    int codigo;
    string descripcion;
    string clasificacion;
    string aplicacion;
    list<TipoComponente> tiposRelacionados; 
};



//Listas principales
list<Estudiantes> listaEstudiantes;
list<Cursos> listaCursos;
list<ComponentesElectronicos> listaComponentes;







void cargarDatos(){
    Cursos c1={"Ingles","CI1230",2};
    listaCursos.push_front(c1);
    Cursos c2={"Circuitos","EL2113",4};
    listaCursos.push_front(c2);
    Cursos c3={"Calculo","MA1103",4};
    listaCursos.push_front(c3);
    Cursos c4={"Analisis","CA3125",3};
    listaCursos.push_front(c4);

    Estudiantes e1={202010, "Ana","Vargas",203650041, 20,"SanJose"};
    e1.matricula.push_back(c2);
    e1.matricula.push_back(c1);
    e1.matricula.push_back(c3);
    listaEstudiantes.push_back(e1);

    Estudiantes e2={202011, "Carlos","Ramirez",303950241, 22,"Cartago"};
    listaEstudiantes.push_back(e2);


    Estudiantes e3={202012, "Juan","Soto",107850089, 18,"SanJose"};
    e3.matricula.push_back(c3);
    e3.matricula.push_back(c4);
    listaEstudiantes.push_back(e3);


    Estudiantes e4={202013, "Pedro","Hernandez",20455025, 20,"Alajuela"};
    e4.matricula.push_back(c4);
    listaEstudiantes.push_back(e4);
    
    Estudiantes e5={202010, "Maria","Rodriguez",507650942, 19,"Guanacaste"};
    e1.matricula.push_back(c2);
    e1.matricula.push_back(c1);
    e1.matricula.push_back(c3);
    listaEstudiantes.push_back(e1);

    Estudiantes e6={202011, "Luis","Rojas",703950789, 21,"Limon"};
    listaEstudiantes.push_back(e2);


    Estudiantes e7={202012, "Valeria","Vega",403780231, 25,"Heredia"};
    e3.matricula.push_back(c3);
    e3.matricula.push_back(c4);
    listaEstudiantes.push_back(e3);


    Estudiantes e8={202013, "Sofia","Perez",202350821, 22,"Alajuela"};
    e4.matricula.push_back(c4);
    listaEstudiantes.push_back(e4);
    
    Estudiantes e9={202012, "Max","Ugalde",603640786, 20,"Puntarenas"};
    e3.matricula.push_back(c3);
    e3.matricula.push_back(c4);
    listaEstudiantes.push_back(e3);


    Estudiantes e10={202013, "Sonia","Brenes",104650835, 27,"SanJose"};
    e4.matricula.push_back(c4);
    listaEstudiantes.push_back(e4);
    
    ComponentesElectronicos cp1={"Resistor",168,"PequeñoComponenteDosTerminales","pasivo","LimitacionDeCorriente"};
    listaComponentes.push_back(cp1);
    
    ComponentesElectronicos cp2={"Capacitor",268,"AlmacenaYLiberaEnergia","pasivo","Filtros"};
    listaComponentes.push_back(cp2);
    
    ComponentesElectronicos cp3={"Inductor",368,"AlmacenaEnergia","pasivo","AcoplamientoDeSeñales"};
    listaComponentes.push_back(cp3);
    
    ComponentesElectronicos cp4={"Diodo",468,"FlujoDeCorriente","pasivo"," RectificacionCorrienteAlterna"};
    listaComponentes.push_back(cp4);
    
    




}

void imprimirE(){
    list<Estudiantes>::iterator posE=listaEstudiantes.begin();
    list<Cursos>::iterator posM;

    
    while(posE!=listaEstudiantes.end()){
        cout<<"\nCarnet: "<<posE->carnet<<endl;
        cout<<"\nNombre: "<<posE->nombre<<endl;
        cout<<"\nSus cursos matriculados son: ";
        posM=posE->matricula.begin();
        while(posM!=posE->matricula.end()){
            cout<<"\n"<<posM->nombre<<"\t"<<posM->creditos;
            posM++;
        }

        posE++;
    }

}
void imprimirC(){
    
    list<ComponentesElectronicos> ::iterator posC=listaComponentes.begin();
    
    while(posC!=listaComponentes.end()){
        cout<<"\nCarnet: "<<posC->aplicacion<<endl;
        cout<<"\nNombre: "<<posC->nombre<<endl;
        cout<<"\nSus cursos matriculados son: ";
        

        posC++;
    }

}




int main()
{
    cout << "Relacionar listas" << endl;
    cargarDatos();

    imprimirE();
    cout<<"\n\nLista de comidas...........\n";
    imprimirC();

   

    return 0;
}