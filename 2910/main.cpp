#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

//������� ������
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//----------------------


//�����
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];

//----------------------
//�������
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void ShopUserMenu();
void CreateStaticStorage();
void ShowStorage();
void RefilStorage();
void WriteOffFromStorage();
void ChangePrice();
void ChangeStaff();
void AddEmployee();

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size);

#if defined(max)
#undef max
#endif



//------------------
int main()
{
	Start();
	delete[]loginArr;
	delete[]passwordArr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameArr;
	return 0;
}
//------------------



void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\tAVI\n\n\n";



	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout << "������������ ������� ����� ��� ������� �����?\n";
				std::cout << "1 - ������� �����\n2 - ������� �����\n\n����: ";
				std::getline(std::cin, choose, '\n');
			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{

			}
			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}
}

bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "������ �����: ";
		std::getline(std::cin, login, '\n');
		std::cout << "������� ������: ";
		std::getline(std::cin, pass, '\n');

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passwordArr[0])
			{
				std::cout << "����� ���������� " << loginArr[0] << '\n';
				isAdmin = true;
				return true;
			}

			else if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << "����� ���������� " << loginArr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "�������� ������ ����� ��� ������!\n\n";
	}
	return true;
}

void ShopUserMenu()
{
	std::cout << "User";

}

void ShopAdminMenu()
{
	std::string choose{};
	while (true)
	{
		do
		{
			std::cout << "1. ������ �������\n";
			std::cout << "2. �������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �����\n";
			std::cout << "5. �������� ����\n";
			std::cout << "6. �������� �����\n";
			std::cout << "7. �������� ��������\n";
			std::cout << "8. ����� � �������\n\n";
			std::cout << "0. ������� �����\n\n\n";
			// ���������� ����� 
			std::cout << "����: ";
			std::getline(std::cin, choose, '\n'); 
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); //���������� asci ������� �� 0 �� 8 ���

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefilStorage();
		}
		else if (choose == "4")
		{
			WriteOffFromStorage();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "MainMenuErorr";
		}
	}
}

void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };

	std::string nameStaticArr[staticSize]
	{ "nike air force 1 white               ", "raf simons ozweego 3               ",
	  "balenciaga 3xl                    ", "nike uptempo                     ",
	  "nike x Travis Scott Air jordan 1",
	  "balenciaga 10 xl                      ", "adidas campus                   ",
	  "adidas samba                           ", "rick owens DRKSHDW               ","new rock                            "
	};

	int countStaticArr[staticSize]{ 35,3,4,8,5,2,10,10,5,5 };

	double priceStaticArr[staticSize]{ 15000.0, 140000.0, 96000.0, 20000.0, 51000.0, 120000.0, 2300.0, 11000.0, 88000.0, 52000.0 };


	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);
}

void ShowStorage()
{
	std::cout << "ID\t��������\t\t\t\t����\t����������\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" 
			<< priceArr[i] << "\t" << countArr[i] << "\n";

	}

}

void RefilStorage()
{
	std::string idStr;
	do
	{
		std::cout << "���������� ������\n������� id ������: ";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}

	} while (idStr.size() > 1 || std::stoi(idStr) < 0 || std::stoi(idStr) > size);



	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\n";

	int add{};
	do
	{
		std::cout << "������� ���-�� ������ ��� ����������: ";
		std::cin >> add;
	} while (add < 0 || add > MAXINT - countArr[id - 1]);

	countArr[id - 1] += add;
	std::cout << "����� " << nameArr[id - 1] << " ������� ��������\n\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("pause");

}

void WriteOffFromStorage()
{
	std::string idStr;
	do
	{
		std::cout << "�������� �� ������\n������� id ������: ";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}

	} while (idStr.size() > 1 || std::stoi(idStr) < 0 || std::stoi(idStr) > size);



	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << " ���-�� " << countArr[id -1] <<  "\n\n";

	int del{};
	do
	{
		std::cout << "������� ���-�� ������ ��� ��������: ";
		std::cin >> del;
	} while (del < 0 || del > countArr[id - 1]);

	countArr[id - 1] -= del;
	std::cout << "����� " << nameArr[id - 1] << " ������� ������\n\n";
	system("pause");
}

void ChangePrice()
{
	std::string idStr;
	do
	{
		std::cout << "��������� ����\n������� id ������: ";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}

	} while (idStr.size() > 1 || std::stoi(idStr) < 0 || std::stoi(idStr) > size);



	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << " ������� ����: " << priceArr[id - 1] << "\n\n";

	double newPrice{};
	do
	{
		std::cout << "������� ����� ����: ";
		std::cin >> newPrice;
	} while (newPrice < 0 || newPrice > MAXINT);

	priceArr[id - 1] = newPrice;
	std::cout << "����� " << nameArr[id - 1] << " ������ ����� ��������� " << newPrice << "\n\n";
	system("pause");
}

void ChangeStaff()
{
	std::string choose;
	std::cout << "��������� ��������� ��������:\n\n";
	do
	{
		std::cout << "1 - �������� ������ ����������\n2 - �������� ����� � ������\n3 - ������� �������� ����������\n0 - �����\n\n����: ";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

	if (choose == "1")
	{

	}
	else if (choose == "2")
	{

	}
	else if (choose == "3")
	{

	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cerr << "\nChangeStaffError\n\n";
	}
}

void AddEmployee()
{

	/*
		int userCount = 2;
		std::string* loginArr = new std::string[userCount]{ "admin", "user" };
		std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
	*/

	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}


	//std::swap(loginArr, tempLogin);

	delete[]loginArr;
	delete[]passwordArr;
	userCount++;
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPass[i];
	}
	std::string newLogin, newPass;
	std::cout << "������� ����� ������ ����������: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "������� ������ ������ ����������: ";
	std::getline(std::cin, newPass, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;
	delete[]tempLogin;
	delete[]tempPass;
}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}