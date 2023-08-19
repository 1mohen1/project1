#include <iostream>
#include <list>
#include <windows.h>

using namespace std;

int Select()
{
    int select;
    cout << "\n��ѡ�� ***********0.���ز˵�******************1.����***************************\n";
    cin >> select;
    return select;
}

//���Ӹ���ϸϸ��ĥ
typedef struct
{
    string name;
    int age;
    string sex;
    string id;
    string phone;
}Student;
list<Student>stulist;//list����
list<Student>::iterator stu;//���������stu��������list����

void inputStudent()
{
    cout << "\n����\t\t����\t\t�Ա�\t\tѧ��\t\t�绰" << endl;
    Student data;
    cin >> data.name >> data.age >> data.sex >> data.id >> data.phone;
    stulist.push_back(data);
    int select = Select();
loop1:
    if (select == 0);
    else if (select == 1)
        inputStudent();
    else
    {
        cout << "ѡ��������������룺\n";
        cin >> select;
        goto loop1;
    }
    return;
}

void printStudent()
{
    cout << "\n����\t\t����\t\t�Ա�\t\tѧ��\t\t�绰" << endl;
    for (stu = stulist.begin(); stu != stulist.end(); stu++)
        cout << (*stu).name << "\t\t" << (*stu).age << "\t\t" << (*stu).sex 
             << "\t\t" << (*stu).id << "\t" << (*stu).phone << endl;
    int select = Select();
    loop1:
    if (select == 0);
    else if (select == 1)
        printStudent();
    else
    {
        cout << "ѡ��������������룺\n";
        cin >> select;
        goto loop1;
    }
}

void changeStudent()
{
    string str;
    bool f = true;
    cout << "������Ҫ�޸���Ϣ��ѧ��ѧ��\n";
    cin >> str;
    for (stu = stulist.begin(); stu != stulist.end(); stu++)
        if (str == (*stu).id)
        {
            cout << "������ϣ���޸ĺ��ѧ����Ϣ\n";
            Student data;
            cin >> data.name >> data.age >> data.sex >> data.id >> data.phone;
            *stu = data;
            cout << "�޸ĳɹ���\n";
            f = !f;
            break;
        }
    if (f)
        cout << "��ͬѧ��Ϣ������\n";
    int select = Select();
loop1:
    if (select == 0);
    else if (select == 1)
        changeStudent();
    else
    {
        cout << "ѡ��������������룺\n";
        cin >> select;
        goto loop1;
    }
}

void deleteStudent()
{
    string str;
    bool f = true;
    cout << "������Ҫɾ����Ϣ��ѧ��ѧ��\n";
    cin >> str;
    for (stu = stulist.begin(); stu != stulist.end(); stu++)
        if (str == (*stu).id)
        {
            stulist.erase(stu);
            cout << "ɾ���ɹ���\n";
            f = !f;
            break;
        }
    if (f)
        cout << "��ͬѧ��Ϣ������\n";
    int select = Select();
loop1:
    if (select == 0);
    else if (select == 1)
        deleteStudent();
    else
    {
        cout << "ѡ��������������룺\n";
        cin >> select;
        goto loop1;
    }
}



void searchStudent()
{
    string str;
    bool f = true;
    cout << "������Ҫ�޸���Ϣ��ѧ��ѧ��\n";
    cin >> str;
    for (stu = stulist.begin(); stu != stulist.end(); stu++)
        if (str == (*stu).id)
        {
            cout << "\n����\t\t����\t\t�Ա�\t\tѧ��\t\t�绰" << endl;
            cout << (*stu).name << "\t\t" << (*stu).age << "\t\t" << (*stu).sex
                << "\t\t" << (*stu).id << "\t" << (*stu).phone << endl;
            f = !f;
            break;
        }
    if (f)
        cout << "��ͬѧ��Ϣ������\n";
    int select = Select();
loop1:
    if (select == 0);
    else if (select == 1)
        searchStudent();
    else
    {
        cout << "ѡ��������������룺\n";
        cin >> select;
        goto loop1;
    }
}




void menu()
{
    cout << "\n                               ѧ����Ϣ����ϵͳ\n\n"
        << " *******************************************************************\n\n"
        << "\t\t\t\t 0.�˳�ϵͳ\n\n"
        << "\t\t\t\t 1.¼����Ϣ\n\n"
        << "\t\t\t\t 2.�����Ϣ\n\n"
        << "\t\t\t\t 3.�޸���Ϣ\n\n"
        << "\t\t\t\t 4.ɾ����Ϣ\n\n"
        << "\t\t\t\t 5.������Ϣ\n\n"
        << " *******************************************************************\n";
}

void keydown()
{
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        system("cls");//��������������������
        cout << " ****************************��¼����Ϣ��*********************************\n";
        inputStudent();
        break;
    case 2:
        system("cls");
        cout << " ****************************�������Ϣ��*********************************\n";
        printStudent();
        break;
    case 3:
        system("cls");
        cout << " ****************************���޸���Ϣ��*********************************\n";
        changeStudent();
        break;
    case 4:
        system("cls");
        cout << " ****************************��ɾ����Ϣ��*********************************\n";
        deleteStudent();
        break;
    case 5:
        system("cls");
        cout << " ****************************��������Ϣ��*********************************\n";
        searchStudent();
        break;
    default:
        cout << " ѡ�������������\n";
        system("pause");
        break;
    }
}


int main()
{
    system("color F0");
    while (1)
    {
        system("cls");
        menu();
        keydown();
    }
    system("pause");
    return 0;
}

