#include<iostream>
#include <iomanip>

using namespace std;


//Administrator Functions

void stocklist(); // Function to declare default stocklist
void Initialmenu(); // First menu
void authentication(); //Authentication for the password
void administrator_menu();
void display_stocklist();
void newstock();
void refill(struct product b[], int size);
void remove();
void pricechange(struct product b[], int size);
int indexing(struct product b[], int size);
void discountchange(struct product b[], int size);


//Administrator Data Validation Function
int quantity_validation(int x);
float price_validation(float x);
float discount_validation(float x);
void number_validation(int x); //Validation for new number of products to be added
int remove_number_validation(int x, int i);

//Customer Functions
void customer_menu();
void Bill_Generator();

//Customer Validation Functions
int  customer_quantity_validation(int x, struct product b[], int code);
int Customer_code_validation(int x, int i);
double price_each_amount(int quantity, struct product b[], int code);



//const int size = 100; //Default setting number of types of products in store

struct product
{

	int SrNo = 0;
	string name;
	float price;
	float discount;
	int quantity;

}
b[100];


void doNothing(const int& x) // Don't worry about what &x is for now, we're just using it to trick the compiler into thinking variable x is used
{
}


//Main Function Beginning
int main()
{
	stocklist();// Calling function to create default stocklist
	Initialmenu();
	return 0;
	cout << "\n\t";
	system("pause");

}
//Main Function Ends




//Function to create default stocklist
void stocklist()
{
	b[0] = { 1,"Bread", 10, 1,100 };
	b[1] = { 2, "Meat", 15, 2,150 };
	b[2] = { 3,"Eggs", 13, 50,100 };
	b[3] = { 4,"Milk", 2.7, 2,101 };
	b[4] = { 5,"Juice", 8.5, 15,100 };
	b[5] = { 6, "Rice", 7, 0,10 };
	b[6] = { 7,"Fish", 6, 20,10 };
	b[7] = { 8,"Pasta", 1, 50,10 };
	b[8] = { 9,"Cereals", 4, 5,10 };
	b[9] = { 10,"Soaps", 7, 5,10 };
}


void Initialmenu()  //Inital Menu
{
	float j;
	cout << "\n\t\t   Super Market Billing System\n\n";
	cout << "\t** Coded by Neeraj Saini ** \n\n\n\n";
	cout << "=============================================================";
	cout << "\n\n\t\t   1. Dealer Menu\n\n\t\t   2. Customer Menu\n\n\t\t ";
	cout << "\n\n=============================================================\n";
	cout << "\n\nEnter Your Choice:";
	cin >> j;

	while (!cin)
	{
		cin.clear();
		cin.ignore();
		cout << "Error Try again: ";
		cin >> j;

	}
	do
	{
		if (j == 1 || j == 2)
		{
			if (j == 1)
			{
				authentication();

			}
			else if (j == 2)
			{
				customer_menu();
			}
			
		}

		if (j != 1 || j != 2)
		{
			cout << "Error Try again: ";
			cin >> j;
		}

	} while (j != 1 || j != 2);

	

}








void authentication()
{
	string userinput;
	string password = "saini";
	cout << "Enter password: ";
	cin >> userinput;
	if (userinput != password) // Validation
	{
		cout << "Password Invalid... Try Again: ";
		cin >> userinput;
		while (userinput != password)
		{
			cout << "Password Invalid... Try Again" << endl;
			cin >> userinput;
		}
	}
	else
		cout << "Password Accepted... ";
	administrator_menu();

}



void administrator_menu() //Administrator menu
{
	

	int i;
	cout << "=================================================================";
	cout << "\n\n\t\t\t    DEALER MENU\n1. Display Stock\n2. Add New Stock\n3. Refill\n4. Remove an item\n5. Change Price\n6. Change Discount\n7. Exit:";
	cout << "\n\n\n==========================END OF MENU=============================\n";
	cin >> i;
	switch (i)
	{
	case 1:
		display_stocklist();
		administrator_menu();
		break;
	case 2:
		newstock();
		administrator_menu();
		break;

	case 3:
		refill(b, 100);
		administrator_menu();
		break;

	case 4:
		remove();
		administrator_menu();
		break;

	case 5:
		pricechange(b, 100);
		administrator_menu();
		break;
	case 6:
		discountchange(b, 100);
		administrator_menu();
		break;

	default:
		Initialmenu();
		break;
	}
}


//Function to display the Stock List
void display_stocklist()
{
	cout << "\n==================================================================";
	cout << "\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout << "\n\n==================================================================\n";
	cout << "\n\nSrNo\tPARTICULARS\tSTOCK AVAILABLE\t PRICE\t Discount";
	cout << "\n\n============================================================\n";

	for (int i = 0; i < 100; i++)
	{
		if (b[i].SrNo != 0)
		{
			cout << b[i].SrNo << "\t";
			cout << b[i].name << "\t\t";
			cout << b[i].quantity << "\t\t";
			cout << b[i].price << "\t";
			cout << b[i].discount << endl;
		}
		else
			break;
	}
}


//Function for adding new items in stock
void newstock()
{
	int n, i;
	cout << "=================Enter the number of products you want to add to inverntory=================\n";
	cin >> n;

	number_validation(n); //check for the number of new products to be added
	i = indexing(b, 100);

	cout << i;
	n = n + i;

	for (i; i < n; i++)
	{
		cout << "\n\nInput the name, price, quantity and discount on item respectively\n\n";
		b[i].SrNo = i + 1;

		cout << "Name:";
		cin >> b[i].name;

		cout << "Quantity:";
		cin >> b[i].quantity;
		b[i].quantity = quantity_validation(b[i].quantity);// Validate quantity

		cout << "Price:";
		cin >> b[i].price;
		b[i].price = price_validation(b[i].price); //validate Price of item

		cout << "Discount(%)"; //validate the discount
		cin >> b[i].discount;
		b[i].discount = discount_validation(b[i].discount);
	}
}


//Functions to refill the quantity

void refill(struct product b[], int size)
{
	int n, i, j;
	j = indexing(b, 100);
	cout << "=================Enter the Serial Number of the product you want to refill=================\n";
	cin >> n;
	n = remove_number_validation(n, j);
	for ( i = 0; i <= j; i++)
	{
		if (b[i].SrNo == n)
		{
			cout << "Enter the new quantity:";
			cin >> b[i].quantity;
			b[i].quantity = quantity_validation(b[i].quantity);
		}

	}

}

// Function to remove product from stocklist

void remove()
{
	int n, i;
	i = indexing(b, 100);
	//cout << i << endl;
	cout << "=================Enter the Serial Number of the product you want to remove=================\n";
	cin >> n;
	n = remove_number_validation(n, i);
	b[i - 1].SrNo = 0;
	for (n = n - 1; n <= i; n++)
	{
		b[i].SrNo = 0;
		b[n].name = b[n + 1].name;
		b[n].quantity = b[n + 1].quantity;
		b[n].price = b[n + 1].price;
		b[n].discount = b[n + 1].discount;
	}
}


//Function to change price of product
void pricechange(struct product b[], int size)
{
	int n, i, j;
	j = indexing(b, 100);
	cout << "=================Enter the Serial Number of the product you want to Change=================\n";
	cin >> n;
	n = remove_number_validation(n, j);
	for (int i = 0; i <= j; i++)
	{
		if (b[i].SrNo == n)
		{
			cout << "Enter the new Price:";
			cin >> b[i].price;
			b[i].price = price_validation(b[i].price);
		}

	}

}

void discountchange(struct product b[], int size)
{
	int n, i, j;
	j = indexing(b, 100);
	cout << "=================Enter the Serial Number of the product you want to Change=================\n";
	cin >> n;
	n = remove_number_validation(n, j);
	for (int i = 0; i <= j; i++)
	{
		if (b[i].SrNo == n)
		{
			cout << "Enter the new Discount:";
			cin >> b[i].discount;
			b[i].discount = discount_validation(b[i].discount);
		}

	}
}




//Customer Menu

void customer_menu()
{
	int i;
	cout << "=================================================================";
	cout << "\n\n\t\t\t    CUSTOMER  MENU\n1. Display Stock\n2. Bill Generation";
	cout << "\n\n\n==========================END OF MENU=============================\n";
	cin >> i;
	switch (i)
	{
	case 1:
		display_stocklist();
		customer_menu();
		break;

	case 2:
		Bill_Generator();
		break;


	default:
		customer_menu();
		break;
	}
}




void Bill_Generator()
{

	double amount, cash_received, total = 0;
	int code, j, quantity;
	int itemssold = 0;
	cout << "\t\t\tCASH MEMO - RETAIL INVOICE\n";
	cout << "----------------------------------------------------------------------------------------------------------------\n";
	cout << "CODE\tITEM NAME\t\t\t\t\tQUANTITY";
	cout << "\t\tAMOUNT($)\n";

	cout << "----------------------------------------------------------------------------------------------------------------\n";
	j = indexing(b, 100);

	for (int i = 1; i != 0; i++)
	
	{
		cin >> code;

		if (code == -1)
		{
			
			cout << fixed << setprecision(2) << "\t\t\t\t\t\t\t\t\t" << "Total: " << total << endl;
			cout << fixed << setprecision(2) << "\t\t\t\t\t\t\t\t\tGST(7%): " << total * .07 << endl;
			total = total + total * .07;
			cout << fixed << setprecision(2) << "\t\t\t\t\t\t\t\t\tQST(7.5%): " << total * .075 << endl;
			total = total + total * .075;
			cout << fixed << setprecision(2) << "\t\t\t\t\t\t\t\t\tAmount : " << total << endl;
			cout << "-------------------------------------------------------------------------------------\n";
			cout << "Total Number of items sold:" << itemssold << endl;
			cout << "Balance Due:      " << total << endl;
			cout << "Cash Received:      ";
			cin >> cash_received;
			while (cash_received < 0 || cash_received < total)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Amount Insufficient Please Provide More Money\n";
				cin >> cash_received;
			}


			cout << fixed << setprecision(2) << "Changed to be returned: " << cash_received - total << endl;
			cout << "-------------------------------------------------------------------------------------\n";
			cout << "\t\t\tCustomer Care Phone # : 1111 111 111\n";
			cout << "\t\t\tCustomer Care E-mail : custcare@gmail.com\n";

			cout << "\n\t\t\tCALL FOR FREE HOME DELIVERY.\n";
			cout << "\n\t\t\t\tNo cash refunds.\n";
			cout << "\t\t\tTerms and conditions apply.*\n";
			cout << "\t\t\t** Thank you for shopping with us **\n\n\n\n";
			cout << "\t\t\t** Coded by  Neeraj Saini **\n\n\n\n";
			Initialmenu();
			break;



		}
		else
		{
			
			code = Customer_code_validation(code, j);
			code = code - 1;
			
			cout << "\t" << b[code].name << "\t\t\t\t\t\t   ";
			cin >> quantity;
			if (customer_quantity_validation(quantity, b, code))
			{
				itemssold += quantity;
				b[code].quantity = b[code].quantity - quantity;
				//cout << b[code].quantity;
				total += price_each_amount(quantity, b, code);
				cout << fixed << setprecision(2) << "\t\t\t\t\t\t\t\t\t\t" << price_each_amount(quantity, b, code) << endl;

			}
		}
	}
}


//Validations Functions

void number_validation(int x)
{
	while (x < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\n********Warning : Number of products cannot be negative Try Again********\n\n" << endl;
		administrator_menu();
		//cin >> x;

	}
}


int indexing(struct product b[], int size) //Indexing function to track
{
	for (int i = 0; i < size; i++)
	{
		if (b[i].SrNo == 0 && i < 100)
		{
			return i;
			break;
		}
		

	}
}



int quantity_validation(int x)
{
	while (x < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\n********Warning : Quantity cannot be negative Try Again********\n\n" << endl;
		cout << "Quantity:";
		cin >> x;
	}
	return x;
}


float price_validation(float x)
{
	while (x < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\n********Warning : Price cannot be negative Try Again********\n\n" << endl;
		cout << "Price:";
		cin >> x;

	}
	return x;
}

float discount_validation(float x)
{
	while (x < 0 || x>99)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\n********Warning : Discont cannot be negative Try Again********\n\n" << endl;
		cout << "Discount:";
		cin >> x;

	}
	return x;
}


int remove_number_validation(int x, int i)
{
	while (x < 0 || x>i || x == 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n\n********Warning : Number of products cannot be negative and out of stock table " << i << " Try Again********\n\n" << endl;
		//administrator_menu();
		cin >> x;

	}
	return x;
}

//Customer Validation functions
int Customer_code_validation(int x, int i)
{

	while (x < 0 || x>i)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t**Error:Try Again with valid code**\n";
		//administrator_menu();
		cin >> x;
		
	}
	return x;
}


int  customer_quantity_validation(int x, struct product b[], int code)
{

	if (x < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t**Error:Try Again with valid Quantity**\n";
		return 0;

	}
	else if (x > b[code].quantity)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t**Error: Out of stock ";
		cout << " Available Quantity: " << b[code].quantity << endl;
		return 0;
	}

	else
		return 1;

}


//Customer Price Calculations

double price_each_amount(int quantity, struct product b[], int code)
{
	return ((b[code].price * quantity) - ((quantity * b[code].price * b[code].discount) / 100));

}


