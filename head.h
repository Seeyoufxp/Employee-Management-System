#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define FILENAME "empFile.txt"

class Worker;

class WorkerManager
{
public:
    WorkerManager();
    ~WorkerManager();
    void Show_Menu();
    void ExitSystem();
    void Add_Emp();
    void save();
    int get_EmpNum();
    void init_Emp();
    void Show_Emp();
    void Del_Emp();
    int isExist(int id);
    void Mod_Emp();
    void Find_Emp();
    void Sort_Emp();
    void Clean_File();

    bool m_FileIsEmpty;
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





