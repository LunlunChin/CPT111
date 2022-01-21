#include <iostream>
#include <string>

using namespace std;

struct Patient
{
	string Name = "";
	long long int ID = 0;
	int Charge = 0,
		HospitalStay = 0,
		Food = 0,
		Surgery = 0,
		Medication = 0,
		Services = 0,
		numServices = 0;
	
};

void HomeMenu();

void KeyInData(Patient*, int);
void SearchPatient(Patient*, int);
void TotalCharge(Patient*, int);
void LowerHighest(Patient*, int);

void ChargeMenu();
void hospitalstayMenu(int&);
void surgeryMenu(int&);
void medicineyMenu(int&);
void serviceMenu(int&, int&);
void foodMenu(int&);


int main()
{
	int size;

	cout << "Please Enter The Number of Patient: ";
	cin >> size;

	Patient* todayPatient = nullptr;
	todayPatient = new Patient[size];

	
	for (int c = 0; c < size; c++)
	{
		cout << todayPatient[c].Name << endl;
		cout << todayPatient[c].ID << endl;
		cout << todayPatient[c].HospitalStay << endl;
		cout << todayPatient[c].Charge << endl;
		cout << todayPatient[c].Food << endl;
		cout << todayPatient[c].Services << endl;
		cout << todayPatient[c].Surgery << endl;
		cout << todayPatient[c].Medication << endl;
		cout << todayPatient[c].numServices << endl;
	}

	int choiceHome;

	HomeMenu();

	cin >> choiceHome;
	while (choiceHome < 0 || choiceHome>4)
	{
		cout << "Error || Invalid Choice Please Enter Again." << endl;
		cout << "Choice :";
		cin >> choiceHome;
	}

	switch (choiceHome)
	{
	case 1:
		KeyInData(todayPatient, size);
		
		
	case 2:
		SearchPatient(todayPatient, size);
	case 3:
		TotalCharge(todayPatient, size);
	case 4:
		LowerHighest(todayPatient, size);
	case 0:
		for (int c = 0; c < size; c++)
		{
		cout << todayPatient[c].Name << endl;
		cout << todayPatient[c].ID << endl;
		cout << todayPatient[c].HospitalStay << endl;
		cout << todayPatient[c].Charge << endl;
		cout << todayPatient[c].Food << endl;
		cout << todayPatient[c].Services << endl;
		cout << todayPatient[c].Surgery << endl;
		cout << todayPatient[c].Medication << endl;
		cout << todayPatient[c].numServices << endl;
		}
		exit(0);
	default:
		cout << "Error|| Invalid Input.";
		break;
	}


	delete[] todayPatient;
	todayPatient = nullptr;

	return 0;
}

void HomeMenu()
{
	cout << endl;
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital\n" << endl;
	cout << "1.\tKey In Data" << endl;
	cout << "2.\tSeach for Patient" << endl;
	cout << "3.\tDisplay Total Charge for all patient" << endl;
	cout << "4.\tDisplay Lowest and Highest Charge" << endl;
	cout << "0.\tExit" << endl;
	cout << endl << "Choice : ";
}

void KeyInData(Patient* data, int size)
{
	int menuChoice;

	for (int c = 0; c < size; c++)
	{
		cin.ignore();
		cout << "\nPatient(" << c + 1 << ")\n" << endl;
		cout << "Name: ";
		getline(cin, data[c].Name);
		cout << "ID(yymmdd ";
		cin >> data[c].ID;
		do
		{

			ChargeMenu();//display menu for admin and prompt admin to choose a charge
			cin >> menuChoice;//get choice by admin

			switch (menuChoice)   		// Informative menu for user
			{
			case 1:
				hospitalstayMenu(data[c].HospitalStay);  //Menu 1 --> Hospital stay charges function call
				break;
			case 2:
				surgeryMenu(data[c].Surgery);	//Menu 2 --> Surgery charges function call
				break;
			case 3:
				medicineyMenu(data[c].Medication);	//Menu 3 --> Pharmacy charges function call
				break;
			case 4:
				serviceMenu(data[c].Services, data[c].numServices);	//Menu 4 --> Service charges function call
				break;
			case 5:
				foodMenu(data[c].Food); //Menu 5 --> Food charges
				break;
			case 0:
				data[c].Charge = data[c].HospitalStay + data[c].Surgery + data[c].Medication + data[c].Services + data[c].Food;
				break;
			default:
				cout << "Invalid Choice Please Enter Your Choice Again." << endl; //Invalid Input
				break;
			}

		} while (menuChoice != 0); //check validation of choice
	}
}

void SearchPatient(Patient* data, int size)
{
	string search;
	int index;
	bool Founded = false;

	cout << "Please Enter Patient Name(E to exit): ";
	cin.ignore();
	getline(cin,search);

	for ( int i = 0; i < size; i++)
	{
		if (search == data[i].Name)
		{
			Founded = true;
			index = i;
		}
	}
	
	if (Founded)
	{
		cout << "Name: " << data[index].Name << endl;
		cout << "ID: " << data[index].ID << endl;
		cout << "Hospital Charge: " << data[index].HospitalStay << "$" << endl;
		cout << "Number of Services Taken: " << data[index].numServices << "$" << endl;
		cout << "Services Charge: " << data[index].Services << "$" << endl;
		cout << "Medicine Charge: " << data[index].Medication << "$" << endl;
		cout << "Surgery Charge: " << data[index].Surgery << "$" << endl;
		cout << "Total Charge: " << data[index].Charge << "$" << endl;
	}
	else
	{
		cout << "Cant Found The Patient" << endl;
	}

}

void TotalCharge(Patient* data, int size)
{
	int total_Charge = 0,
		total_HospitalCharge = 0,
		total_Surgery = 0,
		total_Medication = 0,
		total_Service = 0;

	for (int c = 0; c < size; c++)
	{
		total_HospitalCharge += data[c].HospitalStay;
		total_Medication += data[c].Medication;
		total_Service += data[c].Services;
		total_Surgery += data[c].Surgery;
	}

	total_Charge = total_HospitalCharge + total_Surgery + total_Medication + total_Service;

	cout << "Total Hospital Charge: " << total_HospitalCharge << endl;
	cout << "Total Medication Charge: " << total_Medication << endl;
	cout << "Total Services Charge: " << total_Service << endl;
	cout << "Total Surgery Charge: " << total_Surgery << endl;
	cout << "Total Charge: " << total_Charge << endl;
}

void LowerHighest(Patient* data, int size)
{
	int low = 99999, high = -999999,
		LowIndex, HighIndex;
	for (int i = 0; i < size; i++)
	{
		if (data[i].Charge < low)
			LowIndex = i;
		if (data[i].Charge > high)
			HighIndex = i;
	}

	cout << "\n\nLowest Charge" << endl;
	cout << "Name: " << data[LowIndex].Name << endl;
	cout << "ID: " << data[LowIndex].ID << endl;
	cout << "Total Charge: " << data[LowIndex].Charge << "$" << endl;

	cout << "\n\nHighest Charge" << endl;
	cout << "Name: " << data[HighIndex].Name << endl;
	cout << "ID: " << data[HighIndex].ID << endl;
	cout << "Total Charge: " << data[HighIndex].Charge << "$" << endl;


}

void ChargeMenu()
{
	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "\t\t\t\tTYPE OF CHARGE" << endl << endl;
	cout << "1. Hospital Stay Charge\n2. Surgery Charge\n3. Medication Charge\n4. Services Charge\n5. Food Charges\n0. Next" << endl << endl;
	cout << "Choice: ";
}

void hospitalstayMenu(int& chargeStay)
{

	//declare and create variable to get choice and day from admin
	int choice1 = 0, day;

	//Display type of room for hospital
	cout << "\t\t\t\tHospital Stay Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	4-Bed Room		$100\n2.	Twin Sharing Room	$125\n3.	Premium Twin Room	$150\n4.	Deluxe Room		$180\n5.	Premium Deluxe Room	$230\n" << endl;

	//loop while user input invalid choice
	do
	{
		cout << "What room have patient take: "; //User input room type
		cin >> choice1;
		cout << "How many day patient stay: ";	//User input number of days spent in hospital
		cin >> day;

		//add the price based on the room and day enter by user to chargeStay
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
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl << endl; //Inform admin invalid input 
			break;
		}
	} while (choice1 < 1 || choice1>5);//check validation of the choice1
	cout << endl;
}

//Function defination Surgery charges menu function
void surgeryMenu(int& chargeSurgery)
{
	//declare and initialize the choice2 to get choice from admin
	int choice2 = 0;

	//Display Surgery menu
	cout << "\t\t\t\tSurgery Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	Trauma Surgey		$22445\n2.	Laparoscopic Surgery	$2540\n3.	Colecvectal Surgery	$20683\n4.	Breast Surgery		$6720\n5.	Vascular Surgery	$9000\n6.	Endorine Surgery	$5700" << endl << endl;

	//loop while user input invalid choice
	do
	{
		cout << "What surgery have patient take: "; //User input surgery type
		cin >> choice2;

		//add the price of the surgery selected by admin to chargeSurgery
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
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl << endl; //Inform admin invalid input 
			break;
		}
	} while (choice2 < 1 || choice2 > 6);//check validation of the choice2
	cout << endl;
}


//Function defination Pharmacy charges menu function (at least 5 types of medication)
void medicineyMenu(int& chargeMedicine)
{
	//declare and initialize the choice3 to get choice from admin
	int choice3 = 0, quantity;

	//Display medicine menu
	cout << "\t\t\t\tMedicine Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	Liquid		$29\n2.	Tablet		$15\n3.	Capsules	$20\n4	Injection	$59\n5.	Drop		$5\n6.	Topical		$19" << endl << endl;

	//loop while user input invalid choice
	do
	{
		cout << "What medicine have patient take: "; //User input medicine type
		cin >> choice3;
		cout << " Quantity: ";		//User input quantity of medicine
		cin >> quantity;

		//add medicne price to chargeMedicene based on type of medicine and qunatity enter by admin
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
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl;
			break;
		}
	} while (choice3 < 1 || choice3 > 6);//check validation of the choice3
	cout << endl;
}

//serviceMenu Function defination  
void serviceMenu(int& chargeService, int& Services)
{
	//declare and initialize the choice4 to get choice from admin
	int choice4 = 0;

	//display services menu
	cout << "\t\t\t\tServices Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	X-ray							$22445\n2.	Unnalysis						$2540\n3.	Lipid Profile						$20683\n4.	Health Screaning Package				$5700\n5.	Activated Partial Thromboplatin(ATPP)			$6720\n6.	Comolete Blood Count and Diffential(CBC and Diff)	$9000" << endl << endl;

	//loop while user input invalid choice
	do
	{
		cout << "What service have patient take: "; //User input services taken
		cin >> choice4;

		//add services price to chargeServices based on choice entered by admin
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
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl; //Error output
			break;
		}
	} while (choice4 < 1 || choice4 > 6);//check validation of the choice4
	Services += 1;
	cout << endl;
}

//foodmenu Function defination 
void foodMenu(int& foodService)
{
	//declare and initialize the choice5 to get choice from admin
	int choice5 = 0;

	cout << "\t\t\t\tFood Charge " << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl << endl;

	cout << "1.	banana			$3\n2.	Cookie			$3\n3.	Apple			$5\n4.	orange Juice		$6\n5.	Roti			$2\n6.	Big Bowl Salad		$9" << endl << endl;

	//loop while user input invalid choice
	do
	{
		cout << "What food have patient take: "; //User input food charges
		cin >> choice5;

		//add food price to foodServices based on choice entered by admin
		switch (choice5)
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
			foodService += 6;
			break;
		case 5:
			foodService += 2;
			break;
		case 6:
			foodService += 9;
			break;
		default:
			cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl; //Error output
			break;
		}
	} while (choice5 < 1 || choice5 > 6);//check validation of the choice5

	cout << endl;
}