#include "main.hpp"
/**
 * @author Lucas Moreira
 * @date 29/11/2017
 */

/**
 * [encad::altera_apontador altera o Ponterio]
 * @param position_hashing [Posição do elemento que recbe a modificação]
 * @param apontador        [Posição para o próximo elemento]
 */
void encad::altera_apontador(std::streampos position_hashing, std::streampos apontador) {
    Person pessoa = both::get_element(position_hashing, encad::PATH_FILE);
    pessoa.next = apontador;
    both::set_element(pessoa, position_hashing, encad::PATH_FILE);
}

/**
 * [encad::find_free_position Encontra o último espaço em disponível no arquivo]
 * @return [Valor do apontador para a posição encontrada]
 */
int encad::find_free_position() {
    Person pessoa;
    std::streampos position_hashing;
    int count = TAMANHO_ARQUIVO;
    std::ifstream myFile(encad::PATH_FILE, std::ios::in|std::ios::binary);
    if (myFile.is_open()) {
         do {
            position_hashing = --count * SIZE_PERSON;
            myFile.seekg (position_hashing, std::ios_base::beg);
            myFile.read(reinterpret_cast<char *>(&pessoa), SIZE_PERSON);
        } while (pessoa.chave != EMPTY && count > 0);
    }
    return (position_hashing >= 0)?((int)position_hashing):OVER;
}

/**
 * [encad::find_previous Encontra a posição para o qual ele é apontado]
 * @param  position_hashing [Posição do elemento no qual é procurado o anterior dele]
 * @param  chave            [Chave do elemento em questão]
 * @return                  [Valor do apontador para a posição encontrada]
 */
int encad::find_previous(std::streampos position_hashing, const int chave) {
    Person pessoa;
    int count = 0, chave_anterior, p1 = position_hashing, p2 = position_hashing;
    std::ifstream myFile(encad::PATH_FILE, std::ios::in|std::ios::binary);
    if (myFile.is_open()) {
        do {
            ++count;
            if(count%2 == 0)
                p1 = position_hashing;
            else
                p2 = position_hashing;
            myFile.seekg (position_hashing, std::ios_base::beg);
            myFile.read(reinterpret_cast<char *>(&pessoa), SIZE_PERSON);
            position_hashing = pessoa.next;
        } while (pessoa.chave != chave && pessoa.next != EMPTY);
    }
    if(count % 2 == 0) chave_anterior = p2;
    else chave_anterior = p1;
    return chave_anterior;
}

/**
* [encad::insere Função responsável para inserção de registro do tipo "Resolução por encadeamento"]
* @param pessoa [Dados do registro a ser inserido]
*/
void encad::insere(Person pessoa) {
    std::streampos position_hashing, new_position;
    Person pessoa_tmp = encad::consulta(pessoa.chave, position_hashing);
    if (pessoa_tmp.chave < 0) {
        position_hashing = encad::h1(pessoa.chave);
        pessoa_tmp = both::get_element(position_hashing, encad::PATH_FILE);
        if(pessoa_tmp.chave < 0) {
            // Quando a posição está vazia, é chamado a função de inserção
            both::insere(pessoa, false, position_hashing, encad::PATH_FILE);
        }
        else{
            // Quando a posição está ocupada, é feito os ajustes
            int key = encad::h1(pessoa_tmp.chave);
            if ((key != position_hashing)) {
                // Realiza a consulta da pessoa e retorna na variavel pessoa_tmp
                int previous_pointer = encad::find_previous(key, pessoa_tmp.chave);
                std::streampos pos = encad::find_free_position(); // encontra nova posição vazia na tabela
                // Altera o apontador do elemento anterior
                encad::altera_apontador(previous_pointer, pos);

                // Altera os elementos de posições
                both::insere(pessoa_tmp, false, pos, encad::PATH_FILE);
                both::insere(pessoa, false, position_hashing, encad::PATH_FILE);
            }
            else {
                int previous_pointer = encad::find_previous(position_hashing, pessoa.chave);
                position_hashing = encad::find_free_position(); // encontra nova posição vazia na tabela

                pessoa_tmp = both::get_element(previous_pointer, encad::PATH_FILE);
                if (pessoa_tmp.next == EMPTY) {
                    encad::altera_apontador(previous_pointer, position_hashing);
                }
                else {
                    encad::altera_apontador(pessoa_tmp.next, position_hashing);
                }
                both::insere(pessoa, false, position_hashing, encad::PATH_FILE);
            }
        }
    }
    else {
        both::insere(pessoa, (pessoa.chave >= 0), position_hashing, encad::PATH_FILE);
    }
}

/**
 * [encad::consulta Função responsável para solicitar uma consulta de um registro do tipo "duplo"]
 * @param  chave [valor da chave a ser pesquisada]
 * @return       [Uma strutura do tipo Person]
 */
 Person encad::consulta(const int chave) {
     int acessos;
     std::streampos position_hashing;
     return encad::consulta_e_acessos(chave, acessos, position_hashing);
 }

/**
 * [encad::consulta Função responsável para solicitar uma consulta de um registro do tipo "duplo"]
 * @param  chave [valor da chave a ser pesquisada]
 * @param  position_hashing [Valor do apontador do elemento encontrado]
 * @return       [Uma strutura do tipo Person]
 */
Person encad::consulta(const int chave, std::streampos & position_hashing) {
    int acessos;
    return encad::consulta_e_acessos(chave, acessos, position_hashing);
}

/**
 * [encad::consulta Função responsável para solicitar uma consulta de um registro do tipo "duplo"]
 * @param  chave [valor da chave a ser pesquisada]
 * @param  position_hashing [Valor do apontador do elemento encontrado]
 * @param  total_acessos [Valor total de acessos até encontrar o valor pesquisado]
 * @return       [Uma strutura do tipo Person]

 */
Person encad::consulta_e_acessos(const int chave, int & total_acessos, std::streampos & position_hashing) {
    position_hashing = encad::h1(chave); // Calcula a posição com o h1
    Person pessoa = both::get_element(position_hashing, encad::PATH_FILE); // Verifica se na posicao ja tem algum elemento
    total_acessos = 1;
    if (pessoa.chave != EMPTY) { // primeira posicao consultada estava ocupada estava
        int count = TAMANHO_ARQUIVO;

        std::ifstream myFile(encad::PATH_FILE, std::ios::in|std::ios::binary);
        if (myFile.is_open()) {
            //  Procura a próxima posição vazia através desse loop
            while (pessoa.chave != chave && pessoa.next != EMPTY && count > 0) {
                position_hashing = pessoa.next;
                myFile.seekg (position_hashing, std::ios_base::beg);
                myFile.read(reinterpret_cast<char *>(&pessoa), SIZE_PERSON);
                total_acessos++;
                --count;
            }
            if(pessoa.chave != chave){
                pessoa.chave = EMPTY;
            }
        }
        if (count <= 0) { // Varreu todas as posicoes e nao foi encontrado
            position_hashing = OVER;
            pessoa.chave = OVER;
        }
    }
    return pessoa;
}

/**
 * [encad::remove Função responsável para remover um determinado elemento]
 * @param chave [Chave do elemento a ser removido]
 */
void encad::remove(int chave) {
    std::streampos position_hashing;
    Person pessoa = encad::consulta(chave, position_hashing);
    if (pessoa.chave < 0) { // valores EMPTY e REMOVED
        std::cout << "chave nao encontrada: " << chave << '\n';
    }
    else {
        int key = encad::h1(chave);
        if(key == position_hashing) {
            if (pessoa.next != EMPTY) { // o next aponta para algum elemento
                std::fstream myFile(encad::PATH_FILE, std::ios_base::binary|std::ios_base::in|std::ios_base::out);
                if (myFile.is_open()) {
                    // Leio os dados da posição original
                    std::streampos next = pessoa.next;
                    myFile.seekg (next, std::ios_base::beg);
                    myFile.read(reinterpret_cast<char *>(&pessoa), SIZE_PERSON);

                    myFile.seekp (key, std::ios_base::beg);
                    myFile.write(reinterpret_cast<char *>(&pessoa), SIZE_PERSON); // Faço a escrita

                    Person pessoa_null;
                    myFile.seekp (next, std::ios_base::beg);
                    myFile.write(reinterpret_cast<char *>(&pessoa_null), SIZE_PERSON); // Faço a escrita
                }
            }
            else { // É primário e único
                encad::apague(key);
            }
        }
        else {
            std::streampos position = encad::find_previous(key, chave);
            encad::altera_apontador(position, pessoa.next);
            encad::apague(position_hashing);
        }
    }
}

/**
 * [encad::apague Remove o elemento da posição dada]
 * @param position [Ponteiro ]
 */
void encad::apague(std::streampos position) {
    std::fstream myFile(encad::PATH_FILE, std::ios_base::binary|std::ios_base::in|std::ios_base::out);
    Person pessoa;
    if (myFile.is_open()) {
        myFile.seekp(position, std::ios_base::beg); // Move o ponteiro - output
        myFile.write(reinterpret_cast<char *>(&pessoa), SIZE_PERSON); // Faço a escrita
    }
}

/**
 * [encad::imprime Imprime as informações de todos os registros armazenado no arquivo]
 */
void encad::imprime() {
    std::ifstream myFile(encad::PATH_FILE, std::ios_base::in|std::ios_base::binary);
    if (myFile.is_open()) {
        Person pessoa;
        for (int i = 0; i < TAMANHO_ARQUIVO; i++) {
            myFile.read(reinterpret_cast<char *>(&pessoa), SIZE_PERSON); // Faço a leitura
            std::cout << i << ": ";
            if (pessoa.chave >= 0) {
                 std::cout << pessoa.chave << ' ' << pessoa.nome << ' ' << pessoa.idade << ' ' << ((pessoa.next >= 0)?std::to_string(pessoa.next/SIZE_PERSON):"nulo") << '\n';
            }
            else {
                std::cout << "vazio\n";
            }
        }
    }
}

/**
 * [encad::media_acessos Calcula a média de acesso de cada arquivo contido no arquivo]
 * @return [Retorna o valor da média de acessos do arquivo]
 */
void encad::media_acessos() {
    int acumulador = 0, total=0;
    std::streampos position_hashing;
    // Para cada elemento do arquivo, é feito uma busca calculando sua média de acesso
    for (int i = 0; i < TAMANHO_ARQUIVO; i++) {
        int total_acessos = 1;
        Person pessoa;
        pessoa = both::get_element(i * SIZE_PERSON, encad::PATH_FILE);
        if (pessoa.chave >= 0) {
            pessoa = encad::consulta_e_acessos(pessoa.chave, total_acessos, position_hashing);
            acumulador+= total_acessos;
            total++;
        }
    }
    std::cout << std::fixed << std::setprecision(1) << (acumulador?(double)acumulador/total:0.0) << '\n';
}

/**
 * [duplo::h1 Calcula o valor de h1 conforme consta na descrição da proposta do trabalho]
 * @param  chave [Valor a ser calculado]
 * @return       [Resultado da função h1]
 */
int encad::h1(const int chave) {
    return (chave % TAMANHO_ARQUIVO) * SIZE_PERSON;
}
