#include <iostream>
#include <string.h>
#include <vector>
#include "utils.h"
#include "teste_animal_companie.h"
#include "teste_produs_animal_companie.h"
#include "teste_repo.h"
#include "teste_repo_file.h"
//#include "teste_service.h"
#include "ui.h"

void teste() {
    //TesteService test;
    //teste_animal_companie();
    teste_produs_animal_companie();
    teste_add_and_del_repo();
    teste_update_repo();
    teste_findElem_repo();
    teste_findByName_repo();
    teste_add_and_del_repo_file();
    teste_update_repo_file();
    teste_find_repo_file();
    //test.teste_service();
    std::cout << "testele au trecut cu succes!!" << std::endl;
}

int main()
{
    teste();
    RepoFile<AnimalCompanie> animal_repo("animale.txt");
    //RepoFile<Produs> produs_repo("produse.txt");
    AnimalService animal_service(animal_repo);
    //ProdusService produs_service(produs_repo);
    UI ui(animal_service);
    ui.show_ui();
    std::cout << "succes";
}
