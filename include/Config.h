#pragma once

#include <fstream>
#include <string>
#include <unordered_map>


/** Stores configuration data in key-value pairs */
class Config {
    using ConfigTable = std::unordered_map<std::string, std::string>;

    static const std::string DefaultConfigFile;

public:
    Config();
    Config(const std::string& configFilePath);
    ~Config();

    float       getFloat(const std::string& key)  const;
    int         getInt(const std::string& key)    const;
    std::string getString(const std::string& key) const;

    void refresh();

private:
    ConfigTable configTable;
    std::string configFilePath;
    std::ifstream configFile;

};
