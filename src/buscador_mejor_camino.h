#ifndef BUSCADOR_MEJOR_CAMINO_H
#define BUSCADOR_MEJOR_CAMINO_H

#include "nodo.h"
#include <vector>
class Mapa;

/*Clase que representa un buscador del mejor camino para ir
desde una posicion a otra. Aplica el algoritmo A*.*/
class BuscadorMejorCamino {
	public:
		/*Recibe el tipo al que pertenece la unidad que se mueve,
		un mapa, una posicion inicial y una final y devuelve
		un vector con el mejor/mas rapido camino posible para ir desde
		el punto inicial al final ,utilizando el algoritmo A*. */
		std::vector<std::pair<int, int>> buscar_mejor_camino(Mapa &mapa, 
		std::pair<int, int> &pos_inicial, std::pair<int, int> &pos_final);

	private:
		/*Recibe un vector de nodos y lo recorre deleteando el padre
		de cada uno si es que tiene.*/
		void delete_vector_nodos(std::vector<Nodo> nodos);
};

#endif
