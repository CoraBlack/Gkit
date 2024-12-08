#include "Asset.h"
#include <fstream>

/**
 * Asset Constructor
 * @author Cora
 * @since Version 0.10
 * @param string filePath
 * @return void
 *  
 * Init a Asset object.
 * Before that, it will check the file is whether availiable.
 * 
 * If it is availiable, it would be added to the class.
 * 
 * Also, it will load the format.
 * It is useful when you need to know the file format
 * 
 * If it don't work, it will stop the progress.
 * You will get a Asset Object that is unavailiable.
 */
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

/**
 * Asset::IsAvailiable
 * @author Cora
 * @since Version 0.10
 * @param void
 * @return bool
 * 
 * Check the file is availiable
 */
bool Gkit::Asset::IsAvailiable(){
    return !this->filePath.empty();
}

/**
 * Asset::ChangeFilePath
 * @author Cora
 * @since Version 0.10
 * @param  newFilePath string
 * @return bool
 * 
 * This function can quickly help you change your Asset's path.
 * 
 * And it will return a bool singal to make you know whether it worked.
 * It's progress is like Asset Constructor
 */
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

/**
 * Asset GetFilePath
 * 
 */
std::string Gkit::Asset::GetFilePath(){
    return this->filePath;
}

/**
 * Asset GetFileFormat
 * 
 */
std::string Gkit::Asset::GetFileFormat(){
    return this->fileFormat;
}

void Gkit::Asset::ClearFilePath(){
    this->filePath.clear();
    this->fileFormat.clear();
    return;
}