#include "Utils.h"
#include "Monomio.h"
#include <cstdlib>
#include <iostream>
#include <string>

/**
 * Función que muestra los participantes del grupo
 * @param programa nombre del ejecutable
 */
void participantes(std::string programa);


/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char **argv) {
    std::cout << std::endl;
    int exitCode;
    /// Si no hay argumentos suficientes mostramos un texto por defecto.
    if (argc != 2) {
        std::cout << "Argumentos inválidos, ejecute el programa de la siguiente forma:" << std::endl;
        std::cout << argv[0] << " \"[integral polinomica]\" [valor]" << std::endl;
        exitCode = EXIT_FAILURE;
    }
    else {
        /// Proceso
        const std::string polinomio(argv[1]);
        std::vector<Monomio> monomios = Utils::convertir(polinomio);    //Combierte el polinomio(string) en un vector de polinomios
        std::vector<Monomio> monomiosDerivado = monomios;

        monomiosDerivado = Utils::derivar(monomios);                    //Deriva el vector de monomios
        std::cout << "polinomio (Derivado): ";
        Utils::mostrarPolinomio(monomiosDerivado);                      //Muestra la estructura del polinomio derivado
        double resultadoNewton = Utils::newtonRaphson(monomios);        //genera la aproximacion a la raiz
        std::cout << "Aproximación a la raiz del polinomio mediante el método " << std::endl<< "de Newton Raphson con 10 iteraciones: " << resultadoNewton<< std::endl;


        exitCode = EXIT_SUCCESS;
    }
    participantes("Taller 1");
    return exitCode;
}

void participantes(std::string programa) {
    std::cout << std::endl << "=== Taller " << programa << " ===" << std::endl;
    std::cout << std::endl << "Nombre: Mauricio Bustos Miranda // Rut: 20.133.935-9 ";
    std::cout << std::endl << "Nombre: Cristobal Ramirez Gonzalez // Rut: 20.107.983-7";
}
