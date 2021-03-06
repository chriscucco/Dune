#include "fremen.h"
#include "../Armas/lanza_misiles.h"
#include "../Armas/rifle_asalto.h"

#define ID_FREMEN 12 //para usarlo en el protocolo

//DATOS DE INICIALIZACION HARCODEADOS (VAN A VENIR DEL ARCHIVO CONFIG)
Fremen::Fremen(int id, int id_duenio, std::pair<int, int> centro,
 Root &root) : 
	UnidadInfanteria(root["Fremen"].get("rango", 0).asInt(),
	 root["Fremen"].get("velocidad", 0).asInt(), 
	 root["Fremen"].get("tiempo_entrenamiento", 0).asInt(), 
	 root["Fremen"].get("costo", 0).asInt(), 
	 root["Fremen"].get("puntos_vida", 0).asInt(), id, id_duenio, 
	 root["Fremen"].get("dimension_ancho", 0).asInt(), 
	 root["Fremen"].get("dimension_alto", 0).asInt(), centro) {
		id_tipo = ID_FREMEN;
		RifleAsalto rifle_asalto(root);
		LanzaMisiles lanza_misiles(root);
		armas.push_back(RifleAsalto(rifle_asalto));
		armas.push_back(LanzaMisiles(lanza_misiles));
		rango_ataque_fila = 10;
		rango_ataque_columna = 10;
		for (unsigned int i = 0; i < 
		root["Fremen"]["edificios_necesarios"].size(); i++) {
			ids_tipos_edificios_necesarios.push_back(
			root["Fremen"]["edificios_necesarios"][i].asInt());
		}
	}

std::vector<ObjetoDune*> Fremen::atacar_objetivo(Mapa &mapa, 
int id_objetivo) {
	std::vector<ObjetoDune*> objetos_afectados;
	objetos_afectados.push_back(mapa.obtener_objeto(id_objetivo));
	return objetos_afectados;
}

void Fremen::matar() {
	UnidadMovible::poner_estado_muerta();
}

std::vector<ObjetoDune*> Fremen::ataque_al_morir(Mapa &mapa) {
	std::vector<ObjetoDune*> objs;
	return objs;
}
