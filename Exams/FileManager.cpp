//
// Created by giuli on 04/12/2020.
//
#include "FileManager.h"

typedef std::vector<std::string> row_type;
typedef std::vector<row_type> table_type;

const table_type& FileManager::parse_file (const std::string& filename, char d){
    fields.clear();
    std::ifstream data {filename};
    std::string line;
    while(std::getline(data,line)){
    row_type temp;
    std::istringstream record(line);
    std::string word;
    while (std::getline(record, word, d)){
    temp.push_back(word);
    }
    fields.emplace_back(temp);
    }
const table_type& ret =fields;
return ret;
}









