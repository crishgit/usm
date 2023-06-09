#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;


// ------------------ Classes ------------------ //

// ------------------ Functions ------------------ //

class Table {
private:
    // vector_rows[row][column] -> string of that column
    vector< vector<string> > vector_rows = {};
    vector<int> columns_width = {};
    int columns_ammount = 0;
    int columns_separation = 3;
    char columns_separator = '|';
    int rows_ammount = 0;
    bool have_header = true;

    // ------------------ Private Methods ------------------ // 
    void calculateColumnsWidth(){
        this->columns_width = {};

        for(int i = 0; i < this->columns_ammount; i++){
            int max_width = 0;

            for(int j = 0; j < this->rows_ammount; j++){
                int current_width = this->vector_rows[j][i].size();

                if(current_width > max_width){
                    max_width = current_width;
                }
            }

            this->columns_width.push_back(max_width);
        }
    }

    void printRow(int row_index){
        vector<string> row = this->vector_rows[row_index];
        for(int column_i = 0; column_i < this->columns_ammount; column_i++){
            string column = row[column_i];
            int column_width = this->columns_width[column_i];

            cout << setw(column_width + this->columns_separation) 
                 << column << this->columns_separator;
        }

        cout << endl;
    }

    void printHeader(){
        vector<string> header = this->vector_rows[0];
        for(int column_i = 0; column_i < this->columns_ammount; column_i++){
            string current_column = header[column_i];
            int column_width = this->columns_width[column_i];
            int blank_space = column_width + this->columns_separation - current_column.size();

            cout << string(ceil(blank_space / 2.0), ' ') 
                 << current_column
                 << string(floor(blank_space / 2.0), ' ')
                 << this->columns_separator;
        }


        cout << endl;
    }

public:
    Table(int columns_ammount, int columns_separation = 3, 
          char columns_separator = '|', bool have_header = true){

        if(columns_ammount <= 0){
            throw invalid_argument("Columns ammount must be greater than 0");
        }
        if(columns_separation <= 0){
            throw invalid_argument("Columns separation must be greater than 0");
        }

        this->columns_ammount = columns_ammount;
        this->columns_separation = columns_separation;
        this->columns_separator = columns_separator;
        this->have_header = have_header;
    }

    void addRow (vector<string> row){
        if(row.size() != this->columns_ammount){
            throw invalid_argument("Row size must be equal to columns ammount");
        }

        this->vector_rows.push_back(row);
        this->rows_ammount += 1;
    }

    void printTable(){
        this->calculateColumnsWidth();
        int first_row_i = 0;

        if(this->have_header){
            this->printHeader();
            first_row_i = 1;
        }

        for(int row_i = first_row_i; row_i < this->rows_ammount; row_i++){
            this->printRow(row_i);
        }
    }

    vector<int> getColumnWidth(){
        return this->columns_width;
    }
};

string to_string_with_N_decimals(double number, int decimals = 2){
    // flujo de string, el fixed le avisa que es de punto fijo para 
    // los decimales, el setprecision es la cantidad de decimales
    // luego le pasa el número. Devuelve el string del número.
    stringstream ss;
    ss << fixed << setprecision(decimals) << number;
    return ss.str();
}

double secureCinDouble(){
    double number = 0;
    cin >> number;
    cin.clear();
    cin.ignore();

    return number;
}

int main () {
    // Inputs: debt, interest, months, extraordinary pays
    double input_debt = 0.0;
    double input_interest = 0.0;
    double input_months = 0.0;
    map<int, double> input_extraordinary_pays = {};
    string user_adding_extra = "no";

    // User Inputs
    while(input_debt <= 0.0){
        cout << "Ingrese el monto de la deuda: ";
        input_debt = secureCinDouble();
    }

    while(input_interest <= 0.0){
        cout << "Ingrese el interes de la deuda: ";
        input_interest = secureCinDouble();
    }

    while(input_months <= 0.0){
        cout << "Ingrese la cantidad de meses: ";
        input_months = secureCinDouble();
    }

    cout << "\n";
    cout << "Desea agregar un pago extraordinario? (si/no): ";
    cin >> user_adding_extra;

    while(user_adding_extra == "si"){
        double input_extra_month = 0.0;
        double input_extra_ammount = 0.0;

        while(input_extra_month <= 0.0 || input_extra_month > input_months){
            cout << "Ingrese el mes del pago extraordinario: ";
            input_extra_month = secureCinDouble();
        }

        while(input_extra_ammount <= 0.0){
            cout << "Ingrese el monto del pago extraordinario: ";
            input_extra_ammount = secureCinDouble();
        }

        input_extraordinary_pays[input_extra_month] += input_extra_ammount;

        cout << "\n";
        cout << "Desea agregar otro pago extraordinario? (si/no): ";
        cin >> user_adding_extra; 
        cin.clear();
        cin.ignore();
    }

    // Table Setting
    Debt user_debt(input_debt, input_interest, input_months, input_extraordinary_pays);
    Table table_debt(7, 2);

    vector<string> header_debt_table = {"Mes", "Deuda Pagada", "Interes Pagado", "Deuda", 
                          "Pago Extra", "Interes Total", 
                          "Total Pagado"};
    table_debt.addRow(header_debt_table);

    while(user_debt.haveDebt() ){
        user_debt.passMonth();
        map<string, double> current_month_data = user_debt.getCurrentMonthData();
        map<string, double> report_data = user_debt.getReportData();

        table_debt.addRow(
            {
                "Mes "+ to_string_with_N_decimals( current_month_data["months_paying"], 0), 
                to_string_with_N_decimals( current_month_data["current_debt_paid"] ),
                to_string_with_N_decimals( current_month_data["current_interest_paid"] ),
                to_string_with_N_decimals( current_month_data["current_debt"] ),
                to_string_with_N_decimals( current_month_data["current_extraordinary_pay"] ),
                to_string_with_N_decimals( report_data["total_interest_paid"] ),
                to_string_with_N_decimals( report_data["total_paid"] ),
            }
        );
    }
    
    // Printing Table Start
    system("cls");
    cout << "Corrida de pagos de una deuda de " << input_debt << "$, con un interes de " 
         << input_interest << "%, en " << input_months << " meses."; 
    if(input_extraordinary_pays.size() > 0){
        cout << " Con pagos extraordinarios.";
    }
    cout << "\n\n";

    table_debt.printTable();
    cout << "\n";
    // Printing Table End

    // Printing Report
    map<string, double> debt_report_data = user_debt.getReportData();
    map<string, double> debt_current_data = user_debt.getCurrentMonthData();

    cout << "Reporte de Pago:";

    cout << "En el plazo de " << debt_current_data["months_paying"] << " meses (de " 
         << input_months << " meses), se pagaron "
         << to_string_with_N_decimals(debt_report_data["total_paid"]) 
         << "$, de los cuales " 
         << to_string_with_N_decimals(debt_report_data["total_interest_paid"]) 
         << "$ fueron de intereses."
         << "\n";

    cout << "Se paga un " << to_string_with_N_decimals(debt_report_data["total_paid"] / input_debt * 100) 
         << "% de la deuda inicial, y el " 
         << to_string_with_N_decimals(debt_report_data["total_interest_paid"] / debt_report_data["total_paid"] * 100) 
         << "% del pago son intereses.\n";

    // extraordinary pays report
    // the left 
    if(debt_report_data["left_extraordinary_pays"] > 0){
        cout << "Quedaron " << to_string_with_N_decimals(debt_report_data["left_extraordinary_pays"]) 
             << "$ de pagos extraordinarios sin usar.\n";
    }
    else{
        cout << "Se usaron todos los pagos extraordinarios.\n";
    }


    return 0;
}

















