#include <iostream>
#include <string>

using namespace std;


//creating a data structure for patient
struct Patient
{
	string Name = "",
		   ID = " ";
	int Charge = 0,
		HospitalStay = 0,
		Food = 0,
		Surgery = 0,
		Medication = 0,
		Services = 0,
		numServices = 0;
	
};

// all function prototype
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
	//creating a variable  to hold the size or data structure
	int size, choiceHome;

	cout << "Please Enter The Number of Patient: ";
	cin >> size;

	system("cls");

	//Creating a dynamic allocated Structure array
	Patient* todayPatient = nullptr;
	todayPatient = new Patient[size];

	do
	{
		//calling homemenu function--> display home menu
		HomeMenu();
	
		//enter choice based on home menu
		cin >> choiceHome;
	
		//loop if the input is invalid input
		while (choiceHome < 0 || choiceHome>5)
		{
			//prompt user to enter again the choice
			cout << "Error || Invalid Choice Please Enter Again." << endl;
			cout << "Choice :";
			cin >> choiceHome;
		}

		system("cls");
	
		//doing certain function based on the choice input
		switch (choiceHome)
		{
		case 1:
			//calling keyindata function to key in the patient details and charge
			KeyInData(todayPatient, size);
			break;
		case 2:
			//calling searchpatient function to search for the patient total charge
			SearchPatient(todayPatient, size);
			cout << "\nPlease Enter to Back To Home Menu";
			cin.get();
			system("cls");
			break;
		case 3:
			//calling totalcharge function to display total charge for each catagories and total charge for all patient
			TotalCharge(todayPatient, size);
			cout << "\nPlease Enter to Back To Home Menu";
			cin.get();
			system("cls");
			break;
		case 4:
			//calling lowerheight function to display lowest charge patient and highest charge patient
			LowerHighest(todayPatient, size);
			cout << "\nPlease Enter to Back To Home Menu";
			cin.get();
			system("cls");
			break;
		case 5:
			//checking the data is correct or no
			for (int c = 0; c < size; c++)
			{
				cout << "Name: " << todayPatient[c].Name << endl;
				cout << "ID: " << todayPatient[c].ID << endl << endl;
				cout << "Hospital Stay Charge: " << todayPatient[c].HospitalStay << " $" << endl << endl;
				cout << "Number of Services Taken: " << todayPatient[c].numServices << endl;
				cout << "Services Charge: " << todayPatient[c].Services << " $" << endl << endl;
				cout << "Medicine Charge: " << todayPatient[c].Medication << " $" << endl << endl;
				cout << "Surgery Charge: " << todayPatient[c].Surgery << " $" << endl << endl;
				cout << "Total Charge: " << todayPatient[c].Charge << " $" << endl << endl;
			} 
			cout << "\nPlease Enter to Back To Home Menu";
			cin.get();
			system("cls");
			break;
		case 0:
			exit(0);
			break;
		default:
			//display error message
			cout << "Error|| Invalid Input.";
			break;
			}
	} while (choiceHome != 0);

	//delete the pointer
	delete[] todayPatient;

	//set pointer to nullptr
	todayPatient = nullptr;

	return 0;
}

//duntion defination for HomeMenu Function
void HomeMenu()
{
	//content of home menu
	cout << endl;
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital\n" << endl;
	cout << "1.\tKey In Data" << endl;
	cout << "2.\tSearch for Patient" << endl;
	cout << "3.\tDisplay Total Charge for all patient" << endl;
	cout << "4.\tDisplay Lowest and Highest Charge" << endl;
	cout << "5.\tCheck-out All Patient" << endl;
	cout << "0.\tExit" << endl;
	cout << endl << "Choice : ";
}

//Funtion defination foe KeyInData Function
void KeyInData(Patient* data, int size)
{
	
	int menuChoice;

	for (int c = 0; c < size; c++)
	{	
		cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;
		cout << "\t\t\t\t(Key In Data)" << endl;

		//ignore the input buffer
		cin.ignore();

		//prompt user to enter the details of patient
		cout << "\nPatient(" << c + 1 << ")\n" << endl;
		cout << "Name: ";
		getline(cin, data[c].Name);
		cout << "ID(Number Only): ";
		getline(cin, data[c].ID);
		cout << endl;

		do
		{
			ChargeMenu();//display menu for admin and prompt admin to choose a charge
			cin >> menuChoice;//get choice by admin
			system("cls");

			switch (menuChoice)   		// Informative menu for user
			{
			case 1:
				hospitalstayMenu(data[c].HospitalStay);  //Menu 1 --> Hospital stay charges function call
				system("cls");
				break;
			case 2:
				surgeryMenu(data[c].Surgery);	//Menu 2 --> Surgery charges function call
				system("cls");
				break;
			case 3:
				medicineyMenu(data[c].Medication);	//Menu 3 --> Pharmacy charges function call
				system("cls");
				break;
			case 4:
				serviceMenu(data[c].Services, data[c].numServices);	//Menu 4 --> Service charges function call
				system("cls");
				break;
			case 5:
				foodMenu(data[c].Food); //Menu 5 --> Food charges
				system("cls");
				break;
			case 0:
				data[c].Charge = data[c].HospitalStay + data[c].Surgery + data[c].Medication + data[c].Services + data[c].Food;
				break;
			default:
				cout << "Invalid Choice Please Enter Your Choice Again." << endl; //Invalid Input
				system("cls");
				break;
			}

		} while (menuChoice != 0); //check validation of choice
	}
}

//Funtion defination foe SearchPatient Function
void SearchPatient(Patient* data, int size)
{

	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;
	//create variable for the function
	string search;
	int index;
	bool Founded = false;

	//prompt user to enter the patient name to be search
	cout << "Please Enter Patient Name: ";
	cin.ignore();
	getline(cin,search);
	cout << endl;

	//seach for the patient name
	for ( int i = 0; i < size; i++)
	{
		//set theindex to the current position and set founded to true 
		if (search == data[i].Name)
		{
			Founded = true;
			index = i;
			break;
		}
	}
	
	//display the patient details
	if (Founded)
	{
		cout << "Name: " << data[index].Name << endl;
		cout << "ID: " << data[index].ID << endl << endl;
		cout << "Hospital Charge: " << data[index].HospitalStay << " $" << endl << endl;
		cout << "Number of Services Taken: " << data[index].numServices << endl;
		cout << "Services Charge: " << data[index].Services << " $" << endl << endl;
		cout << "Medicine Charge: " << data[index].Medication << " $" << endl << endl;
		cout << "Surgery Charge: " << data[index].Surgery << " $" << endl << endl;
		cout << "Total Charge: " << data[index].Charge << " $" << endl;
	}
	//Display error message
	else
	{
		cout << "Cant Found The Patient" << endl;
	}

}


//Funtion defination for TotalChrage Function
void TotalCharge(Patient* data, int size)
{
	cin.ignore();

	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;
	//declare and intialize the variable to 0
	int total_Charge = 0,
		total_HospitalCharge = 0,
		total_Surgery = 0,
		total_Medication = 0,
		total_Service = 0,
		average;

	//adding the charge of each catogories for all patient
	for (int c = 0; c < size; c++)
	{
		total_HospitalCharge += data[c].HospitalStay;
		total_Medication += data[c].Medication;
		total_Service += data[c].Services;
		total_Surgery += data[c].Surgery;
	}

	//calculating the total charge for all patient
	total_Charge = total_HospitalCharge + total_Surgery + total_Medication + total_Service;
	average = total_Charge / size;

	
	//display total charge for all patient
	cout << "\nTotal Hospital Charge: " << total_HospitalCharge << " $" << endl;
	cout << "Total Medication Charge: " << total_Medication << " $" << endl;
	cout << "Total Services Charge: " << total_Service << " $" << endl;
	cout << "Total Surgery Charge: " << total_Surgery << " $" << endl ;
	cout << "\nTotal Charge: " << total_Charge << " $" << endl;
	cout << "Average Charge For Each Patient is " << average << " $" << endl;
}


//Funtion defination for LowestHigest Function
void LowerHighest(Patient* data, int size)
{
	cin.ignore();

	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;
	//declare and initialize variable for function
	int low = 99999, high = -999999,
		//function to hold the index at the higest and lowest charge position
		LowIndex, HighIndex;

	//loop to find the lowest and highest price
	for (int i = 0; i < size; i++)
	{
		//checking the charge is lowwe than the current lowest charge if true set the lowindex to the current loop index and change the lowest charge value
		if (data[i].Charge < low) {
			LowIndex = i;
			low = data[i].Charge;
		}
		//checking the charge is higher than the current higest charge if true set the highindex to the current loop index and change the highest charge value
		if (data[i].Charge > high)
		{
			HighIndex = i;
			high = data[i].Charge;
		}
			
	}

	//display the highest and lowest charge patient
	cout << "\nLowest Charge" << endl;
	cout << "-------------\n";
	cout << "Name: " << data[LowIndex].Name << endl;
	cout << "ID: " << data[LowIndex].ID << endl;
	cout << "\nTotal Charge: " << data[LowIndex].Charge << " $" << endl;

	cout << "\nHighest Charge" << endl;
	cout << "-------------\n";
	cout << "Name: " << data[HighIndex].Name << endl;
	cout << "ID: " << data[HighIndex].ID << endl;
	cout << "\nTotal Charge: " << data[HighIndex].Charge << " $" << endl;

}



//Funtion defination for ChargeMenu Function
void ChargeMenu()
{
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl ;

	//display the type of charge in the hospital
	cout << "\t\t\t\tTYPE OF CHARGE" << endl ;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl;

	cout << "1. Hospital Stay Charge\n2. Surgery Charge\n3. Medication Charge\n4. Services Charge\n5. Food Charges\n0. Next" << endl << endl;
	cout << "Choice: ";
}

//Funtion defination for hospitalstayMenu Function
void hospitalstayMenu(int& chargeStay)
{
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;

	//declare and create variable to get choice and day from admin
	int choice1 = 0, day;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl;

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

		//reset the chargeStay due to user might enter the wrong input
		if (chargeStay > 0)
			chargeStay = 0;

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
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;

	//declare and initialize the choice2 to get choice from admin
	int choice2 = 0;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl;

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
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital\n" << endl;

	//declare and initialize the choice3 to get choice from admin
	int choice3 = 0, quantity;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl;

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
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital\n" << endl;

	//declare and initialize the choice4 to get choice from admin
	int choice4 = 0;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl;

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
	cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital\n" << endl;

	//declare and initialize the choice5 to get choice from admin
	int choice5 = 0;

	for (int i = 0; i < 100; i++)
	{
		cout << "-";
	}
	cout << endl;

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