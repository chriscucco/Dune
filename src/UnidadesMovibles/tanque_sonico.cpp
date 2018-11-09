#include "tanque_sonico.h"
#include "../Armas/onda_sonido.h"

#define ID_TANQUE_SONICO 17 //para usarlo en el protocolo

//DATOS DE INICIALIZACION HARCODEADOS (VAN A VENIR DEL ARCHIVO CONFIG)
TanqueSonico::TanqueSonico(int id, int id_duenio, std::pair<int, int> centro,
 Root &root) : 
	Vehiculo(root["Tanque sonico"].get("rango", 0).asInt(),
	 root["Tanque sonico"].get("velocidad", 0).asInt(),
	 root["Tanque sonico"].get("tiempo_entrenamiento", 0).asFloat(),
	 root["Tanque sonico"].get("costo", 0).asInt(), 
	 root["Tanque sonico"].get("puntos_vida", 0).asInt(), id, id_duenio, 
	 root["Tanque sonico"].get("dimension_ancho", 0).asInt(),
	 root["Tanque sonico"].get("dimension_alto", 0).asInt(), centro) {
		id_tipo = ID_TANQUE_SONICO;
		OndaSonido arma_ondas_sonidos(root);
		armas.push_back(OndaSonido(arma_ondas_sonidos));
		expansion_altura_arma_sonica = 70;
		expansion_base_arma_sonica = 50;
		rango_ataque_fila = 10;
		rango_ataque_columna = 10;
		ids_tipos_edificios_necesarios.push_back(5);
		ids_tipos_edificios_necesarios.push_back(7);
	}

std::vector<int> TanqueSonico::atacar_objetivo(Mapa &mapa, int id_objetivo) {
	std::vector<int> objetivos = UnidadMovible::atacar(mapa, id_objetivo);
	if (!objetivos.empty()) {
		return mapa.buscar_unidades_alrededor(this->centro, this->altura,
		this->base, false);
	}
	return objetivos;
}

std::vector<int> TanqueSonico::matar(Mapa &mapa) { 
	UnidadMovible::eliminar(mapa);
	std::vector<int> vecinos_afectados;
	return vecinos_afectados;
}
