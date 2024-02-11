/****************************************************************************
 
LocalizedString.h

Extension for Axmol Engine: localize your strings to several languages

Inspired by the "Multiple language support" tutorial by Den.
https://discuss.cocos2d-x.org/t/tutorial-multiple-language-support/16237

Created by Daniel Alias on 2024/02/11 (yyyy/mm/dd) under MIT Licence

 ****************************************************************************/

#ifndef LOCALIZEDSTRINGTEST_LOCALIZEDSTRING_H
#define LOCALIZEDSTRINGTEST_LOCALIZEDSTRING_H

#ifndef _LocalizedString_H_
#define _LocalizedString_H_

#include "axmol.h"
#include "rapidjson/document.h"

using std::string;

USING_NS_AX;;

class LocalizedString
{
private:
    LocalizedString();
    ~LocalizedString();

    string extension;
    string fullContent;
    ValueMap readMap;

public:
    static LocalizedString* getInstance();
    string getLocalizedString(std::string key);
};

#endif

#endif //LOCALIZEDSTRINGTEST_LOCALIZEDSTRING_H
