#include <iostream>
#include <string>
#include <fstream>



bool BitcoinExchange(std::ifstream &file) {
    
    std::string data;

    while(std::getline(file, data)) {
        // 日付のチェック
        // check_date();
        // // 数値のチェック
        // check_value();
    }
    return true;
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "please input value" << std::endl;
    }
    std::ifstream file("data.csv");
    try {
        BitcoinExchange(file);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}