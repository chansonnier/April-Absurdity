#include <cstdlib>
#include <fstream>
#include <string> 
#include <cctype>
#include <ios>
#include <sstream>
#include <locale>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <vector>
#include "Company.h"
#include "Competitor.h"
#include "Industry.h"
#include "Tournament.h"

using namespace std;

void randomOrderNumbers0thru197array(int arr[], int size){
    // srand((int)time(NULL));
    
    for (int i = 0; i < 197; i++) {
        arr[i] = rand() % 197;
        for (int i2 = 0; i2 < 197; i2++){
            while ((arr[i] == arr[i2]) && (i != i2)){
                arr[i] = rand() % 197;
                i2 = 0;
            }
        }
    }
}

int roll6Die()
{
    // srand((int)time(NULL));
	return rand() % 6 + 1; 
}

int roll9Die()
{
	return rand() % 9 + 1; 
}

int roll100Die()
{
	return rand() % 100 + 1; 
}


int determineWinners(Competitor competitor[], int numCompetitors, int startIndexAt0, string comparisonMetric){
    int j = numCompetitors;
    while (startIndexAt0 < numCompetitors){
        
        
        if (competitor[startIndexAt0].getMetric() > competitor[startIndexAt0+1].getMetric()){   // these first two conditions are general and will work on any metric
            competitor[j] = competitor[startIndexAt0];
        }
        else if (competitor[startIndexAt0].getMetric() < competitor[startIndexAt0+1].getMetric()){                       
            competitor[j] = competitor[startIndexAt0+1];
        }
        // if there's a tie and the metric is CEO to median employee pay ratio
        else if ((competitor[startIndexAt0].getMetric() == competitor[startIndexAt0+1].getMetric()) && (comparisonMetric == "payRatio")){ // inequality metric
            if (competitor[startIndexAt0].getMedianEmplyPayInt() < competitor[startIndexAt0+1].getMedianEmplyPayInt()){   // if there's a tie, use this to break it
                competitor[j] = competitor[startIndexAt0];  // the company with the lower median employee pay is the 'winner'
            }
            else {
                competitor[j] = competitor[startIndexAt0+1];
            }
        }
        // if there's a tie and the metric is revenue
        else if ((competitor[startIndexAt0].getMetric() == competitor[startIndexAt0+1].getMetric()) && (comparisonMetric == "revenue")){ // a company performance metric
            if (competitor[startIndexAt0].getTotalReturnInt() < competitor[startIndexAt0+1].getTotalReturnInt()){   // if there's a tie, use this to break it
                competitor[j] = competitor[startIndexAt0];
            }
            else if (competitor[startIndexAt0].getTotalReturnInt() > competitor[startIndexAt0+1].getTotalReturnInt()){ 
                competitor[j] = competitor[startIndexAt0];
            }
            else if (competitor[startIndexAt0].getTotalReturnInt() == competitor[startIndexAt0+1].getTotalReturnInt()){ // if there is *also* a tie on return as a secondary metric
                if (competitor[startIndexAt0].getPayRatioInt() < competitor[startIndexAt0+1].getPayRatioInt()){   // then use pay ratio to break it (here a lower pay ratio is better/winning)
                    competitor[j] = competitor[startIndexAt0];
                }
                else {
                    competitor[j] = competitor[startIndexAt0+1];
                }
            }
        }
        else if ((competitor[startIndexAt0].getMetric() == competitor[startIndexAt0+1].getMetric()) && (comparisonMetric == "CEOpay")){
            if (competitor[startIndexAt0].getPayRatioInt() > competitor[startIndexAt0+1].getPayRatioInt()){   // if there's a tie, use this to break it      
                competitor[j] = competitor[startIndexAt0];                                                      // then use pay ratio to break it  (here a higher pay ratio is better/winning)
            }
            else {
                competitor[j] = competitor[startIndexAt0+1];
            }
        }
        // competitor[j].printColoredName(); cout << " with a ratio of "; competitor[j].printMetric(); 
        // cout << " won the matchup between "; competitor[startIndexAt0].printColoredName(); 
        // cout << "("; competitor[startIndexAt0].printMetric(); cout << ") and "; competitor[startIndexAt0+1].printColoredName(); 
        // cout << "("; competitor[startIndexAt0+1].printMetric(); cout << ")" << endl;
        
        j++;
        startIndexAt0+=2;
        
    }
        if (startIndexAt0 < j-1){
            determineWinners(competitor, j, startIndexAt0, comparisonMetric);
        }
        else {
            return 0;
        }
}




// prints a table with all the data on each company
void printArray(string arr[], string arr2[], string arr3[], string arr4[], string arr5[], string arr6[], string arr7[],
                string arr8[], string arr9[], string arr10[], string arr11[], int arr12[], int arr13[], int size) { 
                    
    int i = 0; // indexes the items of a given array
    
    cout << left << setw(30) << "Industry" << setw(10) << "Ticker" << setw(39) << "Company Name" << setw(25) 
         << "CEO name" << setw(8) << "'18pay" << setw(12) << "-chg in pay-" << setw(13) << "  '17pay" << setw(9) 
         << "-revnu-" << setw(9) << "return" << setw(12) << "avgEmplPay" << setw(10) << "pay ratio" << setw(14) 
         << "ratioAsDigit" << setw(20) << "EmplPayInteger" << endl; 
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    
    for (i = 0; i < size; i++) // while index is < size of array,
        if (arr[i] != "") {
            cout << left << setw(30) << arr[i] << setw(10) << "(" + arr2[i] + ")" << setw(39) << arr3[i] <<  setw(25) 
                 << arr4[i] << setw(8) << arr5[i] << setw(12) << right << arr6[i] << "   " << left << setw(10) 
                 << arr7[i] << setw(9) << arr8[i] << setw(9) << arr9[i] << setw(10) << right << arr10[i] << setw(10) 
                 << arr11[i] << setw(13) << arr12[i] << setw(17) << arr13[i] << endl;    // print each element
        }
}


// can probably delete this
// void randomMatchupOrder(int arr[], int size){
//     srand((int)time(NULL));
    
//     for (int i = 0; i < 7; i++) {
//         arr[i] = random() % 199 + 1;
//         for (int i2 = 0; i2 < 199; i2++){
//             while ((arr[i] == arr[i2]) && (i != i2)){
//                 arr[i] = random() % 199 + 1;
//                 i2 = 0;
//             }
//         }
//     }
    
// }




int getNYTcompaniesData(string fileName, string industryOfEachCompanyInFile[], string tickerOfEachCompany[], 
                  string eachCompanyName[], string eachCEOname[], string each2018ceoCompensation[], 
                  string CEOpayChange2017to2018[], string each2017ceoCompensation[], 
                  string eachCompany2018revenueInBillions[], string eachCompany2018totalReturn[], 
                  string eachCompanyMedianEmployeePay[], string eachCompanyCEOpayRatio[], int ratioAsDigit[], 
                  int eachCompanyMedianEmployeePayAsDigit[], int lengthOfArr, Competitor competitor[],
                  string eachCompanyNameTruncated[], Industry industries[], string eachPayRatioRank[], 
                  int eachPayRatioRankInt[]){
                      
    ifstream myfile;
    
    int j = 0; // for elements in the array
    bool replaced12 = false;  // the 12th and the 126th companies in the file cannot be used and will be replaced since
    bool replaced126 = false; // the metric by which we'll compare companies is "N.A." in the file for these two
    bool replaced4 = false;     // also replacing one of the Oracles since Oracle had two CEOs at once and a bracket with Oracle vs Oracle might otherwise happen and look like a bug
    //open txt document that cURL creates when given https://www.nytimes.com/interactive/2019/business/highest-paid-ceos-2018.html
    myfile.open(fileName);
    if (myfile.is_open() == false) {
        return -1; // error code
    } 
    else {// that is, myfile.is_open()
        string line = ""; // takes each line from the file
        string word = ""; // takes each word in each line
        // read each line from the file
        while (myfile >> word) { // while new lines can be pulled from the file
            if ((word == "nytg-basic-materials") || (word == "nytg-communication-services") 
            || (word == "nytg-consumer-goods") || (word == "nytg-energy") 
            || (word == "nytg-financial-services") || (word == "nytg-healthcare") 
            || (word == "nytg-industrials") || (word == "nytg-real-estate") || (word == "nytg-technology") 
            || (word == "nytg-utilities")) {            // look first for these tags because they mark the beginning 
                                                        // of each chunk of data for each different company
                if ((replaced4 == false) && (j == 5)){    // if the 12th entry into the array has not yet been replaced once
                    j--;                  // this will allow us to replace company #12 from the file in the array with the next one
                    replaced4 = true;    // since company #12 doesn't have an entry in the file for the comparison metric
                }
                if ((replaced12 == false) && (j == 12)){    // if the 12th entry into the array has not yet been replaced once
                    j--;                  // this will allow us to replace company #12 from the file in the array with the next one
                    replaced12 = true;    // since company #12 doesn't have an entry in the file for the comparison metric
                }
                
                if ((replaced126 == false) && (j == 125)){
                    j--;                   // this will allow us to replace company #126 from the file in the array with the next one
                    replaced126 = true;    // since company #126 doesn't have an entry in the file for the comparison metric
                }
                
                
                industryOfEachCompanyInFile[j] = word; // assign an industry tag to each element in array
                
                getline(myfile, line, '_'); 
                tickerOfEachCompany[j] = line.substr(9, 7); // take the ticker symbol for each company
                
                for (int k = 0; k < 10; k++){ getline(myfile, line); }  //go down several more lines to get the company name
                eachCompanyName[j] = line.substr(32, 50);
                int pos = eachCompanyName[j].find("(");    //delimiting character
                eachCompanyName[j] = eachCompanyName[j].substr(0, pos-1);
                
                if (eachCompanyName[j].length() > 25){
                    eachCompanyNameTruncated[j] = eachCompanyName[j].substr(0, 22) + "...";
                }
                else {
                    eachCompanyNameTruncated[j] = eachCompanyName[j];
                }
                
                for (int k = 0; k < 2; k++){ getline(myfile, line); } //go down a couple more lines to get the CEO name
                eachCEOname[j] = line.substr(3, 50);
                
                for (int k = 0; k < 10; k++){ getline(myfile, line); } //go down several more lines to get the CEOs' 2018 compensations
                each2018ceoCompensation[j] = line.substr(35, 50);
                pos = each2018ceoCompensation[j].find("</");    //delimiting character
                each2018ceoCompensation[j] = each2018ceoCompensation[j].substr(0, pos);
                
                while (line.substr(3, 50) != "<span class=\"nytg-change\">"){ getline(myfile, line); }  // get lines until we have this string
                for (int k = 0; k < 2; k++){ getline(myfile, line); } //now that we have the line that opens the section on change in CEO compensation  
                                                                      //from 2017 to 2018, take a couple more lines because the actual change is below
                if (line.substr(3, 50) != "<span class=\"nytg-na\">N.A.</span>"){  // here's the line with the change in pay
                    CEOpayChange2017to2018[j] = line; 
                }
                else {
                    CEOpayChange2017to2018[j] = "N.A.";  //this means the CEO was a new CEO, and so didn't have a change in pay
                }
                CEOpayChange2017to2018[j] = CEOpayChange2017to2018[j].substr(6, 50);
                if (CEOpayChange2017to2018[j] == "span class=\"nytg-na\">N.A.</span>"){
                    CEOpayChange2017to2018[j] = "N.A.";
                }
                
                while (line.substr(3, 50) != "<span class=\"nytg-year\">2017</span>"){ // now getting 2017 CEO compensation
                    getline(myfile, line); 
                }
                for (int k = 0; k < 2; k++){ getline(myfile, line); }
                each2017ceoCompensation[j] = line.substr(35, 50);
                pos = each2017ceoCompensation[j].find("</");    //delimiting character
                each2017ceoCompensation[j] = each2017ceoCompensation[j].substr(1, pos-1);
                
                while (line.substr(3, 50) != "<span class=\"nytg-performance-revenue\">"){ // now getting revenues
                    getline(myfile, line);
                }
                for (int k = 0; k < 2; k++){ getline(myfile, line); }
                eachCompany2018revenueInBillions[j] = line.substr(5, 5);
                
                while (line.substr(3, 50) != "<span class=\"nytg-performance-return\">"){ // now getting company returns
                    getline(myfile, line);
                }
                for (int k = 0; k < 2; k++){ getline(myfile, line); }
                eachCompany2018totalReturn[j] = line.substr(5, 8);
                
                while (line.substr(3, 50) != "<span class=\"nytg-employee-median-pay\">"){ // now getting median employee pays
                    getline(myfile, line);
                }
                for (int k = 0; k < 2; k++){ getline(myfile, line); }
                eachCompanyMedianEmployeePay[j] = line.substr(5, 8);
                
                while (line.substr(3, 50) != "<span class=\"nytg-ceo-pay-ratio\">"){  // now getting CEO-to-median employee pay ratio
                    getline(myfile, line);
                }
                for (int k = 0; k < 2; k++){ getline(myfile, line); }
                eachCompanyCEOpayRatio[j] = line.substr(5, 10);
                
                bool hasPayRatio = false;
                int index = 0; // now to convert the pay ratio from a string to an integer (dropping the ":1" part of the ratio)
                string tempString = "";
                while (index < eachCompanyCEOpayRatio[j].length()){
                    if (isdigit(eachCompanyCEOpayRatio[j][index])){
                        tempString += eachCompanyCEOpayRatio[j][index];
                        hasPayRatio = true;
                    }
                    index++;
                }
                
                
                tempString = tempString.substr(0, tempString.length() - 1); // to take off the "1" part from the ratio's ":1" 
                if (  ((replaced12 == true) && (j == 11))    ||    ((replaced126 == true) && (j == 124))    ||    ((j != 11) && (j != 124))  ) {  // avoid doing stoi() on "N.A."
                    ratioAsDigit[j] = stoi(tempString);
                }
                
                index = 0;
                tempString = "";
                if (hasPayRatio = true){ // then we know how many lines to go down to get pay ratio rank
                    for (int k = 0; k < 7; k++){ getline(myfile, line); } // go down 7 more lines to get the pay ratio rank
                    eachPayRatioRank[j] = line.substr(38, 5); // take 3 characters from the current line now
                    // pos = eachPayRatioRank[j].find("</");    //delimiting character
                    // eachPayRatioRank[j] = line.substr(0, pos); // now get rid of anything that's not a digit by traversing the string only up to the </ tag
                    while (index < eachPayRatioRank[j].length()){
                        if (isdigit(eachPayRatioRank[j][index])){
                            tempString += eachPayRatioRank[j][index]; // then append that character
                        }
                        index++;
                    }
                    eachPayRatioRank[j] = tempString;
                    if (  ((replaced12 == true) && (j == 11))    ||    ((replaced126 == true) && (j == 124))    ||    ((j != 11) && (j != 124) && (j != 196))  ) {  // avoid doing stoi() on "N.A."
                        eachPayRatioRankInt[j] = stoi(tempString);
                    }
                }
                
                
                index = 0; // now to convert the medianEmployeePay to an integer
                tempString = "";
                while (index < eachCompanyMedianEmployeePay[j].length()){
                    if (isdigit(eachCompanyMedianEmployeePay[j][index])){
                        tempString += eachCompanyMedianEmployeePay[j][index];
                    }
                    index++;
                }
                if (  ((replaced12 == true) && (j == 11))    ||    ((replaced126 == true) && (j == 124))    ||    ((j != 11) && (j != 124))  ) {  // avoid doing stoi() on "N.A."
                    eachCompanyMedianEmployeePayAsDigit[j] = stoi(tempString);
                }
                j++;
            }
        }
        
    //now some necessary corrections (replacing accented/special characters and other problems)
    eachCompanyName[8-1] = "Estee Lauder";           // from Estée Lauder -- the accented é was a problem for alignment via setw()
    eachCompanyName[59-1-1] = "General Motors";        // from General Motors -- unclear what character was problematic
    eachCompanyName[95-1-1] = "Cigna";                 // from Cigna -- unclear what character was problematic
    eachCompanyName[156-2-1] = "McDonald's";           // from McDonald's (the apostrophe was counting as more than the right amount of bytes for setw() to align properly)
    eachCompanyName[158-2-1] = "Exxon Mobil";          // from "Exxon Mobil</div>" (Exxon Mobil did not have a delimiting ticker, i.e., '(XOM)' for the parser to find)
    eachCompanyName[192-2-1] = "McCormick & Co.";      // from McCormick & Co.
    eachCEOname[164-2-1] = "Andre Calantzopoulos";     // from André Calantzopoulos
    eachCEOname[165-2-1] = "Jose E. Almeida";          // from José E. Almeida
    eachCEOname[166-2-1] = "Jean-Jacques Bienaime";    // from Jean-Jacques Bienaimé
    eachCompany2018revenueInBillions[10-1] = "N.A."; // NYT has "N.A." here for Jeffries Financial Group (JEF)
    eachCompany2018totalReturn[5-1] = "N.A.";        // NYT has "N.A." here for T-Mobile
    // eachCompany2018totalReturn[126] = "N.A.";      // NYT has "N.A." here for ADT
    eachCompany2018totalReturn[127-2-1] = "N.A.";      // NYT has "N.A." here for Marsh & McLennan
    eachCompany2018totalReturn[130-2-1] = "N.A.";      // NYT has "N.A." here for Target
    // eachCompanyMedianEmployeePay[12] = "N.A.";     // NYT has "N.A." here for At Home Group
    // eachCompanyMedianEmployeePay[126] = "N.A.";    // NYT has "N.A." here for ADT
    // eachCompanyCEOpayRatio[12] = "N.A.";           // NYT has "N.A." here for At Home Group
    // eachCompanyCEOpayRatio[126] = "N.A.";          // NYT has "N.A." here for ADT
    eachCompanyMedianEmployeePay[42-1-1] = "$42,206";  // rounding up to the next integer value from "$42,205.85" for Omnicom Group
    eachCompanyMedianEmployeePay[7-1] = "$77,181";   // rounding up to the next integer value from "$77,180.84" for PTC 
    eachCompanyNameTruncated[8-1] = "Estee Lauder";  // from Estée Lauder -- the accented é was a problem for alignment via setw()
    eachCompanyNameTruncated[59-1-1] = "General Motors";// from General Motors -- unclear what character was problematic
    eachCompanyNameTruncated[95-1-1] = "Cigna";        // from Cigna -- unclear what character was problematic
    eachCompanyNameTruncated[156-2-1] = "McDonald's";  // from McDonald's (the apostrophe was counting as more than the right amount of bytes for setw() to align properly)
    eachCompanyNameTruncated[192-2-1] = "McCormick & Co.";// from McCormick & Co.
    eachCompanyNameTruncated[158-2-1] = "Exxon Mobil"; // from "Exxon Mobil</div>" (Exxon Mobil did not have a delimiting ticker, i.e., '(XOM)' for the parser to find)
    int counter = 0;  // only for counting how many companies' ratios differ substantially when you calculate them by dividing CEO pay by median employee pay 
    // now to move all the arrays into the Company objects
    for (int i = 0; i < 197; i++){
            competitor[i].setName(eachCompanyName[i]);
            competitor[i].setPayRatio(eachCompanyCEOpayRatio[i]);
            competitor[i].setPayRatioInt(ratioAsDigit[i]);
            competitor[i].setMedianEmplPay(eachCompanyMedianEmployeePay[i]);
            competitor[i].setMedianEmplPayInt(eachCompanyMedianEmployeePayAsDigit[i]);
            competitor[i].setTruncatedName(eachCompanyNameTruncated[i]);
            competitor[i].setIndustry(industryOfEachCompanyInFile[i]);
            competitor[i].useRatioAsMetric();
            competitor[i].setTotalReturn(eachCompany2018totalReturn[i]);
            competitor[i].setTotalReturnInt();
            competitor[i].setCEOpay2018(each2018ceoCompensation[i]);
            competitor[i].setCEOpay2018int();
            competitor[i].setCEOpay2017(each2017ceoCompensation[i]);
            competitor[i].setCEOpay2017int();
            competitor[i].setRevenue(eachCompany2018revenueInBillions[i]);
            competitor[i].setRevenueInt();
            competitor[i].setCEOchangeInComp(CEOpayChange2017to2018[i]);
            competitor[i].setCEOchangeInCompInt();
            competitor[i].setLogo();
            competitor[i].setCeoName(eachCEOname[i]);
            competitor[i].setTicker(tickerOfEachCompany[i]);
            
            if (eachPayRatioRankInt[i] >= 185){
                eachPayRatioRankInt[i] += 1; // bump all the ones at rank 185 and above up by one, so Intercontinental Exchange can fit in where it should be at rank 185
                competitor[i].setPayRatioRank(eachPayRatioRankInt[i]);
            }
            else if (i == 196){
                competitor[i].setPayRatioRank(185);
            }
            else {
                competitor[i].setPayRatioRank(eachPayRatioRankInt[i]);
            }
            
            // cout << setw(39) << competitor[i].getName() << "'s ratio: " << setw(12) << competitor[i].getRatio() << " vs " << (competitor[i].getCEOpay2018int() * 1000000) / competitor[i].getMedianEmplyPayInt()
            // << " as calculated by dividing CEO pay by median employee pay: " << competitor[i].getCEOpay2018int() * 1000000 << " divided by " << competitor[i].getMedianEmplyPayInt() << endl; 
            
            // if (   (abs(  ((competitor[i].getCEOpay2018int() * 1000000) / competitor[i].getMedianEmplyPayInt()) - competitor[i].getPayRatioInt()) ) > 75 ){ // just for seeing how many reported ratios are significantly off from the calculation made by dividing CEO pay by median employee pay
            //     cout << competitor[i].getName() << endl;
            //     counter++;
            // }
    } 
    eachPayRatioRankInt[196] = 185; // NYT has no pay ratio rank for Intercontinental Exchange, despite it having a pay ratio of 105:1, which puts it at rank 185
    eachPayRatioRank[196] = "185"; // string version of the above item
    // cout << "counter: " << counter;
    competitor[0].setCEOpay2017("0");
    competitor[0].setCEOpay2017int(); // Tesla's CEO was paid 0.050 million or $50,000 in 2017 and all other values for 2017 and 2018 are integer values representing a million like 1 or $1 (1 million)
    
    
    // for (int i = 0; i < 197; i++){
    //     competitor[i].printName(); 
    //     cout << " paid their CEO " << competitor[i].getCEOpay2017() << " in 2017 and " << competitor[i].getCEOpay2018() << " in 2018. That's " <<   // values as strings
    //     competitor[i].getCEOpay2017int() << " and " << competitor[i].getCEOpay2018() << endl;                                                       // and now as ints
    // }
    
    for (int i = 0; i < 10; i++){ 
        int idx = 0;
        for (int j = 0; j < 197; j++){ // for each Industry object, go thru all companies and check whether they belong in that industry
            if (competitor[j].getIndustry() == industries[i].getName()){  // if, e.g., Adobe has its industry data member set to "Technology", and the ith industry does as well, then add that company to the Industry object's companies array
                industries[i].addCompanyToArray(competitor[j]);
                idx++;
            }
        }
        // for (int k = 0; k < industries[i].getNumCompanies() ; k++){         // print companies as sorted by industry they belong to
        //     cout << k << "th element of " << industries[i].getName() << "'s array of companies: "; industries[i].printIthCompanyName(k); cout << endl;
        // }
    }
    // for (int i = 0; i < 198; i++){
    //     competitor[i].printAllDataMembers();
    // }
    
    myfile.close();
    return j; // returns the number of integers added to the array
    }
}






void printBracket(Tournament tourney, Competitor competitor[]){

    // string pointRight = "\x1B[31m --->>>  \033[0m"; //  --->>>    "\x1B[31m         \033[0m"    these are without the arrows
    // string pointLeft = "\x1B[31m  <<<--- \033[0m"; //  --->>>     "\x1B[31m         \033[0m"
   
    string offset = "\x1B[33m         \033[0m";
    
    
 //   cout << setw(9+ 119) << "Matchup #1" << endl;
 
    
  // first line / competitors 1 and 9                                       <iomanip> stuff kept over here for an attempt at readability
                                                                            cout << left << setw(9); 
    competitor[0].printMetric(tourney);  // print the ith competitor's metric by which competitors are being compared, if the tournament object's matchup number show's the game is over
                                                                            cout << left << setw(9+ 30); cout << 
    tourney.getColor(0) + competitor[0].getTruncatedName(tourney, 0) + "\033[0m";
                                                                            cout << right << setw(9+ 248); cout << 
    tourney.getColor(8) + competitor[8].getTruncatedName(tourney, 8) + "\033[0m"; 
                                                                            cout << " "; 
    competitor[8].printMetric(tourney); 
                                                                            cout << endl;
  
  
  // second line / 1st and 5th *winners* (located in round 2)
	                                                                        cout << setw(9) << tourney.getArrowToRight(0) << left << setw(32) << "------------------------------" << setw(28 + 9); cout << 
	tourney.getColor(16) + competitor[16].getTruncatedName(tourney, 16) + "\033[0m";
	                                                                        cout << right << setw(9 + 124 + 62); cout << 
	tourney.getColor(20) + competitor[20].getTruncatedName(tourney, 20) + "\033[0m"; 
	                                                                        cout << right << setw(32) << "  ------------------------------" << tourney.getArrowToLeft(4) << endl;
	
	
	// third line / competitors 2 and 10
	                                                                        cout << left << setw(9); 
	competitor[1].printMetric(tourney); 
	                                                                        cout << left << setw(9+ 30);  cout << 
	tourney.getColor(1) + competitor[1].getTruncatedName(tourney, 1) + "\033[0m"; 
	                                                                        cout << setw(31) << "|------------------------------" << 
	                                                                        setw(125 + 62) << right << "------------------------------|" << setw(9+ 30); cout << 
	tourney.getColor(9) + competitor[9].getTruncatedName(tourney, 9) + "\033[0m"; 
	                                                                        cout << right; cout << " "; 
	competitor[9].printMetric(tourney); cout << endl;
	
	                                                                        cout << setw(9) << offset << "------------------------------" << setw(32) << right << "|" << 
	                                                                        setw(93 + 62) << "|" << setw(61) << "------------------------------" << endl; 
	
	
	
	// fifth line / 9th and 11th *winners* (located in round 3)
	                                                                        cout << setw(9) << offset << setw(63 + 7) << tourney.getArrowToRight(8) << right << "| " << setw(9+ 30) << left; cout << 
	tourney.getColor(24) + competitor[24].getTruncatedName(tourney, 24) + "\033[0m"; 
	                                                                        cout << setw(9+ 60 + 62) << right; cout << 
	tourney.getColor(26) + competitor[26].getTruncatedName(tourney, 26) + "\033[0m"; 
	                                                                        cout << " |" << tourney.getArrowToLeft(10) << endl; cout << setw(9) << offset << setw(92) << right 
	                                                                        << "|------------------------------" << setw(63 + 62) << "------------------------------|" << endl;
	
	
	// 7th line / 3rd and 11th competitors, and ultimate winner at the center (i.e., 15th winner)
	                                                                        cout << left << setw(9); 
	competitor[2].printMetric(tourney); 
	                                                                        cout << left << setw(9+ 61); cout << 
	tourney.getColor(2) + competitor[2].getTruncatedName(tourney, 2) + "\033[0m";  
	                                                                        cout << setw(31) << "|" << setw(24) << left << "|" << setw(17) << tourney.getArrowToRight(14) << left << setw(60 + 9); cout << 
	tourney.getColor(30) + competitor[30].getTruncatedName(tourney, 30) + "\033[0m";
	                                                                        cout << setw(31) << "|" << setw(31) << "|" << right << setw(9+ 31); cout << 
	tourney.getColor(10) + competitor[10].getTruncatedName(tourney, 10) + "\033[0m"; 
	                                                                        cout << " "; 
	competitor[10].printMetric(tourney); cout << endl;
	
	
	
	
	
	// 8th line / 2nd and 6th *winners* (located in round 2)
	                                                                        cout << setw(9) << tourney.getArrowToRight(1) << left << setw(32) << "------------------------------" << setw(9+ 29); cout << 
	tourney.getColor(17) + competitor[17].getTruncatedName(tourney, 17) + "\033[0m"; 
	                                                                        cout << "|" << right << setw(32) << "| " << setw(60) << "------------------------------" << 
	                                                                        setw(32) << "|" << setw(31) << "|" << setw(9+ 29); cout << 
	tourney.getColor(21) + competitor[21].getTruncatedName(tourney, 21) + "\033[0m";
	                                                                        cout << "  ------------------------------" << tourney.getArrowToLeft(5) << endl;
	
	
	// 9th line / 4th and 12th competitors
	                                                                        cout << left << setw(9); 
	competitor[3].printMetric(tourney); 
	                                                                        cout << left << setw(9+ 30); cout << 
	tourney.getColor(3) + competitor[3].getTruncatedName(tourney, 3) + "\033[0m";  
	                                                                        cout << setw(32) << "|------------------------------" << right << setw(31) << "|" << setw(31) << "|" << 
	                                                                        setw(31) << "|" << setw(31) << "|" << setw(62) << "------------------------------|" << setw(9+ 30); cout << 
	tourney.getColor(11) + competitor[11].getTruncatedName(tourney, 11) + "\033[0m"; 
	                                                                        cout << " "; 
	competitor[11].printMetric(tourney); 
	                                                                        cout << endl; cout << setw(9) << offset << "------------------------------" << setw(63) << right << "|" << 
	                                                                        setw(31) << "|" << setw(31) << "|" << setw(31) << "|" << setw(92) << "------------------------------" << endl;
	
	
	// 11th line / 13th and 14th *winners* (located in round 4)
	                                                                        cout << setw(9) << offset << setw(94 + 7) << tourney.getArrowToRight(12) << "| " << left << setw(9+ 29); cout << 
	tourney.getColor(28) + competitor[28].getTruncatedName(tourney, 28) + "\033[0m";  
	                                                                        cout << right << "|" << setw(31) << "|" << setw(29 + 9); cout << 
	tourney.getColor(29) + competitor[29].getTruncatedName(tourney, 29) + "\033[0m";  
	                                                                        cout << " |" << tourney.getArrowToLeft(13) << endl;
                                                                            cout << setw(9) << offset << right << setw(93) << "|" << setw(30) << "------------------------------" << 
                                                                            setw(32) << setw(63) << "------------------------------|" << endl;  
  
  
  // 13th line / 5th and 13th competitors
                                                                            cout << left << setw(9); 
    competitor[4].printMetric(tourney); 
                                                                            cout << left << setw(9+ 30); cout << 
    tourney.getColor(4) + competitor[4].getTruncatedName(tourney, 4) + "\033[0m";  
                                                                            cout << right << setw(63) << "|" << setw(31 + 62) << "|" << setw(9+ 92); cout << 
    tourney.getColor(12) + competitor[12].getTruncatedName(tourney, 12) + "\033[0m"; 
                                                                            cout << " "; 
    competitor[12].printMetric(tourney); cout << endl;
  
  
  // 14th line / 3rd and 7th *winners* (located in round 2)
	                                                                        cout << setw(9) << tourney.getArrowToRight(2) << left << setw(32) << "------------------------------" << setw(9+ 30); cout << 
	tourney.getColor(18) + competitor[18].getTruncatedName(tourney, 18) + "\033[0m"; 
	                                                                        cout << right << setw(31) << "|" << setw(31 + 62) << "|" << setw(9+ 60); cout << 
	tourney.getColor(22) + competitor[22].getTruncatedName(tourney, 22) + "\033[0m"; 
	                                                                        cout << right << setw(32) << "  ------------------------------" << tourney.getArrowToLeft(6) << endl;
	
	
	// 15th line / 6th and 14th competitors
	                                                                        cout << left << setw(9); 
	competitor[5].printMetric(tourney); 
	                                                                        cout << left << setw(9+ 30); cout << 
	tourney.getColor(5) + competitor[5].getTruncatedName(tourney, 5) + "\033[0m"; 
	                                                                        cout << setw(31) << "|------------------------------" << right << setw(32) << "|" << setw(31 + 62) << "|" 
	                                                                        << setw(62) << right << "------------------------------|" << setw(9+ 30); cout << 
	tourney.getColor(13) + competitor[13].getTruncatedName(tourney, 13) + "\033[0m"; 
	                                                                        cout << " "; 
	competitor[13].printMetric(tourney); 
	                                                                        cout << endl; cout << setw(9) << offset << "------------------------------" << setw(32) << right << "|" << 
	                                                                        setw(31) << "|" << setw(31 + 62) << "|" << setw(31) << "|" << setw(61) << "------------------------------" << endl; 
	
	
	// 17th line / 10th and 12th *winners* (located in round 3)
	                                                                        cout << setw(9) << offset << setw(63 + 7) << tourney.getArrowToRight(9) << right << "| " << setw(9+ 29) << left; cout << 
	tourney.getColor(25) + competitor[25].getTruncatedName(tourney, 25) + "\033[0m"; 
	                                                                        cout << setw(31) << "|" << right << setw(63) << "|" << setw(9+ 29); cout << 
	tourney.getColor(27) + competitor[27].getTruncatedName(tourney, 27) + "\033[0m"; 
	                                                                        cout << " |" << endl; cout << setw(9) << offset << setw(92) << right << "|------------------------------" 
	                                                                        << setw(63 + 62) << "------------------------------|" << tourney.getArrowToLeft(11) << endl;
	
	
	// 19th line / 7th and 15th competitors
	                                                                        cout << left << setw(9); 
	competitor[6].printMetric(tourney); 
	                                                                        cout << setw(9+ 61); cout << 
	tourney.getColor(6) + competitor[6].getTruncatedName(tourney, 6) + "\033[0m"; 
	                                                                        cout << "|" << right << setw(93 + 62) << "|" << setw(9+ 61); cout << 
	tourney.getColor(14) + competitor[14].getTruncatedName(tourney, 14) + "\033[0m"; 
	                                                                        cout << " "; 
	competitor[14].printMetric(tourney); 
	                                                                        cout << endl;
	
	
	// 20th line / 4th and 8th *winners* (located in round 2)
	                                                                        cout << setw(9) << tourney.getArrowToRight(3) << left << setw(32) << "------------------------------" << setw(9+ 29); cout << 
	tourney.getColor(19) + competitor[19].getTruncatedName(tourney, 19) + "\033[0m"; 
	                                                                        cout << "|" << right << setw(93 + 62) << "|" << setw(9+ 29); cout << 
	tourney.getColor(23) + competitor[23].getTruncatedName(tourney, 23) + "\033[0m"; 
	                                                                        cout << "  ------------------------------" << tourney.getArrowToLeft(7) << endl;
	
	
	// 21st line / 8th and 16th competitors
	                                                                        cout << left << setw(9); 
	competitor[7].printMetric(tourney);                                            cout << setw(9+ 30); cout << 
	tourney.getColor(7) + competitor[7].getTruncatedName(tourney, 7) + "\033[0m"; 
	                                                                        cout << setw(32) << "|------------------------------" << right << 
	                                                                        setw(124 + 62) << "------------------------------|" << setw(9+ 30); cout << 
    tourney.getColor(15) + competitor[15].getTruncatedName(tourney, 15) + "\033[0m"; 
                                                                            cout << " "; 
    competitor[15].printMetric(tourney); 
                                                                            cout << endl; cout << setw(9) << offset << setw(30) << "------------------------------" << 
                                                                            setw(248) << right << "------------------------------" << endl;
  
  
  //don't think I was using this since characters entered in mess this spacing up
  // cout << right << setw(129 + 32) << "|    |    |    |    |    |" << endl;
  
  // this works 
//   cout << right << setw(108 + 32) << "|5..." << std::flush; std::this_thread::sleep_for(std::chrono::seconds(1)); cout << " 4..." << std::flush; usleep(1000000);
//   cout << " 3..." << std::flush; usleep(1000000); cout << " 2..." << std::flush; usleep(1000000); cout << " 1...|" << std::flush; usleep(1000000); cout << endl;
  
  
  //not implemented yet                                [i] investigate companies              
//                                 roll die  [r]     [u]  unfamiliar company 
          
//                                           [f]     [j]
//                                           Gap vs. TJX:
//                                           -----------
//                                           | who wins? |
//                                           ----------- 
//  " << endl;
}




int main(){
    std::srand(std::time(0));
    cout << endl << "Please make your terminal window large if it isn't already, and you may need to zoom out a bit." << endl << endl;
    
    string arr4[197];
    string arrTickers[197];
    string arrCompanies[197];
    string arrCEOs[197];
    string arrCEOs2018comp[197];
    string arrCEOsChangeInCompensation[197];
    string arrCEOs2017comp[197];
    string arrCompany2018revenues[197];
    string arrCompany2018totalReturns[197];
    string arrCompanyMedianEmployeePay[197];
    string arrCEOpayRatios[197];
    string arrCEOpayRatioRanks[197];
    int arrCEOpayRatioRanksInt[197];
    int arrCEOpayRatiosInt[197];
    int arrCompanyMedianEmployeePayInt[197];
    Competitor competitor[197]; 
    string arrCompanyNamesTruncated[197];
    Industry BasicMaterials("Basic Materials");
    Industry CommunicationServices("Communication Services");
    Industry ConsumerGoods("Consumer Goods");
    Industry Energy("Energy");
    Industry FinancialServices("Financial Services");
    Industry Healthcare("Healthcare");
    Industry Industrials("Industrials");
    Industry RealEstate("Real Estate");
    Industry Technology("Technology");
    Industry Utilities("Utilities");
    Industry industries[10] = {BasicMaterials, CommunicationServices, ConsumerGoods, Energy, FinancialServices, Healthcare, Industrials, RealEstate, Technology, Utilities};
    
    
    

    getNYTcompaniesData("NYTdata.txt", arr4, arrTickers, arrCompanies, arrCEOs, arrCEOs2018comp, 
                        arrCEOsChangeInCompensation, arrCEOs2017comp, arrCompany2018revenues, 
                        arrCompany2018totalReturns, arrCompanyMedianEmployeePay, arrCEOpayRatios, 
                        arrCEOpayRatiosInt, arrCompanyMedianEmployeePayInt, 197, competitor,
                        arrCompanyNamesTruncated, industries, arrCEOpayRatioRanks, arrCEOpayRatioRanksInt);
    
    
	
    
    
    
    
    
    
    
    char playAgain;

    Competitor bracketSlots[37]; // we'll fill 16 of these with competitors, 15 will be the winners of those matchups, and the remaining 4 can be substituted in for unfamiliar companies to the player
    int array[197];
    randomOrderNumbers0thru197array(array, 197);
    Tournament tourney;
    Tournament highScoreTourney;
    Competitor highScoreBracketSlots[31];
    int previousHighScore;
    char introChoice;
        // else {// that is, infile1.is_open()
    // else { // still open the high scores file anyway so that a player can be alerted if he or she beats the current high score
        ifstream infile1; 
        infile1.open("highScores.txt"); 
        if (infile1.is_open() == false) {
            return -1; // error code
        } 
            
            //first identify the highest score
            string line1;
            string highestScoreString;
            int highestScore = 0;
            while (infile1 >> line1){
                if (line1 == "Score:"){
                    infile1 >> line1;  // then take the next word into the line1 string
                    string temporaryString;
                    for (int i = 0; i < line1.length(); i++){
                        if (isdigit(line1[i])){
                            temporaryString += line1[i];
                        }
                    }
                    if (stoi(temporaryString) > highestScore){
                        highestScoreString = temporaryString;
                        previousHighScore = stoi(temporaryString);   // we'll save the high score to this var
                    }
                }
            }
            infile1.close(); // we found the highest score in the file
        // }
    // }
    
    
    
    cout << endl << "Skip intro? Enter y/n: ";
    cin >> introChoice;
    while ((introChoice != 'y')  && (introChoice != 'n')){
            
        cout << "Please enter the letter y or the leter n: ";
        cin >> introChoice;
        cout << endl;
        }
    if (introChoice == 'n'){
        cout << endl << "\x1B[33mA LONG TIME AGO IN A GALAXY..\033[0m"; 
        usleep(0000000); cout << endl << "\x1B[33mWell...\033[0m"; 
        usleep(2200000); cout << endl << "\x1B[33mThis one. This galaxy.\033[0m"; 
        usleep(1200000); cout << endl << "\x1B[33mA LONG TIME AGO..\033[0m"; 
        usleep(1200000); cout << endl << "\x1B[33mTHE AVERAGE EMPLOYEE-TO-CEO PAY RATIO IN THE USA WAS AROUND 30-TO-1.\033[0m"; 
        usleep(2200000); cout << endl << "\x1B[33m(Actually, it wasn't all that long ago...)\033[0m"; 
        usleep(5700000); 
        cout << endl;
        usleep(2200000);
        cout << endl << "\x1B[33mANYWAY, THOSE DAYS ARE LONG GONE..." << endl; 
        usleep(2000000); cout << endl << "NOW, IT'S MORE LIKE...\033[0m" << endl; 
        usleep(2000000);
        cout << endl << endl; 
        for (int i = 0; i < 39; i++){
            cout << tourney.getIntroPicture(i) << endl;
        }
        
        usleep(3000000);
        cout << endl << endl << endl << endl << endl << endl << "Wait, what?" << endl; usleep(1000000);
    }
    
    
    
    
    
    
    
    int numCompetitors = 16; // this could be used in cin if we want to allow player to select bracket size, could give them the choice between say 8, 16, or 32 competitors
    
    // creating a selection of random competitors to put into the initial 16 slots of a 16-competitor tournament bracket (leaving out the following competitors)
    int indx3 = 0; // this is used to pass an index from the first for loop to the next
    for (int k = 0; indx3 < 197, k < 16; indx3++){   // only take 16 (index k) elements from the randomized array of competitors, using indx3 to index the 197 of them, and only increment k if a valid one is found
	   // competitor[array[indx3]].useRatioAsMetric();                  
	    if ((competitor[array[indx3]].getIndustry() != "Communication Services") && (competitor[array[indx3]].getName() != "BlackRock") && (competitor[array[indx3]].getName() != "Goldman Sachs") 
	       && (competitor[array[indx3]].getName() != "Scientific Games") && (competitor[array[indx3]].getName() != "Las Vegas Sands")){ // leaving all these out at first because they have 'special effects' if 
            bracketSlots[k] = competitor[array[indx3]];                                                                             // they get randomly substituted in by the player
           	bracketSlots[k].useRatioAsMetric();
           	k++; // k only increments if we find a valid initial competitor (i.e., not one with 'special effects'). 
	    }
    }
    // now go thru again, starting at slot 16 of the array (which gets overwritten by the first competitor anyway) and starting with the indx3 for the 197 possible competitors array, taking any that aren't Scientific Games or Las Vegas Sands
    for (int k = 16; indx3 < 197, k < 35; indx3++){ // now populate the rest of the slots (slots 16 thru 30 will be overwritten by the winners, anyway, but the slots after index 30 (outside the bracket) can be swapped in by the player)
    // 	competitor[array[indx3]].useRatioAsMetric();                  
	    if ((competitor[array[indx3]].getName() != "Scientific Games") && (competitor[array[indx3]].getName() != "Las Vegas Sands")){ // leaving all these out at first because they have 'special effects' if the player's actions 
            bracketSlots[k] = competitor[array[indx3]];                                                                                   //get randomly substituted in by the player  
           	bracketSlots[k].useRatioAsMetric();
           	k++; // only increments when we find a competitor who is NOT Scientific Games nor Las Vegas Sands
	    }
    }
    
    // now we'll put Las Vegas Sands and Scientific Games into slots that can't be randomly drawn from, but where we do know where they are, 
    // so we can adjust the probability that they are subbed in, based on the player's actions throughout the game, and if the probability 
    // threshold is met by a roll of a '100-sided die,' then they get subbed in and we know where to find them
    int indxLVS = 0; // this will index Las Vegas Sands                                                                                     
    int indxSG = 0; // this will index Scientific Games
    for (int i = 0; i < 197; i++){
        if (competitor[i].getName() == "Scientific Games") {
            indxSG = i;
        }
        if (competitor[i].getName() == "Las Vegas Sands") {
            indxLVS = i;
        }
    }
    bracketSlots[35] = competitor[indxLVS]; // put these in particular slots so they can be called into the tournament based on a probability that gets lowered each time the player rolls/'gambles' and attracts them
    bracketSlots[36] = competitor[indxSG];
    
    // prints (all?) of the data in a tabular format just for checking it for weird bugs or whatever
    // printArray(arr4, arrTickers, arrCompanies, arrCEOs, arrCEOs2018comp, arrCEOsChangeInCompensation, 
                // arrCEOs2017comp, arrCompany2018revenues, arrCompany2018totalReturns, arrCompanyMedianEmployeePay, 
                // arrCEOpayRatios, arrCEOpayRatiosInt, arrCompanyMedianEmployeePayInt, 197);
    // cout << endl;
    
    
    string playerChosenMetric = "payRatio";  // this will be a cin thing (but with choices 1, 2, 3, etc. instead of having cin take the string itself)
    tourney.setPlayersChosenMetric(playerChosenMetric);  // set player's choice of metric here ("payRatio", "revenue", "CEOpay")
    
    int idx = 0;
    bool eitherLVSorSGhasSwappedIn = false; // this will stop an if statement below from firing twice, if either Las Vegas Sands or Scientific Games has been swapped in
    bool notSwapping = true;
    int cantInvestigateThisMatchup = -1; // used to hold a matchup number when it can't be investigated and the matchup is reloaded
    determineWinners(bracketSlots, numCompetitors, idx, playerChosenMetric);
    
    // for (int i = 0; i < 35; i++){
    //     cout << i << "th competitor: "; bracketslots[i].printcoloredname();
    //     cout << endl;
    // 
    bool normalBracketFlow = true;
    int itemNotReported;
    for (int i = 0; i < 16; i++){ 
       
        
        while (i < 15){
            char playersInput;
            if (normalBracketFlow == true){    
                cout << endl << endl << endl << endl;
                tourney.setColor(i+16, 'g');  // this makes the current matchup show up highlighted in green
                if (tourney.getMatchupNumber() > 0){
                    usleep(1250000);
                }
                if (tourney.getMatchupNumber() != 14){ // 14 is final matchup for the 0-based matchupNumber Tournament object
                    cout << endl << endl << endl << "                                                                                                                                            Matchup number " << tourney.getMatchupNumber() +1 << endl;
                }
                else {
                    cout << endl << endl << endl << "                                                                                                                                              Final Match" << endl;
                }
                if (notSwapping == true){
                    usleep(2000000);
                }
                else {
                    notSwapping = true; // skip the usleep and reset the flag
                }
                for (int k = 0; k < 30; k++){
                    cout << "                        " << bracketSlots[i*2].getLogo(k) << "                                    " << tourney.getVersus(k) << "                                    " << bracketSlots[i*2+1].getLogo(k) << endl;
                }
                
                cout << endl << right << setw(60) << bracketSlots[i*2].getName() << setw(190) << bracketSlots[i*2+1].getName() << endl; 
                if (bracketSlots[i*2].getIndustry() == bracketSlots[i*2+1].getIndustry()){
                     cout << right << setw(60) << "(" + bracketSlots[i*2].getIndustry() + ")" << setw(115) << "<<<--- same-industry point multiplier in effect! --->>>" << setw(76) << "(" + bracketSlots[i*2+1].getIndustry() + ")" << endl << endl;
                }
                else {
                     cout << right << setw(60) << "(" + bracketSlots[i*2].getIndustry() + ")" << setw(190) << "(" + bracketSlots[i*2+1].getIndustry() + ")" << endl << endl;
                }
                cout << right << setw(60) << "choice [F]" << setw(190) << "choice [J]" << endl << endl;
                    
                printBracket(tourney, bracketSlots);
            }
                cout << endl << "         Swaps [U] remaining: " << tourney.getPlayersSwapsRemaining() << "            Rolls [R] remaining: " << tourney.getPlayersRollActions() << right << setw(221) << "Investigations [I] remaining: " << tourney.getPlayersInvestigateActions() << endl;
                cout << "                                                                                                                 Which one wins? Enter your answer or action (or enter [H] for help): ";
            
            
            
            // cin.ignore(256,' ');
            cin >> playersInput;
            while ((playersInput != 'F') && (playersInput != 'J') && (playersInput != 'U') && (playersInput != 'R') && (playersInput != 'I') && (playersInput != 'Q') && (playersInput != 'H')){
                cout << "You entered " << playersInput << ", which is not a valid input, perhaps because it is not capitalized. Please enter a valid input: "; // require capitalization to minimize inadvertent player choices/keystrokes since I can't figure out how to stop cin from taking everything constantly
                cin >> playersInput;
                cout << endl;
            }
            // " + metric + "
            if (playersInput == 'H'){
                cout << endl << "At every matchup you have \x1B[33mfive options\033[0m: You can enter \x1B[33m[F]\033[0m to select the competitor on the left, \x1B[33m[J]\033[0m to select the competitor on the right, \x1B[33m[U]\033[0m to swap an unfamiliar/undesirable competitor out for a new one (only in the first round!), \x1B[33m[R]\033[0m to roll one of two dice for a chance to reveal" << endl; 
                cout << "a useful bit of information on one or both competitors in the current matchup, or \x1B[33m[I]\033[0m to more thoroughly investigate both competitors in the current matchup and reveal several data points on each. You can also enter \x1B[33m[Q]\033[0m to quit." << endl << endl;
                cout << "In each tournament game you can \x1B[32mroll\033[0m \x1B[33m[R]\033[0m the dice \x1B[32mup to 7\033[0m times, \x1B[32mswap\033[0m \x1B[33m[U]\033[0m out \x1B[32mup to 4\033[0m competitors, and conduct \x1B[32mup to 3 investigations\033[0m \x1B[33m[I]\033[0m. But there additional effects and things to note about these actions." << endl << endl;
                cout << "1) \x1B[33mInvestigations [I]\033[0m: these can reveal very useful information, but your sources can only get you so much information each time, because it is both difficult to gather and difficult not to lose some of the data over the connection you have. You can assume all transmitted info you get" << endl;
                cout << "   in an investigation is, however, accurate and uncorrupted, but there are a handful of instances where the numbers you would like to have aren't derived exactly from the otherwise accurate numbers that may be in front of you..." << endl << endl;
                cout << "2) \x1B[33mUnfamiliar/undesirable competitor swaps [U]\033[0m: Note that your unfamiliar/undesirable competitor swap actions may make you swap in yet another unfamiliar or undesirable competitor... or you may even swap in a competitor that has a \x1B[32mspecial\033[0m \x1B[31meffect\033[0m:" << endl;
                cout << "   - If your luck has you swap in a competitor from the \x1B[32mCommunication Services\033[0m industry (such as \x1B[32mComcast\033[0m or \x1B[32mVerizon\033[0m), you will \x1B[32mupgrade your connection\033[0m and \x1B[32mno longer lose data in transit\033[0m when you conduct an investigation. Unfortunately, there are \x1B[31monly 5 such competitors...\033[0m" << endl << endl;
                cout << "   - If your luck has you swap in \x1B[31mBlackRock\033[0m or \x1B[31mGoldman Sachs\033[0m, then it becomes \x1B[31mmuch harder to conduct investigations\033[0m, since their Aladdin and SecDB software captures most useful information before you or anyone else can get to it." << endl << endl;
                cout << "   - Finally, the more times you roll \x1B[33m[R]\033[0m the dice, the more likely it is that you will attract \x1B[31mScientific Games\033[0m or \x1B[31mLas Vegas Sands\033[0m, and get one of them substituted in at your next swap. If either of these two comes into the tournament, your \x1B[31mluck will be worse\033[0m when rolling the dice." << endl << endl;
                cout << "3) \x1B[33mRolling the dice [R]\033[0m can still be helpful, because it is the only way you can discover a competitor's exact ratio, or even its exact rank as compared to all 196 other possible competitors. Rolling the dice can get you rather useless info, too, but if you find out that a competitor" << endl;
                cout << "   is ranked, say, 5th or 10th or 20th, or 180th or 190th (out of 197), then you will know that that competitor will be winning/losing most or all of its matchups. Rarely, you will even discover both competitors' ranks in a single matchup..." << endl << endl;
                cout << "When playing on All-industries mode, you will earn a 2x point multiplier for any correct matchups that have two competitors from the same general industry. Otherwise, correct answers in round 1 are worth 8 points, correct answers in round two are worth 4 points, round 3 is 2 points," << endl;
                cout << "and the final match is worth 1 point. Thus, the maximum possible score, if every matchup were a same-industry matchup (which is highly improbable), is 170." << endl << endl;
                
                cout << "Enter any key to return to the game, or enter 'b' for background info and sources: ";
                cin >> playersInput;
                if (playersInput == 'b'){
                    cout << endl << "\x1B[33mBackground info and sources:\033[0m" << endl;
                    cout << "In 2010, the Dodd-Frank Wall Street Reform and Consumer Protection Act was passed in the wake of the Great Recession, and section 953(b) of this act requires large public companies to calculate certain new data points annually, including the company's median employee's pay and the" << endl;
                    cout << "  company's 'CEO pay ratio,' and to include this data in their financial disclosures to the SEC--specifically within a form called the DEF 14A, or 'Proxy Statement'. Five years later, in 2015, this requirement was actually implemented by the Securities and Exchange Commission (SEC)," << endl;
                    cout << "  and for calendar-year companies, the first such required disclosure was in 2018, in the 2018 proxy statements for the 2018 annual meetings of shareholders. The data used in this game comes from the following year's disclosures, 2019." << endl << endl;
                    cout << "  These forms are typically due by April 30th every year, although the majority of companies' forms start coming in and are made available online in March (hence, 'March Madness'). This game's data originated in public information calculated and reported by each of the 197 companies" << endl;
                    cout << "  themselves on form DEF 14A, as compiled and reported in May 2019 through a joint effort by The New York Times and Equilar, an executive compensation and corporate governance data firm." << endl << endl;
                    cout << "Writing in The Wall Street Journal, business school professors Bhavya Mohan and Michael I. Norton, of the University of San Francisco and Harvard Business School, respectively, report that the average CEO-to-employee pay ratio \"has soared over the past 40 years to more than 300 to 1" << endl;
                    cout << "  from about 30 to 1.\" They also report that, at the same time, \"Americans believe that the average ratio is 30 to 1, but consider a ratio of just 7 to 1 ideal.\" This shocking disparity between Americans' perception, ideal, and reality is very similar to the disparity Norton and Ariely" << endl;
                    cout << "  had shown years earlier with respect to wealth inequality in America in general, as was visualized in the dramatic graphs of a popular YouTube clip (https://www.youtube.com/watch?v=QPKKQnijnsM)." << endl << endl;
                    cout << "  There must be a good reason for such skyrocketing compensation, we might think, but a week before the business school professors' 2018 piece, The Wall Street Journal's own Vanessa Fuhrmans detailed how \"CEO Pay and Performance Often Don’t Match Up: The S&P 500 CEOs who received the" << endl;
                    cout << "  biggest pay increases scored middling shareholder returns\" in an article under that title and subtitle." << endl << endl;
                    cout << "  Luckily, there to explain how such runaway CEO pay is typically determined is Steven Clifford, writing in The Atlantic, adding: \"I know--for over 20 years, I helped craft some extremely generous executive-compensation packages.\" Rather than go into the details of how or why this" << endl;
                    cout << "  has happened and continues to happen, however, this game merely uses the NYT/Equilar data and generates a random tournament of 16 of some of the biggest public companies by revenue to let the player aim for the high score through solving the question 'Who is the most unequal?'" << endl << endl << endl;
                    cout << "For deeper context/background/interpretations:" << endl << endl;
                    cout << "    Why this issue is extremely important--start here:" << endl << endl;
                    cout << "        'The Spirit Level: Why More Equal Societies Almost Always Do Better'. Richard Wilkinson and Kate Pickett, Bloomsbury Press (2009)." << endl;
                    cout << "        TED Talk by one of the authors, Richard Wilkinson: \"How economic inequality harms societies\" (https://www.youtube.com/watch?v=cZ7LzE3u7Bw)." << endl << endl;
                    cout << "    How did this happen/how did we get here:" << endl << endl;
                    cout << "        on runaway CEO compensation:" << endl;
                    cout << "            \"How Companies Actually Decide What to Pay CEOs: I know—for over 20 years, I helped craft some extremely generous executive-compensation packages.\" - Steven Clifford in The Atlantic (June 2017)" << endl;
                    cout << "        more broadly:" << endl;
                    cout << "            'The Vanishing Middle Class'. Peter Temin, MIT Press (2017)." << endl;
                    cout << "            'A Brief History of Neoliberalism'. David Harvey, Oxford University Press (2007)." << endl;
                    cout << "            'The Nobel Factor: The Prize in Economics, Social Democracy, and the Market Turn'. Avner Offer and Gabriel Soderberg, Princteon University Press (2017)." << endl;
                    cout << "            'Race and the Origins of American Neoliberalism'. Randolph Hohle, Routledge (2015)." << endl;
                    cout << "            'Racecraft: The Soul of Inequality in American Life'. Karen E. Fields and Barbara J. Fields, Verso Books (2014)." << endl;
                    cout << "            'Dog Whistle Politics: How Coded Racial Appeals Have Reinvented Racism and Wrecked the Middle Class'. Ian Haney Lopez, Oxford University Press (2014)." << endl;
                    cout << "                  or his YouTube talk: \"Dog Whistle Politics: Coded Racism and Inequality for All\" - Brown University Center for the Study of Race + Ethnicity in America: https://www.youtube.com/watch?v=H6A3NQiJpH0" << endl << endl << endl;
                    cout << "    Where this has brought us: " << endl << endl;
                    cout << "        'Democracy Incorporated: Managed Democracy and the Specter of Inverted Totalitarianism'. Sheldon Wolin, Princeton University Press (2008)." << endl;
                    cout << "        'Capitalist Realism: Is There No Alternative?'. Mark Fisher, Zero Books (2009)." << endl << endl;
                    cout << "    What might be a solution:" << endl << endl;
                    cout << "        More effective trade unions with higher membership rates; and an end to right-to-work laws with a repeal of the Taft-Hartley Act." << endl;
                    cout << "        'Democracy at Work: A Cure for Capitalism'. Richard D. Wolff, Haymarket Books (2012)." << endl;
                    cout << "        Richard Wolff: \"Democracy at Work: A Cure for Capitalism\" | Talks at Google (https://www.youtube.com/watch?v=ynbgMKclWWc)." << endl << endl;
                    
                    cout << endl << "Enter any key to return to the game: " << endl;
                    cin >> playersInput;
                }
                normalBracketFlow = true;
                i--;
                break;
            }
            
            cout << endl << endl;
            
            while (  ((playersInput == 'U')  && ((tourney.getPlayersUnfamiliarCompanyActions() == 5) || (tourney.getMatchupNumber() > 7)))  // while the player enters a valid action but is out of that move or can't do it anymore
                    ||    ((playersInput == 'R') && (tourney.getPlayersRollActions() == 0))    
                    ||     ((playersInput == 'I') && (tourney.getPlayersInvestigateActions() == 0)) ){
                        
                    cout << "You can't do that anymore! Please enter a valid choice: ";
                    cin >> playersInput;
                    cout << endl;
                    
                    // if player starts entering invalid input now:
                    while ((playersInput != 'F') && (playersInput != 'J') && (playersInput != 'U') && (playersInput != 'R') && (playersInput != 'I') && (playersInput != 'Q')){
                       cout << "You entered " << playersInput << ", which is not a valid input, perhaps because it is not capitalized. Please enter a valid input: ";
                       cin >> playersInput;
                       cout << endl;
                    }
            }
            
            
            if (playersInput == 'I'){  // the 'investigate' choice/action
                itemNotReported = roll6Die(); // a random data point to be left out of the investigation
                bool blackRockOrGoldman = false; 
                for (int i = 0; i < 16; i++){ // checking to see if a communication services industry company is in the tournament, and also if BlackRock or Goldman Sachs is in it
                    if (bracketSlots[i].getIndustry() == "Communication Services"){
                        itemNotReported = 20; // because if it is, then you get a 'connection upgrade' and you will not lose any of the data below in transit during an investigation
                    }
                    if ((bracketSlots[i].getName() == "BlackRock") || (bracketSlots[i].getName() == "Goldman Sachs")){
                        blackRockOrGoldman = true;
                    }
                }
                if (blackRockOrGoldman == true){ // this if statement can still flip this bool back to false for this attempt at an investigation if the rollDie() value was even
                    blackRockOrGoldman = roll6Die() % 2; // if either of these is in the tournament, you have a 50/50 chance that you can't do an investigation at the moment because they got to the data first
                }
                if ((itemNotReported == 20) && (blackRockOrGoldman == false)){ // 20 is working here like a bool to say yes/no there is a Communications Services industry company in this tournament
                    cout << "You've got a communications upgrade! Your investigation data is coming in over a very strong connection..." << endl;
                }
                if ((blackRockOrGoldman == false) && (cantInvestigateThisMatchup != tourney.getMatchupNumber())){
                    cout << "Investigating..." << endl;
                    usleep(1000000);
                    for (int l = 0; l < 2; l++){
                        string companyDataPointArray[6] = {"____________", "____________", "____________", "____________", "____________", "____________"};
                        for (int j = 0; j < 6; j++){
                            if ((j != itemNotReported -1) && (j == 0)){
                                companyDataPointArray[j] = bracketSlots[i*2+l].getName();
                            }
                            if ((j != itemNotReported -1) && (j == 1)){
                                companyDataPointArray[j] = bracketSlots[i*2+l].getCEOpay2018();
                            }
                            if ((j != itemNotReported -1) && (j == 2)){
                                companyDataPointArray[j] = bracketSlots[i*2+l].getCEOchangeInComp();
                            }
                            if ((j != itemNotReported -1) && (j == 3)){
                                companyDataPointArray[j] = bracketSlots[i*2+l].getRevenue();
                            }
                            if ((j != itemNotReported -1) && (j == 4)){
                                companyDataPointArray[j] = bracketSlots[i*2+l].getTotalReturn();
                            }
                            if ((j != itemNotReported -1) && (j == 5)){
                                companyDataPointArray[j] = bracketSlots[i*2+l].getMedianEmplyPay();
                            }
                        }
                        // first format/color code the change in compensation
                        if (companyDataPointArray[2][0] == '+'){ // if positive change in CEO compensation
                            cout << "\x1B[33m" + companyDataPointArray[0] + "\033[0m" << "'s CEO had a compensation of " << "\x1B[32m" + companyDataPointArray[1] + "\033[0m" << " million in 2018, a " << 
                            "\x1B[32m" + companyDataPointArray[2] + "\033[0m" << " change from 2017. ";
                        }
                        else if (companyDataPointArray[2][0] == '-'){ // else if negative change in CEO compensation
                            cout << "\x1B[33m" + companyDataPointArray[0] + "\033[0m" << "'s CEO had a compensation of " << "\x1B[32m" + companyDataPointArray[1] + "\033[0m" << " million in 2018, a " << 
                            "\x1B[31m" + companyDataPointArray[2] + "\033[0m" << " change from 2017. ";
                        }
                        else if (companyDataPointArray[2][0] == 'N'){ // else if new/interim CEO in 2018
                            cout << "\x1B[33m" + companyDataPointArray[0] + "\033[0m" << "'s CEO had a compensation of " << "\x1B[32m" + companyDataPointArray[1] + "\033[0m" << " million in 2018. " << 
                            "The CEO was either new or an interim CEO in 2018 and has no pay data for 2017. ";
                        }
                        else { // else if this is the item left out by the 'investigate' action this time
                            cout << "\x1B[33m" + companyDataPointArray[0] + "\033[0m" << "'s CEO had a compensation of " << "\x1B[32m" + companyDataPointArray[1] + "\033[0m" << " million in 2018, a " << 
                            "\x1B[33m" + companyDataPointArray[2] + "\033[0m" << " change from 2017. ";
                        }
                        
                        // next format the revenue data
                        if (companyDataPointArray[3][0] == 'N'){ // if no revenue data is available
                            cout << "The company has no data on revenue for 2018, generated a ";
                        }
                        else {
                            cout << "The company had " << "\x1B[32m" + companyDataPointArray[3] + "\033[0m" << " billion in revenue in 2018, generated a ";
                        }
                        
                        // lastly, format the total return data
                        if (companyDataPointArray[4][0] == '+'){ // if total return was positive
                            cout << "\x1B[32m" + companyDataPointArray[4] + "\033[0m" << " total return, and paid its median employee " << "\x1B[32m" + companyDataPointArray[5] + "\033[0m" << "." << endl;
                        }
                        else if (companyDataPointArray[4][0] == '-'){ // else if total return was negative
                            cout << "\x1B[31m" + companyDataPointArray[4] + "\033[0m" << " total return, and paid its median employee " << "\x1B[32m" + companyDataPointArray[5] + "\033[0m" << "." << endl;
                        }
                        else if (companyDataPointArray[4][0] == 'N'){ // else if total return was not disclosed
                            cout << "\x1B[33mnon-disclosed\033[0m total return, and paid its median employee " << "\x1B[32m" + companyDataPointArray[5] + "\033[0m" << "." << endl;
                        }
                        else { // if total return is 'hidden'/left out by the 'investigate' action this time
                            cout << "\x1B[33m" + companyDataPointArray[4] + "\033[0m" << " total return, and paid its median employee " << "\x1B[32m" + companyDataPointArray[5] + "\033[0m" << "." << endl;
                        }
                    }
                    cout << endl << "Maybe this information is helpful somehow... " << endl;
                    tourney.decrementPlayersInvestigateActions();
                }
                else { // i.e., BlackRock or Goldman Sachs is in the tournament and the 50/50 chance that you can't do an investigation went the wrong way
                    cout << "Your sources say they can't find any data for you at the moment. Someone or something is gobbling up all the data first. Something about \"Aladdin\" or \"SecDB\".....    ";
                    cantInvestigateThisMatchup = tourney.getMatchupNumber(); // hold this matchup number so a new random number does not allow the player to just try it again upon the reset of the matchup 
                }
                // cout << "Enter any key to continue: ";
                normalBracketFlow = false;
                // cin >> playersInput;
                i--;
                break;
            }
            
            if (playersInput == 'R'){
                normalBracketFlow = false;
                cout << "Which die would you like roll?       The 9-sided die that might get you one or both competitors' overall ranks?          Or the 6-sided die that has a better chance at getting you one of the competitors' pay ratios?          Enter 9 or 6, or c to cancel: ";
                cin >> playersInput;
                while ((playersInput != '9') && (playersInput != '6') && (playersInput != 'c')){
                   cout << "You didn't choose 9 or 6 or cancel. You entered " << playersInput << ", which is not a valid input. Please enter a choice 9 or 6, or c to cancel: ";
                   cin >> playersInput;
                   cout << endl;
                }
                if (playersInput == '9'){
                    cout << "rolling the 9-sided die..." << flush << endl;
                    usleep(1000000);
                    tourney.lowerThresholdForLVSandSG(); // rolling the dice lowers the threshold for Las Vegas Sands or Scientific Games to come into the tournament
                    tourney.decrementPlayersRollActions();
                    int playersRoll = roll9Die();
                    string result = tourney.get9dieResult(playersRoll);
                    if (result == "best"){
                        cout << "You've got great luck! You discovered that " << bracketSlots[i*2].getName() << " is ranked " << "\x1B[32m" + to_string(bracketSlots[i*2].getPayRatioRank()) + "\033[0m" << " overall, and " << bracketSlots[i*2+1].getName() << " is ranked " << "\x1B[32m" + to_string(bracketSlots[i*2+1].getPayRatioRank()) + "\033[0m" << " overall." << endl;
                        // cout << "Enter any key to continue: ";
                        // cin >> playersInput;
                        i--;
                        break;
                    }
                    else if (result == "better"){
                        cout << bracketSlots[i*2+(playersRoll %2)].getName() << " is ranked " << "\x1B[32m" + to_string(bracketSlots[i*2+(playersRoll %2)].getPayRatioRank()) + "\033[0m" << " overall." << endl;
                        // cout << "Enter any key to continue: ";
                        // cin >> playersInput;
                        i--;
                        break;
                    }
                    else if (result == "good"){
                        cout << bracketSlots[i*2+(playersRoll %2)].getName() << " paid their median employee " << bracketSlots[i*2+(playersRoll %2)].getMedianEmplyPay() << " in 2018." << endl;
                        // cout << "Enter any key to continue: ";
                        // cin >> playersInput;
                        i--;
                        break;
                    }
                    else { 
                        cout << "This doesn't seem very helpful... ";
                        if ((playersRoll % 2 == 0) && (bracketSlots[i*2+(playersRoll %2)].getName() != "Jefferies Financial Group")){
                            cout << bracketSlots[i*2+(playersRoll %2)].getName() << " had " << bracketSlots[i*2+(playersRoll %2)].getRevenue() << " billion in revenue in 2018." << endl;
                        }
                        else if ((playersRoll % 2 == 1) && (bracketSlots[i*2+(playersRoll %2)].getName() != "Target") && (bracketSlots[i*2+(playersRoll %2)].getName() != "T-Mobile US") 
                                 && (bracketSlots[i*2+(playersRoll %2)].getName() != "Marsh & McLennan")) {
                            cout << bracketSlots[i*2+(playersRoll %2)].getName() << " generated a " << bracketSlots[i*2+(playersRoll %2)].getTotalReturn() << " total return in 2018." << endl;
                        }
                        else {
                            cout << endl << bracketSlots[i*2+(playersRoll %2)].getName() << "'s CEO is " << bracketSlots[i*2+(playersRoll %2)].getCeoName() << endl; // in case neither case above applies, as in a matchup between Target and Jefferies
                        }
                        // cout << "Enter any key to continue: ";
                        // cin >> playersInput;
                        i--;
                        break;
                    }
                }
                if (playersInput == '6'){
                    cout << "rolling the 6-sided die..." << flush << endl;
                    usleep(1000000);
                    tourney.lowerThresholdForLVSandSG(); // rolling the dice lowers the threshold for Las Vegas Sands or Scientific Games to come into the tournament
                    tourney.decrementPlayersRollActions();
                    int playersRoll = roll6Die();
                    string result = tourney.get6dieResult(playersRoll);
                    if (result == "best"){
                        cout << "You've got great luck! You discovered that " << bracketSlots[i*2].getName() << " has a pay ratio of " << "\x1B[32m" + to_string(bracketSlots[i*2].getPayRatioInt()) + " to 1." + "\033[0m" << endl;
                        // cout << "Enter any key to continue: ";
                        // cin >> playersInput;
                        i--;
                        break;
                    }
                    else if (result == "better"){
                        if (bracketSlots[i*2+(playersRoll %2)].getCEOchangeInComp() != "N.A.") {
                            cout << bracketSlots[i*2+(playersRoll %2)].getCeoName() << ", who is " << bracketSlots[i*2+(playersRoll %2)].getName() << "'s CEO, had a " << bracketSlots[i*2+(playersRoll %2)].getCEOchangeInComp() << " change in compensation in 2018." << endl;
                        }
                        else { // if the CEO was new or interim and didn't have a change in compensation
                            cout << bracketSlots[i*2+(playersRoll %2)].getName() << "'s CEO, " << bracketSlots[i*2+(playersRoll %2)].getCeoName() << ", had a total compensation of " << bracketSlots[i*2+(playersRoll %2)].getCEOpay2018() << " million in 2018." << endl;
                        }
                        // cout << "Enter any key to continue: ";
                        // cin >> playersInput;
                        i--;
                        break;
                    }
                    else if (result == "crap"){
                        cout << "This doesn't seem very helpful... ";
                        if ((playersRoll % 2 == 0) && (bracketSlots[i*2+(playersRoll %2)].getName() != "Jefferies Financial Group")){
                            cout << bracketSlots[i*2+(playersRoll %2)].getName() << " had " << bracketSlots[i*2+(playersRoll %2)].getRevenue() << " billion in revenue in 2018." << endl;
                        }
                        else if ((playersRoll % 2 == 1) && (bracketSlots[i*2+(playersRoll %2)].getName() != "Target") && (bracketSlots[i*2+(playersRoll %2)].getName() != "T-Mobile US")
                                 && (bracketSlots[i*2+(playersRoll %2)].getName() != "Marsh & McLennan")) {
                            cout << bracketSlots[i*2+(playersRoll %2)].getName() << " generated a " << bracketSlots[i*2+(playersRoll %2)].getTotalReturn() << " total return in 2018." << endl;
                        }
                        else {
                            cout << bracketSlots[i*2+(playersRoll %2)].getName() << "'s CEO is " << bracketSlots[i*2+(playersRoll %2)].getCeoName() << endl; // in case neither case above applies, as in a matchup between Target and Jefferies
                        }
                        // cout << "Enter any key to continue: ";
                        // cin >> playersInput;
                        i--;
                        break;
                    }
                }
                else if (playersInput == 'c'){
                    i--; // have to decrement this so we start back at this same matchup with the new competitor swapped in
                    cout << "Canceling roll..." << endl;
                    break;  
                }
            }
            
            
            if (playersInput == 'U'){
                int probabilityOfLVSorSGswap = roll100Die();
                cout << "Enter w to swap out the team on the left, o to swap out the team on the right, or c to cancel: ";
                cin >> playersInput;
                while ((playersInput != 'w') && (playersInput != 'o') && (playersInput != 'c')){
                   cout << "You didn't choose w or o or cancel. You entered " << playersInput << ", which is not a valid input. Please enter a choice w or o, or c to cancel: ";
                   cin >> playersInput;
                   cout << endl;
                }
                if (playersInput == 'w'){
                    if ((probabilityOfLVSorSGswap > tourney.getThresholdForLVSandSG()) && (eitherLVSorSGhasSwappedIn == false)){ // if the random value exceeds the threshold/probability
                        bracketSlots[i*2] = bracketSlots[35+ (probabilityOfLVSorSGswap % 2)];       // swap in either Las Vegas Sands or Scientific Games, and use the random value already generated to pick either +0 or +1 for the index between LVS/SG
                        tourney.incrementPlayersUnfamiliarCompanyActions();  // player has a limited amount and used one of these moves so this is like decrementing them just in the other direction
                        determineWinners(bracketSlots, numCompetitors, idx, playerChosenMetric); // winners of the bracket's matchups have to be recalculated to include the newly-swapped-in competitor
                        
                        i--; // have to decrement this so we start back at this same matchup with the new competitor swapped in
                        tourney.decrementPlayersSwapsRemaining();
                        cout << endl << "Ack! You swapped in " << bracketSlots[35+ (probabilityOfLVSorSGswap % 2)].getName() << "! With them in the tournament, your luck is worse, and you'll need to roll better rolls for the same results." << flush;
                        tourney.badLuck();
                        normalBracketFlow = true;
                        eitherLVSorSGhasSwappedIn = true; // so this condition doesn't fire again, because otherwise the game gets repetitive it's not at least a random entrance of either one or the other but not both
                        usleep(5000000); // just for the player to be able to read the message telling what just happened
                        break; 
                    }
                    else{
                        bracketSlots[i*2] = bracketSlots[30 + tourney.getPlayersUnfamiliarCompanyActions()];       // swap in for the left competitor by taking a competitor from the ith spot after the final winners spot in the array
                        tourney.incrementPlayersUnfamiliarCompanyActions();  // player has a limited amount and used one of these moves so this is like decrementing them just in the other direction
                        determineWinners(bracketSlots, numCompetitors, idx, playerChosenMetric); // winners of the bracket's matchups have to be recalculated to include the newly-swapped-in competitor
                        
                        i--; // have to decrement this so we start back at this same matchup with the new competitor swapped in
                        tourney.decrementPlayersSwapsRemaining();
                        cout << endl << "Swapping...";
                        normalBracketFlow = true;
                        notSwapping = false;
                        usleep(1000000);
                        break; 
                        
                    } 
                }
                
                
                else if (playersInput == 'o'){
                    if ((probabilityOfLVSorSGswap > tourney.getThresholdForLVSandSG()) && (eitherLVSorSGhasSwappedIn == false)){ // if the random value exceeds the threshold/probability, and if one of the two has not already been swapped in
                        bracketSlots[i*2+1] = bracketSlots[35+ (probabilityOfLVSorSGswap % 2)];       // swap in either Las Vegas Sands or Scientific Games
                        tourney.incrementPlayersUnfamiliarCompanyActions();  // player has a limited amount and used one of these moves so this is like decrementing them just in the other direction
                        determineWinners(bracketSlots, numCompetitors, idx, playerChosenMetric); // winners of the bracket's matchups have to be recalculated to include the newly-swapped-in competitor
                        
                        i--; // have to decrement this so we start back at this same matchup with the new competitor swapped in
                        tourney.decrementPlayersSwapsRemaining();
                        cout << endl << "Ack! You swapped in " << bracketSlots[35+ (probabilityOfLVSorSGswap % 2)].getName() << "! With them in the tournament, your luck is worse, and you'll need to roll better rolls for the same results." << flush;
                        tourney.badLuck();
                        normalBracketFlow = true;
                        eitherLVSorSGhasSwappedIn = true; // so this condition doesn't fire again, because otherwise the game gets repetitive it's not at least a random entrance of either one or the other but not both
                        usleep(5000000); // just for the player to be able to read the message telling what just happened
                        break; 
                    }
                    else{
                        bracketSlots[i*2+1] = bracketSlots[30 + tourney.getPlayersUnfamiliarCompanyActions()];       // swap in for the right competitor by taking a competitor from the ith spot after the final winners spot in the array
                        tourney.incrementPlayersUnfamiliarCompanyActions();  // player has a limited amount and used one of these moves so this is like decrementing them just in the other direction
                        determineWinners(bracketSlots, numCompetitors, idx, playerChosenMetric); // winners of the bracket's matchups have to be recalculated to include the newly-swapped-in competitor
                        
                        i--; // have to decrement this so we start back at this same matchup with the new competitor swapped in
                        tourney.decrementPlayersSwapsRemaining();
                        cout << endl << "Swapping...";
                        normalBracketFlow = true;
                        notSwapping = false;
                        usleep(1000000);
                        break;  
                    }
                }
                
                else if (playersInput == 'c'){
                    i--; // have to decrement this so we start back at this same matchup with the new competitor swapped in
                    cout << endl << "Canceling swap..." << endl;
                    normalBracketFlow = false;
                    break;  
                }
            }
            
            
            if (playersInput == 'Q'){
                cout << "Are you sure you want to quit? Enter y/n: ";
                cin >> playersInput;
                while ((playersInput != 'y') && (playersInput != 'n')){
                    cout << "You entered " << playersInput << ", which is not a valid input. Please enter y/n: ";
                    cin >> playersInput;
                    cout << endl;
                }
                if (playersInput == 'y'){
                    cout << "Goodbye!" << endl;
                    return 0;
                }
                else if (playersInput == 'n'){
                    i--;
                    normalBracketFlow = false;
                    break;
                }
                
            }
            
            
            
            if (((bracketSlots[i*2].getPayRatioInt() > bracketSlots[i*2+1].getPayRatioInt()) && (playersInput == 'F')) || ((bracketSlots[i*2].getPayRatioInt() < bracketSlots[i*2+1].getPayRatioInt()) && (playersInput == 'J'))
                // or if there's a tie, player chose the one on the left ('F'), and the one on the left has the lower median employee pay than the one on the right (the tie-breaking condition)
                || ((bracketSlots[i*2].getPayRatioInt() == bracketSlots[i*2+1].getPayRatioInt()) && (playersInput == 'F') && (bracketSlots[i*2].getMedianEmplyPayInt() < bracketSlots[i*2+1].getMedianEmplyPayInt())) 
                // or same thing, a tie, but player chose the one on the right ('J'), and the one on the right has the lower median employee pay 
                ||  ((bracketSlots[i*2].getPayRatioInt() == bracketSlots[i*2+1].getPayRatioInt()) && (playersInput == 'J') && (bracketSlots[i*2].getMedianEmplyPayInt() > bracketSlots[i*2+1].getMedianEmplyPayInt()))){
                    
                    //now determine which one was correct for color coding and potential point multiplier bonus
                if ((bracketSlots[i*2].getPayRatioInt() > bracketSlots[i*2+1].getPayRatioInt()) && (playersInput == 'F')){
                    if (bracketSlots[i*2].getIndustry() == bracketSlots[i*2+1].getIndustry()){
                        tourney.setColor(i*2, 'b'); // Same-Industry Bonus
                    }
                    else {
                        tourney.setColor(i*2, 'c'); // no bonus                              
                    }
                }
                else {
                    if (bracketSlots[i*2].getIndustry() == bracketSlots[i*2+1].getIndustry()){
                        tourney.setColor(i*2+1, 'b'); // Same-Industry Bonus 
                    }
                    else {
                        tourney.setColor(i*2+1, 'c'); // no bonus 
                    }
                }
                normalBracketFlow = true;
                tourney.incrementMatchupNum();
                tourney.setColor(i+16, 'y');                                        
                
                for (int m = 0; m < 30; m++){ // m indexes the elements of the ascii art string array for printing them out
                    cout << "                                                                                                                      " << tourney.getCorrect(m) << endl;
                }
                cout << endl << "                                                                                                                                      T H A T ' S   C O R R E C T !" << endl;
                if (bracketSlots[i*2].getIndustry() == bracketSlots[i*2+1].getIndustry()){
                    cout <<     "                                                                                                                                        + X2 same-industry bonus!" << endl;
                }
                else {
                    cout << endl;
                }
                cout <<         "                                                                                                                                              Your score: " << tourney.getPlayerScore() << endl << endl << endl << endl;
            }
            
            
            else if (((bracketSlots[i*2].getPayRatioInt() < bracketSlots[i*2+1].getPayRatioInt()) && (playersInput == 'F')) || ((bracketSlots[i*2].getPayRatioInt() > bracketSlots[i*2+1].getPayRatioInt()) && (playersInput == 'J'))) {
                for (int m = 0; m < 30; m++){
                    cout << "                                                                                                                         " << tourney.getIncorrect(m) << endl;
                }
                cout << "                                                                                                                                        Better luck next time..." << endl << endl << endl << endl << endl; 
                
                
                if (playersInput == 'F'){
                    tourney.setColor(i*2, 'r');                                        
                }
                else {
                    tourney.setColor(i*2+1, 'r');                                        
                }
                
                normalBracketFlow = true;
                tourney.incrementMatchupNum();
                tourney.setColor(i+16, 'y');                                        
            }
            else {
                i--;
                normalBracketFlow = true;
                break; // reset the matchup
            }
            if (normalBracketFlow == true){
                usleep(1000000);
            }
            i++;
        }
        if (i == 15){ // game over
            cout << "                                                                                                                                    The winner is ... " << flush; usleep(1000000); cout << bracketSlots[30].getName() << endl << endl;
            usleep(1000000);
            for (int j = 0; j < 30; j++){ // print the winner's logo in the center
                cout << "                                                                                                                      " << 
                bracketSlots[30].getLogo(j) << endl;  
            }
            usleep(2000000);
            cout << endl << "                                                                                                                                                "; // just spacing
            bracketSlots[30].printMetric(tourney);
            cout << endl;
            usleep(4000000);
            printBracket(tourney, bracketSlots);
            cout << endl << endl << endl << endl;
            cout << "Game over!" << endl;
            usleep(1000000);
            if (tourney.getPlayerScore() > previousHighScore){
                cout << "You've got the new high score!" << endl;
                usleep(1000000);
            }
            // else {    // ask if want to view the highest scoring bracket? what about if want to play again?
            //     cout << 
            // }
            cout << "Your score is: " << tourney.getPlayerScore() << endl;
            usleep(1000000);
            cout << "Enter a name to record your score under: "; 
            string playersname;
            cin >> playersname;
            cout << "Saving your bracket and score..." << endl;
            
            // open the high scores text file in append mode.
            ofstream outfile;
            outfile.open("highScores.txt", ios::app);
            // write data
            outfile << "Score:" << endl; 
            outfile << tourney.getPlayerScore() << endl;
            outfile << "Chosen metric:" << endl;
            outfile << tourney.getPlayersChosenMetric() << endl;
            outfile << "Player's name:" << endl;
            outfile << playersname << endl << endl;
            
            // save player's bracket to high scores file
            for (int i = 0; i < 31; i++){
                outfile << bracketSlots[i].getName() << endl; // saving each competitor's name at each slot in the bracket
                outfile << tourney.getColor(i) << endl; // saving the colorization data and any scores at each slot
            }
            
            outfile << endl;
        
           // close the opened file.
           outfile.close(); 
           
        }
    }
    cout << "Do you want to view the highest-scoring bracket? (if you didn't just set the new high score yourself!) Enter y/n: ";
    cin >> introChoice;
    while ((introChoice != 'y')  && (introChoice != 'n')){
            
        cout << "Please enter the letter y or the leter n: ";
        cin >> introChoice;
        cout << endl;
        }
    if (introChoice == 'y'){
        cout << "Grabbing high scores..." << endl; 
        ifstream infile1; 
        infile1.open("highScores.txt"); 
        if (infile1.is_open() == false) {
            return -1; // error code
        } 
        else {// that is, infile1.is_open()
            
            //first identify the highest score
            string line1;
            string highestScoreString;
            int highestScore = 0;
            while (infile1 >> line1){
                if (line1 == "Score:"){
                    infile1 >> line1;  // then take the next word into the line1 string
                    string temporaryString;
                    for (int i = 0; i < line1.length(); i++){
                        if (isdigit(line1[i])){
                            temporaryString += line1[i];
                        }
                    }
                    if (stoi(temporaryString) > highestScore){
                        highestScoreString = temporaryString;
                        highestScore = stoi(temporaryString);
                    }
                }
            }
            infile1.close(); // we found the highest score in the file, so we'll close it and open it again to start from the top and print the first player to score that highest score
            
            
            
            infile1.open("highScores.txt"); 
            if (infile1.is_open() == false) {
                return -1; // error code
            } 
            else {// that is, infile1.is_open()
                string line = ""; // takes each line from the file
                // read each line from the file
                while (line != highestScoreString){
                    infile1 >> line;
                }
                bool competitorFound = false;
                for (int i = 0; i < 31; i++){  // for each of the 31 bracket slots on the high score bracket
                if (line == "Chosen metric:"){
                    getline(infile1, line);
                    highScoreTourney.setPlayersChosenMetric(line);
                }
                if (line == "Player's name:"){
                    getline(infile1, line).ignore();
                    highScoreTourney.setPlayerName(line);
                }
                
                    if ((i > 0) && (competitorFound == false)){ // don't increment i if no competitor was found on that line
                        i--;
                    }
                    else {
                        competitorFound = false; // reset the bool for the next go-through
                    }
                    for (int j = 0; j < 197; j++){ // check all competitors'/companies' names for a match
                        if (line == competitor[j].getName()){ // if they match, assign that Competitor object to that bracket slot
                            competitorFound = true; // this will allow index i to increment
                            highScoreBracketSlots[i] = competitor[j];
                            getline(infile1, line); // on the next line is the high-scoring player's choice and points awarded
                            highScoreTourney.setColorWithCode(i, line); // show the player's choice on the bracket by color coding each bracket slot (red = incorrect, green = correct, yellow = default) and appending scores for each
                            if (i % 2 == 0){  // every time i has hit an even number
                                highScoreTourney.incrementMatchupNum(); //increment the matchup number. This will allow ratios to print at the margins of the high score bracket
                            }
                        }
                
                    }
                    getline(infile1, line);
                }
            }
            infile1.close();
        }
        cout << "                                                                                                                      " << highScoreTourney.getPlayerName() << " holds the current high score of " << highScoreTourney.getPlayerScore() << " with this bracket:";
        cout << endl;
        printBracket(highScoreTourney, highScoreBracketSlots);
        cout << endl;
    } 
    else{
        cout << "Goodbye!" << endl;
    }
}



