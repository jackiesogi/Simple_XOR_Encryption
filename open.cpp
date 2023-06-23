#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void decryptFile(const fs::path& filePath, const string& key) {
    ifstream encryptedFile(filePath, ios::binary);
    
    string decryptedFileName = filePath.filename().string();
    decryptedFileName = decryptedFileName.substr(0, decryptedFileName.find_last_of('.'));
    ofstream decryptedFile(decryptedFileName, ios::binary);

    char ch;
    size_t keyIndex = 0;

    while (encryptedFile.get(ch)) {
        ch ^= key[keyIndex];
        decryptedFile.put(ch);
        keyIndex = (keyIndex + 1) % key.length();
    }
    
    cout << "Restored " << decryptedFileName << ".\n";

    encryptedFile.close();
    decryptedFile.close();

    fs::remove(filePath); // Optional: Remove the encrypted file after decryption
}

void decryptFolder(const fs::path& folderPath, const string& key) {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (fs::is_directory(entry.path())) {
            decryptFolder(entry.path(), key); // Recursively decrypt subfolders
        } else {
            decryptFile(entry.path(), key); // Decrypt individual file
        }
    }
}

int main() {
    
	string folderPath = "C:\\The\\directory\\you\\want\\to\\encrypt";
    string encryptionKey = "yourCustomizedPassword";
    
	for (const auto& entry : fs::directory_iterator(folderPath)) {
        if(!entry.path().string().ends_with(".encrypted")){
            cerr << "[Wrong operation] The files have already decrypted!\n";
            return -1;
        }
    }
    
	string d;
    cout << "Enter the decryption key: ";
	cin >> d;
	
	if(d == encryptionKey){
		decryptFolder(folderPath, encryptionKey);
		cout << "Decryption completed successfully." << endl;
	}
	else{
		cout << "Wrong Key!!!\n";
	}

    return 0;
}

