#include "cas-proto/SymbolBase.h"

using std::string;



const string& SymbolBase::getLexeme() const
{
    return lexeme;
}

SymbolBase::SymbolBase(const string& lexeme)
    : lexeme(lexeme)
{}
