#include <map>
#include <cmath>
using namespace std;

class Debt  {
private:
    // Initial Variables
    double initial_debt = 0.0;
    double interest = 0.0;
    double months = 0.0;
    double payment = 0.0;
    map<int, double> extraordinary_pays = {};
    double total_extraordinary_pay = 0.0;

    // Current Variables
    double months_paying = 0.0;
    double current_debt = 0.0;
    double current_interest_pay = 0.0;
    double current_debt_pay = 0.0;
    double current_extraordinary_pay = 0.0;

    // Report Variables
    double total_interest_pay = 0.0;
    double total_pay = 0.0;
    double left_extraordinary_pay = 0.0;

    // ------------------ Private Methods ------------------ //
    double getTotalExtraordinaryPay(){
        double total = 0.0;
        for (auto const &pair : this->extraordinary_pays) {
            total += pair.second;
        }
        return total;
    }

    void actualizeCurrentPays(){
        this->current_interest_pay = this->current_debt * this->interest;
        this->current_debt_pay = this->payment - this->current_interest_pay;
        this->current_extraordinary_pay = this->extraordinary_pays[this->months_paying];
    }

    void adjustToMaxPossiblePay(double &pay){
        double abs_difference = abs(this->current_debt - pay);

        if(pay >= this->current_debt or abs_difference < 0.001){
            pay = this->current_debt;
        }
    }

    void payWith(double &pay){
        this->current_debt -= pay;
    }

public:
    // ------------------ Public Methods ------------------ //
    Debt (double initial_debt, double interest, double months, 
          map<int, double> extraordinary_pays){

        // Initial Variables
        this->initial_debt = initial_debt;
        this->interest = interest / 100.0;
        this->months = months;
        this->payment = (this->initial_debt * this->interest) / 
                        (1 - pow(1 + this->interest, -this->months) );
        this->extraordinary_pays = extraordinary_pays; 
        this->total_extraordinary_pay = this->getTotalExtraordinaryPay();

        // Current variables
        this->current_debt = this->initial_debt;
        this->current_interest_pay = 0.0;
        this->current_debt_pay = 0.0;
        this->current_extraordinary_pay = 0.0;
        this->months_paying = 0.0;
        this->total_interest_pay = 0.0;
        this->total_pay = 0.0;
        this->left_extraordinary_pay = this->total_extraordinary_pay;
    }

    void passMonth(){
        if(this->current_debt <= 0){
            return;
        }

        this->months_paying += 1;
        actualizeCurrentPays();
        this->total_interest_pay += this->current_interest_pay;

        adjustToMaxPossiblePay(this->current_debt_pay);
        payWith(this->current_debt_pay);

        adjustToMaxPossiblePay(this->current_extraordinary_pay);
        payWith(this->current_extraordinary_pay);
        this->left_extraordinary_pay -= this->current_extraordinary_pay;

        this->total_pay += this->current_debt_pay + 
                           this->current_extraordinary_pay + 
                           this->current_interest_pay;
    }

    map<string, double> getInitialData(){
        map<string, double> data = {
            {"initial_debt", this->initial_debt},
            {"interest", this->interest},
            {"months", this->months},
            {"payment", this->payment},
            {"total_extraordinary_pays", this->total_extraordinary_pay}
        };

        return data;
    }

    map<string, double> getCurrentMonthData(){
        map<string, double> data = {
            {"months_paying", this->months_paying},
            {"current_debt_paid", this->current_debt_pay},
            {"current_interest_paid", this->current_interest_pay},
            {"current_extraordinary_pay", this->current_extraordinary_pay},
            {"current_debt", this->current_debt},
        };

        return data;
    }

    map<string, double> getReportData(){
        map<string, double> data = {
            {"total_interest_paid", this->total_interest_pay},
            {"total_paid", this->total_pay},
            {"left_extraordinary_pays", this->left_extraordinary_pay},
        };

        return data;
    }

    bool haveDebt(){
        return (this->current_debt > 0) ? true : false;
    }

};
