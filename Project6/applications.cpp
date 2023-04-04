#include "library.h"

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//процес входу в аккаунт
	cout << "=====SIGN IN====="<<endl;
	string log, pas,namemodel,cardnum,adress;
	int action,cart=0,paymethod;
	bool isAdmin = false;
	cout << "Login: ";
	getline(cin, log);
	cout << "Password: ";
	getline(cin, pas);
	if (log == "admin" && pas == "1111") {
		isAdmin = true;
	}
	Account user(log,pas,isAdmin); // запис інформації
	
	system("cls");
	if (isAdmin) { // перевірка на адміна
		cout << "You have gained access to the admin functionality.";
	}
	else {
		while (true) {
			cout << "=====List of products=====" << endl; // меню
			Phone model("Iphone 13", "China", "16.3.1", 2023, 5000);
			model.about();
			cout << endl;
			Phone model2("Iphone 9", "North Corea", "15.6.2", 2020, 3500);
			model2.about();
			cout << endl;
			Phone model3("Iphone 15", "Vietnam", "17.1", 2024, 10000);
			model3.about();
			cout << endl;
			Phone model4("Iphone 14 Pro", "Califonia", "16.8.2", 2023, 8750);
			model4.about();
			cout << endl;
			cout << "=====================" << endl;
			while (true) {
				
				cout << "Select an action(exit - 0, add to cart - 1, placing an order - 2): ";  // функціонал
				
				cin >> action;
				cin.ignore();
				if (action == 0) { // якщо користувач вводить 0 то программа закривається
					exit(0);
				}
				else if (action == 1) { // користувачу потрібно ввести назву моделі щоб добавиити її в кошик
					cout << "Enter name of model: "; 
					getline(cin, namemodel);
					if (namemodel == "Iphone 13") { // додання вибраних моделів до кошика
						cart += 5000;

					}
					else if (namemodel == "Iphone 9") {
						cart += 3500;

					}
					else if (namemodel == "Iphone 15") {
						cart += 10000;

					}
					else if (namemodel == "Iphone 14 Pro") {
						cart += 8750;

					}
					else {
						cout << "Name of model is incorrect." << endl; 
						cout << "=====================" << endl;
						continue;
					}
				}
				else if (action == 2) {// процес оформлення замовлення
					system("cls");
					cout << "The total value of your goods: " << cart << endl;  
					cout << "Enter the shipping address:";
					getline(cin, adress);
					
					cout << "Choose a payment method(make a difference-0, pay by card-1): ";// оплата товару
					cin >> paymethod;
					if (paymethod == 0) {
						cart = 0;
						system("cls");
						break;
					}
					else if (paymethod == 1) {
						cout << "Enter the card number: ";
						cin.ignore();
						getline(cin, cardnum);
						
						if (cardnum.length() <= 13 || cardnum.length() >= 19 || cardnum >= "a" && cardnum <= "z" || cardnum >= "A" && cardnum <= "Z") {
							SetConsoleTextAttribute(hConsole, 12);
							cout <<"Incorrect number of card."<<endl;
							SetConsoleTextAttribute(hConsole, 7);
							break;
							
						}
						else {
							SetConsoleTextAttribute(hConsole, 10);
							cout <<"A payment request has been sent."<<endl;
							SetConsoleTextAttribute(hConsole, 7);
							break;
							
							
						}
						
					}
				}
			}
		}
	}
	

	return 0;
}
