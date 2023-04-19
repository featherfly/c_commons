#ifndef __FF__OS_ENV_H
#define __FF__OS_ENV_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#include <windows.h>

#define IS_WIN(_code) _code

#define SET_CONSOLE_OUTPUT_UTF8() SetConsoleOutputCP(65001);
#define CONSOLE_OUTPUT_UTF8 SetConsoleOutputCP(65001);

//    设置windows 控制台终端为utf-8
//    SetConsoleOutputCP(65001);
//    system("chcp 65001 & cls");

#else

#define IS_WIN(_code)
// 或许来处理
#define SET_CONSOLE_OUTPUT_UTF8() ;
#define CONSOLE_OUTPUT_UTF8 ;

#endif


#ifdef __cplusplus
}
#endif

// 头文件定义宏结束
#endif
