#include <iostream>
#include <string>

using namespace std;


//Prototype for showMenu, hospitalstayMenu, surgeryMenu, medicineMenu, servicesMenu, displayCharge, foodMenu
void showMenu();
void hospitalstayMenu(int&);
void surgeryMenu(int&);
void medicineyMenu(int&);
void serviceMenu(int&, int&);
void foodMenu(int&);
void displayCharge(int, int, int, int, int, int,int);
void reset(int&, int&, int&, int&, int&, int&);
void displayDayCharge(string [], int [], int [],int [],int [],int [],int [],int []);



int dayTotalHospital[5];
int dayTotalSurgery[5];
int dayTotalMedicine[5];
int dayTotalServices[5];
int dayTotalFood[5];
int dayTotal[5];

string patientName[5];
int patientID[5];

int main(){
    
    int totalHospital, totalSurgery, totalMedicine, totalServices, numServices, totalFood;//Declare and initialize variable to hold some charge 
	string name; 		//name to hold name of patient
	long long int id;  //id to hold patient id number
	char pass = 'Y';
	
int i=0;
    while (pass == 'Y' || pass == 'y'){
		//reset value for some variable
		
		reset(totalHospital, totalSurgery, totalMedicine, totalServices, numServices, totalFood);
		int choice=1;
		cout << "Patient Name: ";   //User input name
		getline(cin, name);
		patientName[i]=name;

		cout << "Patient ID Num: ";	//User input Patient ID
		cin >> id;
		patientID[i]=id;

		 while (choice != 0){
			showMenu();//display menu for admin and prompt admin to choose a charge
			cin >> choice;//get choice by admin
		
			switch (choice){
			case 1:hospitalstayMenu(totalHospital);break;  //Menu 1 --> Hospital stay charges function call

			case 2:surgeryMenu(totalSurgery);break;	//Menu 2 --> Surgery charges function call
				
			case 3:medicineyMenu(totalMedicine);break;	//Menu 3 --> Pharmacy charges function call
				
			case 4:serviceMenu(totalServices, numServices);break;	//Menu 4 --> Service charges function call
				
			case 5:foodMenu(totalFood);break; //Menu 5 --> Food charges
				
			case 0:
			
				cout << endl << "Name: " << patientName[i] << "\nID Num: " << patientID[i] << endl; //Display Patient information and total charges for patient
				displayCharge(totalHospital, totalSurgery, totalMedicine, numServices, totalServices, totalFood, i);
				break;//calculate total charges
				
			default: cout << "Invalid Choice Please Enter Your Choice Again." << endl;break; //Invalid Input
			}
         }
		i++;
		cout << "Is there other Patients(Y/N): "; //ask admin whether there is another patient to check out
		cin >> pass;
		cin.ignore();
		cout << endl;
	} 

	displayDayCharge(patientName,patientID,dayTotalHospital, dayTotalSurgery, dayTotalMedicine,dayTotalServices,dayTotalFood,dayTotal);
}

		void showMenu(){
			//display menu 
			cout << "\t\t\tWelcome to CPT 111 Group 71 Hospital" << endl;

			for (int i = 0; i < 100; i++)
			{
				cout << "-";
			}
			cout << endl << endl;

			cout << "\t\t\t\tTYPE OF CHARGE" << endl << endl;
			cout << "1. Hospital Stay Charge\n2. Surgery Charge\n3. Medication Charge\n4. Services Charge\n5. Food Charges\n0. Check-out" << endl << endl;
			cout << "Choice: ";
		}

    	//display menu 
    	void hospitalstayMenu(int& chargeStay){
		int choice1 = 0, day;
		//Display type of room for hospital
		cout << "\t\t\t\tHospital Stay Charge " << endl;
	    cout << "------------------------------------------------------------------------------------------"<< endl << endl;
	    cout << "1.	4-Bed Room		$100\n2.	Twin Sharing Room	$125\n3.	Premium Twin Room	$150\n4.	Deluxe Room		$180\n5.	Premium Deluxe Room	$230\n" << endl;

			//loop while user input invalid choice
			do{
				cout << "What room have patient take: "; //User input room type
				cin >> choice1;
				cout << "How many day patient stay: ";	//User input number of days spent in hospital
				cin >> day;

					//add the price based on the room and day enter by user to chargeStay
					switch (choice1){
					case 1:chargeStay += 100 * day;break;
					case 2:chargeStay += 125 * day;break;
					case 3:chargeStay += 150 * day;break;
					case 4:chargeStay += 180 * day;break;
					case 5:chargeStay += 230 * day;break;
					default:cout << endl << "Invalid Choice Please Enter Your Choice Again."  << endl << endl;break; //Inform admin invalid input 
					}
				} while (choice1 < 1 || choice1>5);//check validation of the choice1
					cout << endl;
			}

			//Function defination Surgery charges menu function
			void surgeryMenu(int &chargeSurgery){
				//declare and initialize the choice2 to get choice from admin
				int choice2 = 0;

				//Display Surgery menu
				cout << "\t\t\t\tSurgery Charge " << endl;
				cout << "------------------------------------------------------------------------------------------"<< endl << endl;
				cout << "1.	Trauma Surgey		$22445\n2.	Laparoscopic Surgery	$2540\n3.	Colecvectal Surgery	$20683\n4.	Breast Surgery		$6720\n5.	Vascular Surgery	$9000\n6.	Endorine Surgery	$5700" << endl<< endl;

				//loop while user input invalid choice
				do{
					cout << "What surgery have patient take: "; //User input surgery type
					cin >> choice2;

					//add the price of the surgery selected by admin to chargeSurgery
					switch (choice2){
					case 1:chargeSurgery += 22445;break;
					case 2:chargeSurgery += 2540;break;
					case 3:chargeSurgery += 20683;break;break;
					case 4:chargeSurgery += 6720;break;break;
					case 5:chargeSurgery += 9000;break;break;
					case 6:chargeSurgery += 5700;break;break;
					default:cout << endl << "Invalid Choice Please Enter Your Choice Again.\n\n"; //Inform admin invalid inputbreak;
					}
				} while (choice2 < 1 || choice2 > 6); //check validation of the choice2
				cout << endl;
			}

			//Function defination Pharmacy charges menu function (at least 5 types of medication)
			void medicineyMenu(int &chargeMedicine){
				//declare and initialize the choice3 to get choice from admin
				int choice3 = 0, quantity;

				//Display medicine menu
				cout << "\t\t\t\tMedicine Charge " << endl;
				cout << "------------------------------------------------------------------------------------------"<< endl << endl;
				cout << "1.	Liquid		$29\n2.	Tablet		$15\n3.	Capsules	$20\n4	Injection	$59\n5.	Drop		$5\n6.	Topical		$19" << endl << endl;

				//loop while user input invalid choice
				do {
					cout << "What medicine have patient take: "; //User input medicine type
					cin >> choice3;
					cout << " Quantity: "; //User input quantity of medicine
					cin >> quantity;

					//add medicne price to chargeMedicene based on type of medicine and qunatity enter by admin
					switch (choice3){
					case 1:chargeMedicine += 29 * quantity;break;
					case 2:chargeMedicine += 15 * quantity;break;
					case 3:chargeMedicine += 20 * quantity;break;
					case 4:chargeMedicine += 59 * quantity;break;
					case 5:chargeMedicine += 5 * quantity;break;
					case 6:chargeMedicine += 19 * quantity;break;
					default:cout << endl<< "Invalid Choice Please Enter Your Choice Again." << endl;break;
					}
				} while (choice3 < 1 || choice3 > 6); //check validation of the choice3
				cout << endl;
			}

			//serviceMenu Function defination
			void serviceMenu(int &chargeService, int &Services){
				//declare and initialize the choice4 to get choice from admin
				int choice4 = 0;
				//display services menu
				cout << "\t\t\t\tServices Charge " << endl;
				cout << "------------------------------------------------------------------------------------------\n\n" ;
				cout << "1.	X-ray							$22445\n2.	Unnalysis						$2540\n3.	Lipid Profile						$20683\n4.	Health Screaning Package				$5700\n5.	Activated Partial Thromboplatin(ATPP)			$6720\n6.	Comolete Blood Count and Diffential(CBC and Diff)	$9000" << endl<< endl;

				//loop while user input invalid choice
				do{
					cout << "What service have patient take: "; //User input services taken
					cin >> choice4;

					//add services price to chargeServices based on choice entered by admin
					switch (choice4){
					case 1:chargeService += 22445;break;
					case 2:chargeService += 2540;break;
					case 3:chargeService += 20683;break;
					case 4:chargeService += 6720;break;
					case 5:chargeService += 9000;break;
					case 6:chargeService += 5700;break;
					default:cout << endl<< "Invalid Choice Please Enter Your Choice Again." << endl;break; //Error output
					}
				} while (choice4 < 1 || choice4 > 6); //check validation of the choice4
				Services += 1;
				cout << endl;
			}

			//foodmenu Function defination 
			void foodMenu(int& foodService){
				//declare and initialize the choice5 to get choice from admin
				int choice5 = 0;
				cout << "\t\t\t\tFood Charge " << endl;
				cout << "------------------------------------------------------------------------------------------\n\n" ;
				cout << "1.	banana			$3\n2.	Cookie			$3\n3.	Apple			$5\n4.	orange Juice		$6\n5.	Roti			$2\n6.	Big Bowl Salad		$9" << endl << endl;

				//loop while user input invalid choice
				do{
					cout << "What food have patient take: "; //User input food charges
					cin >> choice5;
					//add food price to foodServices based on choice entered by admin
					switch (choice5){
					case 1:foodService += 3;break;
					case 2:foodService += 3;break;
					case 3:foodService += 5;break;
					case 4:foodService += 6;break;
					case 5:foodService += 2;break;
					case 6:foodService += 9;break;
					default:cout << endl << "Invalid Choice Please Enter Your Choice Again." << endl;break; //Error output
					}
				} while (choice5 < 1 || choice5 > 6);//check validation of the choice5

				cout << endl;
			}

			//Total charges menu function
			void displayCharge(int charge1, int charge2, int charge3, int numServices, int charge4, int charge5, int i){
				//counter
				cout << endl;
				//check whether there is Hospital Stay Charges and display Hospital stay charge
				if (charge1 > 0 || charge5>0)
					cout << "Hostpital Stay Charge + Food Charges: $ " << charge1 + charge5 << endl;

				//check whether there is surgeryCharges and display surgery charge
				if (charge2 > 0)
					cout << "Surgery Charge: $ " << charge2 << endl;

				//check whether there is Medicine Charges and display medicine charge
				if (charge3 > 0)
					cout << "Medicine Charge:" << charge3 << endl;

				//check whether there is Services Charges and display sercies charge
				if (charge4 > 0)
					cout << numServices << " Services have been taken, Services Charge: $ " << charge4 << endl;

				cout << endl << "The Total Charge is $ " << charge1 + charge2 + charge3 + charge4 + charge5 << endl << endl; // charges added up and displayed
				//cout<<i;
				dayTotalHospital[i]=charge1;
				dayTotalSurgery[i]=charge2;
				dayTotalMedicine[i]=charge3;
				dayTotalServices[i]=charge4;
				dayTotalFood[i]=charge5;

				
				
			}

			//Function defination for reset()
			void reset(int& charge1, int& charge2, int& charge3, int& numServices, int& charge4, int& charge5)
			{
				//reset all the value
				charge1 = 0;
				charge2 = 0;
				charge3 = 0;
				charge4 = 0;
				charge5 = 0;
				numServices = 0;
			}

			void displayDayCharge(string patientName[], int patientID[], int dayTotalHospital[],int dayTotalSurgery[],int dayTotalMedicine[],int dayTotalServices[],int dayTotalFood[],int dayTotal[]) {

				int sumHospital=0;
				int sumSurgery=0;
				int sumMedicine=0;
				int sumServices=0;
				int sumPatientTotal=0;
				int patientTotal[5];
				cout<<"============================================================================================================================================================================================\n";
				cout<<"Patient Name\t\t\t"<<"Patient ID\t\t"<<"Hospital + Food Charges\t\t"<< "Surgery Charges\t\t" << "Medicine Charges\t\t"<<"Services Charges\t\t"<<"Total Charges\t\t\n";
				cout<<"============================================================================================================================================================================================\n";
				for(int i=0;i<5;i++){
					patientTotal[i]=dayTotalHospital[i]+dayTotalFood[i]+dayTotalSurgery[i]+dayTotalMedicine[i]+dayTotalServices[i];
					cout<< patientName[i]<<"\t\t\t"<< patientID[i]<<"\t\t\t\t"<< dayTotalHospital[i]+dayTotalFood[i]<<"$\t\t\t\t"<<dayTotalSurgery[i]<<"$\t\t\t\t"<<dayTotalMedicine[i]<<"$\t\t\t\t"<<dayTotalServices[i]<<"$\t\t\t"<<patientTotal[i]<<endl;
					sumHospital+=dayTotalHospital[i]+dayTotalFood[i];
					sumSurgery+=dayTotalSurgery[i];
					sumMedicine+=dayTotalMedicine[i];
					sumServices+=dayTotalServices[i];
					sumPatientTotal+=patientTotal[i];
				}

					int index=0;
					int highest=0;
				for(int i=0;i<5;i++){
					if(patientTotal[i]>highest){
						index=i;
						highest=patientTotal[i];
					}
				}
					int index2=0;
					int lowest=0;
				for(int i=0;i<5;i++){
					if(patientTotal[i]<lowest){
						index2=i;
						lowest=patientTotal[i];
					}
				}
				//cout<<"==========================================================================================\n";
				//cout<<"\t\t\t\tDay 21\n";
				cout<<"============================================================================================================================================================================================\n";
				cout << "Total Hostpital Stay Charge + Food Charges: $ " << sumHospital << endl;
				cout << "Total Surgery Charge: $ " <<  sumSurgery << endl;
				cout << "Total Medicine Charge:" <<  sumMedicine << endl;
				cout << "Total Services Charge: $ " <<  sumServices << endl<<endl;
				cout << "Total Charge on Day: $ "  << sumPatientTotal << endl;

				//cout << "average hospital stay for a patient: $ "  << sumPatientTotal << endl;

				cout << "Patient that pays the highest bill: $ "  << patientName[index] << endl;
				cout << "Patient that pays the lowest bill: $ "  << patientName[index2]<< endl;
				cout<<"============================================================================================================================================================\n";
			}