#include <iostream>
#include <fstream>
#include <vector>

struct Colors {
    const std::string RED = "\033[0;31m";
    const std::string GREEN = "\033[1;32m";
    const std::string YELLOW = "\033[1;33m";
    const std::string CYAN = "\033[0;36m";
    const std::string MAGNETA = "\033[0;35m";
    const std::string RESET = "\033[0m";
};

int fileSizeOf(std::string& f) {
    std::ifstream file(f, std::ios::binary);
    file.seekg(0, std::ios::end);
    const int SIZE = file.tellg(); // Returns in bytes

    return SIZE;
}

bool isFileSizeEqual(std::string& fileA, std::string& fileB) {
    return ((fileSizeOf(fileA) == fileSizeOf(fileB))) ? true : false;
}

bool isEqualLineByLine(std::string& fileA, std::string& fileB) {
    std::ifstream r_MainFile(fileA);
    std::ifstream r_SyncFile(fileB);
    std::string mainFile, syncFile;

    // Get through each line and check if they are the same
    while (getline(r_MainFile, mainFile) && getline(r_SyncFile, syncFile)) {
        return (mainFile == syncFile) ? true : false;
    }
    return false;
}

void syncFiles(std::string& fileA, std::string& fileB) {
    Colors color;

    std::cout << color.RED << fileB + " File is Outdated! Updating...\n" << color.RESET;

    std::ifstream r_MainFile(fileA);
    std::ofstream w_SyncFile(fileB);

    std::string line;

    // Store each line into a vector to be written to remotefile
    std::vector<std::string> lines;
    while (getline(r_MainFile, line)) { lines.push_back(line); }
    
    for (size_t i = 0; i < lines.size(); i++) {
        std::string nline = (i == lines.size()-1) ? "" : "\n";
        w_SyncFile << lines[i] << nline;
    }

    r_MainFile.close();
    w_SyncFile.close();

    std::cout << fileB + " Finished!\n";
}

int main(int argc, char const *argv[]) {
    /* 
     *  Read the Main text & Sync text file (containing the file path of files to sync and must be in same line A B)
     *      1st Pass: Check if the filesize for both are the same.
     *      2nd Pass: Check each file and compare each line by line, if one is not true then break operation and sync.
     *      If both of those are passed then the file is updated.
     */

    std::ifstream r_MainFilePath("MainPath.txt");
    std::ifstream r_SyncFilePath("SyncPath.txt");
    std::string localFile, remoteFile;

    Colors color;

    while (getline(r_MainFilePath, localFile) && getline(r_SyncFilePath, remoteFile)) {
        if (isFileSizeEqual(localFile, remoteFile) && isEqualLineByLine(localFile, remoteFile))
            std::cout << color.GREEN << remoteFile + " File is already Up-to-Date!\n" << color.RESET;
        else
            syncFiles(localFile, remoteFile); // Update Both Files
    }

    return 0;
}