#include "tanque.h"
#include "../Armas/canion.h"

#define ID_TANQUE 16 //para usarlo en el protocolo

//DATOS DE INICIALIZACION HARCODEADOS (VAN A VENIR DEL ARCHIVO CONFIG)
Tanque::Tanque(int id, int id_duenio, std::pair<int, int> centro,
 Root &root) : 
	Vehiculo(root["Tanque"].get("rango", 0).asInt(),
	 root["Tanque"].get("velocidad", 0).asInt(),
	 root["Tanque"].get("tiempo_entrenamiento", 0).asFloat(),
	 root["Tanque"].get("costo", 0).asInt(), 
	 root["Tanque"].get("puntos_vida", 0).asInt(), id, id_duenio, 
	 root["Tanque"].get("dimension_ancho", 0).asInt(),
	 root["Tanque"].get("dimension_alto", 0).asInt(), centro) {
		id_tipo = ID_TANQUE;
		Canion canion(root);
		armas.push_back(Canion(canion));
		rango_ataque_fila = 10;
		rango_ataque_columna = 10;
		for (unsigned int i = 0; i < 
		root["Tanque"]["edificios_necesarios"].size(); i++) {
			ids_tipos_edificios_necesarios.push_back(
			root["Tanque"]["edificios_necesarios"][i].asInt());
		}
	}

std::vector<ObjetoDune*> Tanque::atacar_objetivo(Mapa &mapa, int id_objetivo) {
	std::vector<ObjetoDune*> objetos_afectados;
	objetos_afectados.push_back(mapa.obtener_objeto(id_objetivo));
	return objetos_afectados;
}

void Tanque::matar() { 
	UnidadMovible::poner_estado_muerta();
}

std::vector<ObjetoDune*> Tanque::ataque_al_morir(Mapa &mapa) {
	std::vector<ObjetoDune*> objs;
	return objs;
}
