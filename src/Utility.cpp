//
// Created by Vojtěch Pašek on 19.05.2023.
//

#include "Utility.h"

#include "openssl/md5.h"
#include <fstream>

#include "entry/Symlink.h"
#include "entry/File.h"
#include "entry/Folder.h"

std::string Utility::escape(const std::string& input) {
    std::string escaped;

    for (char c : input) {
        switch (c) {
            case '\"':
                escaped += "\\\"";
                break;
            case '\'':
                escaped += "\\\'";
                break;
            case '\\':
                escaped += "\\\\";
                break;
            case '\n':
                escaped += "\\n";
                break;
            case '\r':
                escaped += "\\r";
                break;
            case '\t':
                escaped += "\\t";
                break;
            default:
                escaped += c;
        }
    }

    return escaped;
}

std::shared_ptr<Entry> Utility::makeEntry(const std::filesystem::path& path) {
    if (is_symlink(path))
        return std::shared_ptr<Entry>{new Symlink{path}};
    else if (is_regular_file(path))
        return std::shared_ptr<Entry>{new File{path}};
    else if (is_directory(path))
        return std::shared_ptr<Entry>{new Folder{path}};
    return nullptr;
}

std::string Utility::getHash(const std::filesystem::path& path) {
    std::ifstream::pos_type fileSize;
    char * fileContent;

    std::ifstream file (path, std::ios::ate);

    fileSize = file.tellg();
    fileContent = new char[fileSize];
    file.seekg(0,std::ios::beg);
    file.read(fileContent, fileSize);
    file.close();

    unsigned char result [MD5_DIGEST_LENGTH];
    MD5((unsigned char*) fileContent, fileSize, result);
    return {(char*) result, MD5_DIGEST_LENGTH};
}
