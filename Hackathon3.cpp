#include <iostream>
#include <string>

using namespace std;

void showMenu();
void hospitalstayMenu(int&);
void surgeryMenu(int&);
void medicineyMenu(int&);
void serviceMenu(int&,int&);
void displayCharge(int, int, int, int, int, int);
void foodMenu(int&);


int main()
{
	int choice, totalHospital = 0 , totalSurgery = 0, totalMedicine = 0, totalServices = 0, numServices=0 , totalFood=0;
	string name;
	long long int id;

	cout << "Patient Name: ";   //User input name
	getline(cin, name);
	cout << "Patient ID Num: ";	//User input Patient ID
	cin >> id;

	do 
	{
		showMenu();
		cin >> choice;

		switch (choice)   		// Informative menu for user
		{
		case 1:
			hospitalstayMenu(totalHospital);  //Menu 1 --> Hospital stay charges function call
			break;
		case 2:
			surgeryMenu(totalSurgery);	//Menu 2 --> Surgery charges function call
			break;
		case 3:
			medicineyMenu(totalMedicine);	//Menu 3 --> Pharmacy charges function call
			break;
		case 4:
			serviceMenu(totalServices, numServices);	//Menu 4 --> Service charges function call
			break;

		case 5:
			 foodMenu(totalFood); //Menu 5 --> Food charges
			 break;
		case 0:
			cout << endl << "Name: " << name << "\nID Num: " << id << endl;
			displayCharge(totalHospital, totalSurgery, totalMedicine, numServices ,totalServices, totalFood);
			break;
		default:
			cout << "Invalid Choice Please Enter Your Choice Again." << endl; //Invalid Input
			break;
		}
	} while (choice != 0);
}

void showMenu()
{
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "\t\t\t\tTYPE OF CHARGE" << endl << endl;
	cout << "1. Hospital Stay Charge\n2. Surgery Charge\n3. Medication Charge\n4. Services Charge\n5. Food Charges\n0. Calculate Total" << endl << endl;
	cout << "Choice: ";
}

//Hospital stay charges menu function
void hospitalstayMenu(int & chargeStay)
{

	int choice1 = 0, day;

	cout << "\t\t\t\tHospital Stay Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	4-Bed Room		$100\n2.	Twin Sharing Room	$125\n3.	Premium Twin Room	$150\n4.	Deluxe Room		$180\n5.	Premium Deluxe Room	$230\n" << endl ;

	do
	{
		cout << "What room have patient take: "; //User input room type
		cin >> choice1;
		cout << "How many day patient stay: ";	//User input number of days spent in hospital
		cin >> day;

		switch (choice1)
		{
		case 1:
			chargeStay += 100 * day;
			break;
		case 2:
			chargeStay += 125 * day;
			break;
		case 3:
			chargeStay += 150 * day;
			break;
		case 4:
			chargeStay += 180 * day;
			break;
		case 5:
			chargeStay += 230 * day;
			break;
		default:
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl << endl;
			break;
		}
	} while (choice1 < 1 || choice1>5);
	cout << endl;
}

//Surgery charges menu function
void surgeryMenu(int& chargeSurgery)
{

	int choice2 = 0;

	cout << "\t\t\t\tSurgery Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	Trauma Surgey		$22445\n2.	Laparoscopic Surgery	$2540\n3.	Colecvectal Surgery	$20683\n4.	Breast Surgery		$6720\n5.	Vascular Surgery	$9000\n6.	Endorine Surgery	$5700" << endl ;

	do
	{
		cout << "What surgery have patient take: "; //User input surgery type
		cin >> choice2;

		switch (choice2)
		{
		case 1:
			chargeSurgery += 22445;
			break;
		case 2:
			chargeSurgery += 2540;
			break;
		case 3:
			chargeSurgery += 20683;
			break;
		case 4:
			chargeSurgery += 6720;
			break;
		case 5:
			chargeSurgery += 9000;
			break;
		case 6:
			chargeSurgery += 5700;
			break;
		default:
			cout <<endl << "Invalid Choice Please Enter Your Choice Again." << endl << endl;
			break;
		} 
	}while (choice2 < 1 || choice2 > 6);
	cout << endl;
}

//Pharmacy charges menu function (at least 5 types of medication)
void medicineyMenu(int& chargeMedicine) 
{

	int choice3 = 0, quantity;

	cout << "\t\t\t\tMedicine Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	Liquid		$29\n2.	Tablet		$15\n3.	Capsules	$20\n4	Injection	$59\n5.	Drop		$5\n6.	Topical		$19" << endl ;

	do
	{
		cout << "What medicine have patient take: "; //User input medicine type
		cin >> choice3;
		cout << " Quantity: ";		//User input quantity of medicine
		cin >> quantity;

		switch (choice3)
		{
		case 1:
			chargeMedicine += 29 * quantity;
			break;
		case 2:
			chargeMedicine += 15 * quantity;
			break;
		case 3:
			chargeMedicine += 20 * quantity;
			break;
		case 4:
			chargeMedicine += 59 * quantity;
			break;
		case 5:
			chargeMedicine += 5 * quantity;
			break;
		case 6:
			chargeMedicine += 19 * quantity;
			break;
		default:
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl ;
			break;
		}
	} while (choice3 < 1 || choice3 > 6);
	cout << endl;
}

//Service charges menu function
void serviceMenu(int& chargeService, int& Services)
{

	int choice4 = 0;

	cout << "\t\t\t\tServices Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	X-ray							$22445\n2.	Unnalysis						$2540\n3.	Lipid Profile						$20683\n4.	Health Screaning Package				$5700\n5.	Activated Partial Thromboplatin(ATPP)			$6720\n6.	Comolete Blood Count and Diffential(CBC and Diff)	$9000" << endl << endl;

	do
	{
		cout << "What service have patient take: "; //User input services taken
		cin >> choice4;

		switch (choice4)
		{
		case 1:
			chargeService += 22445;
			break;
		case 2:
			chargeService += 2540;
			break;
		case 3:
			chargeService += 20683;
			break;
		case 4:
			chargeService += 6720;
			break;
		case 5:
			chargeService += 9000;
			break;
		case 6:
			chargeService += 5700;
			break;
		default:
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl ; //Error output
			break;
		}
	} while (choice4 < 1 || choice4 > 6);
	Services += 1;
	cout << endl;
}

//Food charges
void foodMenu(int& foodService)
{

	int choice6 = 0;

	cout << "\t\t\t\tFood Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	banana			$3\n2.	Cookie			$3\n3.	Apple			$5\n4.	orange Juice		$6\n5.	Roti			$2\n6.	Big Bowl Salad		$9" << endl << endl;

	do
	{
		cout << "What food have patient take: "; //User input food charges
		cin >> choice6;

		switch (choice6)
		{
		case 1:
			foodService += 3;
			break;
		case 2:
			foodService += 3;
			break;
		case 3:
			foodService += 5;
			break;
		case 4:
			foodService+= 6;
			break;
		case 5:
			foodService += 2;
			break;
		case 6:
			foodService += 9;
			break;
		default:
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl ; //Error output
			break;
		}
	} while (choice6 < 1 || choice6 > 6);
	
	cout << endl;
}

//Total charges menu function
void displayCharge(int charge1, int charge2, int charge3, int numServices, int charge4,int charge6) 
{
	if (charge1 > 0)
		cout << "Hostpital Stay Charge + Food Charges: $ " << charge1+charge6 << endl;
	if (charge2 > 0)
		cout << "Surgery Charge: $ " << charge2 << endl;
	if (charge3 > 0)
		cout << "Medicine Charge:" <<numServices<<" Services $" << charge3 << endl;
	if (charge4 > 0)
		cout << "Services Stay Charge: $ " << charge4 << endl;
	cout << "The Total Charge is $ " << charge1 + charge2 + charge3 + charge4 +charge6 << endl; // charges added up and displayed
	
}