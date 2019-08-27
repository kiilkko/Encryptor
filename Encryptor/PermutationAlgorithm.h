#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "BaseAlgorithm.h"
#include "KeyElement.h"
#include "KeyStringElement.h"

using namespace std;

class PermutationAlgorithm : BaseAlgorithm
{
public:
    PermutationAlgorithm (string& theKey, string& theOrigin) : BaseAlgorithm (theKey, theOrigin)
    {};

    std::vector<string> Encrypt();
    string Decrypt();

private:

    std::vector <KeyElement> aKeyOrderVec;

    void DetermineOrder (const string& theCleanKey);
};

