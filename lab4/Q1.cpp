#include <iostream>

using namespace std;

class time{
private:
	int hours;
	int minutes;
	int seconds;
public:
	time(){
		hours=0;
		minutes=0;
		seconds=0;
	}


	void getData(){
		cout << "Enter time in hr:min:sec format:"<<endl;
		cin >>hours ;
		cin >>minutes;
		cin >> seconds;
	}

	void add_time(time t1, time t2){


		hours=t1.hours+t2.hours;
		minutes=t1.minutes+t2.minutes;
		seconds=t1.seconds+t2.seconds;

	}

	void Display24format(){
		if (seconds >= 60 ){
			seconds-=60;
			minutes++;
		}
		if ( minutes >=60)
		{
			minutes-=60;
			hours++;
		}
		if (hours>=24)
		{
			hours-=24;
		}
		cout << "Time is "<<hours<<":"<<minutes<<":"<<seconds<<endl;
	}

	void Display12format(){
		if (seconds >= 60 ){
			seconds-=60;
			minutes++;
		}
		if ( minutes >=60)
		{
			minutes-=60;
			hours++;
		}
		if (hours>=24)
		{
			hours-=24;
		}
		if (hours>=12){
			hours-=12;
			cout<<"Time is "<<hours<<":"<<minutes<<":"<<seconds<<" PM"<<endl;
		}
		else{
		cout<<"Time is "<<hours<<":"<<minutes<<":"<<seconds<<"AM"<<endl;
		}
	}
};

int main(){

	time t1,t2,t3;
	t1.getData();
	t2.getData();
	t3.add_time(t1,t2);
	t3.Display24format();
	t3.Display12format();

	return 0;
}