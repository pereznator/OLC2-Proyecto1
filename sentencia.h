#ifndef SENTENCIA_H
#define SENTENCIA_H

#include "expresion.h"

namespace MiniOlc {
class Sentencia{
    public:
        Sentencia();
        Sentencia(Expresion *_expresion);
        Expresion *expresion;
        void ejecutar();
};
}

#endif // SENTENCIA_H
