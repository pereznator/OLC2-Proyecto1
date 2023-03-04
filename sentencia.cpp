#include "sentencia.h"
#include "ast.h"

namespace MiniOlc {
Sentencia::Sentencia(){}
Sentencia::Sentencia(Expresion *_expresion) {
    this->expresion = _expresion;
}

void Sentencia::ejecutar(){
    AST::getAST()->salida += "El resultado es: " + std::to_string(this->expresion->evaluar()) + "\n";
}
}
