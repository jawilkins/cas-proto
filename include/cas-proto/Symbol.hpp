#pragma once
#ifndef Symbol_hpp
#define Symbol_hpp

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#include "Symbol.h"

#include <cassert>



template<class T>
Symbol<T>& Symbol<T>::Create()
{
    return Symbol<T>::Create(T::genLexeme(), T::undef);
}

template<class T>
Symbol<T>& Symbol<T>::Create(const std::string& lexeme)
{
    return Symbol<T>::Create(lexeme, T::undef);
}

template<class T>
Symbol<T>& Symbol<T>::Create(const std::string& lexeme, T& definition)
{
    return *(new Symbol<T>(lexeme, definition));
}

template<class T>
Symbol<T>& Symbol<T>::Create(T& definition)
{
    return *(new Symbol<T>(T::genLexeme(), definition));
}

template<class T>
T& Symbol<T>::getDefinition() const
{
    return *definition_ptr;
}

template<class T>
void Symbol<T>::Redefine(T& definition)
{
    definition_ptr->Release();
    definition_ptr = &definition;
    definition_ptr->Acquire();
}

template<class T>
Symbol<T>::Symbol(const std::string& lexeme, T& definition)
    : SymbolBase(lexeme)
    , definition_ptr(&definition)
{
    if (definition_ptr != &T::undef) definition_ptr->Acquire();
}

template<class T>
Symbol<T>::~Symbol()
{
    if (definition_ptr != &T::undef) definition_ptr->Release();
    definition_ptr = 0;
}

#endif // Symbol_hpp
