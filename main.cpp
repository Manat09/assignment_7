#include "Text_Preprocessor.h"
#include <thread>
#include <fstream>

using namespace std;

int main() {
    Text_Preprocessor *text = new Text_Preprocessor("../Task_1.txt");

    text->preprocess_text();
    string word;
    cin>>word;
    cout << text->search_word(word);

    delete text;


    /*
     * ******************************************************************************************************
     * ******************************************************************************************************
     * ******************************************************************************************************
     */

    fstream cop;
    cop.open("../Task_2.txt");
    string strLine;
    float total = 0;
    int count = 0;
    vector<float>nums;

    while(getline(cop, strLine)) {
        count++;
        float cur = stof(strLine);
        nums.push_back(cur);
        total += cur;
    }

    float avg = total / (count*1.0);

    auto thread_one = [](const vector<float>&numbers, float average) {
        ofstream str("../Thread_1.txt");
        for(auto to : numbers){
            if(to > average){
                str << to_string(to) << "\n";
            }
        }
        str.close();
    };

    auto thread_two = [](const vector<float>&numbers, float average) {
        ofstream str("../Thread_2.txt");
        for(auto to : numbers){
            if(to < average){
                str << to_string(to) << "\n";
            }
        }
        str.close();
    };

    auto thread_three = [](const vector<float>&numbers, float average) {
        ofstream str("../example.txt");
        for(auto to : numbers){
            if(to < average){
                str << to_string(to) << "\n" << "HA";
            }
        }
        str.close();
    };

    thread th1(thread_one, nums, avg);
    thread th2(thread_two, nums, avg);
    thread th3(thread_three, nums, avg);

    th1.join();
    th2.join();
    th3.join();
}
