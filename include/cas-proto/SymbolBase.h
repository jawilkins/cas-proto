#ifndef SymbolBase_h
#define SymbolBase_h

#ifndef Object_h
#include "Object.h"
#endif



class Definition;

class SymbolBase : public Object {

public:

    virtual Definition& getDefinition() const = 0;

    const std::string& getLexeme() const;

protected:

    SymbolBase(const std::string&);

private:

    SymbolBase(const Object&); // not implemented
    SymbolBase& operator = (const SymbolBase&); // not implemented

    const std::string lexeme;

};



#endif
