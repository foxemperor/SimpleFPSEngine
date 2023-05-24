#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class BLAZE_API IApplication {

	// Приложение

public:
	/* Конструктор приложения */
	IApplication();

	/* Деконструктор */
	virtual ~IApplication() {};


public:
	/* Вызов инициализации приложения при запуске  */
	virtual VOID Initialize() = 0;

	/* Обновление - Запускается в каждом цикле работы приложения */
	virtual VOID Update() = 0;
};

IApplication* EntryApplication();