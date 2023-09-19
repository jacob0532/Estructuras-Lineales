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
    list<struct Proyecto>proyectos;
    
};
struct Proyecto{
    string nombre;
    string descripcion;
    string porcentaje;
    
};

struct TipoComponente {
    int codigo;
    string nombre;
    string descripcion;
    int cantidad;
};

struct ComponentesElectronicos{
    string nombre;
    int codigo;
    string descripcion;
    string clasificacion;
    string aplicacion;
    list<struct TipoComponente> tipos; 
};



//Listas principales
list<Estudiantes> listaEstudiantes;
list<Cursos> listaCursos;
list<ComponentesElectronicos> listaComponentes;
list<TipoComponente> listaTipos;
list<Proyecto> listaProyecto;






void cargarDatos(){
    Proyecto p1={"Ingles","OralPresentation","20%"};
    listaProyecto.push_front(p1);
    Proyecto p2={"Circuitos","CrearCircuito","25%"};
    listaProyecto.push_front(p2);
    Proyecto p3={"Calculo","Factorizar","20%"};
    listaProyecto.push_front(p3);
    Proyecto p4={"Analisis","ProgramarC++","45%"};
    listaProyecto.push_front(p4);
    
    Cursos c1={"Ingles","CI1230",2};
    c1.proyectos.push_back(p1);
    listaCursos.push_front(c1);
    Cursos c2={"Circuitos","EL2113",4};
    c2.proyectos.push_back(p2);
    listaCursos.push_front(c2);
    Cursos c3={"Calculo","MA1103",4};
    c3.proyectos.push_back(p3);
    listaCursos.push_front(c3);
    Cursos c4={"Analisis","CA3125",3};
    c4.proyectos.push_back(p4);
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
    e5.matricula.push_back(c2);
    e5.matricula.push_back(c1);
    e5.matricula.push_back(c3);
    listaEstudiantes.push_back(e5);

    Estudiantes e6={202011, "Luis","Rojas",703950789, 21,"Limon"};
    listaEstudiantes.push_back(e6);


    Estudiantes e7={202012, "Valeria","Vega",403780231, 25,"Heredia"};
    e7.matricula.push_back(c3);
    e7.matricula.push_back(c4);
    listaEstudiantes.push_back(e7);


    Estudiantes e8={202013, "Sofia","Perez",202350821, 22,"Alajuela"};
    e8.matricula.push_back(c4);
    listaEstudiantes.push_back(e8);
    
    Estudiantes e9={202012, "Max","Ugalde",603640786, 20,"Puntarenas"};
    e9.matricula.push_back(c3);
    e9.matricula.push_back(c4);
    listaEstudiantes.push_back(e9);


    Estudiantes e10={202013, "Sonia","Brenes",104650835, 27,"SanJose"};
    e10.matricula.push_back(c4);
    
    listaEstudiantes.push_back(e10);
    
    TipoComponente t1={1681,"Resistor de alambre","PequeñoComponenteDosTerminales",20};
    listaTipos.push_front(t1);
    TipoComponente t2={1682,"Resistor de carbon","PequeñoComponenteDosTerminales",30};
    listaTipos.push_front(t2);
    TipoComponente t3={1683,"Resistor fijo","PequeñoComponenteDosTerminales",25};
    listaTipos.push_front(t3);
    TipoComponente t4={2681,"Capacitor de ceramica","AlmacenaYLiberaEnergia",26};
    listaTipos.push_front(t4);
    TipoComponente t5={2682,"Capacitor electrolitico","AlmacenaYLiberaEnergia",46};
    listaTipos.push_front(t4);
    TipoComponente t6={2683,"Capacitor de pelicula","AlmacenaYLiberaEnergia",19};
    listaTipos.push_front(t4);
    TipoComponente t7={3681,"Inductor de alambre","AlmacenaEnergia",24};
    listaTipos.push_front(t7);
    TipoComponente t8={3682,"Inductor de hierrro","AlmacenaEnergia",39};
    listaTipos.push_front(t8);
    TipoComponente t9={4681,"Diodo LED","FlujoDeCorriente",17};
    listaTipos.push_front(t9);
    TipoComponente t10={4682,"Diodo tunel","FlujoDeCorriente",37};
    listaTipos.push_front(t10);
    
    ComponentesElectronicos cp1={"Resistor",168,"PequeñoComponenteDosTerminales","pasivo","LimitacionDeCorriente"};
    cp1.tipos.push_back(t1);
    cp1.tipos.push_back(t2);
    cp1.tipos.push_back(t3);
    listaComponentes.push_back(cp1);
    
    ComponentesElectronicos cp2={"Capacitor",268,"AlmacenaYLiberaEnergia","pasivo","Filtros"};
    cp2.tipos.push_back(t5);
    cp2.tipos.push_back(t4);
    cp2.tipos.push_back(t6);
    listaComponentes.push_back(cp2);
    
    ComponentesElectronicos cp3={"Inductor",368,"AlmacenaEnergia","pasivo","AcoplamientoDeSeñales"};
    cp3.tipos.push_back(t7);
    cp3.tipos.push_back(t8);
    listaComponentes.push_back(cp3);
    
    ComponentesElectronicos cp4={"Diodo",468,"FlujoDeCorriente","pasivo"," RectificacionCorrienteAlterna"};
    cp4.tipos.push_back(t9);
    cp4.tipos.push_back(t10);
    listaComponentes.push_back(cp4);
    
    
    




}

void imprimirE(){
    list<Estudiantes>::iterator posE=listaEstudiantes.begin();
    list<Cursos>::iterator posM;

    
    while(posE!=listaEstudiantes.end()){
        cout<<"\nCarnet: "<<posE->carnet<<endl;
        cout<<"\nNombre: "<<posE->nombre<<endl;
        cout<<"\nApellido: "<<posE->apellido<<endl;
        cout<<"\nCedula: "<<posE->cedula<<endl;
        cout<<"\nEdad: "<<posE->edad<<endl;
        cout<<"\nLugar de residencia: "<<posE->lugarResidencia<<endl;
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
    list<TipoComponente>::iterator posN;
    while(posC!=listaComponentes.end()){
        cout<<"\nNombre: "<<posC->nombre<<endl;
        cout<<"\nCodigo: "<<posC->codigo<<endl;
        cout<<"\nDescripcion: "<<posC->descripcion<<endl;
        cout<<"\nClasificacion: "<<posC->clasificacion<<endl;
        cout<<"\nAplicacion: "<<posC->aplicacion<<endl;
        posN=posC->tipos.begin();
        while(posN!=posC->tipos.end()){
            cout<<"\n"<<posN->nombre<<"\t"<<posN->codigo;
            cout<<"\n"<<posN->descripcion<<"\t"<<posN->cantidad;
            posN++;
        }
        

        posC++;
    }

}

void imprimirCu(){
    list<Cursos>::iterator posE=listaCursos.begin();
    list<Proyecto>::iterator posM;

    
    while(posE!=listaCursos.end()){
        cout<<"\nCodigo: "<<posE->codigo<<endl;
        cout<<"\nNombre: "<<posE->nombre<<endl;
        cout<<"\nCreditos: "<<posE->creditos<<endl;
        posM=posE->proyectos.begin();
        while(posM!=posE->proyectos.end()){
            cout<<"\n"<<posM->nombre<<"\t"<<posM->descripcion<<"\t"<<posM->porcentaje;
            posM++;
        }

        posE++;
    }

}


int main()
{
    cout << "Relacionar listas" << endl;
    cargarDatos();

    //imprimirE();

    //imprimirC();

   //imprimirCu();

    return 0;
}