#pragma once
#include <iostream>
#include "repo_file.h"
#include "animal_de_companie.h"

class AnimalService
{
	private:
		RepoFile<AnimalCompanie> repo;
	public:
		AnimalService();
		AnimalService(RepoFile<AnimalCompanie>&);
		void addAnimal(AnimalCompanie&);
		int deleteAnimal(const char*);
		void updateAnimal(const char* name, int, const char*, float, struct data, int, int);
		std::deque<AnimalCompanie> getAll();
		int findAnimal(AnimalCompanie);
		AnimalCompanie findAnimalByName(const char*);
		int getSize();
		~AnimalService();
};