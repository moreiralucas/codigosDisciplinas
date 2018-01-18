/**
 * @author Lucas Moreira
 * @date 29/11/2017
 */
#include <iostream>
#include <fstream>
#include <iomanip>

// -------------------------------------------
// Trecho utilizado somente para desenvolvimento
#define debug false

#ifndef print
#define print if(debug)std::cout <<
#endif
// -------------------------------------------

// Constantes definidas para serem utilizdas durante a execução do algoritmo
const unsigned int TAMANHO_ARQUIVO = 11;
const unsigned int TAM_NOME = 21;
const int EMPTY = -1;
const int OVER = -2;
const int REMOVED = -3;

struct Person {
    int next = EMPTY; // Guarda ponteiro para o próximo elemento
    int chave = EMPTY;
    char nome[TAM_NOME];
    unsigned int idade = 0;
};

const unsigned int SIZE_PERSON = sizeof(Person);

namespace duplo {
    const std::string PATH_FILE = "double.dat";
    void media_acessos();
    int h1(const int chave);
    int h2(const int chave);
    void menu_hashing();
    void insere(Person pessoa);
    void imprime();
    void remove(int chave);
    Person consulta(const int chave);
    Person consulta(const int chave, std::streampos & position_hashing);
    Person consulta_e_acessos(const int chave, int & total_acessos, std::streampos & position_hashing);
}

namespace encad {
    const std::string PATH_FILE = "encad.dat";
    void media_acessos();
    int find_free_position();
    int find_previous(std::streampos position_hashing, const int chave);
    int h1(const int chave);
    void altera_apontador(std::streampos position_hashing, std::streampos apontador);
    void apague(std::streampos position);
    void imprime();
    void insere(Person pessoa);
    void menu_hashing();
    void remove(int chave);
    Person consulta(const int chave);
    Person consulta(const int chave, std::streampos & position_hashing);
    Person consulta_e_acessos(const int chave, int & total_acessos, std::streampos & position_hashing);
}

namespace both {
    bool file_exists(const std::string pathFile);
    void init_hashing(const std::string path_file);
    void insere(Person pessoa, bool existente, std::streampos position, const std::string path_file);
    void set_element(Person pessoa, std::streampos position, const std::string path_file);
    Person get_element(int position, const std::string path_file);
}
