#include "Asset.h"
#include <fstream>

/// Constructor ///
Gkit::Asset::Asset(std::string file_path){
    std::ifstream ifs(file_path);
    // Can't find the file
    if(!ifs.is_open()){
        return;
    }
    // Load format of file
    for(int i = file_path.size() - 1; i >= 0; --i){
        if (file_path[i] == '.') break;
        this->file_format.push_back(file_path[i]);
    }

    this->file_path = file_path;
    return;
}

/// Operation functions ///
bool Gkit::Asset::IsAvailiable(){
    return !this->file_path.empty();
}

bool Gkit::Asset::ChangeFilePath(std::string new_file_path){
    std::ifstream ifs(new_file_path);
    if(!ifs.is_open()){
        // Can't find the new file or unavailiable
        // And return false
        return false;
    }

    this->file_format.clear();
    // Load format of file
    for(int i = file_path.size() - 1; i >= 0; --i){
        if (file_path[i] == '.') break;
        this->file_format.push_back(file_path[i]);
    }
    this->file_path = new_file_path;
    // All of the progress worked
    // Return true
    return true;
}

std::string Gkit::Asset::GetFilePath(){
    return this->file_path;
}


std::string Gkit::Asset::GetFileFormat(){
    return this->file_format;
}

void Gkit::Asset::ClearFilePath(){
    this->file_path.clear();
    this->file_format.clear();
    return;
}