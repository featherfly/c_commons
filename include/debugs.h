#ifndef __FF__DEBUGS_H
#define __FF__DEBUGS_H

#ifdef ENABLE_DEBUG
#define D(_code) _code
#else
#define D(_code)
#endif

#endif