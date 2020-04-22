#include <cassert>
#include <iostream>
#include "teste_service.h"
#include "repo_file.h"
#include "utils.h"
#include "animal_de_companie.h"
#include "animal_service.h"

TesteService::TesteService() {}

TesteService::~TesteService() {}

void TesteService::teste_service() {
	this->teste_add_and_del();
	this->teste_update();
}

void TesteService::teste_add_and_del() {
	struct data data_caine, data_pisica;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	AnimalCompanie a1(2, "caine", 39, data_caine, 12, 3), a2(3, "pisica", 34, data_pisica, 1, 3);
	RepoFile<AnimalCompanie> repo("teste_service.txt");
	AnimalService service(repo);
	assert(service.getSize() == 2);
	std::deque<AnimalCompanie> elem = service.getAll();
	assert(strcmp(elem[1].getName(), "pisica") == 0);
	int i = service.deleteAnimal("caine");
	assert(i == 0);
}

void TesteService::teste_update() {
	struct data data_caine, data_pisica;
	data_caine.zi = 12;
	data_caine.luna = 5;
	data_caine.an = 1900;
	data_pisica.zi = 3;
	data_pisica.luna = 1;
	data_pisica.an = 200;
	AnimalCompanie a1(2, "caine", 39, data_caine, 12, 3), a2(3, "pisica", 34, data_pisica, 1, 3);
	RepoFile<AnimalCompanie> repo("teste_service.txt");
	AnimalService service(repo);
	std::deque<AnimalCompanie> elem = service.getAll();
	service.updateAnimal("cal", 1, "veverita", 45.5, data_caine, 3, 3);
	assert(elem[0].getCod() == 1);
	assert(strcmp(elem[0].getName(), "veverita") == 0);
}

