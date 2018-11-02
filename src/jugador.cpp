#include "jugador.h"
#include <iostream>

Jugador::Jugador(std::string casa): casa(casa) {
	dinero = 100000000; //INICIO DE DINERO DE UN JUGADOR -->HACER SETEABLE
}

bool Jugador::agregar_edificio(std::shared_ptr<Edificio> edificio, 
int id_edificio, int id_tipo_edificio) {
	int costo = edificio->obtener_costo();
	if (costo > dinero) return false;
	else {
		reducir_dinero(costo);
		edificios.insert(std::pair<int, std::shared_ptr<Edificio>>(id_edificio, 
		edificio));
		if (edificios_por_tipo.count(id_tipo_edificio) > 0) {
			(edificios_por_tipo.at(id_tipo_edificio))++;
		} else {
			edificios_por_tipo.insert(std::pair<int, 
			int>(id_tipo_edificio, 1));
		}
		return true;
	}
}

bool Jugador::agregar_unidad(std::shared_ptr<UnidadMovible> unidad, 
int id_unidad, int id_tipo_unidad) {
	int costo = unidad->obtener_costo();
	if (costo > dinero) return false;
	if (!existe_edificio(id_tipo_unidad)) return false;
	else {
		reducir_dinero(costo);
		unidades.insert(std::pair<int, std::shared_ptr<UnidadMovible>>(id_unidad, 
		unidad));
		if (unidades_por_tipo.count(id_tipo_unidad) > 0) {
			(unidades_por_tipo.at(id_tipo_unidad))++;
		} else {
			unidades_por_tipo.insert(std::pair<int, 
			int>(id_tipo_unidad, 1));
		}
		return true;
	}
}

void Jugador::reducir_dinero(int valor) {
	dinero -= valor;
}

void Jugador::eliminar_edificio(int id_edificio, int id_tipo_edificio) {
	edificios.erase(id_edificio);
	(edificios_por_tipo.at(id_tipo_edificio))--;
}

void Jugador::eliminar_unidad(int id_unidad, int id_tipo_unidad) {
	unidades.erase(id_unidad);
	(unidades_por_tipo.at(id_tipo_unidad))--;
}

void Jugador::aumentar_dinero(int valor) {
	dinero += valor;
}

bool Jugador::existe_edificio(int id_unidad) {
	switch(id_unidad){
	    case 0: 
	    break;
	    case 1: 
	    break;
	    //en caso de querer crear un raider debe existir una fabrica ligera
	    case 5: if (edificios_por_tipo.count(4) == 0){
	    			std::cout << "No existe edificio con id 4" << std::endl;
	    			return false;
			    }
			    break;
	    default: return false;
	}
	return true;
}