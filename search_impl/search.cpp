#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> 


class word {
private:
    std::string word_;
public:
    word(){}
    word(const std::string& oth):word_(oth){}
    ~word(){}
    std::string get_word() const {
        return word_;
    }
    void set_word(const std::string& oth) {
        word_ = oth;
    }
    void Normalise() {
    std::string word_cheker;
    std::ifstream file("words_alpha.txt");
    while(file >> word_cheker) {
        if(word_cheker !=  word_) {
            if(word_[word_.size()- 1] == 's'){
                word_.pop_back();
            }
        }
    }


}

};
class text {
private:
    std::vector<word> lines;
public:
    text(){}
    text(const std::vector<word>& other):lines(other) {}
    ~text(){}

    void create(const std::string& FILE_NAME) {
        std::ifstream file(FILE_NAME.c_str());
    
        if (file.is_open()) {
            std::string line;
            while (file >> line) {
                lines.push_back(line);
            }
            file.close();
        }   
        else {
            std::cout << "Unable to open file: " << "lorem.txt" << std::endl;
        }
    }

    void text_normalise() {
        for(auto& it : lines){
            it.Normalise();
        }
    }

    void word_isalpha() {
    for (auto& word : lines) {
        std::string cleanedWord;
        for (auto c : word.get_word()) {
            if (std::isalpha(c)) {                
                cleanedWord += std::tolower(c);
            }   
        }
        if(!cleanedWord.empty())
            word.set_word (cleanedWord);
        }
    }
    void print() {
        for(auto& it: lines) {
            std::cout<<it.get_word() << " ";

        }
        std::cout<<std::endl;
    }

    
};  

void Normalise(std::string&);
void foo( std::vector<std::string>& lines, const std::string& FILE_NAME) {
    std::ifstream file(FILE_NAME.c_str());
    
    if (file.is_open()) {
        std::string line;
        while (file >> line) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cout << "Unable to open file: " << "lorem.txt" << std::endl;
    }
}




void text_normalise(std::vector<std::string>& lines) {
    for(auto& it : lines){
        Normalise(it);
    }
}

void Normalise(std::string& word) {
    std::string word_cheker;
    std::ifstream file("words_alpha.txt");

    while(file >> word_cheker) {
        if(word_cheker !=  word) {
            if(word[word.size()- 1] == 's'){
                word.pop_back();
            }
        }
    }


}

void word_isalpha(std::vector<std::string>& lines) {
    for (std::string& word : lines) {
        std::string cleanedWord;
        for (char c : word) {
            if (std::isalpha(c)) {                
                cleanedWord += std::tolower(c);
            }   
        }
        if(!cleanedWord.empty())
        word = cleanedWord;
    }
}
std::string find_word(const std::string& word,std::ifstream& in) {
    std::string file_line;
    while(std::getline(in,file_line)) {
        std::string key_word;
        std::string file_name;
        int index = 0;
        for(; index < file_line.size(); ++index) {
            if(file_line[index] != ':' ) {
                key_word.push_back(file_line[index]);
            }
            else {
                index++;
                break;
            }
        }        
        for(;index < file_line.size(); ++index) {
            file_name.push_back(file_line[index]);
        }
        if(word == key_word) {
                    
            return file_name;
        }
    }
    std::cout<<"word not found ";
    return "";
}
void same_word(std::ofstream& of) {
    std::string file1 = "1.txt";
    std::string file2 = "2.txt";
    std::ifstream file_1(file1.c_str());
    std::ifstream file_2(file2.c_str());
    std::vector<std::string> lines1;
    std::vector<std::string> lines2;
    foo(lines1,file1);
    foo(lines2,file2);
    word_isalpha(lines1);
    text_normalise(lines1);
    word_isalpha(lines2);
    text_normalise(lines2);
    for(auto& it: lines1) {
        of << it  << ": " << file1 << " ";
        if(std::find(lines2.begin(),lines2.end(),it) != lines2.end()) {
            of << file2 << " "; 
        }
        of << std::endl;
    }
    for(auto& it: lines2) {
        if(std::find(lines1.begin(),lines1.end(),it) == lines1.end()) {
            of << it << ": " << file2 ; 
        }
        of << std::endl;
    } 
}


int main () {
    std::ofstream of("db.txt");
    std::vector<word> lines;
    text obj(lines);
    obj.create("lorem.txt");
    obj.word_isalpha();
    obj.text_normalise();
    same_word(of);
    of.close();
    std::string usr_input;
    std::cout << "input word -> ";
    std::cin>>usr_input;
    std::ifstream in("db.txt");
    std::cout<<find_word(usr_input,in);
}
