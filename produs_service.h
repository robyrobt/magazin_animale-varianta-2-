#pragma once
#include <iostream>
#include "repo_file.h"
#include "produs_animal_companie.h"

class ProdusService
{
private:
	RepoFile<Produs> repo;
public:
	ProdusService();
	ProdusService(RepoFile<Produs>&);
	void addProdus(Produs&);
	int deleteProdus(const char*);
	void updateProdus(const char* name, int, const char*, float, struct data, struct data, int);
	std::deque<Produs> getAll();
	int findProdus(Produs);
	Produs findProdusByName(const char*);
	int getSize();
	~ProdusService();
};