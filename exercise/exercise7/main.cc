#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*Employee abstract base class.*/

class Employee
{
	public:
		Employee( const string & );
		void setName( const string & );
		string getName() const;
		//your code...
		virtual double earning() const = 0;
		virtual void print() const;
	private:   
		string Name;   
};

Employee::Employee( const string & name ): Name(name){}

void Employee::setName( const string &name )
{
	Name = name;
}

string Employee::getName() const
{
	return Name;
}

void Employee::print() const
{
	cout << getName();
}

/*SalariedEmployee class derived from Employee.*/
class SalariedEmployee : public Employee
{
	public:
		SalariedEmployee( const string &, double = 0.0 );
		void setWeeklySalary( double );
		double getWeeklySalary() const;
		//your code...
		virtual	double earning() const;
		virtual void print() const;
	private:   
		double weeklySalary;   
};

SalariedEmployee::SalariedEmployee( const string & name, const double weeklySalary_): Employee(name), weeklySalary(weeklySalary_){}

void SalariedEmployee::setWeeklySalary( const double weeklySalary_ )
{
	weeklySalary = weeklySalary_;
}

double SalariedEmployee::getWeeklySalary() const
{
	return weeklySalary;
}

double SalariedEmployee::earning() const
{
	return weeklySalary;
}

void SalariedEmployee::print() const
{
	cout << "salaried employee: " << getName() << endl;
    cout << "weekly salary: " << getWeeklySalary();
}

/*CommissionEmployee class derived from Employee.*/
class CommissionEmployee : public Employee
{
	public:
		CommissionEmployee(const string&, double = 0.0, double = 0.0);
		void setGrossSales( double );
		double getGrossSales() const;
		void setCommissionRate( double );
		double getCommissionRate() const;
		//your code...
		virtual double earning() const;
		virtual void print() const;
	private:       
		double grossSales;
		double commissionRate;
};

CommissionEmployee::CommissionEmployee( const string & name, const double grossSales_, const double commissionRate_)
	: Employee(name), grossSales(grossSales_), commissionRate(commissionRate_){}

void CommissionEmployee::setGrossSales( const double grossSales_ )
{
	grossSales = grossSales_;
}

double CommissionEmployee::getGrossSales() const
{
	return grossSales;
}

void CommissionEmployee::setCommissionRate( const double commissionRate_ )
{
	commissionRate = commissionRate_;
}

double CommissionEmployee::getCommissionRate() const
{
	return commissionRate;
}

double CommissionEmployee::earning() const
{
	return grossSales * commissionRate;
}

void CommissionEmployee::print() const
{
	cout << "commission employee: " << getName() << endl;
    cout << "gross sales: " << getGrossSales() << "; commission rate: " << getCommissionRate();
}


/*BasePlusCommissionEmployee class derived from CommissionEmployee.*/
class BasePlusCommissionEmployee : public CommissionEmployee
{
	public:
		BasePlusCommissionEmployee(const string&, double = 0.0, double = 0.0, double = 0.0 );
		void setBaseSalary( double );
		double getBaseSalary() const;
		//your code...
		virtual double earning() const;
		virtual void print() const;
	private:       
		double baseSalary;
};

BasePlusCommissionEmployee::BasePlusCommissionEmployee( const string & name, const double grossSales_, const double commissionRate_, const double baseSalary_)
	: CommissionEmployee(name, grossSales_, commissionRate_), baseSalary(baseSalary_){}

void BasePlusCommissionEmployee::setBaseSalary( const double baseSalary_ )
{
	baseSalary = baseSalary_;
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
}

double BasePlusCommissionEmployee::earning() const
{
	return (getGrossSales()*getCommissionRate())+baseSalary;	
}

void BasePlusCommissionEmployee::print() const
{
	cout << "base-salaried commission employee: " << getName() << endl;
    cout << "gross sales: " << getGrossSales() << "; commission rate: " << getCommissionRate() << "; base salary: " << getBaseSalary();
}

void virtualViaPointer( const Employee * const);

int main()
{
	string name1,name2,name3;
	double salary, sales, rate, basesales, baserate, basesalary;
	while( cin >> name1 >> salary    >>
		          name2 >> sales     >> rate     >>
		          name3 >> basesales >> baserate >> basesalary)
	{
		SalariedEmployee salariedEmployee(name1,salary);
		CommissionEmployee commissionEmployee(name2,sales,rate);
		BasePlusCommissionEmployee basePlusCommissionEmployee(name3,basesales,baserate,basesalary);
		vector < Employee* > employee(3);
		employee[0] = &salariedEmployee;
		employee[1] = &commissionEmployee;
		employee[2] = &basePlusCommissionEmployee;
		for( size_t i = 0; i < employee.size(); i++ )
		virtualViaPointer( employee[i] );
	}      
}

void virtualViaPointer( const Employee * const baseClassPtr )
{
	baseClassPtr->print();
	cout << "\nearned $" << baseClassPtr->earning() << "\n\n";
}
