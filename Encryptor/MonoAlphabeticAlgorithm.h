#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "BaseAlgorithm.h"

using namespace std;

class MonoAlphabeticAlgorithm : BaseAlgorithm
{
public:
    MonoAlphabeticAlgorithm (string& theKey, string& theOrigin) : BaseAlgorithm (theKey, theOrigin)
    {};
    
    std::vector <string> Encrypt();
    string Decrypt();

private:

    unordered_map<char, char> aDictionary;
    unordered_set<char> aCryptoAlphabet;

    void CreateDictionary (string& theKey, string& theOrigin, string& theCryptoAlphabet, bool Reverse = false);
};

