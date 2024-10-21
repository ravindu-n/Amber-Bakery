#include <iostream>
#include<fstream>
#include <vector>
#include <string>

using namespace std;

void Login();
void systemMenu();
void ViewbkryItems();
void addBkryItems();
void deleteBkryItems();
void displaycompanydetails();
void displaySales();
double calculateTotalSales();
void createOrder();


//main function
int main() {
	
	Login();
    
    return 0;
} 


//Login Function
void Login(){
	
    ifstream userFile;
    userFile.open("loginDetails.txt");
    bool login=false;
    
    string username, password, fileUsername, filePassword;

    cout << " Enter Username: ";
    cin >> username;

    cout << " Enter Password: ";
    cin >> password;
    
    while (userFile>>fileUsername>> filePassword) {
    	if (username == fileUsername && password == filePassword){
    		login=true;
			break;
		}
	}

    if(login){
    	cout<<"\n successfully login!"<<endl;
		systemMenu();
	}
	else {
		cout<<" Wrong username or password. Try again...!\n"<<endl;
		Login();
	}
    userFile.close();
}

//exit function
int exit(){
	return -1;;
}

//logout funtion
int logout(){
	Login();
}
//move back
void back(){
	systemMenu();
}

//System Menu
void systemMenu(){
	
    int selection;
    cout<<"\n Welcome to Amber bakery "<<endl;
    cout<<"         ======="<<endl;
    cout<<"           Menu"<<endl;
    cout<<"         ======="<<endl;
  
    cout<<"1. View details of bakery"<<endl;
    cout<<"2. View bakery items"<<endl;
    cout<<"3. Add bakery items"<<endl;
    cout<<"4. Delete bakery items"<<endl;
    cout<<"5. View sales details"<<endl;
    cout<<"6. Place an order"<<endl;
    cout<<"7. Logout"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"\nPlease Select : ";
    cin>>selection;
  
    switch(selection){
    	case 1: displaycompanydetails();
    	    break;
    	case 2: ViewbkryItems();
    	    break;
    	case 3: addBkryItems();
    	    break;
    	case 4: deleteBkryItems();
    	    break;
    	case 5: displaySales();
    	    break;
    	case 6: createOrder();
    	    break;
    	case 7: logout();
    	    break;
    	case 8: exit();
		    break;    
    	default:cout<<"\n*** Enter Valide Number ***"<<endl;
    	    systemMenu();
    	    break;         
    }  
}


// Display information
void displaycompanydetails(){
	int number;
	cout<<"\n     ====================================";
	cout<<"\n Amber bakery is one of the very famous pastry shops in UK \n";
    cout<<"\n Address: 155A,London \n";
    cout<<"\n Telephone: +44 111-5566555\n";
    cout<<"\n Email: amberb@gmail.com";
    cout<<"\n     ====================================";
    
    cout<<"\nPress 1 to go back:";
    cin>>number;
    if(number == 1){
    	back();
	}else{
		cout<<"\n\nEnter valide number!";
		displaycompanydetails();
	}
}

//Add items function
void addBkryItems(){
	ofstream coFile;
    coFile.open("ItemDetails.txt",ios::app);
    
    int ItemID,number;
    string ItemName, ItemPrice; 
    cout<<"Enter Item ID : ";
    cin>>ItemID;
    cout<<"Enter Item name : ";
    cin>>ItemName;
    cout<<"Enter Item Price : ";
    cin>>ItemPrice;
    
    coFile<<ItemID<<"\t"<<ItemName<<"\t"<<ItemPrice<<endl; 
    coFile.close(); 
	 
    cout<<"\nPress 1 to go back:";
    cin>>number;
    if(number == 1){
    	back();
	}else{
		cout<<"\nEnter valide number!\n";
		addBkryItems();
	}
    
}

//View Items function
void ViewbkryItems(){
	int number;
	ifstream coFile;
    coFile.open("ItemDetails.txt");
    
    int ItemID;
    string ItemName,ItemPrice;
    cout<<"\n\n    BEKERY ITEMS"<<endl;
    cout<<"Item ID   Item Name    Item Price"<<endl;
    coFile>>ItemID>>ItemName>>ItemPrice; 
    
    while (coFile){
    	cout<<ItemID<<"\t  "<<ItemName<<"\t\t"<<ItemPrice<<endl;
        coFile>>ItemID>>ItemName>>ItemPrice; 
	}
	
	coFile.close();
  
    cout<<"\nPress 1 to go back:";
    cin>>number;
    if(number == 1){
    	back();
	}else{
		cout<<"\n\nEnter valide number!";
		ViewbkryItems();
	}
}

//delete function
void deleteBkryItems() {
	ifstream inFile("ItemDetails.txt");
    ofstream outFile("temp.txt"); // Create a temporary file to copy data

    int deleteID,number;
    bool found = false;
    
    cout << "\nEnter the Item ID to delete: ";
    cin >> deleteID;

    int ItemID;
    string ItemName, ItemPrice;
    
    while (inFile >> ItemID >> ItemName >> ItemPrice){
    	if (ItemID == deleteID){
    		found = true;
            cout << "Deleted Item: " << ItemName << " with ID " << ItemID << endl;
		}else{
			outFile << ItemID << "\t" << ItemName << "\t" << ItemPrice << endl;
		}
	}
	inFile.close();
    outFile.close();

    // Remove the original file and rename the temporary file
    remove("ItemDetails.txt");
    rename("temp.txt", "ItemDetails.txt");
    
    if (!found){
    	cout << "Item with ID " << deleteID << " not found." << endl;
	}
	cout<<"\nPress 1 to go back:";
    cin>>number;
    if(number == 1){
    	back();
	}else{
		cout<<"\nEnter valide number!";
		deleteBkryItems();
	}  
}

//Read Sales details
void displaySales(){
	
	int number;
	ifstream coFile;
    coFile.open("salesDetails.txt");
    
    int OrderID;
    double orderPrice;
    cout<<"\n        ---Sales---"<<endl;
    cout<<"Order Number      Total Price"<<endl;
    coFile>>OrderID>>orderPrice; 
    
    while (coFile){
    	cout<<OrderID<<"\t\t  "<<orderPrice<<endl;
        coFile>>OrderID>>orderPrice; 
	}
	
	cout<<"\nTotal Sales =  Ru."<<calculateTotalSales()<<endl;
	
	coFile.close();
	
	cout<<"\nPress 1 to go back:";
    cin>>number;
    if(number == 1){
    	back();
	}else{
		cout<<"\nEnter valide number!";
		displaySales();
	}  
}

//Calculate total sales function
double calculateTotalSales() {
    ifstream coFile;
    coFile.open("salesDetails.txt");

    int OrderID;
    double orderPrice;
    double totalSales = 0.0; 

    while (coFile >> OrderID >> orderPrice) {
        totalSales += orderPrice; 
    }

    coFile.close();

    return totalSales;
}

double calculateOrderPrice(const vector<int>& itemIDs, const vector<int>& quantities) {
    ifstream itemFile("ItemDetails.txt");
    double totalOrderPrice = 0.0;

    int ItemID;
    double orderPrice;
    string ItemName;

    for (size_t i = 0; i < itemIDs.size(); ++i) {
        while (itemFile >> ItemID >> ItemName >> orderPrice) {
            if (ItemID == itemIDs[i]) {
                totalOrderPrice += orderPrice * quantities[i];
                break;
            }
        }
        itemFile.clear(); // Reset EOF flag to read the file from the beginning
        itemFile.seekg(0, ios::beg); // Reset file position to the beginning
    }

    itemFile.close();

    return totalOrderPrice;
}

 //Generate OrderID function
int generateOrderID() {
    ifstream orderIDFile("orderID.txt");
    int lastOrderID = 0;
    if (orderIDFile) {
        orderIDFile >> lastOrderID;
        orderIDFile.close();
    }
    int newOrderID = lastOrderID + 1;
    ofstream outFile("orderID.txt");
    outFile << newOrderID;
    outFile.close();
    return newOrderID;
}

// CreateOrder function
void createOrder() {
    ofstream salesFile("salesDetails.txt", ios::app); 
    
    //View Item List
    ifstream coFile;
    coFile.open("ItemDetails.txt");
    
    int iID;
    string iName,iPrice;
    cout<<"\n\n    BEKERY ITEMS"<<endl;
    cout<<"Item ID   Item Name    Item Price"<<endl;
    coFile>>iID>>iName>>iPrice; 
    
    while (coFile){
    	cout<<iID<<"\t  "<<iName<<"\t\t"<<iPrice<<endl;
        coFile>>iID>>iName>>iPrice; 
	}
	
	coFile.close();

    int OrderID = generateOrderID(); // Generate a new order ID

    int itemID, quantity;
    vector<int> itemIDs;
    vector<int> quantities;

    cout << "\n Enter the items you want to order and their quantities  (ItemID  Quantity).\n Enter -1 to finish:\n";

    while (cin >> itemID && itemID != -1) {
        cin >> quantity;
        itemIDs.push_back(itemID);
        quantities.push_back(quantity);
    }

    double totalOrderPrice = calculateOrderPrice(itemIDs, quantities);

    salesFile << OrderID << "\t" << totalOrderPrice << endl;

    salesFile.close();

    cout << "\n Order added Successfully with Order ID: " << OrderID << " and Total price: " << totalOrderPrice << endl;
    
    back();
}


