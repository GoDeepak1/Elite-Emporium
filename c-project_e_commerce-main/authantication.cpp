#include "cart.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <string>
using namespace std;
void login();
void registr();
void forgot();
int billAmount = 0;
Cart cart("cart.txt");
// Delete item from cart
// class--------------------------------------------------------------------
class CartRemove {
public:
  CartRemove(const string &filename) : m_filename(filename) {}

  float removeItemAndGetPrice(const string &itemName) {
    float price = 0;
    string line;
    ifstream file(m_filename);

    if (file.is_open()) {
      ofstream tempFile("temp.txt");

      while (getline(file, line)) {
        string name, quantity, itemPrice;
        int comma1 = line.find(',');
        int comma2 = line.find(',', comma1 + 1);

        name = line.substr(0, comma1);
        itemPrice = line.substr(comma1 + 1, comma2 - comma1 - 1);
        quantity = line.substr(comma2 + 1);

        if (name != itemName) {
          tempFile << line << endl;
        } else {
          price = stof(itemPrice);
        }
      }

      tempFile.close();
      file.close();
      remove(m_filename.c_str());
      rename("temp.txt", m_filename.c_str());
    }

    return price;
  }

private:
  string m_filename;
};
CartRemove ce("cart.txt");
//===============================================================================================
// Second Screen Code
class Second_Screen {
public:
  int returnInterfade() {
    int c, a, money, citem, price, p;
    int item, driver_value;
    string product;
    cout << "============Welcome to Deepak ki Dukaan==========" << endl;

  items:
    cout << "Please select your Choice" << endl;
    cout << "1.Buy Items\n2.View Cart\n3.Checkout\n4.Exit" << endl;
    cout << "---------------------------------------------------\n";
    cin >> item;
    if (item == 1) {
      system("cls");
      driver_value = 1;
      Second_Screen *nxt = new Second_Screen();
      a = nxt->returTotalBill();
    } else if (item == 2) {
      system("cls");
      do {
        cout << "\n========================Cart==========================\n";
        cout << "Item\t\tQuantity\t\tCost\n";
        cart.display();
        cout << "\n----------------------------------------------------------";
        cout << "\nTotal cart value is $" << billAmount << "\n";
        cout << "\n=======================================================\n";
        cout << "\n-------------------------------------------------------\n";
        cout << "Please select any one option\n";
        cout << "1.Remove items from cart\n2.Go back" << endl;
        cout << "=======================================================\n";
        cin >> citem;
        switch (citem) {
        case 1:
          cout << "Enter name of product to remove\n";
          cin.ignore();
          getline(cin, product);
          price = ce.removeItemAndGetPrice(product);
          if (price == 0) {
            system("cls");
            cout << product << " is not in your cart\n";
            billAmount -= price;
            break;
          } else {
            system("cls");
            cout << product << " has been removed from cart\n";
            billAmount -= price;
            break;
          }

        case 2:
          system("cls");
          break;

        default:
          system("cls");
          cout << "Enter valid value\n";
          cout << "\n=======================================================\n";
          break;
        }
      } while (citem != 2);
    } else if (item == 3) {
      system("cls");
      cout << "\n========================Cart==========================\n";
      cout << "Item\t\tQuantity\t\tCost\n";
      cart.display();
      cout << "\n----------------------------------------------------------";
      cout << "\nTotal cart value is $" << billAmount << "\n";
      cout << "\n=======================================================\n";
      cout << "Press\n1.Proceed to payment\n2.Go back\n";
      cout << "----------------------------------------------------------\n";
      cin >> p;
      if (p == 1) {
        cout << "Please do the payment: ";
        cin >> money;
        while (billAmount != money) {
          if (money > billAmount) {
            system("cls");
            cout << "Oops you paid extra\n";
            cout << "Your extra payment will be credited back to your account "
                    "within 24 hours\n";
            cout << "Thanks for shopping";
            exit(0);
          }
          billAmount = billAmount - money;
          cout << "Please pay the remaining amount of $" << billAmount << "\n";
          cin >> money;
        }
        billAmount = 0;
        std::ofstream ofs;
        ofs.open("cart.txt", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
        system("cls");
        cout << "Thanks for shopping";
        exit(0);
        return 7;
      } else if (p == 2) {
        system("cls");
        returnInterfade();
      } else {
        system("cls");
        cout << "You have choosen wrong option try again\n";
      }
    } else if (item == 4) {
      system("cls");
      cout << "Thanks for using the application\n";
      exit(0);
      //}
    } else {
      system("cls");
      cout << "Please enter valid value\n";
      returnInterfade();
    }
    return 0;
  }
  int returTotalBill() {
    int c;
    int qty;
    int item;
    int electronicDevice;
    int books;
    int sports;
    int healthcare;
    char selectAgain;
    Cart cart("cart.txt");
    cout << "============Welcome to Deepak ki Dukaan==========" << endl;
    cout << "Please press 1 to go ahead for shopping your favourite items"
         << endl;
  start:
    cin >> c;
    if (c == 1) {
    items:
      system("cls");
      cout << "================================================================"
              "=======\n";
      cout << "Please select your Choice" << endl;
      cout << "1.Electronics\n2.Books\n3.Sports\n4.Healthcare\n5.Go back"
           << endl;
      cout << "================================================================"
              "=======\n";
      cin >> item;
      if (item == 1) {
        system("cls");
      electronicdeviceList:
        cout << "======================================================\n";
        cout << "Please select 1,2,3,4,5,6,7,8,9 as per your choice" << endl;
        cout << "======================================================\n";
        cout << "1.Dell XPS 13           :   Price:$-999.99\n";
        cout << "------------------------------------------------------\n";
        cout << "2.Macbook Pro           :   Price:$-1,299.99\n";
        cout << "------------------------------------------------------\n";
        cout << "3.HP Spectre x360       :   Price:$-1,099.99\n";
        cout << "------------------------------------------------------\n";
        cout << "4.Lenovo ThinkPad       :   Price:$-1,001.99\n";
        cout << "------------------------------------------------------\n";
        cout << "5.Asus ZenBook          :   Price:$-899.99\n";
        cout << "------------------------------------------------------\n";
        cout << "6.Samsung Galaxy S21    :   Price:$-859.99\n";
        cout << "------------------------------------------------------\n";
        cout << "7.iPhone 12             :   Price:$-909.99\n";
        cout << "------------------------------------------------------\n";
        cout << "8.Sony Bravia TV        :   Price:$-939.99\n";
        cout << "------------------------------------------------------\n";
        cout << "9.Bose QuietComfort 35  :   Price:$-959.99\n";
        cout << "======================================================\n";
        cin >> electronicDevice;
        if (electronicDevice == 1) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 999.99);
          cart.add_item("Dell XPS 13", (qty * 999.99), qty);
        } else if (electronicDevice == 2) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 1, 299.99);
          cart.add_item("Macbook Pro", (qty * 1, 299.99), qty);
        } else if (electronicDevice == 3) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 1, 099.99);
          cart.add_item("HP Spectre x360 ", (qty * 1, 099.99), qty);
        } else if (electronicDevice == 4) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 1, 001.99);
          cart.add_item("Lenovo ThinkPad", (qty * 1, 001.99), qty);
        } else if (electronicDevice == 5) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 899.99);
          cart.add_item("Asus ZenBook", (qty * 899.99), qty);
        } else if (electronicDevice == 6) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 859.99);
          cart.add_item("Samsung Galaxy S21", (qty * 859.99), qty);
        } else if (electronicDevice == 7) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 909.99);
          cart.add_item("iPhone 12", (qty * 909.99), qty);
        } else if (electronicDevice == 8) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 939.99);
          cart.add_item("Sony Bravia TV", (qty * 939.99), qty);
        } else if (electronicDevice == 9) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 959.99);
          cart.add_item("Bose QuietComfort 35", (qty * 959.99), qty);
        } else {
          system("cls");
          cout << "You have entered wrong value,please press correct value"
               << endl;
          goto electronicdeviceList;
        }
        cout << "Press \"y\" to add more items" << endl;
        cin >> selectAgain;
        if (selectAgain == 'y') {
          system("cls");
          goto items;
        } else {
          system("cls");
          return billAmount;
        }
      } else if (item == 2) {
        system("cls");
      booksList:
        cout << "======================================================\n";
        cout << "Please select 1,2,3,4,5,6,7,8,9 as per your choice" << endl;
        cout << "======================================================\n";
        cout << "1.Tum Pahle Kyu Nhi Aaye           :   Price:$3\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "2.Harry Potter                     :   Price:$5\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "3.The adventure of Tin Tin         :   Price:$2\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "4.Data Structures and algorithms   :   Price:$4\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "5.Constitution of India            :   Price:$4.5\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "6.The Hunger games                 :   Price:$7\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "7.Marvel Legacy                    :   Price:$9\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "8.The great legacy of India        :   Price:$11\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "9.Marketing stratigies             :   Price:$3.5\n" << endl;
        cout << "======================================================\n";
        cin >> books;
        if (books == 1) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 3);
          cart.add_item("Tum Pahle Kyu Nhi Aaye", (qty * 3), qty);
        } else if (books == 2) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 5);
          cart.add_item("Harry Potter", (qty * 5), qty);
        } else if (books == 3) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 2);
          cart.add_item("The adventure of Tin Tin", (qty * 2), qty);
        } else if (books == 4) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 4);
          cart.add_item("Data Structures and algorithms", (qty * 4), qty);
        } else if (books == 5) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 4.5);
          cart.add_item("Constitution of India", (qty * 4.5), qty);
        } else if (books == 6) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 7);
          cart.add_item("The Hunger games ", (qty * 7), qty);
        } else if (books == 7) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 9);
          cart.add_item("Marvel Legacy", (qty * 9), qty);
        } else if (books == 8) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 11);
          cart.add_item("The great legacy of India", (qty * 11), qty);
        } else if (books == 9) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 3.5);
          cart.add_item("Marketing stratigies", (qty * 3.5), qty);
        } else {
          system("cls");
          cout << "You have entered wrong value,please press correct value!!!!!"
               << endl;
          goto booksList;
        }
        cout << "Press \"y\" to add more items" << endl;
        cin >> selectAgain;
        if (selectAgain == 'y') {
          system("cls");
          goto items;
        } else {
          system("cls");
          return billAmount;
        }

      } else if (item == 3) {
        system("cls");
      sportsList:
        cout << "======================================================\n";
        cout << "Please select 1,2,3,4,5,6,7,8,9 as per your choice" << endl;
        cout << "======================================================\n";
        cout << "1.Football                           :   Price:$50\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "2.Cricket Bat                        :   Price:$35\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "3.Golf Club                          :   Price:$100\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "4.Table Tennis kit                   :   Price:$55\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "5.Cosco Badminton                    :   Price:$95\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "6.Shuttle pack                       :   Price:$45\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "7.Basket Ball                        :   Price:$10\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "8.Sports Shoes                       :   Price:$80\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "9.Cricket Kit                        :   Price:$75\n" << endl;
        cout << "======================================================\n";
        cin >> sports;
        if (sports == 1) {
          cout << "Enter Quantity: : ";
          cin >> qty;
          billAmount = billAmount + (qty * 50);
          cart.add_item("Football", (qty * 50), qty);
        } else if (sports == 2) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 35);
          cart.add_item("Cricket Bat", (qty * 35), qty);
        } else if (sports == 3) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 100);
          cart.add_item("Golf Club", (qty * 100), qty);
        } else if (sports == 4) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 55);
          cart.add_item("Table Tennis kit", (qty * 55), qty);
        } else if (sports == 5) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 95);
          cart.add_item("Cosco Badminton", (qty * 95), qty);
        } else if (sports == 6) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 45);
          cart.add_item("Shuttle pack", (qty * 45), qty);
        } else if (sports == 7) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 10);
          cart.add_item("Basket Ball", (qty * 10), qty);
        } else if (sports == 8) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 80);
          cart.add_item("Sports Shoes", (qty * 80), qty);
        } else if (sports == 9) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 75);
          cart.add_item("Cricket Kit", (qty * 75), qty);
        } else {
          system("cls");
          cout << "You have entered wrong value,please press correct value!!!!!"
               << endl;
          goto sportsList;
        }
        cout << "Add more items,y or n?" << endl;
        cin >> selectAgain;
        if (selectAgain == 'y') {
          system("cls");
          goto items;
        } else {
          system("cls");
          return billAmount;
        }

      } else if (item == 4) {
        system("cls");
      healthcareList:
        cout << "======================================================\n";
        cout << "Please select 1,2,3,4,5 as per your choice" << endl;
        cout << "======================================================\n";
        cout << "1.Thermometer                    :   Price:$100\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "2.Stethoscope                    :   Price:$150\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "3.Blood pressure monitor         :   Price:$115\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "4.pulse oximeter                 :   Price:$200\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "5.Glucometer                     :   Price:$80\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "6.Antihistamines                 :   Price:$130\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "7.Alcohol swabs                  :   Price:$175\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "8.Nebulizer                      :   Price:$400\n" << endl;
        cout << "------------------------------------------------------\n";
        cout << "9.First-aid kit                  :   Price:$70\n" << endl;
        cout << "======================================================\n";
        cin >> healthcare;
        if (healthcare == 1) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 100);
          cart.add_item("Thermometer", (qty * 100), qty);
        } else if (healthcare == 2) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 150);
          cart.add_item("Stethoscope", (qty * 150), qty);
        } else if (healthcare == 3) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 115);
          cart.add_item("Blood pressure monitor", (qty * 115), qty);
        } else if (healthcare == 4) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 200);
          cart.add_item("Pulse Oximeter", (qty * 200), qty);
        } else if (healthcare == 5) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 80);
          cart.add_item("Glucometer", (qty * 80), qty);
        } else if (healthcare == 6) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 130);
          cart.add_item("Antihistamines", (qty * 130), qty);
        } else if (healthcare == 7) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 175);
          cart.add_item("Alcohol swabs", (qty * 175), qty);
        } else if (healthcare == 8) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 400);
          cart.add_item("Nebulizer", (qty * 400), qty);
        } else if (healthcare == 9) {
          cout << "Enter Quantity: ";
          cin >> qty;
          billAmount = billAmount + (qty * 70);
          cart.add_item("First-aid kit", (qty * 70), qty);
        } else {
          system("cls");
          cout << "You have entered wrong value,please press correct value!!!!!"
               << endl;
          goto healthcareList;
        }
        cout << "Press y to add more items or n to end?" << endl;
        cin >> selectAgain;
        if (selectAgain == 'y') {
          system("cls");
          goto items;
        } else {
          system("cls");
          return billAmount;
        }

      } else if (item == 5) {
        system("cls");
        returnInterfade();
      } else {
        system("cls");
        cout << "We Appreciate your Excitation for shopping,Unfortunately "
                "Entered WRONG INPUT,Please Try AGAIN!"
             << endl;
        goto items;
      }

    } else {
      system("cls");
      cout << "You have entered wrong value,please press 1" << endl;
      goto start;
    }
    system("cls");
    return billAmount;
  }
};
//===============================================================================
main() {
  int choice;
  std::ofstream ofs;
  ofs.open("cart.txt", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  // Cart cart("cart.txt");
  cout << "======================Welcome to Deepak ki "
          "dukaan=====================";
  cout << "\n1.Login";
  cout << "\n2.Register";
  cout << "\n3.Forgot";
  cout << "\n4.Exit";
  cout << "\n------------------------------------------------------------------"
          "----\n";
  cout << "Please enter your choice: ";
  cin >> choice;
  switch (choice) {
  case 1:
    system("cls");
    login();
    break;
  case 2:
    system("cls");
    registr();
    break;
  case 3:
    system("cls");
    forgot();
    break;
  case 4:
    system("cls");
    cout << "Thanks for using the application";
    exit(0);
    break;
  default:
    cout << "Please enter valid choice\n";
    main();
  }
}
void registr() {
  string rusr, rpas, u;
  int exist = 0;
  system("cls");
  while (1) {
    exist = 0;
    cout << "Please enter the username: ";
    cin >> rusr;
    cout << "Please enter the password: ";
    cin >> rpas;

    ifstream input("password.txt");
    while (input >> u) {
      if (u == rusr) {
        exist = 1;
        break;
      }
    }
    input.close();
    if (exist == 0) {
      break;
    } else {
      system("cls");
      cout << "User name already exist please try another username\n";
    }
  }
  ofstream reg("password.txt", ios::app);
  reg << rusr << " " << rpas << endl;
  system("cls");
  cout << "Congratulations! You are successfully registered\n";
  main();
}

void login() {
  int exist = 0, a, b;
  string user, pass, u, p;
  system("cls");
  cout << "Please enter the username: ";
  cin >> user;
  cout << "Please enter the password: ";
  cin >> pass;

  ifstream input("password.txt");
  while (input >> u >> p) {
    if (u == user && p == pass) {
      exist = 1;
      break;
    }
  }
  input.close();
  if (exist == 1) {
    system("cls");
    cout << "Welcome " << u;
    cout << "\n";
    Second_Screen *nxt = new Second_Screen();
    while (1) {
      b = nxt->returnInterfade();
      if (b == 7) {
        cout << "Thanks for shopping\n";
      }
    }
  } else {
    system("cls");
    cout << "Invalid username or password\n";
    main();
  }
}

void forgot() {
  int ch;
  cout << "Please select one of the following ways to retrive password or to "
          "go back\n";
  cout << "--------------------------------------------------------------------"
          "-------\n";
  cout << "1.Search your account by username\n";
  cout << "2.Search your account by password\n";
  cout << "3.Main menu\n";
  cout << "--------------------------------------------------------------------"
          "-------\n";
  cout << "Please enter your choice: ";
  cin >> ch;

  switch (ch) {
  case 1: {
    system("cls");
    int ex = 0;
    string suser, su, sp;
    cout << "Enter the username you remember: ";
    cin >> suser;

    ifstream susr("password.txt");
    while (susr >> su >> sp) {
      if (su == suser) {
        ex = 1;
        break;
      }
    }
    susr.close();
    if (ex == 1) {
      cout << "Your account has been found\n";
      cout << "Your password is " << sp;
      cout << "\n";
      main();
    } else {
      cout << "Account does not exist with current user name\n";
      main();
    }
    system("cls");
    break;
  }
  case 2: {
    system("cls");
    int exi = 0;
    string spas, su2, sp2;
    cout << "Enter the password you remember: ";
    cin >> spas;

    ifstream spass("password.txt");
    while (spass >> su2 >> sp2) {
      if (sp2 == spas) {
        exi = 1;
        break;
      }
    }
    spass.close();
    if (exi == 1) {
      cout << "Your account has been found\n";
      cout << "Your userID is " << su2;
      cout << "\n";
      main();
    } else {
      cout << "Account does not exist with current password\n";
      main();
    }
    system("cls");
    break;
  }
  case 3:
    system("cls");
    main();
    break;

  default:
    system("cls");
    cout << "Please choose the right option\n";
    forgot();
  }
}
