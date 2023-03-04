
#include "tipo.h"
#include "literal.h"
#include "expresion.h"

namespace MiniOlc {

Literal::Literal(std::string _valor, Tipo _tipo, int _linea, int _columna) : Expresion(_linea, _columna) {
    this->valor = _valor;
    this->tipo = _tipo;
}

}
