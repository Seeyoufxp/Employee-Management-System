#include "head.h"

WorkerManager::WorkerManager()
{
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager()
{
}

void WorkerManager::Show_Menu()
{
    std::cout << "********************************" << std::endl;
    std::cout << "*********** 0.Exit   ***********" << std::endl;
    std::cout << "*********** 1.Add    ***********" << std::endl;
    std::cout << "*********** 2.Show   ***********" << std::endl;
    std::cout << "*********** 3.Delete ***********" << std::endl;
    std::cout << "*********** 4.Modify ***********" << std::endl;
    std::cout << "*********** 5.Search ***********" << std::endl;
    std::cout << "*********** 6.Sort   ***********" << std::endl;
    std::cout << "*********** 7.Empty  ***********" << std::endl;
    std::cout << "********************************" << std::endl;
    std::cout << std::endl;
}

void WorkerManager::ExitSystem()
{
    system("pause");
    exit(0);
}

Employee::Employee(int id, std::string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}
void Employee::showInfo()
{
    std::cout << this->m_Id << "\t" << this->m_Name << "\t" << this->getDeptName() << "\t"
              << " Junior tasks " << std::endl;
}
std::string Employee::getDeptName()
{
    return std::string("Employee");
}

Manager::Manager(int id, std::string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}
void Manager::showInfo()
{
    std::cout << this->m_Id << "\t" << this->m_Name << "\t" << this->getDeptName() << "\t"
              << " Intermediate tasks " << std::endl;
}
std::string Manager::getDeptName()
{
    return std::string("Manager");
}

Boss::Boss(int id, std::string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}
void Boss::showInfo()
{
    std::cout << this->m_Id << "\t" << this->m_Name << "\t" << this->getDeptName() << "\t"
              << " Advance tasks " << std::endl;
}
std::string Boss::getDeptName()
{
    return std::string("Boss");
}

void WorkerManager::Add_Emp()
{
    int addNum = 0;
    std::cout << "Num:" << std::endl;
    std::cin >> addNum;
    if (addNum > 0)
    {
        int newSize = this->m_EmpNum + addNum;
        Worker **newSpace = new Worker *[newSize];
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for (int i = 0; i < addNum; i++)
        {
            int id;
            std::string name;
            int dSelect;
            std::cout << i + 1 << " Id: " << std::endl;
            std::cin >> id;
            std::cout << i + 1 << " Name: " << std::endl;
            std::cin >> name;
            std::cout << i + 1 << " Dselect(1.Employee,2.Manager,3.Boss): " << std::endl;
            std::cin >> dSelect;
            Worker *worker = NULL;
            switch(dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            newSpace[this->m_EmpNum + i] = worker;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        std::cout << "fine" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
    system("pause");
    system("cls");
}




