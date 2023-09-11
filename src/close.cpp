#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void encryptFile(const fs::path& filePath, const string& key) {
    ifstream inputFile(filePath, ios::binary);
    ofstream encryptedFile(filePath.string() + ".encrypted", ios::binary);
    
    cout << "Locked " << filePath.filename().string() << "." << endl;
    
    char ch;
    size_t keyIndex = 0;

    while (inputFile.get(ch)) {
        ch ^= key[keyIndex];
        encryptedFile.put(ch);
        keyIndex = (keyIndex + 1) % key.length();
    }

    inputFile.close();
    encryptedFile.close();

    fs::remove(filePath); // Optional: Remove the original file after encryption
}

void encryptFolder(const fs::path& folderPath, const string& key) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (fs::is_directory(entry.path())) {
            encryptFolder(entry.path(), key); // Recursively encrypt subfolders
        } else {
            encryptFile(entry.path(), key); // Encrypt individual file
        }
    }
}

int main() {
    string folderPath = "C:\\The\\directory\\you\\want\\to\\encrypt";
    string encryptionKey = "yourCustomizedPassword";
    
	for (const auto& entry : fs::directory_iterator(folderPath)) {
        if(entry.path().string().ends_with(".encrypted")){
            cerr << "[Wrong operation] The files have already encrypted!\n";
            return -1;
        }
    }
    
	encryptFolder(folderPath, encryptionKey);

    cout << "Encryption completed successfully." << endl;

    return 0;
}
