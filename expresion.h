#ifndef EXPRESION_H
#define EXPRESION_H

#include <string>
#include "tipo.h"
#include "ast.h"

namespace MiniOlc {
class Expresion {
    public:
        Expresion();
        Expresion(int _linea, int _columna);
        int linea, columna;
        virtual Retorno ejecutar(MiniOlc::AST *entorno);
};
}

#endif // EXPRESION_H
