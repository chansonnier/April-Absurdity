#ifndef INDUSTRY_H
#define INDUSTRY_H

#include <string>
#include "Company.h"
#include "Competitor.h"
#include "Tournament.h"
#include <vector>
using namespace std;

class Industry {
    // functions associated with Industry
    public:
        Industry(); // default constructor
        Industry(string name); // parameterized constructor
    
        void printCompanies();
        
        void setName(string input);
        
        void addCompanyToArray(Competitor company);
        
        string getName();
        
        int getNumCompanies();
        
        void printIthCompanyName(int i);
        
    private: 
        
        string industryName;
        
        int numCompanies = 0;
        
        vector<Company> companies;
        
        int companyArrayAddingIndex = 1;
    
};

#endif