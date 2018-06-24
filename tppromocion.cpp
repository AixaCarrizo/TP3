#include <cstdlib>
#include <iostream>
#define INFI  9000
#define MAXNODOS  5
#define no_visitado 0
#define visitado 1
#define CANTCIUDADES 8
using namespace std;


class ciudad{
	string nombreciudad;
	//int distancias[CANTCIUDADES][CANTCIUDADES];
   
    
    void setNombreCiudad(string nombre){nombreciudad=nombre;};
    //void setDistancias(int dist[CANTCIUDADES][CANTCIUDADES]);//por el momneto esto no lo use y pienso seriamente en borrarlo
    string getNombreCiudad(){return nombreciudad;};
    //int getdistanciaentreciudades(string a, string b, ciudad* ciudades[],int matrizdistancias[CANTCIUDADES][CANTCIUDADES]);

    public:
    void setCiudad(string nombre){setNombreCiudad(nombre);};
    //void setDist(int dist[CANTCIUDADES][CANTCIUDADES]){setDistancias (dist);};
    string getNombre(){return getNombreCiudad();};
    //int getDistancia(string a, string b,ciudad * ciudades[],int matrizdistancias[CANTCIUDADES][CANTCIUDADES]){return getdistanciaentreciudades(a, b,ciudades, matrizdistancias);};
};
typedef ciudad * pciudad;
int ubicacionCiudad(string nombre, pciudad  ciudades[]);
typedef ciudad * pciudad;

/*void ciudad::setDistancias(int dist[CANTCIUDADES][CANTCIUDADES]){
	for(int i=0; i<CANTCIUDADES; i++){
		for(int j=0; j<CANTCIUDADES; j++){
			distancias[i][j]=dist[i][j];
		}
	}
}
*/

int getdistanciaentreciudades(string a, string b, pciudad ciudades[],int matrizdistancias[CANTCIUDADES][CANTCIUDADES]){
	int ciudad1=ubicacionCiudad(a,ciudades);int ciudad2 =ubicacionCiudad(b, ciudades);
	return matrizdistancias[ciudad1][ciudad2];
}
cargarCiudades(pciudad ciudades[]){
	string nombres[CANTCIUDADES]={"MA", "BA", "RO", "PA", "LO", "BE", "AM", "MO"};
	for(int i=0; i<CANTCIUDADES; i++){
		ciudades[i]=new ciudad;
		ciudades[i]->setCiudad(nombres[i]);
	}
}

int ubicacionCiudad(string nombre, pciudad  ciudades[] ){
	for(int i=0; i<CANTCIUDADES;i++){
		if(ciudades[i]->getNombre()==nombre){
			return i;
		}
    }
}

void BPF(int v, int peso[][MAXNODOS], int marca[]){
   int w;
   marca[v]=visitado;
   cout<<"v="<<v<<endl;
   for(w=0;w<MAXNODOS;w++){
       if((peso[v][w]==1)&&(marca[w]==no_visitado)) BPF(w,peso,marca);
   }      
}

void toPrint(pciudad ciudades[], int matrizdistancias[CANTCIUDADES][CANTCIUDADES]){
	  for(int i=0; i<CANTCIUDADES; i++){
  	cout<<"ciudad: "<<ciudades[i]->getNombre()<<"   Nro de ciudad: "<<i<<endl<<endl;
  }
  cout<<"matriz de distancias"<<endl;
  for(int i=0; i<CANTCIUDADES; i++){
  	cout<<endl;
  	for(int j=0; j<CANTCIUDADES; j++){
  		cout<<matrizdistancias[i][j]<<"  ";
	  }
  }
}

int main(int argc, char *argv[])
{  
  pciudad ciudades[CANTCIUDADES];
  int matrizdistancias[CANTCIUDADES][CANTCIUDADES]={   0, 150, 180, 210, 340, 310, 280, 600,
                                                     150,   0, 220, 200, 350, 290, 220, 590,
                                                     180, 220,   0, 350, 440, 240, 200, 700, 
													 210, 200, 350,   0,  95, 180, 200, 500,
													 340, 350, 440,  95,   0, 300, 180, 800,
													 310, 290, 240, 180, 300,   0, 150, 240,
													 280, 220, 200, 200, 180, 150,   0, 780, 
													 600, 590, 700, 500, 800, 240, 780,   0  };


  cargarCiudades(ciudades);
  toPrint(ciudades, matrizdistancias);
  
  cout<<endl<<endl<<"distancia madrid->londres: "<<getdistanciaentreciudades("MA", "LO", ciudades, matrizdistancias)<<endl;
  cout<<"distancia londres->madrid: "<<getdistanciaentreciudades("LO", "MA", ciudades, matrizdistancias)<<endl;
  
}


