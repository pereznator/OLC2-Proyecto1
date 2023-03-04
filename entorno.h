#ifndef ENTORNO_H
#define ENTORNO_H

namespace MiniOlc {
    class Entorno {
    public:
        Entorno(Entorno &ant);
        Entorno &anterior;
        Entorno getGlobal();
    };
}

#endif // ENTORNO_H
