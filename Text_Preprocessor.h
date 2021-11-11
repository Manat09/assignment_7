#ifndef ASSIGNMENT_7_TEXT_PREPROCESSOR_H
#define ASSIGNMENT_7_TEXT_PREPROCESSOR_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Text_Preprocessor {
public:
    string file_name;
    ifstream cop;
    vector<string>processedData;

    Text_Preprocessor(const string &fileName);

    void preprocess_text();

    string search_word(const std::string &str);

    virtual ~Text_Preprocessor();
};

#endif //ASSIGNMENT_7_TEXT_PREPROCESSOR_H
