#ifndef REPOFILE_H
#define REPOFILE_H

#include "repo.h"

template<class T>
class RepoFile : public Repo<T> {
private:
	char* file_name;
public:
	RepoFile<T>();
	RepoFile(const char*);
	~RepoFile();
	void loadFromFile(const char*);
	void saveToFile();
};

template<class T>
RepoFile<T>::RepoFile<T>():Repo<T>(){}

template<class T>
void RepoFile<T>::saveToFile() {

}

#endif // !REPOFILE_H