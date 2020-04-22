#include "animal_service.h"

AnimalService::AnimalService() {}

AnimalService::AnimalService(RepoFile<AnimalCompanie>& repo) {
	this->repo = repo;
}

void AnimalService::addAnimal(AnimalCompanie& animal) {
	repo.addItem(animal);
	repo.saveToFile();
}

int AnimalService::deleteAnimal(const char* name) {
	AnimalCompanie del = repo.findByName(name);
	if (del == AnimalCompanie()) {
		return -1;
	}
	else {
		int i = repo.delItem(del);
		repo.saveToFile();
		return i;
	}
}

void AnimalService::updateAnimal(const char* name, int new_cod, const char* new_name, float new_pret, struct data new_data, int new_varsta, int new_nr_exemplare) {
	AnimalCompanie update = repo.findByName(name);
	if (update == AnimalCompanie()) {
		std::cout << "fail" << std::endl;
	}
	else {
		AnimalCompanie up(new_cod, new_name, new_pret, new_data, new_varsta, new_nr_exemplare);
		repo.updateItem(update, up);
		repo.saveToFile();
	}
}

std::deque<AnimalCompanie> AnimalService::getAll() {
	return repo.getAll();
}

int AnimalService::findAnimal(AnimalCompanie animal) {
	return repo.findElem(animal);
}

AnimalCompanie AnimalService::findAnimalByName(const char* name) {
	return repo.findByName(name);
}

int AnimalService::getSize() {
	return repo.getSize();
}

AnimalService::~AnimalService() {}