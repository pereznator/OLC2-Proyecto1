#ifndef AST_H
#define AST_H


#include "sentencia.h"
#include <QList>

namespace MiniOlc  {
class AST {
    public:
        AST();
        static AST *ast;
        static AST *getAST();
        std::string salida;
        QList<Sentencia> listaSentencias;
        std::string listaErrores;
        void ejecutar();
};
}

#endif // AST_H
