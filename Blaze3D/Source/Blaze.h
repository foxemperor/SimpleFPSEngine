#pragma once

#ifdef _WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
#define BLAZE_API __declspec(dllexport) // ���� ����� ������ ���������� ������, �� �������
#else
#define BLAZE_API __declspec(dllimport) // ���� ����� ��� ���������� ������, �� ������
#endif