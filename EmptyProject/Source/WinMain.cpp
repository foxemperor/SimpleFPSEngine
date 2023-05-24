/* ------------------------------------------------------ */
/*  Filename: WinMain.cpp                                 */
/*  Author: Dmitry Koval aka FoxEmperor                   */
/*  Licence: MIT Licence                                  */
/* ------------------------------------------------------ */

#include "pch.h"

/* ------------------------------------------------------ */
/*  Глобальные переменные                                 */
/* ------------------------------------------------------ */
#pragma region GlobalVariables

WCHAR			WindowClass[MAX_NAME_STRING];
WCHAR			WindowTitle[MAX_NAME_STRING];

INT				WindowWidth; // Ширина окна
INT				WindowHeight; // Высота окна

HICON			hIcon; // Переменная значка

#pragma endregion

/* ------------------------------------------------------ */
/*  Пре-объявления                                        */
/* ------------------------------------------------------ */
#pragma region Pre-Declarations

VOID InitializeVariables();
VOID CreateWindowClass();
VOID InitializeWindow();
VOID MessageLoop();
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);
#pragma endregion

/* ------------------------------------------------------ */
/*  Операции Windows                                      */
/* ------------------------------------------------------ */
#pragma region Windows Operation
/* - Где первый HINSTANCE - это hInstance, а второй HINSTANCE - это hPrevInstance, от которого мы избавились из-за отсутсвия поддержки в Windows 8 и выше - */
/*
INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	InitializeVariables();
	CreateWindowClass();
	InitializeWindow();
	MessageLoop();

	return 0;
}
*/
/* - Класс закрытия программы после закрытия окна - */
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0); // Закрытие программы
		break;
	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}
#pragma endregion

/* ------------------------------------------------------ */
/*  Функции                                               */
/* ------------------------------------------------------ */
#pragma region Functions
/* - Инициализация глобальных переменных - */
VOID InitializeVariables() {
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING); // Установка имени класса окна
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING); // Установка заголовка окна
	WindowWidth = 1366; // Установка ширины окна
	WindowHeight = 768; // Установка высоты окна
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON)); // Загрузка значка
}
/* - Создание окна - */
VOID CreateWindowClass()
{
	WNDCLASSEX wcex; // Встроенный класс для отрисовки окон
	wcex.cbSize = sizeof(WNDCLASSEX); // Размер структуры
	wcex.style = CS_HREDRAW | CS_VREDRAW; // Стиль окна
	wcex.cbClsExtra = 0; // Дополнительное место для класса
	wcex.cbWndExtra = 0; // Дополнительное место для окна
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); // Загрузка курсора
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); // Задание фона окна
	wcex.hIcon = hIcon; // Загрузка иконки
	wcex.hIconSm = hIcon; // Загрузка маленькой иконки
	wcex.lpszClassName = WindowClass; // Установка имени класса
	wcex.lpszMenuName = nullptr; // Установка имени меню
	wcex.hInstance = HInstance(); // Получение экземпляра приложения
	wcex.lpfnWndProc = WindowProcess; // Установка функции обработки сообщений окна
	RegisterClassEx(&wcex); // Регистрация класса окна
}
/* - Создаем и отображаем окно приложения - */
VOID InitializeWindow() {
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr); // Создание окна
	if (!hWnd) {
		MessageBox(0, L"Failed to Create Window!", 0, 0); // Вывод сообщения об ошибке, если окно не удалось создать
		PostQuitMessage(0); // Закрыть окно
	}
	/* - Показать окно - */
	ShowWindow(hWnd, SW_SHOW);
}
/* - Прослушать сообщения - */
VOID MessageLoop() {
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		// Если есть сообщения в очереди, обрабатываем их
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg); // Переводим сообщения клавиш в символы
			DispatchMessage(&msg); // Отправляем сообщение на обработку
		}
	}
}
#pragma endregion