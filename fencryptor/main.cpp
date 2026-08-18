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
//TODO utf8 support
std::string readFromFile(std::string fileLoc) {
    std::string lineContentStr;
    std::ifstream MyReadFile(fileLoc);
    std::string encText; //encrypted text

    while (getline(MyReadFile, lineContentStr)) {
        if (!lineContentStr.empty()) {
            for (int i = 0; i < lineContentStr.size() - 1; i++) {

                if (lineContentStr[i] == ' ') {
                    encText += ' ';
                }
                else {
                    encText += encryptChar(lineContentStr[i]);
                }

                //end line
                if (lineContentStr[i] == lineContentStr.size() - 1) {
                    encText += '\n';
                }
            }
        }
        else {
            encText += '\n';
        }
        
    }
    return encText;
}

bool writeToFile() {

    return false;
}

int main(int argc, char* argv[]) {
    //file reading
    std::string fileLocation;
    std::cout << "dosya konumunu girin: ";
    std::cin >> fileLocation;

    std::string encFileContent = readFromFile(fileLocation);
    //------------------------------------
    std::cout << '\n' << encFileContent << std::endl;
    //std::string encryptedFileContent;
    //encryptedFileContent = encryptText(fileContent);
    ///*for (int i = 0;i < fileContent.length() - 1;i++) {
    //    encryptedFileContent += encryptChar(fileContent[i]);
    //}*/
    //std::cout <<"\n"<< encryptedFileContent << std::endl;

    std::cin.get();

    //TODO write to new file

    return 0;
}