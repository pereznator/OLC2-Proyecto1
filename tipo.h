#ifndef TIPO_H
#define TIPO_H

namespace MiniOlc {
    enum Tipo {
        INT,
        DOUBLE,
        STRING,
        BOOLEAN,
        ARRAY,
        NULO
    };

    struct Retorno {
        Tipo tipo;
        void* valor;
    };

}

#endif // TIPO_H
