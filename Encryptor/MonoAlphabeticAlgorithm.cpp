#include "pch.h"
#include "MonoAlphabeticAlgorithm.h"


void MonoAlphabeticAlgorithm::CreateDictionary (string& theKey, string& theOrigin, string& theCryptoAlphabet, bool Reverse)
{
    //making a cryptoalphabet and a dictionary
    string aSourceAlphabet = theKey + anAlphabet;
    for (const auto& aChar : aSourceAlphabet) {
        auto aFound = aCryptoAlphabet.find (aChar);
        if (aFound == aCryptoAlphabet.end()) {
            aCryptoAlphabet.emplace (aChar);
        } else {
            continue;
        }
    }
    for (const auto& aChar : aCryptoAlphabet) {
        if (!anAlphabet.empty()){
            const auto& anAlphabetChar = anAlphabet[0];
            if (Reverse) {
                aDictionary.insert (std::make_pair (aChar, anAlphabetChar));
            } else {
                aDictionary.insert (std::make_pair (anAlphabetChar, aChar));
            }            
            anAlphabet.erase (anAlphabet.begin());
        }
    }
}

std::vector <string> MonoAlphabeticAlgorithm::Encrypt()
{     
    string aCleanKey = "";
    string aCleanOrigin = "";
    string aCryptoAlphabet = "";
    RemoveInsignificantChars (aKey, aCleanKey);
    RemoveInsignificantChars (anOrigin, aCleanOrigin);
    CreateDictionary (aCleanKey, aCleanOrigin, aCryptoAlphabet);

    //encrypting
    string aResult = "";
    for (auto& aChar : aCleanOrigin) {
        auto aPair = aDictionary.find (aChar);
        char aNewChar;
        if (aPair != aDictionary.end()) {
            aNewChar = aPair->second;
        } else {
            aNewChar = aChar;
        }        
        aResult = aResult + aNewChar;
    }
    auto aDivededOriginVec = DivideByNumber (aResult, 5);
    return aDivededOriginVec;
}

string MonoAlphabeticAlgorithm::Decrypt()
{
    string aCleanKey = "";
    string aCleanOrigin = "";
    string aCryptoAlphabet = "";
    RemoveInsignificantChars (aKey, aCleanKey);
    RemoveInsignificantChars (anOrigin, aCleanOrigin);
    CreateDictionary (aCleanKey, aCleanOrigin, aCryptoAlphabet, true);

    //decrypting
    string aResult = "";
    for (auto& aChar : aCleanOrigin) {
        auto aPair = aDictionary.find (aChar);
        char aNewChar;
        if(aPair != aDictionary.end ()) {
            aNewChar = aPair->second;
        } else {
            aNewChar = aChar;
        }
        aResult = aResult + aNewChar;
    }
    return aResult;

    
}
