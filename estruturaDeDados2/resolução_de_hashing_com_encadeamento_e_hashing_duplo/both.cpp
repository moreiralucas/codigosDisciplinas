#include "main.hpp"
/**
 * @author Lucas Moreira
 * @date 29/11/2017
 */

/**
 * [both::file_exists Verifica se o arquivo existe ou não]
 * @param  path_file [Caminho para o arquivo]
 * @return           [true caso exista e false caso não exista]
 */
bool both::file_exists(const std::string path_file) {
    std::ifstream myFile(path_file, std::ios_base::in);
    if (myFile.is_open()) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * [both::get_element Realiza a leitura de um elemento]
 * @param  position  [valor referente ao ponteiro de acesso ai elemento de interesse]
 * @param  path_file [Caminho para o arquivo binário que contem o elemento]
 * @return           [Dados contidos na posição acessada]
 */
Person both::get_element(int position, const std::string path_file) {
    Person pessoa;
    std::ifstream myFile(path_file, std::ios_base::in|std::ios_base::binary);
    if (myFile.is_open()) {
        myFile.seekg(position, std::ios_base::beg);
        myFile.read(reinterpret_cast<char *>(&pessoa), SIZE_PERSON); // Faço a leitura
    }
    return pessoa;
}

/**
 * [both::set_element Altera as informações de um determinado elemento]
 * @param pessoa    [Valor a ser escrita]
 * @param position  [Ponterio que indica a posição que deve ser alterada]
 * @param path_file [Caminho do arquivo binario]
 */
void both::set_element(Person pessoa, std::streampos position, const std::string path_file) {
    std::ofstream myFile(path_file, std::ios_base::binary|std::ios_base::in|std::ios_base::out);
    if (myFile.is_open()) {
        myFile.seekp(position, std::ofstream::beg); // Move o ponteiro - output
        myFile.write(reinterpret_cast<const char *>(&pessoa), SIZE_PERSON); // Faço a escrita
    }
}

/**
 * [both::init_hashing Iniciliza o hashing]
 * @param path_file [Caminho para o arquivo binario]
 */
void both::init_hashing(const std::string path_file) {
    if (!file_exists(path_file)) {
        std::ofstream myFile(path_file, std::ios_base::binary|std::ios_base::out|std::ios_base::app);
        Person onePerson;
        if (myFile.is_open()) {
            print "Inicializando arquivo binario: ";
            for (int i = 0; i < TAMANHO_ARQUIVO; i++) {
                print i << ' ';
                myFile.write(reinterpret_cast<const char *>(&onePerson), SIZE_PERSON);
            }
            print "\n";
        }
    }
}

/**
 * [both::insere Função para inserir o elemento no arquivo]
 * @param pessoa    [Estrutura com daods a serem gravados]
 * @param existente [Valor para decidir se o elemento já está armazenado ou não]
 * @param position  [Poisção no arquivo onde deverá ser alocado o elemento]
 * @param path_file [caminho para o arquivo binário]
 */
void both::insere(Person pessoa, bool existente, std::streampos position, const std::string path_file) {
    if (existente) {
        std::cout << "chave ja existente: " << pessoa.chave << '\n';
    }
    else {
        if(position != OVER) { // Verifica se tem espaço no arquivo
            both::set_element(pessoa, position, path_file);
        }
    }
}
