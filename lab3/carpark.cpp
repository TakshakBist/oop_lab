#include <iostream>

using namespace std;

class carpark{
private:
	int id;
	int chargePerHour;
	float parkTime;
public:
	carpark(int iden, int cph, float pt){
		id=iden;
		chargePerHour=cph;
		parkTime=pt;
	}
	int totalCharge(){
		return chargePerHour*parkTime;
	}

};

int main(){
	int id, cph;
	float pt;
	cout << "Enter id:" << flush;
	cin >> id;
	cout << "Enter Charge Per Hour:" << flush;
	cin >> cph;
	cout << "Enter Park Time in hours:" << flush;
	cin >> pt;
	carpark t1(id,cph,pt);

	cout << " You have Parked for "<< pt <<" Hours. So your fine is $ "<<t1.totalCharge()<<endl;
	return 0;

}