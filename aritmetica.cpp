#include "ast.h"
#include "aritmetica.h"
#include "tipo.h"


namespace MiniOlc {
Aritmetica::Aritmetica(Expresion *_operandoIzquierda, Expresion *_operandoDerecha, OperacionAritmetica _tipoOperacion, int linea, int columna) : Expresion (linea, columna) {
    this->operandoIzquierda = _operandoIzquierda;
    this->operandoDerecha = _operandoDerecha;
    this->tipoOperacion = _tipoOperacion;
}

Retorno Aritmetica::ejecutar(MiniOlc::AST *entorno) {
    Retorno resultado;
    resultado.tipo = INT;
    switch(this->tipoOperacion){
        case SUMA: {
            int valor1 = *(int*)operandoIzquierda->ejecutar(entorno).valor + *(int*)operandoDerecha->ejecutar(entorno).valor;
            resultado.valor = &valor1;
            break;
        }
        case RESTA:{
            int valor2 = *(int*)operandoIzquierda->ejecutar(entorno).valor - *(int*)operandoDerecha->ejecutar(entorno).valor;
            resultado.valor = &valor2;
            break;
        }
        case MULTIPLICACION: {
            int valor2 = *(int*)operandoIzquierda->ejecutar(entorno).valor * *(int*)operandoDerecha->ejecutar(entorno).valor;
            resultado.valor = &valor2;
            break;
        }
        case DIVISION: {
            int valor2 = *(int*)operandoIzquierda->ejecutar(entorno).valor / *(int*)operandoDerecha->ejecutar(entorno).valor;
            resultado.valor = &valor2;
            break;
        }
        case MODULO:{
            int valor2 = *(int*)operandoIzquierda->ejecutar(entorno).valor % *(int*)operandoDerecha->ejecutar(entorno).valor;
            resultado.valor = &valor2;
            break;
        }
        case NEGACION: {
            int valor2 = - *(int*)operandoIzquierda->ejecutar(entorno).valor;
            resultado.valor = &valor2;
            break;
        }
    }
    return resultado;
}

}
