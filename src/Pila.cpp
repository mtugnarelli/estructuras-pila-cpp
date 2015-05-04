#include "Pila.h"

#define ELEMENTO_INVALIDO 0;

Pila::Pila() {

    this->tope = NULL;
}

bool Pila::estaVacia() {

    return (this->tope == NULL);
}

void Pila::apilar(char elemento) {

    Nodo* nuevoTope = new Nodo(elemento);
    nuevoTope->cambiarSiguiente(this->tope);
    this->tope = nuevoTope;
}

char Pila::desapilar() {

    char elemento = ELEMENTO_INVALIDO;

    if (! this->estaVacia()) {

        /* remueve el tope de la estructura */
        Nodo* topeAnterior = this->tope;
        this->tope = topeAnterior->obtenerSiguiente();

        /* devuelve el elemento y libera los recursos asociados */
        elemento = topeAnterior->obtenerDato();
        delete topeAnterior;
    }

    return elemento;
}

char Pila::obtenerTope() {

    char elemento = ELEMENTO_INVALIDO;

    if (! this->estaVacia()) {

        elemento = this->tope->obtenerDato();
    }

    return elemento;
}

Pila::~Pila() {

    while (! this->estaVacia()) {

        this->desapilar();
    }
}
