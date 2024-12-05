#include "Asset.h"
#include <fstream>

// Asset Constructor
// Return: void
// Args: string filePath
// Init a Asset object
// Before that, it will check the file is whether availiable.
// If it is availiable, it would be added to the class.
// Also, it will load the format.
// It is useful when you need to know the file format
// If it don't work, it will stop the progress.
// You will get a Asset Object that isn't availiable.
Gkit::Asset::Asset(std::string filePath){
    std::ifstream ifs(filePath);
    // Can't find the file
    if(!ifs.is_open()){
        return;
    }
    // Load format of file
    for(int i = filePath.size() - 1; i >= 0; --i){
        if (filePath[i] == '.') break;
        this->fileFormat.push_back(filePath[i]);
    }

    this->filePath = filePath;
    return;
}

// Asset::IsAvailiable
// Return: bool
// Args: None
// Check the file is availiable
bool Gkit::Asset::IsAvailiable(){
    return !this->filePath.empty();
}

// Asset::ChangeFilePath
// Return bool
// Args: string newFilePath
// This function can quickly help you change your Asset's path.
// And it will return a bool singal to make you know whether it worked.
// It's progress is like Asset Constructor
bool Gkit::Asset::ChangeFilePath(std::string newFilePath){
    std::ifstream ifs(newFilePath);
    if(!ifs.is_open()){
        // Can't find the new file or unavailiable
        // And return false
        return false;
    }

    fileFormat.clear();
    // Load format of file
    for(int i = filePath.size() - 1; i >= 0; --i){
        if (filePath[i] == '.') break;
        this->fileFormat.push_back(filePath[i]);
    }
    this->filePath = newFilePath;
    // All of the progress worked
    // Return true
    return true;
}

// Asset::GetFilePath
// Return: String
// Args: None
// The work is just like its name 
// -- return the file path
std::string Gkit::Asset::GetFilePath(){
    return this->filePath;
}