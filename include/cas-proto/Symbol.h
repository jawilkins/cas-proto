#ifndef Symbol_h
#define Symbol_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef SymbolBase_h
#include "SymbolBase.h"
#endif



template <class T>
class Symbol : public SymbolBase {

public:

    static Symbol<T>& Create();
    static Symbol<T>& Create(T&);
    static Symbol<T>& Create(const std::string&);
    static Symbol<T>& Create(const std::string&, T&);

    T& getDefinition() const;

    void Redefine(T&);

protected:

    Symbol<T>(const std::string&, T&);

    ~Symbol<T>();

private:

    Symbol<T>(const Symbol&);                // not implemented
    Symbol<T>& operator=(const Symbol<T>&); // not implemented

    T* definition_ptr;

};



#include "Symbol.hpp"



#endif // Symbol_h
