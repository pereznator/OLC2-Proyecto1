#include "parserctx.hpp"
#include "parser.hpp"
#include "lex.yy.c"
#include "ast.h"

namespace MiniOlc {
    ParserCtx::ParserCtx() {
        // se inicializa el lexer (*void se convierte a scanner)
        yylex_init(&lexer);
        // se crea un location
        loc = new yy::location();
        // se crea un parser
        Parser = new yy::Parser(lexer, *loc, *this);
        Salida = "";
    }

    ParserCtx::~ParserCtx() {
        yylex_destroy(lexer);
        delete loc;
        delete Parser;
    }

    std::string ParserCtx::Analizar(std::string entrada) {
        this->Salida = "";
        MiniOlc::AST::getAST()->salida = "";
        MiniOlc::AST::getAST()->listaErrores = "";
        MiniOlc::AST::getAST()->listaSentencias.clear();

        // ser carga el buffer en analizador
        yy_scan_string(entrada.c_str(), lexer);
        // se activa registro de depuracion
        this->Parser->set_debug_level(true);
        // se analiza
        this->Parser->parse();
        MiniOlc::AST::getAST()->ejecutar();

        this->Salida += MiniOlc::AST::getAST()->salida;
        this->Salida += "\n ERRORES \n" + MiniOlc::AST::getAST()->listaErrores;
        return "";
    }
}

