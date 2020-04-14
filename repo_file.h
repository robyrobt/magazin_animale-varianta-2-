#pragma once
#include "repo.h"

template<class T>
class RepoFile : public Repo<T> {
	private:
		char* file_name;
	public:
		RepoFile();
		RepoFile(const char*);
		~RepoFile();
		void loadFromFile(const char*);
		void saveToFile();
};