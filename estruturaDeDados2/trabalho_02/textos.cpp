#include "textos.hpp"
#include "main.hpp"
#include <iostream>

Search_word::Search_word(int size, std::string text, std::string pattern){
    this->text = text;
    this->pattern = pattern;
    this->size = size;
}

void Search_word::print_datas() {
    print "Text: " << this->text << '\n';
    print "Pattern: " << this->pattern << '\n';
    print "Size: " << this->size << '\n';
}
void Search_word::search_pattern() {
    // TODO: Implement you code here
}

void Search_word::compute_table() {
    // TODO: Implement you code here
}
