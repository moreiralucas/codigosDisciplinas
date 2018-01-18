/**
 * @author Lucas Moreira
 * @date 29/11/2017
 */

#include "main.hpp"

using namespace std;

/**
* [main aplicação principal]
*/
int main() {
    char type;
    std::cin >> type;
    if (type == 'd') {
        duplo::menu_hashing();
    }
    else if (type == 'l') {
        encad::menu_hashing();
    }
    return 0;
}

/**
 * [encad::menu_hashing Exibe as opções do menu do Método de Resolução de Colisão com Encadeamento]
 */
void encad::menu_hashing() {
    both::init_hashing(encad::PATH_FILE);
    bool execute = true;
    char option;
    int chave, media;
    Person pessoa;
    while (execute) {
        std::cin >> option;
        switch (option) {
            case 'i': // Insere
                std::cin >> pessoa.chave;
                std::cin.ignore();
                std::cin.getline(pessoa.nome, TAM_NOME);
                std::cin >> pessoa.idade;
                encad::insere(pessoa);
                break;
            case 'c': // Consulta
                std::cin >> chave;
                pessoa = encad::consulta(chave);
                if (pessoa.chave >= 0) {
                    std::cout << "chave: " << pessoa.chave << '\n';
                    std::cout << pessoa.nome << '\n';
                    std::cout << pessoa.idade << '\n';
                }
                else {
                    std::cout << "chave nao encontrada: " << chave << '\n';
                }
                break;
            case 'r': // Remove
                std::cin >> chave;
                encad::remove(chave);
                break;
            case 'p':
                encad::imprime();
                break; // Imprime
            case 'm':
                encad::media_acessos();
                break; // Media de acessos
            case 'e':
                execute = false;
                break; // Fim
        }
    }
}

/**
 * [duplo::menu_hashing Exibe as opções do menu de hashing duplo]
 */
void duplo::menu_hashing() {
    both::init_hashing(duplo::PATH_FILE);
    bool execute = true;
    char option;
    double media;
    int chave;
    Person pessoa;

    while (execute) {
        std::cin >> option;
        switch (option) {
            case 'i': // Insere
                std::cin >> pessoa.chave;
                std::cin.ignore();
                std::cin.getline(pessoa.nome, TAM_NOME);
                std::cin >> pessoa.idade;
                duplo::insere(pessoa);
                break;
            case 'c': // Consulta
                std::cin >> chave;
                pessoa = duplo::consulta(chave);
                if (pessoa.chave >= 0) {
                    std::cout << "chave: " << pessoa.chave << '\n';
                    std::cout << pessoa.nome << '\n';
                    std::cout << pessoa.idade << '\n';
                }
                else {
                    std::cout << "chave nao encontrada: " << chave << '\n';
                }
                break;
            case 'r': // Remove
                std::cin >> chave;
                duplo::remove(chave);
                break;
            case 'p':
                duplo::imprime();
                break; // Imprime
            case 'm':
                duplo::media_acessos();
                break; // Media de acessos
            case 'e':
                execute = false;
                break; // Fim
        }
    }
}
