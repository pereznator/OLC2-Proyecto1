#ifndef LITERAL_H
#define LITERAL_H

#include "expresion.h"
#include "tipo.h"
#include "ast.h"
#include "valorliteral.h"

namespace MiniOlc {

class Literal : public Expresion {
public:
    Literal(std::string _valor, MiniOlc::Tipo _tipo, int linea, int columna);
    ValorLiteral<void> valor;
    MiniOlc::Tipo tipo;
    MiniOlc::Retorno ejecutar(MiniOlc::AST *entorno);
};
}

#endif // LITERAL_H
