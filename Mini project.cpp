#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include<cstdlib>

using namespace std;

const int SIZE=50;


class Food
{
public:
    int FoodId;
    string Foodname;
    float FoodPrice;
    Food* next;

     void setFoodId(int FID)
    { FoodId = FID;}

    void setFoodname(string Fname)
    { Foodname = Fname;}
    void setFoodPrice(float Fprice)
    { FoodPrice = Fprice; }

    int getFoodId()
    {return FoodId;}

    string getFoodname()
    { return Foodname;}

    float getFoodPrice()
    { return FoodPrice;}
};



class FoodList
{
private:
    int count=0;
    int index=-1;
    Food* frontPtr;
    Food* backPtr;

public:
    FoodList() { frontPtr= backPtr= NULL;}
    ~FoodList()
    {
        Food* currFood = frontPtr, *nextNode = NULL;

        while (currFood != NULL)
        {
        nextNode = currFood->next;
        delete currFood;
        currFood = nextNode;
        }
    }

    void setHead (Food*f)
    {
        frontPtr=f;
    }
    Food *getHead ()
    {
        return frontPtr;
    }

    bool IsEmpty()
    {
        return frontPtr== NULL;
    }

    /*void enFood(int FId, string Fname, float FPrice)
    {
        Food* currFood = frontPtr;

        Food* newFood = new Food;
        newFood->FoodId= FId;
        newFood->Foodname= Fname;
        newFood->FoodPrice= FPrice;

        newFood->next = frontPtr;
        frontPtr = newFood;

    }*/

    void enFood(int FId, string Fname, float FPrice)
    {
         Food* newFood = new Food;
         newFood->FoodId= FId;
         newFood->Foodname= Fname;
         newFood->FoodPrice= FPrice;
         newFood->next=NULL;

        if(frontPtr==NULL)
        {
         frontPtr=backPtr=newFood;
        }
        else
        {
         Food* currFood = backPtr;
         currFood->next=newFood;
         backPtr=newFood;
        }

    }


    Food * SearchbyID(int x)
    {
        Food* currFood=frontPtr;
        int currIndex= 1;

        while (currFood && currFood->FoodId!=x)
        {
        currFood=currFood->next;
        currIndex++;
        }
        if (currFood)
        return currFood;
        else
        return 0;
    }

    Food * FindbyPrice(int x)
    {
        Food* currFood=frontPtr;
        int currIndex= 1;

        while (currFood && currFood->FoodPrice!=x)
        {
        currFood=currFood->next;
        currIndex++;
        }
        if (currFood)
        return currFood;
        else
        return 0;
    }
/*
    void deFood(int x)
    {
        Food* prevNode= NULL;
        Food* currFood = frontPtr;
        int currIndex=1;

        while (currFood && currFood->FoodId !=x)
        {
        prevNode = currFood;
        currFood = currFood->next;
        currIndex++;
        }

        if (prevNode)
        {
        prevNode->next = currFood->next;
        delete currFood;
        }
        else
        {
        frontPtr = currFood->next;
        delete currFood;
        }

    }
*/
      void deFood()
    {

        if(frontPtr==NULL)
        {
            cout<<"\nPlease enqueue item first, there is no item to delete. \n\n";
        }
        else
        {

        Food* currFood = frontPtr;

        frontPtr=currFood->next;
        currFood->next=NULL;
        cout<<"Deleted Food : \n"
        << "FOOD-ID    : " <<currFood->FoodId
        << "\nFOOD-NAME  : " << currFood->Foodname
        << "\nFOOD-PRICE : "<< currFood->FoodPrice<< endl
        <<"------------------------------------------------------------------------------\n\n";



        delete currFood;
        }


    }

    void DisplayList()
    {
        int num = 0;
        Food* currFood = frontPtr;

        cout<< setw(12)<< "FOOD-ID" << setw(35) << "FOOD-NAME" << setw(27) << "FOOD-PRICE\n"
                <<"------------------------------------------------------------------------------\n";

        while (currFood != NULL)
        {
            cout << setw(10)<< currFood->FoodId << setw(40)
              << currFood->Foodname<< setw(20)
              << currFood->FoodPrice<< endl;

        currFood = currFood->next;
        num++;
        }

        cout<<"Number of Foods in the FoodList:"<<num<<endl;
    }

    void SortbyID()
    {
        Food* curr = frontPtr;
        int count = 0;
        while(curr!=NULL)
        {
            count++;
            curr = curr->next;
        }
        for(int i = count ; i > 1 ; i-- )
        {
            Food *temp, *swap1;
            swap1 = frontPtr;
            for(int j = 0 ; j < count-1 ; j++ )
            {
                if(swap1->getFoodId() > swap1->next->getFoodId())
                {
                    Food *swap2 = swap1->next;
                    swap1->next = swap2->next;
                    swap2->next = swap1;
                    if(swap1 == frontPtr)
                    {
                        frontPtr = swap2;
                        swap1 = swap2;
                    }
                    else
                    {
                        swap1 = swap2;
                        temp->next = swap2;
                    }
                }
                temp = swap1;
                swap1 = swap1->next;
            }
        }
    }

    void SortbyPrice()
    {
        Food* curr = frontPtr;
        while(curr!=NULL)
        {
            count++;
            curr = curr->next;
        }
        for(int i = count ; i > 1 ; i-- )
        {
            Food *temp, *swap1;
            swap1 = frontPtr;
            for(int j = 0 ; j < count-1 ; j++ )
            {
                if(swap1->getFoodPrice() > swap1->next->getFoodPrice())
                {
                    Food *swap2 = swap1->next;
                    swap1->next = swap2->next;
                    swap2->next = swap1;
                    if(swap1 == frontPtr)
                    {
                        frontPtr = swap2;
                        swap1 = swap2;
                    }
                    else
                    {
                        swap1 = swap2;
                        temp->next = swap2;
                    }
                }
                temp = swap1;
                swap1 = swap1->next;
            }
        }
    }

    void viewFood(Food *food)
    {

        cout<< setw(15) << "FOOD-ID" << setw(35) << "FOOD-NAME" << setw(25) << "FOOD-PRICE\n";
         cout << setw(10) << food->getFoodId() << setw(40)
              << food->getFoodname()<< setw(20)
              << food->getFoodPrice() << endl;
    }

};



class Foodcart : public FoodList
{
private:

    double total=0.0;
    FoodList foodcart;

public:

    void AddFooditem(int fid)
     {
         Food *food = SearchbyID(fid);
         total+=food->getFoodPrice();

         foodcart.enFood(food->getFoodId(),food->getFoodname(),food->getFoodPrice());
     }

    double TotalPrice()
     {
         return total;
     }
    Food * SearchbyPrice(int x)
    {
         return FoodList::FindbyPrice(x);
    }

   virtual void DeFoodcartitem()
    {

        total-=foodcart.getHead()->getFoodPrice();
        foodcart.deFood();
    }

    void SortbyPrice()
    {
        foodcart.SortbyPrice();
    }

    void DisplayFoodcart()
    {
        foodcart.DisplayList();
    }

     void viewCFood(Food *i)
    {
        viewFood(i);
    }

};


class Administrator :  public Foodcart
{
private:


    int ID;
    string adminID;
    string adminname;

public:

    void setAdminID()
    {
      A: cout << "ENTER YOUR STAFF ID-NO (DEFAULT:123456): ";
        cin >> adminID;

        if ((adminID == "123456") || (adminID == "223456") || (adminID == "323456") || (adminID == "423456") || (adminID == "23456"))
        {
        }

        else
        {
            cout << "\nInput Error! Please try again.\nIf you don't have staff ID, contact our office. \n";
            goto A;
        }

    }

     void setadminname()
    {
      cout << "ENTER YOUR NAME : ";
      cin.ignore();
      getline(cin,adminname);
    }

      string getName()
    {
        return adminname;
    }

    string getID()
    {
        return adminID;
    }

    void EnFoodItem(int FoodId,string Foodname,double FoodPrice)
     {
         FoodList::enFood(FoodId,Foodname,FoodPrice);

     }

    void DeFoodItem()
     {


         FoodList::deFood();
     }

   void SearchbyID()
    {
        cout<<"\nPlease enter the food ID : ";
        cin>>ID;
        Food *food = FoodList::SearchbyID(ID);

        if (food==0)
        {
            cout<<" The Food Item is not in the FoodList. \n";
        }
        else
        {
            FoodList::viewFood(food);
        }
    }

    void SortbyID()
    {
        FoodList::SortbyID();
    }

    void showFoodlist()
    {
         FoodList::DisplayList();
    }

};

class Customer : public Foodcart
{
private:
    int ID;
    string customername;
    string n;
    string customerPhone;


public:

     void setcustomername()
    {
      cout << "ENTER YOUR NAME : ";
      cin.ignore();
      getline(cin,customername);
    }

    void setcustomerPhone()
    {
     cout << "ENTER YOUR PHONE NUMBER: ";
     cin >> customerPhone;
    }

    string getcustomername()
    {
      return customername;
    }

    string getcustomerPhone()
    {
     return customerPhone;
    }

    void viewFoodList()
     {
       FoodList::DisplayList();
     }

    void viewFoodcart()
     {
       Foodcart::DisplayFoodcart();
     }

     void Addtocart()
     {

         A: cout<<" Enter the FoodID to add the food in the FoodCart : " ;
         cin>> ID;
         Food *food =FoodList::SearchbyID(ID);
         if(food==0)
         {
            cout<<"Error FoodId. \n";
            goto A;
         }
         Foodcart::AddFooditem(ID);

         Foodcart::DisplayFoodcart();
         cout<<" \n Do you want Add more Food? (y/n) : " ;
         cin>> n;



         if (n=="y")
         goto A;
     }

    virtual void DeFoodcartitem()
     {
         Foodcart::DeFoodcartitem();
     }

    void SortFDbyPrice()
     {
        FoodList::SortbyPrice();
     }

    void sortbyprice()
     {
        Foodcart::SortbyPrice();
     }

     void TotalPrice()
     {
         cout<<"Total Price : " <<Foodcart::TotalPrice()<<endl;
     }

};



int main()
{
    cout << "**************************************************" << endl
         << "|         WELCOME TO FOOD ORDERING SYSTEM        |" << endl
         << "**************************************************" << endl
         << endl;

    ifstream input("FoodList.txt", ios::in);
    if (!input)
    {
       cout<<" Error : The file Can not read. \n" ;
       exit(0);
    }

    Administrator admin;
    Customer cust;

    int FoodId , count=0;
    string Foodname;
    float FoodPrice;
    int ch;
    int choice;

    while(!input.eof())
     {
        input>>FoodId ;
        input>> Foodname;
        input >> FoodPrice;

        admin.enFood(FoodId,Foodname,FoodPrice);

     }


A:
    cout << "\nDEAR USER, YOU WANT TO ACCESS AS :\n\n"
         << "  \t(1). Administrator \n"
         << "  \t(2). Customer\n"
         << "  \t(3). Exit  \n\n"
         << "PLEASE CHOOSE AN OPTION- ";
    cin >> choice;
    std::system("cls");

    if (choice == 1)
    {
        admin.setadminname();
        admin.setAdminID();
        cout << "-------------------------------------------------" << endl
             << "|   DEAR ADMIN, WE GIVE YOU A WARM WELCOME ^_^  |" << endl
             << "-------------------------------------------------" << endl
             << endl;

    C:
        cout << "\n  Dear Admin,\n"
             << "      (1). Food List \n"
             << "      (2). Insert Food to Food List as Queue\n"
             << "      (3). Delete Food as Queue\n"
             << "      (4). Search Food by ID  \n"
             << "      (5). Sort Food by ID \n"
             << "      (6). Logout \n"
             << "      (7). Exit  \n"
             << "      Choose an option- ";
        cin >> ch;

        if (ch == 1)
        {
            std::system("cls");
            cout << "\t-------------------------------------------------" << endl
                 << "\t|               CURRENT STOCK                   |" << endl
                 << "\t-------------------------------------------------" << endl
                 << endl;

                 admin.showFoodlist();
                 goto C;
        }

        else if (ch == 2)
        {
            std::system("cls");
             cout<< "-------------------------------------------------" << endl
                 << "|            Insert Food to Food List            |" << endl
                 << "-------------------------------------------------" << endl
                 << endl;

                 cout<<" Please Enter the Food ID : ";
                 cin>>FoodId;
                 cout<<" Please Enter the Food Name : ";
                 cin.ignore();
                 getline(cin,Foodname);
                 cout<<" Please Enter the Food Price : ";
                 cin>>FoodPrice;

                 admin.EnFoodItem(FoodId,Foodname,FoodPrice);
                 admin.showFoodlist();
                 cout<<endl<<endl;
                 goto C;
        }

        else if (ch == 3)
        {
            std::system("cls");
             cout<< "-------------------------------------------------" << endl
                 << "|                   Delete Food                  |" << endl
                 << "-------------------------------------------------" << endl
                 << endl;

            admin.DeFoodItem();
            admin.showFoodlist();
            cout<<endl<<endl;

            goto C;
        }

        else if (ch == 4)
        {
            std::system("cls");
             cout<< "-------------------------------------------------" << endl
                 << "|               Search Food by ID              |" << endl
                 << "-------------------------------------------------" << endl
                 << endl;

            admin.SearchbyID();

            goto C;
        }

        else if (ch == 5)
        {
            std::system("cls");
             cout<< "\t-------------------------------------------------" << endl
                 << "\t|               Sort Food by ID                 |" << endl
                 << "\t-------------------------------------------------" << endl
                 << endl;
                 admin.SortbyID();
                 admin.showFoodlist();
                 cout<<endl<<endl;
                 goto C;
        }

        else if (ch == 6)
        {
            std::system("cls");
            goto A;
            }

        else if (ch == 7)
        {
            exit(0);
        }

        else
        {
            cout << "\n Input Error 0_0  !\n";
            goto C;
        }
    }

  //customer part start

    else if (choice == 2)
    {
        cust.setHead(admin.getHead());
        cout << "-----------------------------------------------------------" << endl
             << "|     DEAR CUSTOMER, WE GIVE YOU A WARM WELCOME ^_^       |" << endl
             << "-----------------------------------------------------------" << endl

             << endl;
            cust.setcustomername();
            cust.setcustomerPhone();

    D:
        cout << "\n  Dear Customer,\n"
             << "      (1). Food List \n"
             << "      (2). Sort Food List By Price \n"
             << "      (3). Add Item to FoodCart \n"
             << "      (4). Sort FoodCart by Price \n"
             << "      (5). Delete Food as Queue from FoodCart  \n"
             << "      (6). Place Order \n"
             << "      (7). Logout \n"
             << "      (8). Exit  \n"
             << "      Choose an option- ";
        cin >> ch;

        if (ch == 1)
        {

            std::system("cls");
            cout << "\t-------------------------------------------------" << endl
                 << "\t|               CURRENT STOCK                   |" << endl
                 << "\t-------------------------------------------------" << endl
                 << endl;

                 cust.viewFoodList();

            goto D;
        }

        else if (ch == 2)
        {

            std::system("cls");
            cout<< "---------------------------------------------------" << endl
                 <<"|               Sort Food by Price                |" << endl
                 <<"---------------------------------------------------" << endl
                 << endl;


            cust.SortFDbyPrice();
            cust.viewFoodList();
            cout<<endl<<endl;
            goto D;
        }

        else if (ch == 3)
        {
            std::system("cls");
             cout<< "-------------------------------------------------" << endl
                 << "|             Add Item to FoodCart              |" << endl
                 << "-------------------------------------------------" << endl
                 << endl;

                 cust.viewFoodList();
                 cout<<endl<<endl;
                 cust.Addtocart();
                 cust.DisplayFoodcart();
                 goto D;
        }

        else if (ch == 4)
        {
            std::system("cls");
            cout<< "-------------------------------------------------" << endl
                 <<"|               Sort FoodCart by Price          |" << endl
                 <<"-------------------------------------------------" << endl
                 << endl;
                 cust.sortbyprice();
                 cust.viewFoodcart();
            goto D;
        }

        else if (ch == 5)
        {
             cout<< "-------------------------------------------------" << endl
                 << "|         Delete Food from FoodCart             |" << endl
                 << "-------------------------------------------------" << endl
                 << endl;

            cust.DeFoodcartitem();
            cust.viewFoodcart();
            cout<<endl<<endl;

            goto D;
        }

        else if (ch == 6)
        {
            std::system("cls");
            cout<< "\t-------------------------------------------------" << endl
                 <<"\t|                 Place Order                   |" << endl
                 <<"\t-------------------------------------------------" << endl
                 << endl;
                 cout<<"Customer Name : " << cust.getcustomername()<<endl;
                 cout<<"Customer Phone Number : " <<cust.getcustomerPhone()<<endl<<endl;
                 cust.viewFoodcart();
                 cout<<endl;
                 cust.TotalPrice();
                 cout<<endl;
            goto D;
        }

        else if (ch == 7)
        {
            std::system("cls");
            goto A;
        }

        else if (ch == 8)
        {
            exit(0);
        }
        else
        {
            cout << "\n Input Error 0_0  !\n";
            goto D;
        }
    }
    else if (choice==3)
    {
       exit(0);
    }
    else
    {
        cout << "\n Input Error 0_0  !\n";
        goto A;
    }

    return 0;

    }








