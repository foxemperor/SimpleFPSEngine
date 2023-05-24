#pragma once

#include "Platform/WIN32/IApplication.h"


class Application : public IApplication {

	// Приложение

public:
	/* Конструктор приложения */
	Application();

	/* Деконструктор */
	~Application();


public:
	/* Вызов инициализации приложения при запуске  */
	VOID Initialize();

	/* Обновление - Запускается в каждом цикле работы приложения */
	VOID Update();
};