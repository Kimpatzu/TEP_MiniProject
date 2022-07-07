#include "Clause.h"

Clause::Clause(std::string &sClauseInfo) {
    vDataReader(sClauseInfo);
}

void Clause::vPrint() {
    std::cout << "Liczba wartosci: " << viValues.size() << std::endl;
    std::cout << "Liczba booli: " << vbNegated.size() << std::endl;
    for (int i=0; i < viValues.size(); i++){
        if(vbNegated.at(i)){
            std::cout<<"-";
        }
        std::cout << viValues.at(i) << "    ";
    }
}

void Clause::setValueAt(int i, int iVal) {
    if (i >= 0 && i < viValues.size()) {
        viValues.at(i) = iVal;
    } else {
        std::cout << "Index " << i << " out of bounds for viValues size of " << viValues.size() << std::endl;
    }
}

int Clause::getValueAt(int i) {
    if (i >= 0 && i < viValues.size()) {
        return viValues.at(i);
    } else {
        std::cout << "Index " << i << " out of bounds for viValues size of " << viValues.size() << std::endl;
        return 0;
    }
}

void Clause::setNegationAt(int i, bool bIsNegated) {
    if (i >= 0 && i < vbNegated.size()) {
        vbNegated.at(i) = bIsNegated;
    } else {
        std::cout << "Index " << i << " out of bounds for vbNegated size of " << vbNegated.size() << std::endl;
    }
}

bool Clause::getNegationAt(int i) {
    if (i >= 0 && i < vbNegated.size()) {
        return vbNegated.at(i);
    } else {
        std::cout << "Index " << i << " out of bounds for vbNegated size of " << vbNegated.size() << std::endl;
        return false;
    }
}

bool Clause::isPleased(const std::vector<bool> &vbSolution) {
    bool ispleased = false;
    for (int i=0; i<viValues.size(); i++){
        if (vbSolution.at(viValues.at(i)) == vbNegated.at(i)){          //by spełnione - false, false - nigdzie nie zanegowane lub true true, zanegowane w obu przypadkach
            ispleased = true;
        }
    }
    return ispleased;
}

void Clause::vDataReader(std::string &sClauseInfo){                      //returns highest met value
    sClauseInfo = sClauseInfo.substr(2,(sClauseInfo.length()-3));
    std::string sCurrentString = "";
    int iCurrentValue;
    bool firstWhiteSpace = true;
    for (int i=0; i<sClauseInfo.length(); i++){     //przechodzimy przez informacja o klazuli
        if(sClauseInfo.at(i) != ' '){
            sCurrentString += sClauseInfo.at(i);    //dodajemy kolejne znaki liczby (łącznie z minusem jeśli jest)
            firstWhiteSpace = true;
        } else {
            if (firstWhiteSpace){
                iCurrentValue = std::stoi(sCurrentString);
                if(iCurrentValue == 0){             //przypadek gdy numer zmiennej to 0, jedyny gdzie "-" byłby niewłaściwie ignorowany
                    if (sCurrentString.at(0) == '-'){
                        vbNegated.push_back(true);
                    } else {
                        vbNegated.push_back(false);
                    }
                    viValues.push_back(iCurrentValue);
                } if(iCurrentValue < 0){
                    vbNegated.push_back(true);
                    viValues.push_back(-iCurrentValue);
                } if (iCurrentValue > 0){
                    vbNegated.push_back(false);
                    viValues.push_back(iCurrentValue);
                }
                firstWhiteSpace = false;
                sCurrentString = "";
            }
        }
    }
}