#include "main.hpp"
/**
 * @author Lucas Moreira
 * @date 29/11/2017
 */

/**
* [duplo::insere Função responsável para inserção de registro do tipo "duplo"]
* @param pessoa [Dados do registro a ser inserido]
*/
void duplo::insere(Person pessoa) {
    std::streampos position_hashing;
    Person tmp = duplo::consulta(pessoa.chave, position_hashing);
    if (tmp.chave >= 0) { // A chave a ser inserida já existe
        both::insere(pessoa, true, position_hashing, duplo::PATH_FILE);
    }
    else {
        position_hashing = duplo::h1(pessoa.chave);
        tmp = both::get_element(position_hashing, duplo::PATH_FILE);
        std::streampos size_table = TAMANHO_ARQUIVO * SIZE_PERSON;
        std::streampos key = duplo::h2(pessoa.chave);

        while (tmp.chave != EMPTY && tmp.chave != REMOVED) {
            position_hashing = (std::streampos)(position_hashing + key) % size_table; // Calcula a posicao do ponteiro
            tmp = both::get_element(position_hashing, duplo::PATH_FILE);
        }
        both::insere(pessoa, false, position_hashing, duplo::PATH_FILE);
    }
}

/**
 * [duplo::consulta Função responsável para solicitar uma consulta de um registro do tipo "duplo"]
 * @param  chave [valor da chave a ser pesquisada]
 * @return       [Uma strutura do tipo Person]
 */
Person duplo::consulta(const int chave, std::streampos & position_hashing) {
    int acessos;
    return duplo::consulta_e_acessos(chave, acessos, position_hashing);
}

/**
 * [duplo::consulta Função responsável para solicitar uma consulta de um registro do tipo "duplo"]
 * @param  chave [valor da chave a ser pesquisada]
 * @return       [Uma strutura do tipo Person]
 */
Person duplo::consulta(const int chave) {
    std::streampos position_hashing;
    int acessos;
    return duplo::consulta_e_acessos(chave, acessos, position_hashing);
}

/**
 * [duplo::consulta_e_acessos Essa função pesquisa por um elemento e Calcula o custo de aceso]
 * @param  chave         [Valor da chave]
 * @param  total_acessos [description]
 * @return               [description]
 */
Person duplo::consulta_e_acessos(const int chave, int & total_acessos, std::streampos & position_hashing) {
    position_hashing = duplo::h1(chave); // Retorna a posição do registro no arquivo
    Person pessoa = both::get_element(position_hashing, duplo::PATH_FILE);

    std::streampos size_table = TAMANHO_ARQUIVO * SIZE_PERSON;
    std::streampos key = duplo::h2(chave);

    total_acessos = 1;
    int count = TAMANHO_ARQUIVO;
    while (chave != pessoa.chave && pessoa.chave != EMPTY && (count--) > 0) {
        total_acessos++;
        position_hashing = (std::streampos)(position_hashing + key) % size_table; // Calcula a posicao do ponteiro
        pessoa = both::get_element(position_hashing, duplo::PATH_FILE);
    }
    if (count <= 0) { // Varreu todas as posicoes e nao foi encontrado
        pessoa.chave = OVER;
        position_hashing = OVER;
    }
    return pessoa;
}

/**
 * [duplo::remove description]
 * @param chave [description]
 */
void duplo::remove(int chave) {
    std::streampos position_hashing;
    Person pessoa = duplo::consulta(chave, position_hashing);
    if (pessoa.chave < 0) { // valores EMPTY e REMOVED
        std::cout << "chave nao encontrada: " << chave << '\n';
    }
    else {
        pessoa.chave = REMOVED;
        both::set_element(pessoa, position_hashing, duplo::PATH_FILE);
    }
}

/**
 * [duplo::imprime Imprime as informações de todos os registros armazenado no arquivo]
 */
void duplo::imprime() {
    std::ifstream myFile(duplo::PATH_FILE, std::ios_base::in|std::ios_base::binary);
    if (myFile.is_open()) {
        Person pessoa;
        myFile.seekg(0, std::ios_base::beg);
        for (int i = 0; i < TAMANHO_ARQUIVO; i++) {
            myFile.read(reinterpret_cast<char *>(&pessoa), SIZE_PERSON); // Faço a leitura
            std::cout << i << ": ";
            if (pessoa.chave >= 0) {
                 std::cout << pessoa.chave << ' ' << pessoa.nome << ' ' << pessoa.idade << '\n';
            }
            else {
                std::cout << "vazio\n";
            }
        }
    }
}

/**
 * [duplo::media_acessos Calcula a média de acesso de cada arquivo contido no arquivo]
 * @return [Retorna o valor da média de acessos do arquivo]
 */
void duplo::media_acessos() {
    int acumulador = 0, tam = 0;
    Person pessoa;
    std::streampos position_hashing;
    for (int i = 0; i < TAMANHO_ARQUIVO; i++) {
        int total_acessos = 1;
        pessoa = both::get_element(i * SIZE_PERSON, duplo::PATH_FILE);
        if (pessoa.chave >= 0) {
            duplo::consulta_e_acessos(pessoa.chave, total_acessos, position_hashing);
            acumulador+= total_acessos;
            tam++;
        }
    }
    std::cout << std::fixed << std::setprecision(1) << (acumulador?(acumulador*1.0/tam):0.0) << '\n';
}

/**
 * [duplo::h1 Calcula o valor de h1 conforme consta na descrição da proposta do trabalho]
 * @param  chave [Valor a ser calculado]
 * @return       [Resultado da função h1]
 */
int duplo::h1(const int chave) {
    return (chave % TAMANHO_ARQUIVO) * SIZE_PERSON;
}

/**
 * [duplo::h2 Calcula o valor de h2 conforme consta na descrição da proposta do trabalho]
 * @param  chave [Valor a ser calculado]
 * @return       [Resultado da função h2]
 */
int duplo::h2(const int chave) {
    int ans = (chave/TAMANHO_ARQUIVO) % TAMANHO_ARQUIVO;
    ans = ans * SIZE_PERSON;
    return (ans)?ans:SIZE_PERSON;
}
