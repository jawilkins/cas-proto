#ifndef SymbolBase_h
#define SymbolBase_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifndef Object_h
#include "Object.h"
#endif



class Definition;

class SymbolBase : public Object {

public:

    CAS_PROTO_API virtual Definition& getDefinition() const = 0;

    CAS_PROTO_API const std::string& getLexeme() const;

protected:

    CAS_PROTO_API SymbolBase(const std::string&);

private:

    SymbolBase(const Object&);                // not implemented
    SymbolBase& operator=(const SymbolBase&); // not implemented

    const std::string lexeme;

};



#endif //' SymbolBase_h
