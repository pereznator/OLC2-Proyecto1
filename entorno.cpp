#include "entorno.h"
#include <stdio.h>

namespace MiniOlc {
Entorno::Entorno(Entorno &ant): anterior(ant) {
}

Entorno Entorno::getGlobal() {
    Entorno *actual = this;
    while (actual != NULL) {
        actual = &actual->anterior;
    }
    return *actual;
}
}
