#include "cas-proto/SymbolBase.h"



CAS_PROTO_API const std::string& SymbolBase::getLexeme() const
{
    return lexeme;
}

CAS_PROTO_API SymbolBase::SymbolBase(const std::string& lexeme)
    : lexeme(lexeme)
{}
