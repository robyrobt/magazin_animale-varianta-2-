#include "produs_service.h"

ProdusService::ProdusService() {}

ProdusService::ProdusService(RepoFile<Produs>& repo) {
	this->repo = repo;
}

void ProdusService::addProdus(Produs& Produs) {
	repo.addItem(Produs);
	repo.saveToFile();
}

int ProdusService::deleteProdus(const char* name) {
	Produs del = repo.findByName(name);
	if (del == Produs()) {
		return -1;
	}
	else {
		int i = repo.delItem(del);
		repo.saveToFile();
		return i;
	}
}

void ProdusService::updateProdus(const char* name, int new_cod, const char* new_name, float new_pret, struct data new_data_int, struct data new_data_exp, int new_nr_exemplare) {
	Produs update = repo.findByName(name);
	if (update == Produs()) {
		std::cout << "fail" << std::endl;
	}
	else {
		Produs up(new_cod, new_name, new_pret, new_data_int, new_data_exp, new_nr_exemplare);
		repo.updateItem(update, up);
		repo.saveToFile();
	}
}

std::deque<Produs> ProdusService::getAll() {
	return repo.getAll();
}

int ProdusService::findProdus(Produs Produs) {
	return repo.findElem(Produs);
}

Produs ProdusService::findProdusByName(const char* name) {
	return repo.findByName(name);
}

int ProdusService::getSize() {
	return repo.getSize();
}

ProdusService::~ProdusService() {}