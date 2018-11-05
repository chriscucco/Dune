#ifndef DESVIADOR_H
#define DESVIADOR_H

#include "vehiculo.h"
#include <vector>

/*Clase que representa una unidad de un desviador en el mundo de Dune.
Es un tanque que dispara un misil que al explotar esparce una nube tóxica y 
genera una confusion en la unidad impactada de manera que pasa a ser del
jugador.*/ 
class Desviador: public Vehiculo {
	public:
		/*Constructor de la clase.*/
		Desviador(int id, int id_duenio, std::pair<int, int> centro);

		/*Recibe el mapa y el id del objeto y devuelve todas las unidades
		afectadas por su ataque.*/
		virtual std::vector<int> atacar_objetivo(Mapa &mapa, int id_objetivo);

		/*Recibe un mapa, mata a la unidad y la remueve del mapa. Devuelve
		un vector con pares (id_duenio, vida_restante) segun si la unidad
		afecto unidades vecinas al morir.*/
		virtual std::vector<std::pair<int, int>> matar(Mapa &mapa);
};

#endif

