#include "ui.h"
#include "utils.h"
UI::UI() {}

UI::~UI() {}

UI::UI(AnimalService& animal_serv){//, ProdusService& produs_serv) {
	this->animal_service = animal_serv;
	//this->produs_service = produs_serv;
}

void UI::mainMenu() {
	std::cout << "1. Animale de companie" << std::endl;
	std::cout << "2. Produse pentru animale de companie" << std::endl;
	std::cout << "0. Close" << std::endl;
}

void UI::animalMenu() {
	std::cout << "1. Cumpara animal (nume)" << std::endl;
	std::cout << "2. Afisare animale" << std::endl;
	std::cout << "0. Close" << std::endl;
}

void UI::cumpara_animal() {
	char* animal_name = new char[30];
	std::cout << "numele animalului: "; std::cin >> animal_name;
	AnimalCompanie animal = this->animal_service.findAnimalByName(animal_name);
	if (animal == AnimalCompanie()) {
		std::cout << "Animalul cu numele " << animal_name <<R"( nu a fost gasit)" << std::endl;
	}
	else {
		int exemplare, exempl;
		std::cout << "Cata exemplare?: "; std::cin >> exemplare;
		exempl = animal.getNrExemplare() - exemplare;
		if (exempl < 0) {
			std::cout << "Ati introdus prea multe exemplare. Numarul exestent de exemplare este: " << animal.getNrExemplare() << std::endl;
		}
		else {
			animal_service.updateAnimal(animal.getName(), animal.getCod(), animal.getName(), animal.getPret(), animal.getData(), animal.getVarsta(), exempl);
			std::cout << "Cumparat cu succes" << std::endl;
		}
	}
}

void UI::animal_function() {
	showAll(this->animal_service.getAll());
	std::cout << std::endl;
	bool gata = false;
	int opt;
	while (!gata) {
		this->animalMenu();
		std::cout << "opt: "; std::cin >> opt;
		switch (opt) {
		case 1: this->cumpara_animal(); break;
		case 2: showAll(this->animal_service.getAll()); break;
		case 0: gata = true; break;
		default:
			break;
		}
	}
}

void UI::show_ui() {
	bool gata = false;
	int opt;
	while (!gata) {
		this->mainMenu();
		std::cout << "opt: "; std::cin >> opt;
		switch (opt)
		{
		case 1: this->animal_function(); break;
		case 0: gata = true; break;
		default:
			break;
		}
	}
}