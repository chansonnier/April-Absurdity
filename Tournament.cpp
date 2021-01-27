#include <iostream>
#include "Tournament.h"
#include <iomanip>
using namespace std;

Tournament::Tournament(){
    
}

void Tournament::setPlayerName(string name){
    playerName = name;
}

string Tournament::getPlayerName(){
    return playerName;
}

string Tournament::getColor(int i){
   return colors[i];
}

void Tournament::setColorWithCode(int index, string colorCode){
    if (colorCode == "[32m"){     
        colors[index] = "\x1B[32m";
    }
    else if (colorCode == "[33m"){    
        colors[index] = "\x1B[33m";
    }
    else if (colorCode == "[31m+0 "){   
        colors[index] = "\x1B[31m+0 ";
    }
    else if ((colorCode == "[32m+1 ") && (index > 27)){    
        colors[index] = "\x1B[32m+1 ";            
        playerScore++; 
    }
    else if ((colorCode == "[32m+2 ") && (index > 27)){    
        colors[index] = "\x1B[32m+2 ";            
        playerScore+=2; 
    }
    else if ((colorCode == "[32m+2 ") && (index > 23)){    
        colors[index] = "\x1B[32m+2 ";            
        playerScore += 2;
    }
    else if ((colorCode == "[32m+3 ") && (index > 23)){    
        colors[index] = "\x1B[32m+3 ";            
        playerScore += 3;
    }
    else if ((colorCode == "[32m+4 ") && (index > 15)){    
        colors[index] = "\x1B[32m+4 ";            
        playerScore += 4;
    }
    else if ((colorCode == "[32m+5 ") && (index > 15)){    
        colors[index] = "\x1B[32m+5 ";            
        playerScore += 5;
    }
    else if (colorCode == "[32m+8 "){        
        colors[index] = "\x1B[32m+8 ";            
        playerScore += 8;
    }
    else if (colorCode == "[32m+9 ") {                 
        colors[index] = "\x1B[32m+9 ";            
        playerScore += 9;
    }
    else if (colorCode == "[32m+16 ") {
        colors[index] = "\x1B[32m+16 ";
        playerScore += 8*2;
    }
}


void Tournament::setColor(int i, char choice){
    if (choice == 'g'){          // 'g' for green (used to highlight current matchup)
        colors[i] = "\x1B[32m";
    }
    else if (choice == 'y'){     // 'y' for yellow (used as default color)
        colors[i] = "\x1B[33m";
    }
    else if (choice == 'r'){     // 'r' for red (used for "incorrect"/"wrong" answers)
        colors[i] = "\x1B[31m+0 ";
    }
    else if ((choice == 'c') && (i > 27)){     // 'c' for "correct"
        colors[i] = "\x1B[32m+1 ";              // 1 point for correct answers in round 4
        playerScore++; 
    }
    else if ((choice == 'b') && (i > 27)){     // 'b' for "bonus" (if the two competitors are in the same industry)
        colors[i] = "\x1B[32m+2 ";              // 1 point for correct answers in round 4, *2 bonus multiplier
        playerScore+=1*2; 
    }
    else if ((choice == 'c') && (i > 23)){     // 'c' for "correct"
        colors[i] = "\x1B[32m+2 ";              // 2 points for correct answers in round 3
        playerScore += 2;
    }
    else if ((choice == 'b') && (i > 23)){     // 'b' for "bonus"
        colors[i] = "\x1B[32m+4 ";              // 2 points for correct answers in round 3, *2 bonus multiplier
        playerScore += 2*2;
    }
    else if ((choice == 'c') && (i > 15)){     // 'c' for "correct"
        colors[i] = "\x1B[32m+4 ";              // 4 points for correct answers in round 2
        playerScore += 4;
    }
    else if ((choice == 'b') && (i > 15)){     // 'b' for "bonus"
        colors[i] = "\x1B[32m+8 ";              // 4 points for correct answers in round 2, *2 bonus multiplier
        playerScore += 4*2;
    }
    else if (choice == 'c') {                   // 'c' for "correct"              
        colors[i] = "\x1B[32m+8 ";              // 8 points for correct answers in round 1
        playerScore += 8;
    }
    else if (choice == 'b') {                   // 'b' for "bonus"              
        colors[i] = "\x1B[32m+16 ";              // 8 points for correct answers in round 1, *2 bonus multiplier
        playerScore += 8*2;
    }
    
}

int Tournament::getMatchupNumber(){
    return matchupNumber;
}

void Tournament::incrementMatchupNum(){
    matchupNumber++;
}


string Tournament::getArrowToLeft(int arrowLocation){
    if (matchupNumber == arrowLocation){
        return "\x1B[31m  <<<--- \033[0m";
    }
    else {
        return "\x1B[33m         \033[0m"; // make no arrow appear, just fill the space
    }
}

string Tournament::getArrowToRight(int arrowLocation){
    if (matchupNumber == arrowLocation){
        return "\x1B[31m --->>>  \033[0m";
    }
    else {
        return "\x1B[33m         \033[0m"; // make no arrow appear, just fill the space
    }
}

void Tournament::setPlayersChosenMetric(string input){
    playersChosenMetric = input;
}

string Tournament::getPlayersChosenMetric(){
    return playersChosenMetric;
}

void Tournament::setPlayerScore(int score){
    playerScore = score;
}

int Tournament::getPlayerScore(){
    return playerScore;
}


string Tournament::getVersus(int index){
    return versus[index];
}

string Tournament::getCorrect(int index){
    return correct[index];
}

string Tournament::getIncorrect(int index){
    return incorrect[index];
}
void Tournament::incrementPlayersUnfamiliarCompanyActions(){
    playersUnfamiliarCompanyActions++;
}
void Tournament::decrementPlayersSwapsRemaining(){
    playersNumSwapsAvailable--;
}

int Tournament::getPlayersUnfamiliarCompanyActions(){
    return playersUnfamiliarCompanyActions;
}

void Tournament::decrementPlayersRollActions(){
    playersRollActions--;
}

int Tournament::getPlayersRollActions(){
    return playersRollActions;
}


void Tournament::decrementPlayersInvestigateActions(){
    playersInvestigateActions--;
}

void Tournament::incrementPlayersInvestigateActions(){
    playersInvestigateActions++;
}

int Tournament::getPlayersInvestigateActions(){
    return playersInvestigateActions;
}

string Tournament::getIntroPicture(int index){
    return introPicture[index];
}

int Tournament::getPlayersSwapsRemaining(){
    return playersNumSwapsAvailable;
}

void Tournament::badLuck(){ // this gets called if Las Vegas Sands or Scientific Games enters the tournament
    roll9ThresholdBest = 9; // makes it harder to get good results/data from a roll
    roll9ThresholdBetter = 8;
    roll9ThresholdGood = 5;
    
    roll6ThresholdBest = 5;
    roll6ThresholdBetter = 3;
}

string Tournament::get9dieResult(int rollValue){
    if (rollValue >= roll9ThresholdBest){
        return "best";
    }
    else if (rollValue >= roll9ThresholdBetter){
        return "better";
    }
    else if (rollValue >= roll9ThresholdGood){
        return "good";
    }
    else {
        return "crap";
    }
}

string Tournament::get6dieResult(int rollValue){
    if (rollValue >= roll6ThresholdBest){
        return "best";
    }
    else if (rollValue >= roll6ThresholdBetter){
        return "better";
    }
    else {
        return "crap";
    }
}
    
void Tournament::lowerThresholdForLVSandSG(){
    thresholdForLVSandSG -= 17; // decrement by 20 for every player roll so that after 7 rolls the probability is guaranteed (since threshold is 140 at first)
}

int Tournament::getThresholdForLVSandSG(){
    return thresholdForLVSandSG;
}