#pragma once

class KeyElement
{
public:
    KeyElement()
    {}

    KeyElement (const char& theKeyChar) : aKeyChar (theKeyChar)
    {}

    int aKeyNumber;
    char aKeyChar;
};

