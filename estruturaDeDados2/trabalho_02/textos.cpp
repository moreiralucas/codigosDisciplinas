#include "textos.hpp"

/**
 * [Search_word::Search_word Classe principal do projeto de busca em texto através de uma algoritmo de automato]
 * @param size    [Tamanho do texto]
 * @param text    [Texto a ser utilizado]
 * @param pattern [Padrão a ser procurado no texto]
 */
Search_word::Search_word(const int size, const std::string& text, const std::string& pattern){
    // Atribuição dos valores passados na entrada
    this->text = text;
    this->pattern = pattern;
    this->size = size;
    // Construção do alfabeto
    for (char caracter = 97; caracter < 123; caracter++) {
        alphabet.push_back(caracter);
    }
    alphabet.push_back('.');
    alphabet.push_back(',');
    alphabet.push_back(' ');
}

/**
 * [Search_word::caracter_to_int Altera valor de um caracter para um inteiro, de acordo com o alfabeto da classe principal]
 * @param  c [Caracter a ser alterado]
 * @return   [Valor inteiro correspondente ao caracter dado na entrada]
 */
int Search_word::caracter_to_int(char c) {
    int ans;
    switch (c) {
        case 46: ans = 26; // Ponto
            break;
        case 44: ans = 27; // Vírgula
            break;
        case 32: ans = 28; // Espaço
            break;
        default:
            ans = c - 97;
    }
    return ans;
}

/**
 * [Search_word::compute_table Calcula os valores da tabela Delta, conforme algoritmo do livro do Cormen]
 */
void Search_word::compute_table() {
    const int m = pattern.size();
    const int n = alphabet.size();
    for (int q = 0; q <= m; q++) {
        for (int i = 0; i < n; i++) {
            int k = std::min(m+1,q+2);
            do {
                k--;
            } while(Search_word::is_not_suffix(k, q, alphabet[i]));
            Search_word::set_delta(i, k);
        }
    }
}

/**
 * [Search_word::get_delta Pega valor na tabela Delta previamente calculado]
 * @param  estado   [Estado do autômato referente ao padrão da Classe principal]
 * @param  caracter [Caracter aceito (ou não) pelo automato]
 * @return          [Estado seguinte para onde o autômato segue, tendo como entrada o estado e o caracter]
 */
int Search_word::get_delta(int estado, int caracter) {
    return table[caracter][estado];
}

/**
 * [Search_word::int_to_caracter Altera valor de um inteiro para um caracter, de acordo com o alfabeto da classe principal]
 * @param  i [Inteiro a ser alterado]
 * @return   [Caracter correspondente ao valor inteiro dado na entrada]
 */
char Search_word::int_to_caracter(int i) {
    char c;
    switch (i) {
        case 26: c = 46; // Ponto
            break;
        case 27: c = 44; // Vírgula
            break;
        case 28: c = 32; // Espaço
            break;
        default:
            c = i + 97;
    }
    return c;
}

/**
 * [Search_word::is_not_suffix Função responsável para verificar se dada dois Strings, uma é sufixo da outra]
 * @param  k [description]
 * @param  q [description]
 * @param  c [description]
 * @return   [Valor booleano indicando se os strings são sufixos um do outro ou não]
 */
bool Search_word::is_not_suffix(const int k, const int q, const char c) {
    if (k > 0 && pattern[k - 1] != c) {
        return true;
    }
    if (k >= 2) {
        for (int i = k - 2, j = q - 1; i >= 0; i--, j--)
            if (pattern[i] != pattern[j]) {
                return true;
        }
    }
    return false;
}

/**
 * [Search_word::print_table Imprime valores da Tabela Delta]
 */
void Search_word::print_table() {
    const int qtd_caracteres = this->alphabet.size();
    const int qtd_estados = this->pattern.size() + 1;
    char c;

    std::cout << "Tabela Delta:" << std::endl;
    for (int estado = 0; estado < qtd_estados; estado++) {
        for (int caracter = 0; caracter < qtd_caracteres; caracter++) {
            int delta = Search_word::get_delta(estado, caracter);
            if (delta != 0) {
                c = Search_word::int_to_caracter(caracter);
                std::cout << "[" << estado << ", ";
                if (c == 32) // Em caso do valor ser "zero"
                     std::cout << "' '";
                else
                    std::cout << c;
                std::cout << "]: " << delta << std::endl;
            }
        }
    }
}

/**
 * [Search_word::search_pattern Esta operação indica a partir de quais posições do texto o padrão ocorre.]
 */
void Search_word::search_pattern() {
    const int n = this->size; // Tamanho do texto
    const int m = this->pattern.size(); // Tamanho do padrão
    int c_int, q = 0;

    for (int i = 0; i < n; i++) {
        c_int = Search_word::caracter_to_int(text[i]);
        q = Search_word::get_delta(q, c_int);
        if (q == m)
            std::cout << i - m + 2 << std::endl;
    }
}

/**
 * [Search_word::set_delta Atribui o valor na tabela Delta previamente calculado]
 * @param caracter [Caracter aceito (ou não) pelo automato]
 * @param valor    [Estado seguinte para onde o autômato segue, tendo como entrada o caracter]
 */
void Search_word::set_delta(int caracter, int valor) {
    this->table[caracter].push_back(valor);
}
