#include<iostream>
using namespace std;

int main(){
	int monthCounter, dayCounter, monthLong; int weekDay = 1;
	cout << "Calendario Año 2023" << endl;
	for (monthCounter = 1; monthCounter <= 12; monthCounter++){
		if (monthCounter == 2){
			monthLong = 28;
		}
		else if (monthCounter == 4 or monthCounter == 6 or monthCounter == 9 or monthCounter == 11){
			monthLong = 30;
		}
		else{
			monthLong = 31;
		}

		cout << endl << "mes: " << monthCounter << endl;

		for(dayCounter = 1; dayCounter <= monthLong; dayCounter++){
			cout << dayCounter << ":" << weekDay << " ";
			if(weekDay < 7){weekDay++;}
			else weekDay = 1;
		};
	};
};


