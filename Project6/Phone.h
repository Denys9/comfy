#include <iostream>
using namespace std;
struct Phone
{
private:
	string model;
	string manufacturer;
	string os;
	int year;
	double price;
public:
	Phone(string model, string manufacturer, string os, int year, double price)
	{
		this->model = model;
		this->manufacturer = manufacturer;
		this->os = os;
		this->year = year;
		this->price = price;
	}
	string getModel()
	{
		return this->model;
	}
	string getManufacturer()
	{
		return this->manufacturer;
	}
	string getOs()
	{
		return this->os;
	}
	int getYear()
	{
		return this->year;
	}
	double getPrice()
	{
		return this->price;
	}
	void setModel(string model)
	{
		this->model = model;
	}
	void setManufacturer(string manufacturer)
	{
		this->manufacturer = manufacturer;
	}
	void setOs(string os)
	{
		this->os = os;
	}
	void setYear(int year)
	{
		this->year = year;
	}
	void setPrice(double price)
	{
		this->price = price;
	}
	void about()
	{
		cout << "Model: " << this->model<<endl;
		cout <<"Manufacturer: " << this->manufacturer<<endl;
		cout <<"OS: " << this->os<<endl;
		cout <<"Year: " << this->year<<endl;
		cout <<"Price: " << this->price<<endl;
	}

};