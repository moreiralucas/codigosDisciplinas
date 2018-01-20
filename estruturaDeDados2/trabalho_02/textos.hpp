#include <vector>
#include <string>

class Search_word {
        std::string text;
        std::string pattern;
        int size;
        void compute_table();
    public:
        Search_word(int size, std::string text, std::string pattern);
        std::vector<std::vector<int> > table;
        void print_datas();
        void search_pattern();

};
