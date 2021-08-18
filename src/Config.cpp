#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

#include "Config.h"
#include "Engine.h"


const std::string Config::DefaultConfigFile = "./frack.cfg";


Config::Config() :
    Config(DefaultConfigFile)
{
}

Config::Config(const std::string& configFilePath) :
    configFilePath(configFilePath)
{
    refresh();
}

Config::~Config()
{
    if (configFile.is_open()) configFile.close();
}

/** Reloads config data from file into local config table */
void Config::refresh()
{
    // TODO: fix cwd so config file is found in correct location no matter
    //       where game is launched from

    using boost::algorithm::trim;
    using std::string;
    using std::getline;

    configFile.open(configFilePath);
    string curLine;
    while (!configFile.eof()) {
        getline(configFile, curLine);
        string key, value;

        // Ignore comments
        size_t delimPos = curLine.find('#');
        if (delimPos != string::npos) {
            curLine = curLine.substr(0, delimPos);
        }

        delimPos = curLine.find('=');
        if (!curLine.empty() && delimPos == string::npos) {
            Engine::getEngine().getLogger().log(boost::str(boost::format("Config: bad format: %1%") % curLine));
            continue;
        }
        key = curLine.substr(0, delimPos);
        value = curLine.substr(delimPos+1); // skip delim char
        trim(key);
        if (key.empty()) continue;
        trim(value);

        // Store key-value pair
        configTable[key] = value;
    }
    configFile.close();
}

float Config::getFloat(const std::string& key) const
{
    static const float DefaultValue = 0.0f;

    std::string value = getString(key);
    if (value.empty()) return DefaultValue;
    
    // remove trailing 'f' if exists
    if (value.back() == 'f' || value.back() == 'F') {
        value = value.substr(0, value.length() - 1);
    }
    try {
        return boost::lexical_cast<float>(value); 
    }
    catch (const boost::bad_lexical_cast&) {
        fprintf(stderr, "Config: key \"%s\" is invalid float value\n", key.c_str());
    }
    return DefaultValue;
}

int Config::getInt(const std::string& key) const
{
    static const int DefaultValue = 0;

    try {
        return boost::lexical_cast<int>(getString(key));
    }
    catch (const boost::bad_lexical_cast&) {
        fprintf(stderr, "Config: key \"%s\" is invalid int value", key.c_str());
    }
    return DefaultValue;
}

std::string Config::getString(const std::string& key) const
{
    try {
        return configTable.at(key);
    }
    catch (const std::out_of_range& ex) {
        /*
        Engine::getEngine().getLogger().log(
                boost::str(boost::format("Warning: Config key \"%1%\" not found") % key)
        );
        */
        return "";
    }
}
