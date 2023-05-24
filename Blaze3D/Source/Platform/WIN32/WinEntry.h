#include "Blaze.h"
#include "IApplication.h"

extern IApplication* EntryApplication();

INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryApp = EntryApplication();

	EntryApp->Initialize();

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		// Если есть сообщения в очереди, обрабатываем их
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg); // Переводим сообщения клавиш в символы
			DispatchMessage(&msg); // Отправляем сообщение на обработку
		}
		else {
			EntryApp->Update();
		}
	}

	return 0;
}
