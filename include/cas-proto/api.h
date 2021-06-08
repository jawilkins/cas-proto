#pragma once
#ifndef api_h
#define api_h

#ifdef _WIN32
# ifdef CAS_PROTO_BUILD_DLL
#  define CAS_PROTO_API __declspec(dllexport)
# else
#  define CAS_PROTO_API __declspec(dllimport)
# endif
#else
# define CAS_PROTO_API
#endif

#endif // api_h
