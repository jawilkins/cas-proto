#pragma once
#ifndef api_h
#define api_h

#ifndef __cplusplus
#error This is a C++ header file.
#endif

#ifdef _WIN32
# if defined(CAS_PROTO_API_EXPORT) && defined(CAS_PROTO_API_IMPORT)
#  error CAS_PROTO_API_EXPORT and CAS_PROTO_API_IMPORT are mutually exclusive options.
# endif
# if defined(CAS_PROTO_API_EXPORT)
#  define CAS_PROTO_API __declspec(dllexport)
# elif defined(CAS_PROTO_API_IMPORT)
#  define CAS_PROTO_API __declspec(dllimport)
# else
#  define CAS_PROTO_API
# endif
#else
# if defined(CAS_PROTO_API_EXPORT) || defined(CAS_PROTO_API_IMPORT))
#  error CAS_PROTO_BUILD_DLL and CAS_PROTO_STATIC are Windows options.
# endif
# define CAS_PROTO_API
#endif



#endif // api_h
