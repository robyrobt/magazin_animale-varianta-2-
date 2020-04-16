#include "animal_service.h"

Service::Service() {}

Service::Service(RepoFile<AnimalCompanie>& repo) {
	this->repo = repo;
}

void Service::addAnimal(AnimalCompanie& animal) {
	repo.addItem(animal);
	repo.saveToFile();
}

int Service::deleteAnimal(const char* name) {
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

void Service::updateAnimal(const char* name, int new_cod, const char* new_name, float new_pret, struct data new_data, int new_varsta, int new_nr_exemplare) {
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

std::deque<AnimalCompanie> Service::getAll() {
	return repo.getAll();
}

int Service::findAnimal(AnimalCompanie animal) {
	return repo.findElem(animal);
}

AnimalCompanie Service::findAnimalByName(const char* name) {
	return repo.findByName(name);
}

int Service::getSize() {
	return repo.getSize();
}

Service::~Service() {}