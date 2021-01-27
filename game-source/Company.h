#ifndef COMPANY_H
#define COMPANY_H

#include <string>
using namespace std;

class Company {
    // functions associated with Competitor
    public:
        Company(); // default constructor
    
        void setName(string input);
        string getName();
        void printName();
    
        void setMedianEmplPayInt(int pay);
        int getMedianEmplyPayInt();
        
        void setPayRatio(string input);
        string getRatio();
        void printRatio();
        
        void setPayRatioInt(int ratio);
        int getPayRatioInt();
        
        void setIndustry(string input);
        string getIndustry();
        
        
        void setMedianEmplPay(string pay);
        string getMedianEmplyPay();
        
        void setTotalReturn(string input);
        void setTotalReturnInt();
        int getTotalReturnInt();
        string getTotalReturn();
        
        void setCEOpay2018(string pay);
        void setCEOpay2017(string pay);
        void setCEOpay2018int();
        void setCEOpay2017int();
        string getCEOpay2018();
        string getCEOpay2017();
        int getCEOpay2017int();
        int getCEOpay2018int();
        
        void setRevenue(string input);
        void setRevenueInt();
        string getRevenue();
        int getRevenueInt();
        
        void setCEOchangeInComp(string input);
        void setCEOchangeInCompInt();
        string getCEOchangeInComp();
        int getCEOchangeInCompInt();
        
        void printAllDataMembers();
        void setLogo();
        string getLogo(int logoLineIndex);
        
        void setCeoName(string input);
        string getCeoName();
        
        void setTicker(string input);
        string getTicker();
    
        
    private: 
        
        string industry;
       
        string ticker;
    
        string name;
    
        string ceoName;
    
        string ceoPay2018;
    
        string ceoChangeInComp;
    
        string ceoPay2017;
    
        string revenue;
    
        string totalReturn;
    
        string medianEmplPay;
    
        string payRatio;
        
        string logo[30];
        
    
        int payRatioInt;
    
        int medianEmplPayInt;
        
        int totalReturnInt;
        
        int ceoPay2017int;
        
        int ceoPay2018int;
        
        int revenueInt;
        
        int ceoChangeInCompInt;
        
        
};

#endif