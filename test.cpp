#include "head.h"

int main()
{
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        wm.Show_Menu();
        std::cout << "Choose: " << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            wm.ExitSystem();
            break;
        case 1:
            wm.Add_Emp();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}