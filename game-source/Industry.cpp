#include <iostream>
#include "Company.h"
#include "Industry.h"
using namespace std;

Industry::Industry(){
    
}


Industry::Industry(string name){
    industryName = name;
}

void Industry::printCompanies(){
    for (int i = 0; i < numCompanies; i++){
        cout << "Company #" << i+1 << ": "; companies[i].printName();
        cout << endl;
    }
}

void Industry::setName(string input){
    industryName = input;
}

string Industry::getName(){
    return industryName;
}

void Industry::addCompanyToArray(Competitor company){
    companies.push_back(company); // add the input company to this industry's vector/array
    companyArrayAddingIndex++;
    numCompanies++;
}

int Industry::getNumCompanies(){
    return numCompanies;
}

void Industry::printIthCompanyName(int i){
    companies[i].printName();
}