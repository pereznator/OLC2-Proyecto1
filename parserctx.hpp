#ifndef PARSERCTX_H
#define PARSERCTX_H

#include <string>

namespace yy {
    class Parser;
    class location;
}

namespace MiniOlc {
    class ParserCtx {
        public:
            ParserCtx();
            ~ParserCtx();
            // Atributos del analizador
            void* lexer;
            yy::location* loc;
            yy::Parser* Parser;
            // funcion de analisis
            std::string Analizar(std::string entrada);
            std::string Salida;
    };
}

#endif // PARSERCTX_H
