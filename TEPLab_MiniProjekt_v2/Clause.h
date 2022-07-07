#ifndef TEPLAB_MINIPROJEKT_V2_CLAUSE_H
#define TEPLAB_MINIPROJEKT_V2_CLAUSE_H
#include <iostream>
#include "vector"


class Clause {

public:

    Clause(std::string &sClauseInfo);

    void vPrint();
    void setValueAt(int i, int iVal);
    int getValueAt(int i);
    void setNegationAt(int i, bool bIsNegated);
    bool getNegationAt(int i);
    bool isPleased(const std::vector<bool> &vbSolution);

private:
    std::vector<int> viValues;
    std::vector<bool> vbNegated;

    void vDataReader(std::string &sClauseInfo);
};


#endif //TEPLAB_MINIPROJEKT_V2_CLAUSE_H
