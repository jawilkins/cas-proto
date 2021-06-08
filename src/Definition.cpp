#include "cas-proto/Definition.h"

CAS_PROTO_API bool Definition::IsSame(const Definition& rhs) const
{
    return this == &rhs;
}
