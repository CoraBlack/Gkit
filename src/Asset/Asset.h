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
    /**
     * Asset Constructor
     * @author Cora
     * @since Version 0.10
     * @param file_path
     * @return void
     *  
     * @note Init a Asset object.
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
    Asset(std::string file_path);
    ~Asset() = default;

    /**
     * @brief Change the file path of the asset.
     * @author Cora
     * @since Version 0.10
     * @param void
     * @return bool
     * @note Check the file is availiable
     */
    bool IsAvailiable();
    /**
     * @brief Clear the original file path and replace it with a new one.
     * @author Cora
     * @since Version 0.10
     * @param  new_file_path string
     * @return bool
     * @note This function can quickly help you change your Asset's path.
     * 
     * And it will return a bool singal to make you know whether it worked.
     * It's progress is like Asset Constructor
     */
    bool ChangeFilePath(std::string new_file_path);
    /**
     * @brief This function can quickly help you get your Asset's path. 
     * @author Cora
     * @since Version 0.10
     * @param None
     * @return std::string -- your Asset's path
     */
    std::string GetFilePath();
    /**
     * @brief GetFileFormat
     * @author Cora
     * @since Version 0.10
     * @param None
     * @return std::string -- The file format of your Asset
     */
    std::string GetFileFormat();
    /**
     * @brief Clear the file path of your Asset and make it unavailiable.
     * @author Cora
     * @since Version 0.10
     * @param None
     * @return Void
     */
    void ClearFilePath();

private:
    std::string file_path   = "";
    std::string file_format = ""; 
};// class Asset

}// namespace cora
#endif