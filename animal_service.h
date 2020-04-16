#pragma once
#include <iostream>
#include "repo_file.h"
#include "animal_de_companie.h"

class Service
{
	private:
		RepoFile<AnimalCompanie> repo;
	public:
		Service();
		Service(RepoFile<AnimalCompanie>&);
		void addAnimal(AnimalCompanie&);
		int deleteAnimal(const char*);
		void updateAnimal(const char*);
		std::deque<AnimalCompanie> getAll();
		int findAnimal(AnimalCompanie);
		AnimalCompanie findAnimalByName(const char*);
		int getSize();
		~Service();
};