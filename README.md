# LocalizedString for Axmol Engine

Localize your strings to several languages in Axmol Engine.

Inspired by the ["Multiple language support"](https://discuss.cocos2d-x.org/t/tutorial-multiple-language-support/16237) tutorial by Den.

## Preparations

Include the following files in your `Source` folder:

```
LocalizedString.h
LocalizedString.cpp
```

You can edit `LocalizedString.cpp` in order to add more languages or changing the names and formats of your localization files.

Available languages:
```
CHINESE JAPANESE FRENCH ITALIAN GERMAN SPANISH DUTCH RUSSIAN HUNGARIAN PORTUGUESE
KOREAN ARABIC NORWEGIAN POLISH TURKISH UKRAINIAN ROMANIAN BULGARIAN BELARUSIAN
```

Available file formats:
* `.json`
* `.plist`

Create the localization files inside your `Content` folder.

In this extension the files are called `Localizable_xx.json` by default. This is an example on how you can create one in any text editor:

**Localizable_en.json**
```
{
    "play_button_label":"Play",
    "mode_selection_label":"Select mode",
    "pause_label":"Pause"
}
```
The first element is the `key` you have to call to get the localized string, second is the localized string.

## How to use

Add `#include "LocalizedString.h"` in your class file.

Use the following call with your `key` to get the translated string:

`std::string textToLocalize =  LocalizedString::getInstance()->getLocalizedString("key_to_translate");`

**Note**: If the `key` is not found inside the files, the same `key` will be returned.

***

If you have a lot of text, you can make the call shorter by using something similar to this:

```
string HelloWorld::localizedString(string key)
{
    return LocalizedString::getInstance()->getLocalizedString(key);
}
```
Then you can just use `string text = localizedString("key_to_translate");`

***

Final note: adding more languages is out of the reach of this extension. In case of need, these are some of the files inside Axmol Engine you may want to check:

* [Utils.cpp](https://github.com/axmolengine/axmol/blob/2.1/core/base/Utils.cpp) (all platforms except Windows)
* [Application-win32.cpp](https://github.com/axmolengine/axmol/blob/2.1/core/platform/win32/Application-win32.cpp) (for Windows)


