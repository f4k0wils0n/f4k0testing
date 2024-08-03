#pragma once

#define VERBOSE_BUILD 1



#if defined __cplusplus && __cplusplus != 0
# include "cppinc.hpp"
# if VERBOSE_BUILD == 1
#  pragma message ("Using c++ compiler")
# endif
#elif defined __STDC__ && __STDC__ != 0
# include "cinc.h"
# if VERBOSE_BUILD == 1
#  pragma message ("Using C compiler")
# endif
#else
# if VERBOSE_BUILD == 1
#  pragma message ("Using unknown compiler")
# endif
# include "cppinc.hpp"
# include "cinc.h"
#endif

#if VERBOSE_BUILD == 1
# define STRINGIFY(x) #x
# define TOSTRING(x) STRINGIFY(x)
# if defined _DEBUG
#  pragma message ("Build: Debug")
# elif defined NDEBUG
#  pragma message ("Build: Release")
# else
#  pragma message ("Build: Unknown")
# endif
# if defined _MSC_FULL_VER
#  pragma message ("MSVC version: " TOSTRING(_MSC_FULL_VER))
# endif
# if defined (_M_X64)
#  pragma message ("Architecture: x64")
# elif defined (_M_IX86)
#  pragma message ("Architecture: x86")
# else
#  pragma message ("Architecture: Unknown")
# endif
#endif
