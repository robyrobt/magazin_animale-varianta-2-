#pragma once
#include "animal_service.h"
#include "produs_service.h"

class UI
{
	private:
		AnimalService animal_service;
		//ProdusService produs_service;
		void mainMenu();
		void animalMenu();
		void produsMenu();
		void animal_function();
		void cumpara_animal();
	public:
		UI();
		~UI();
		UI(AnimalService&);
		void show_ui();
};