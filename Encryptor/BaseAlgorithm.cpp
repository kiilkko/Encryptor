#include "pch.h"
#include <cctype>
#include <locale>
#include "BaseAlgorithm.h"


char BaseAlgorithm::ToUpper (char& theChar)
{
    setlocale (LC_ALL, "RUS");
    auto UpChar = std::toupper (static_cast<unsigned char> (theChar));
    return UpChar;
}

void BaseAlgorithm::RemoveInsignificantChars (const string& theString, string& theNewString)
{
    for (auto ch : theString) {
        bool ToWrite = true;
        for(auto item = anInsignificantChars.cbegin (); item != anInsignificantChars.cend (); ++item){
            auto& aChar = *item;
            if(ch == aChar) {
                ToWrite = false;
                break;
            }
        }
        if (ToWrite) {
            theNewString = theNewString + ToUpper (ch);
        }
    }
}

std::vector<string> BaseAlgorithm::DivideByNumber (string& theString, const int& theNumber)
{
    int aCounter = 0;
    string aSubString = "";
    std::vector<string> aDivededOriginVec;

    for (auto i = theString.begin(), e = theString.end (); i != e; ++i) {        
        ++aCounter;
        if (aCounter % theNumber == 0) {
            aSubString = aSubString + *i;
            aDivededOriginVec.push_back (std::move (aSubString));
            continue;
        } else {
            aSubString = aSubString + *i;
        }
    }
    if (!aSubString.empty()) {
        aDivededOriginVec.push_back (std::move (aSubString));
    }

    return aDivededOriginVec;
}