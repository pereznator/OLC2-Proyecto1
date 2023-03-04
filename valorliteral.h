#ifndef VALORLITERAL_H
#define VALORLITERAL_H

namespace MiniOlc {
template <typename TvalorLiteral>
class ValorLiteral {
public:
    TvalorLiteral getValue();
private:
    TvalorLiteral value;
};
}

#endif // VALORLITERAL_H
