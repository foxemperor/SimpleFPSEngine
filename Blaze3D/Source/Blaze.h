#pragma once

#ifdef _WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
#define BLAZE_API __declspec(dllexport) // Если файлы внутри директории движка, то экспорт
#else
#define BLAZE_API __declspec(dllimport) // Если файлы вне директории движка, то импорт
#endif