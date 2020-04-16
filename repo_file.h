#ifndef REPOFILE_H
#define REPOFILE_H
#include <sstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include "repo.h"

template<class T>
class RepoFile : public Repo<T> {
private:
	const char* file_name;
public:
	RepoFile<T>();
	RepoFile(const char*);
	~RepoFile();
	void loadFromFile(const char*);
	void saveToFile();
};

template<class T>
RepoFile<T>::RepoFile<T>():Repo<T>(){
	file_name = NULL;
}

template<class T>
RepoFile<T>::RepoFile(const char* new_file_name) {
	this->file_name = new_file_name;
	std::ifstream f(file_name);
	std::string linie;
	while (getline(f, linie)) {
		T t(linie);
		this->addItem(t);
	}
	f.close();
}

template<class T>
void RepoFile<T>::loadFromFile(const char* new_file_name) {
	this->elem.clear();
	this->file_name = new_file_name;
	std::ifstream f(file_name);
	std::string linie;
	while (getline(f, linie)) {
		T t(linie);
		this->addItem(t);
	}
	f.close();
}

template<class T>
void RepoFile<T>::saveToFile() {
	std::ofstream f(file_name);
	std::deque<T> elem = this->getAll();
	for (int i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}

template <class T>
RepoFile<T>::~RepoFile() {
	file_name = NULL;
}

#endif // !REPOFILE_H