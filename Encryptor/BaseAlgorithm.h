#pragma once
#include <string>
#include <vector>

using namespace std;

class BaseAlgorithm
{
public:
    BaseAlgorithm (string& theKey, string& theOrigin) : aKey (theKey),
                                                        anOrigin (theOrigin)
    {};

protected:

    string anAlphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
    string anInsignificantChars = "~`!' @#$%^&*()-_=+\\|:;\".<> ?,/[]{}«»";
    string aKey;
    string anOrigin;

    char ToUpper (char& theChar);
    void RemoveInsignificantChars (const string& theString, string& theNewString);
    std::vector<string> DivideByNumber (string& theString, const int& theNumber);
};

