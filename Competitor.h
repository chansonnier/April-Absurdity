#ifndef COMPETITOR_H
#define COMPETITOR_H

#include <string>
#include "Tournament.h"
#include "Industry.h"
using namespace std;

class Competitor: public Company {
    // functions associated with Competitor
    public:
        Competitor(); // default constructor 
        
        // void assignMatchupNumber(int competitorNumber);
        
        void useRatioAsMetric();
        
        void printMetric(Tournament tourney);
        
        int getMetric();
        
        void revealMetric();
        
        // void getCompetitorName();
        
        void printColoredName();
        
        void defaultColorName();
        
        void correctChoiceName();
        
        void incorrectChoiceName();
        
        void setTruncatedName(string name);
        
        string getTruncatedName(Tournament tourney, int competitorNumber);
        
        void printTruncatedName();
        
        void updateColorName();
        
        void setPayRatioRank(int rank);
        int getPayRatioRank();
        
        
        
        
    private:
        int matchupNumber = 0;
        
        string stringMetric = "\x1B[33m         \033[0m"; // metric by which matchups are won is hidden until game over state
        
        string hiddenStringMetric = "";
        
        int intMetric = 0;
        int payRatioRank;
        
        string truncatedName = "";
        string nameWithoutColor = ""; // as it comes in from Company
        string nameYellow = "";
        string nameGreen = "";
        string nameRed = "";
        string coloredName = ""; // this will be set at various times to the three colors above
        
};

#endif