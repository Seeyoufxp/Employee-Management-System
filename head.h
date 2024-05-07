#pragma once
#include <iostream>
#include <string>

class Worker;

class WorkerManager
{
public:
    WorkerManager();
    ~WorkerManager();
    void Show_Menu();
    void ExitSystem();
    void Add_Emp();

    int m_EmpNum;
    Worker **m_EmpArray;
    int dSelect;
};

class Worker
{
public:
    virtual void showInfo() = 0;
    virtual std::string getDeptName() = 0;

    int m_Id;
    std::string m_Name;
    int m_DeptId;
};

class Employee : public Worker
{
public:
    Employee(int id, std::string name, int dId);
    virtual void showInfo();
    virtual std::string getDeptName();
};

class Manager : public Worker
{
public:
    Manager(int id, std::string name, int dId);
    virtual void showInfo();
    virtual std::string getDeptName();
};

class Boss : public Worker
{
public:
    Boss(int id, std::string name, int dId);
    virtual void showInfo();
    virtual std::string getDeptName();
};



