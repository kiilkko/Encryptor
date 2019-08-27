#include "pch.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "PermutationAlgorithm.h"

std::vector<string> PermutationAlgorithm::Encrypt ()
{
    string aCleanKey = "";
    string aCleanOrigin = "";
    RemoveInsignificantChars (aKey, aCleanKey);
    RemoveInsignificantChars (anOrigin, aCleanOrigin);
    DetermineOrder (aCleanKey);
    auto aDivededOriginVec = DivideByNumber (aCleanOrigin, aCleanKey.size());

    string aResult = "";
    int aCounter = 0;
    for (int j = 0; j < (int)aKeyOrderVec.size(); ++j) {
        for (int i = 0; i < (int)aKeyOrderVec.size (); ++i) {
            auto aKeyChar = aKeyOrderVec[i];
            if (aKeyChar.aKeyNumber == aCounter) {
                for (auto item = aDivededOriginVec.begin (), end = aDivededOriginVec.end (); item != end; ++item) {
                    auto anElement = *item;
                    if (i > (int)anElement.size()-1) {
                        continue;
                    }
                    aResult = aResult + anElement[i];
                }
                ++aCounter;
            }
        }
    }       
    auto aDivededResult = DivideByNumber (aResult, 5);
    return aDivededResult;
}

string PermutationAlgorithm::Decrypt()
{
    string aCleanKey = "";
    string aCleanOrigin = "";
    RemoveInsignificantChars (aKey, aCleanKey);
    RemoveInsignificantChars (anOrigin, aCleanOrigin);
    DetermineOrder (aCleanKey);

    auto aDividedOrigin = DivideByNumber (aCleanOrigin, aCleanKey.size());
    auto aStringsNumber = aDividedOrigin.size();

    auto aFindInKeyOrderVec = [this] (const int& theIndex) ->int  {
        for (int i=0; i< (int)aKeyOrderVec.size(); ++i) {
            if (theIndex == aKeyOrderVec[i].aKeyNumber) {
                return i;
            }
        }
        return 0;
    };

    vector <KeyStringElement> aResultVec;
    string aSubstring;
    int aRemainder;
    auto aLastIndex = aCleanOrigin.size() - 1;
    int aQuantityOfIncompleteStrings = aCleanKey.size() - (aCleanOrigin.size() % aCleanKey.size());
    int aMinIncompleteStringsNumber = aCleanKey.size() - aQuantityOfIncompleteStrings;

    for (int i = 0; i < (int)aCleanOrigin.size(); ++i) {
        
        aSubstring += aCleanOrigin[i];
        auto aNumberOfString = aFindInKeyOrderVec (aResultVec.size ());
        
        if (i > 0) {
            if (aQuantityOfIncompleteStrings && aNumberOfString >= aMinIncompleteStringsNumber) {
                if (aStringsNumber < aSubstring.size()) {
                    aRemainder = aSubstring.size() % (aStringsNumber-1);
                } else {
                    aRemainder = aSubstring.size() - (aStringsNumber - 1);
                }                
            } else {
                if (aStringsNumber < aSubstring.size ()) {
                    aRemainder = aSubstring.size() % aStringsNumber;
                } else {
                    aRemainder = aSubstring.size() - aStringsNumber;
                }                
            }           
            if ((aRemainder == 0) || (i == aLastIndex)) {
                KeyStringElement anElement (std::move (aSubstring));
                anElement.aKeyNumber = aFindInKeyOrderVec (aResultVec.size());
                aResultVec.push_back (std::move (anElement));                
            }
        }
    }

    auto aCompare = [](const KeyStringElement& A, const KeyStringElement& B) ->bool {
        return (A.aKeyNumber < B.aKeyNumber);
    };
    std::sort (aResultVec.begin(), aResultVec.end(), aCompare);

    string aResult ("");
    int aCounter = 0;
    auto aSize = aResultVec[0].aKeyString.size();
    while (aCounter <= (int)aSize) {
        for (int j = 0; j < (int)aResultVec.size (); ++j) {
            auto anItem = aResultVec[j];
            if (aCounter > (int)(anItem.aKeyString.size() - 1)) {
                continue;
            }
            aResult += anItem.aKeyString[aCounter];
        }
        ++aCounter;
    }
    return aResult;
}

void PermutationAlgorithm::DetermineOrder (const string& theCleanKey)
{
    for (const auto& aChar : theCleanKey) {
        KeyElement anElement (aChar);
        aKeyOrderVec.push_back (anElement);
    }
    int aCounter = 0;
    for (auto i = anAlphabet.begin(), e = anAlphabet.end(); i != e; ++i) {
        auto anAlphabetChar = *i;
        for (auto& anElement : aKeyOrderVec) {
            if (anElement.aKeyChar == anAlphabetChar) {
                anElement.aKeyNumber = aCounter;
                ++aCounter;
            }
        }
    }
}
