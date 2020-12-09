#include "videogame.h"
#include <algorithm>

VideoGame::VideoGame()
{

}

//Nombre de usuario
void VideoGame::setUsuario(const string &u)
{
    usuario = u;
}

string VideoGame::getUsuario()
{
    return usuario;
}

//Agregar
void VideoGame::agregarFinal(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

//Resumen
void VideoGame::mostrar()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(12) << "Ubicacion X";
    cout << setw(12) << "Ubicacion Y";
    cout << setw(12) << "Puntuacion";
    cout << endl;

    for(size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout << c;
        /*cout<<"Marca: "<<c.getMarca()<<endl;
        cout<<"Sistema operativo: "<<c.getSisop()<<endl;
        cout<<"Peso: "<<c.getPeso()<<endl;
        cout<<"Ram: "<<c.getRam()<<endl;
        cout<<endl;*/
    }
}

/*void Laboratorio::respaldar_tabla()
{
    ofstream archivo("computadoras_tabla.txt");
    if(archivo.is_open()){
        archivo << left;
        archivo << setw(10) << "Marca";
        archivo << setw(12) << "Sistema O.";
        archivo << setw(8) << "Peso";
        archivo << setw(8) << "Ram";
        archivo << endl;
        for(size_t i = 0; i < computadoras.size(); i++)
        {
            Computadora &c = computadoras[i];
            archivo << c;
        }
    }
    archivo.close();
}*/


/*void Laboratorio::respaldar()
{
    ofstream archivo("computadoras.txt");
    if(archivo.is_open()){
        for(size_t i = 0; i < computadoras.size(); i++)
        {
            Computadora &c = computadoras[i];
            archivo << c.getMarca()<<endl;
            archivo << c.getSisop()<<endl;
            archivo << c.getPeso()<<endl;
            archivo << c.getRam()<<endl;
        }
    }
    archivo.close();
}*/


/*void Laboratorio::recuperar()
{
    ifstream archivo("computadoras.txt");
    if (archivo.is_open()){
        string temp;
        float peso;
        int ram;
        Computadora c;

        while (true)
        {
            getline(archivo, temp);
            if(archivo.eof())
            {
                break;
            }
            c.setMarca(temp);

            getline(archivo, temp);
            c.setSisop(temp);

            getline(archivo, temp);
            peso = stof(temp);
            c.setPeso(peso);

            getline(archivo, temp);
            ram = stoi(temp);
            c.setRam(ram);

            agregarFinal(c);

        }
        
    }
    archivo.close();
}*/

//insertar
void VideoGame::insertar(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

//total
size_t VideoGame::total()
{
    return civilizaciones.size();
}

//crear civilizaciones
void VideoGame::inicializar(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

//primera
Civilizacion VideoGame::primera()
{
    return civilizaciones.front();
}

//ultimo
Civilizacion VideoGame::ultimo()
{
    return civilizaciones.back();
}

//ordenar nombre
void VideoGame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}

//ordenar ubicacion x
void VideoGame::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getX() < c2.getX();});
}

//ordenar ubicacion y
void VideoGame::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getY() < c2.getY();});
}

//ordenar puntuacion
void VideoGame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

//eliminar
Civilizacion* VideoGame::eliminar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        civilizaciones.erase(it);
        return 0;
    }
}

//buscar
Civilizacion* VideoGame::buscar(const Civilizacion &c)
{
    //vector<Computadora>::iterator
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}
