/**
 * @author Lucas Moreira
 * @date 18/01/2018
 */
#include "main.hpp"
#include "textos.hpp"

using namespace std;

/**
* [main aplicação principal]
*/
int main() {
    int tam_texto;
    string texto, padrao_texto;

    // -------- Lendo os dados de entrada -----------
    cin >> tam_texto;
    cin.ignore();
    getline(cin, texto);
    getline(cin, padrao_texto);
    // ------------------------------------------------
    Search_word text(tam_texto, texto, padrao_texto);
    if(debug) text.print_datas();

    char input;
    while (cin >> input, input != 'e') {
        if (input == 's') {
            print "busca padrão" << '\n';
        }
        else { // input == 'u'
            print "impressão da tabela" << '\n';
        }

    }
    print "input: " << input << endl;
    return 0;
}
