/****************************************************************************
 
LocalizedString.cpp

Extension for Axmol Engine: localize your strings to several languages

Inspired by the "Multiple language support" tutorial by Den.
https://discuss.cocos2d-x.org/t/tutorial-multiple-language-support/16237

Created by Daniel Alias on 2024/02/11 (yyyy/mm/dd) under MIT Licence

 To call this class, use
    std::string textToLocalize =  LocalizedString::getInstance()->getLocalizedString("key_to_translate");

 ****************************************************************************/

#include "LocalizedString.h"

using namespace rapidjson;
using std::string;

USING_NS_AX;

static LocalizedString* localizedString = nullptr;

LocalizedString*LocalizedString::getInstance()
{
    if (!localizedString) {
        localizedString = new (std::nothrow)LocalizedString();
    }

    return localizedString;
}

LocalizedString::LocalizedString()
{
    /* Files can be .json or .plist
       The available LanguageType are the following:

       CHINESE JAPANESE FRENCH ITALIAN GERMAN SPANISH DUTCH RUSSIAN HUNGARIAN PORTUGUESE
       KOREAN ARABIC NORWEGIAN POLISH TURKISH UKRAINIAN ROMANIAN BULGARIAN BELARUSIAN
   */

    string filename = "";
    auto language = Application::getInstance()->getCurrentLanguage();

    switch (language) {
        case (LanguageType::ENGLISH):
            AXLOG("Set to English");
            filename = "Localizable_en.json";
            break;

        case (LanguageType::SPANISH):
            AXLOG("Set to Spanish");
            filename = "Localizable_es.json";
            break;

            // Add more languages here

        default:
            AXLOG("Set to default - English");
            filename = "Localizable_en.json";
            break;
    };

    // Find the extension

    extension = "";
    size_t pos = filename.find_last_of(".");
    if (pos != string::npos)
        extension = filename.substr(pos + 1);
    else
    {
        AXLOG("Localization: file have no extension");
        return;
    }

    // Read the file based on the extension

    fullContent = "";
    string path = FileUtils::getInstance()->fullPathForFilename(filename);

    if (extension == "plist")
        readMap = FileUtils::getInstance()->getValueMapFromFile(path);
    else if (extension == "json")
        fullContent = FileUtils::getInstance()->getStringFromFile(path);
    else
        AXLOG("Localization: incorrect file extension");

    return;
}

string LocalizedString::getLocalizedString(std::string key)
{

    if (key.length() == 0)
    {
        AXLOG("Localization: empty key");
        return "empty_key";
    }

    // Read the data based on the provided key

    string localizedText = "";

    if (extension == "plist") {

        auto fieldValue = readMap[key];
        localizedText = fieldValue.asString();

        if (localizedText.length() == 0)
        {
            AXLOG("Localization: key not found");
            return key;
        }

    } else if (extension == "json") {

        if (fullContent.length() == 0)
        {
            AXLOG("Localization: .json file is empty");
            return key;
        }

        Document document;
        document.Parse(fullContent.c_str());

        if(document.HasParseError())
        {
            AXLOG("Localization: Error parsing .json file");
            return key;
        }
        else if (!document.HasMember(key.c_str()) || document[key.c_str()].IsNull())
        {
            AXLOG("Localization: key not found");
            return key;
        }


        localizedText = document[key.c_str()].GetString();

    } else
        return key;

    // For testing purposes
    // AXLOG("Localization:Localized text: %s", localizedText.c_str());

    return localizedText;

}

