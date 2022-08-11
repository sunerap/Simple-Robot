#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"SerialPort.h"
#define KEY(c) ( GetAsyncKeyState((int)(c)) & (SHORT)0x8000 )


char output[MAX_DATA_LENGTH];
char input[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

char* port = "\\\\.\\COM3";


int main() {
	short int v1, v2, dist;



	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Connection made" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}
	while (arduino.isConnected()) {

		short int* in1, * in2, * d;
		char* p, * pb, * q, * qb;
		short int FullStop1 = 90;
		short int FullStop2 = 90;

		v1 = FullStop1;
		v2 = FullStop2;

		arduino.readSerialPort(input, 2);
		Sleep(100);

		qb = input;
		q = qb;
		d = (short int*)q;
		dist = *d;

		/*if (dist >= 10) {

			if (KEY(VK_UP)) {
				v1 = 0;
				v2 = 180;
			}
			else if (KEY(VK_DOWN)) {
				v1 = 180;
				v2 = 0;
			}
			else if (KEY(VK_LEFT)) {
				v1 = 0;
				v2 = 0;
			}
			else if (KEY(VK_RIGHT)) {
				v1 = 180;
				v2 = 180;
			}
		}*/
			
		/*else if (dist < 10) {
		v1 = 180;
		v2 = 0;
		cout << "Obstruction" << endl;
		}*/





		if (KEY(VK_UP)) {
			v1 = 0;
			v2 = 180;
		}
		else if (KEY(VK_DOWN)) {
			v1 = 180;
			v2 = 0;
		}
		else if (KEY(VK_LEFT)) {
			v1 = 0;
			v2 = 0;
		}
		else if (KEY(VK_RIGHT)) {
			v1 = 180;
			v2 = 180;
		}

		if (10<dist && dist<25 ) {
			v1 = 0;
			v2 = 180;
		}
		else if (dist < 10) {
			v1 = 180;
			v2 = 180;
		}
		else if (25 <dist && dist< 30 ) {
			v1 = 0;
			v2 = 0;
		}

		pb = output;
		p = pb;

		in1 = (short int*)p;
		*in1 = v1;
		p += sizeof(short int);
		in2 = (short int*)p;
		*in2 = v2;

		arduino.writeSerialPort(output, 4);





		cout << "\nOutput  " << output[0] << "\t" << output[2] << endl;
		cout << "\nInput  " << dist << "\t" << endl;


	}
	return 0;




}