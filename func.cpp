#include "head.h"

WorkerManager::WorkerManager()
{
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "no file" << std::endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        std::cout << "no member" << std::endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    this->m_FileIsEmpty = false;
    int num = this->get_EmpNum();
    this->m_EmpNum = num;
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    this->init_Emp();
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArray[i];
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
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
            switch (dSelect)
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
        this->m_FileIsEmpty = false;
        std::cout << "fine" << std::endl;
        this->save();
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    std::ofstream ofs;
    ofs.open(FILENAME, std::ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << std::endl;
    }

    ofs.close();
}

int WorkerManager::get_EmpNum()
{
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);
    int id;
    std::string name;
    int dId;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    ifs.close();

    return num;
}

void WorkerManager::init_Emp()
{
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);
    int id;
    std::string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;
        if (dId == 1)
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        std::cout << "None" << std::endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        std::cout << "no flie" << std::endl;
    }
    else
    {
        std::cout << "id: " << std::endl;
        int id = 0;
        std::cin >> id;
        int index = this->isExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();
            std::cout << "fine" << std::endl;
        }
        else
        {
            std::cout << "Exist" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::isExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        std::cout << "no flie" << std::endl;
    }
    else
    {
        std::cout << "id:" << std::endl;
        int id;
        std::cin >> id;

        int ret = this->isExist(id);
        if (ret = -1)
        {
            delete this->m_EmpArray[ret];
            int newId = 0;
            std::string newName = "";
            int dSelet = 0;

            std::cout << "find: " << id << std::endl;
            std::cout << "newid= " << std::endl;
            std::cin >> newId;
            std::cout << "newname= " << std::endl;
            std::cin >> newName;
            std::cout << "dId(1.employee,2.Manager,3.Boss)" << std::endl;
            std::cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }
            this->m_EmpArray[ret] = worker;
            std::cout << "fine" << std::endl;
            this->save();
        }
        else
        {
            std::cout << "Exist" << std::endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        std::cout << "no file" << std::endl;
    }
    else
    {
        std::cout << "ways:  1.id  2.name" << std::endl;
        int select = 0;
        std::cin >> select;
        if (select == 1)
        {
            int id;
            std::cout << "id= " << std::endl;
            std::cin >> id;
            int ret = isExist(id);
            if (ret != -1)
            {
                std::cout << "find it" << std::endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                std::cout << "None" << std::endl;
            }
        }
        else if (select == 2)
        {
            std::string name;
            std::cout << "name= " << std::endl;
            std::cin >> name;
            bool flag = false;
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    std::cout << "find it" << std::endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if (flag == false)
            {
                std::cout << "None" << std::endl;
            }
        }
    }

    system("pause");
    system("cls");
}

void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty = NULL)
    {
        std::cout << "no file" << std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        std::cout << "ways: 1.Ascending  2.Descending" << std::endl;
        int select = 0;
        std::cin >> select;
        for (int i = 0; i < m_EmpNum; i++)
        {
            int MinOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1)
                {
                    if (m_EmpArray[MinOrMax]->m_Id > m_EmpArray[j]->m_Id)
                    {
                        MinOrMax = j;
                    }
                }
                else if (select == 2)
                {
                    if (m_EmpArray[MinOrMax]->m_Id < m_EmpArray[j]->m_Id)
                    {
                        MinOrMax = j;
                    }
                }
            }
            if (MinOrMax != i)
            {
                Worker *temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[MinOrMax];
                m_EmpArray[MinOrMax] = temp;
            }
        }
        std::cout << "fine" << std::endl;
        this->save();
        this->Show_Emp();
    }
}

void WorkerManager::Clean_File()
{
    std::cout << "for sure? 1.sure 2.back" << std::endl;
    int select = 0;
    std::cin >> select;
    if (select == 1)
    {
        std::ofstream ofs(FILENAME, std::ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArray[i];
            }
        }
        this->m_EmpNum = 0;
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
    }
    std::cout << "fine" << std::endl;

    system("pause");
    system("cls");
}
