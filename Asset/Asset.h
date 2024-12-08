/*
    File name: Asset.h
    Writed by @Cora

    This file state the base class Asset
    Asset is the base of all the game source object
    Every object about game source class is extended by it

    About Asset:
    When you need to create a Asset object, you need to provide a file path to create it.
    the file path's format is string, file path is the base of Asset.
    You may pay attention to it : Don't use the Asset whose file path is empty!!!
    In the basic function we provide, they only check it when you create the Asset object
    or changed the file path. You have to pay more attention about your game sources whether
    are moved.
*/

#ifndef ASSET_H
#define ASSET_H

#include <string>

namespace Gkit{
class Asset{
public:
    Asset(std::string filePath);
    ~Asset() = default;

    bool IsAvailiable();
    bool ChangeFilePath(std::string newFilePath);
    std::string GetFilePath();
    std::string GetFileFormat();
    void ClearFilePath();

private:
    std::string filePath   = "";
    std::string fileFormat = ""; 
};// class Asset

}// namespace cora
#endif