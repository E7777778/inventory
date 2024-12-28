#include <iostream>
#include <string>


using namespace std;

int productid;
int productsub[10] = {0};
int subproductsnum[10] = {0};
int productsnum[10] = {0};
int newproductsnum[10] = {0};
int price[10] = {0};

string products[10] = {"Milk", "Injera", "Rice", "Sugar", "Butter", "Bread", "Meat", "Fish", "Candy", "Berbere"};


void displaystock();
void menu();
void addproduct();
void addsales();
void viewstock();
void search();

int main() {
    system("cls");
    cout << " GRP7 GROCERIES INVENTORY MANAGEMENT SYSTEM PROGRAM\n";
    menu();
    return 0;
}

void menu() {
    int menu_num;
    cout << "\t            Menu             \n";
    cout << "\t\t**********";
    cout << "\n\t1. Add Products to Stock\n";
    cout << "\t2. Products for Sale\n";
    cout << "\t3. Search Item in Stock\n";
    cout << "\t4. Exit Program\n\n";
    cout << "Enter your choice here: ";
    cin >> menu_num;

    switch(menu_num) {
        case 1:
            system("cls");
            addproduct();
            break;
        case 2:
            system("cls");
            addsales();
            break;
        case 3:
            system("cls");
            search();
            break;
        case 4:
            cout << "BYE, HOPE TO SEE YOU AGAIN ";
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
            menu();
    }
}

void addproduct() {
    int choice;
    cout << "************** Stock ***************\n";
    cout << "1. Add product to stock\n";
    cout << "2. Go to menu\n";
    cout << "3. View stock\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    switch(choice) {
        case 1:
            system("cls");
            for (int i = 0; i < 10; i++) {
                cout << "\nEnter Amount of " << products[i] << ": ";
                cin >> newproductsnum[i];
                cout << "Enter price of " << products[i] << ": ";
                cin >> price[i];
            }
            displaystock();
            break;
        case 2:
            system("cls");
            menu();
            break;
        case 3:
            system("cls");
            viewstock();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            addproduct();
    }
}

void viewstock() {
    displaystock();
}

void addsales() {
    cout << "MilkID:0, InjeraID:1, RiceID:2, SugarID:3, ButterID:4, BreadID:5, MeatID:6, FishID:7, CandyID:8, BerbereID:9\n";
    cout << "Enter the product ID you want to purchase: ";
    cin >> productid;

    if (productid >= 0 && productid < 10) {
        cout << "Enter amount of " << products[productid] << ": ";
        cin >> productsub[productid];
        cout << "PURCHASED\n";

        menu();
    } else {
        cout << "No product with that ID, try again!\n\n";
        addsales();
    }
}

void displaystock() {
    cout << "ProductID\t\tProducts\t\tNum of Products\t\tUnit Price\n";
    for (productid = 0; productid < 10; productid++) {
        subproductsnum[productid] = productsnum[productid] - productsub[productid];
        productsnum[productid] = productsnum[productid] + newproductsnum[productid];
        cout << productid << "\t\t\t" << products[productid] << "\t\t\t" << productsnum[productid] << "\t\t\t" <<
         price[productid] << " ETB\n";
    }
}

void search() {
    cout << "MilkID:0, InjeraID:1, RiceID:2, SugarID:3, ButterID:4, BreadID:5, MeatID:6, FishID:7, CandyID:8, BerbereID:9\n";
    cout << "What product's information do you want to see? Enter its ID here: ";
    cin >> productid;

    if (productid >= 0 && productid < 10) {
        cout << "\t\tPRODUCT DETAILS\n";
        cout << "PRODUCT NAME: " << products[productid] << "\n";
        cout << "TOTAL UNITS IN STOCK: " << subproductsnum[productid] << "\n";
        cout << "UNIT PRICE: " << price[productid] << " ETB\n";
    } else {
        cout << "No product with that ID, try again!\n\n";
        search();
    }
}
