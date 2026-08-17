#include <iostream>
#include <cctype>
#include <fstream>
#include <string>

char alphabet[29] = {
        'A', 'B', 'C', 'Ç', 'D', 'E', 'F', 'G', 'Ğ', 'H',
        'I', 'İ', 'J', 'K', 'L', 'M', 'N', 'O', 'Ö', 'P',
        'R', 'S', 'Ş', 'T', 'U', 'Ü', 'V', 'Y', 'Z'
};

char encryptChar(char charParam) {
    char resultChar;
    for (int i = 0;i < 29;i++) {
        if (toupper(charParam) == alphabet[i]) {
            if (i == 0) {
                resultChar = alphabet[1];
            }
            else if (i == 28) {
                resultChar = alphabet[27];
            }
            else {
                resultChar = alphabet[i + 1];
            }
            return resultChar;
        }
    }
}

std::string encryptText(std::string value) {
    std::string result = "";

    for (int i = 0;i < value[-1];i++) {
        if (value[i] != ' ') {
            result += encryptChar(value[i]);
        }
        else {
            result += ' ';
        }
    }
    return result;
}

std::string readFromFile(std::string fileLoc) {
    std::string result;
    std::string fileContentStr;
    std::ifstream MyReadFile(fileLoc);

    while (getline(MyReadFile, fileContentStr)) {
        std::cout << fileContentStr + "\n";
    }

    return "false";
}

bool writeToFile() {
    return false;
}

int main(int argc, char* argv[]) {
    //file reading
    std::string fileLocation;
    std::cout << "dosya konumunu girin: ";
    std::cin >> fileLocation;
    readFromFile(fileLocation);
    //------------------------------------

    //TODO encrypt file content and write to new file

    return 0;
}