#include <iostream>
#include "Company.h"
#include "Competitor.h"
#include "Tournament.h"
#include "Industry.h"
using namespace std;

Competitor::Competitor(){
    
}



// void Competitor::assignMatchupNumber(int competitorNumber){
//     matchupNumber = competitorNumber/2;
// }

void Competitor::useRatioAsMetric(){
    intMetric = getPayRatioInt();
    
    string s = to_string(getPayRatioInt());
    if (s.size() < 4){ 
        string metric = s + ":1";
        stringMetric = "\x1B[33m" + metric + "\033[0m";
    }
    else
    {
        string tack_on = "," + s.substr(s.size() - 3, s.size());
        string metric = to_string((getPayRatioInt() / 1000)) + tack_on + ":1";
        stringMetric = "\x1B[33m" + metric + "\033[0m";
    }
}



void Competitor::printMetric(Tournament tourney){
    
    if (tourney.getPlayersChosenMetric() == "payRatio"){
        if (tourney.getMatchupNumber() >= 15){ 
            string s = to_string(getPayRatioInt());
            if (s.size() < 4){ 
                string metric = s + ":1";
                cout << metric;
            }
            else {
                string tack_on = "," + s.substr(s.size() - 3, s.size());
                string metric = to_string((getPayRatioInt() / 1000)) + tack_on + ":1";
                cout << metric;
            }
        }
        else {
            cout << "";
        }
    }
    else if (tourney.getPlayersChosenMetric() == "revenue"){
        
    }
    else if (tourney.getPlayersChosenMetric() == "CEOpay"){
        
    }
    else if (tourney.getPlayersChosenMetric() == "highestAvgEmployeesPay"){
        
    }
    else if (tourney.getPlayersChosenMetric() == "CEOchangeInCompensation"){
        
    }
    else if (tourney.getPlayersChosenMetric() == "highestTotalReturn"){
        
    }
    
}

int Competitor::getMetric(){
    return intMetric;
}

void Competitor::revealMetric(){
    string s = to_string(getPayRatioInt());
    if (s.size() < 4){ 
        string metric = s + ":1";
        hiddenStringMetric = "\x1B[33m" + metric + "\033[0m";
    }
    else
    {
        string tack_on = "," + s.substr(s.size() - 3, s.size());
        string metric = to_string((getPayRatioInt() / 1000)) + tack_on + ":1";
        hiddenStringMetric = "\x1B[33m" + metric + "\033[0m";
    }
    stringMetric = hiddenStringMetric;
}

// void Competitor::getCompetitorName(){
//     nameWithoutColor = getTruncatedName();
//     nameYellow = "\x1B[33m" + getTruncatedName() + "\033[0m";
//     nameGreen =  "\x1B[32m" + getTruncatedName() + "\033[0m";
//     nameRed =    "\x1B[31m" + getTruncatedName() + "\033[0m";
// }


void Competitor::printColoredName(){
    cout << coloredName;
}

void Competitor::defaultColorName(){
    coloredName = nameYellow;
}

void Competitor::correctChoiceName(){
    coloredName = nameGreen;
}

void Competitor::incorrectChoiceName(){
    coloredName = nameRed;
}

void Competitor::setTruncatedName(string name){
    truncatedName = name;
}

string Competitor::getTruncatedName(Tournament tourney, int competitorNumber){
    string s = "             ?              ";
    // if ((tourney.getMatchupNumber() >= competitorNumber/2) || ((competitorNumber == tourney.getMatchupNumber() +15) && (tourney.getMatchupNumber() > 0)){
    if (competitorNumber <= tourney.getMatchupNumber() + 15){
        return truncatedName;
    }
    else if ((competitorNumber == 30) && (tourney.getMatchupNumber() <= 14) && (tourney.getPlayersChosenMetric() == "payRatio")){
        return "  Who Is The Most Unequal?  ";
    }
    else if ((competitorNumber == 30) && (tourney.getMatchupNumber() <= 14) && (tourney.getPlayersChosenMetric() == "ceoPay")){
        return "  Who Pays Its CEO The Most? ";
    }
    else if ((competitorNumber == 30) && (tourney.getMatchupNumber() <= 14) && (tourney.getPlayersChosenMetric() == "highestAvgEmployeesPay")){
        return "  Who Pays Workers The Best? ";
    }
    else if ((competitorNumber == 30) && (tourney.getMatchupNumber() <= 14) && (tourney.getPlayersChosenMetric() == "lowestAvgEmployeesPay")){
        return " Who Pays Workers The Worst? ";
    }
    // else if ((competitorNumber == 30) && (competitorNumber == tourney.getMatchupNumber() + 16)){
    //     return "      The Most Unequal       ";
    // }
    else if (competitorNumber == tourney.getMatchupNumber() + 16){
        return "         ??????????         ";
    }
    else {
        return s;
    }
}

void Competitor::printTruncatedName(){
    cout << truncatedName;
}

void Competitor::setPayRatioRank(int rank){
    payRatioRank = rank;
}

int Competitor::getPayRatioRank(){
    return payRatioRank;
}
