#ifndef EXPRESION_H
#define EXPRESION_H

#include <string>

namespace MiniOlc {
class Expresion {
    public:
        Expresion();
        Expresion(Expresion *_operandoIzquierda, Expresion *_operandoDerecha, char _operador);
        Expresion *operandoIzquierda;
        Expresion *operandoDerecha;
        char operador;
        std::string valor;
        int evaluar();
};
}

#endif // EXPRESION_H
