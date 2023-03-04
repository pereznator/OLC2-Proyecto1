#ifndef ARITMETICA_H
#define ARITMETICA_H

#include "tipo.h"
#include "expresion.h"
#include "ast.h"

namespace MiniOlc {

enum OperacionAritmetica {
    SUMA,
    RESTA,
    MULTIPLICACION,
    DIVISION,
    MODULO,
    NEGACION
};

class Aritmetica: public Expresion {
public:
    Aritmetica(Expresion *_operandoIzquierda, Expresion *_operandoDerecha, OperacionAritmetica tipoOperacion, int linea, int columna);
    Retorno ejecutar(AST *ast);
    Expresion *operandoIzquierda, *operandoDerecha;
    OperacionAritmetica tipoOperacion;
};
}

#endif // ARITMETICA_H
