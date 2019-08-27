#pragma once
#include <string>

using namespace std;

class KeyStringElement
{
public:
    KeyStringElement()
    {}

    KeyStringElement (string theKeyString) : aKeyString (theKeyString)
    {}

    int aKeyNumber;
    string aKeyString;
};
