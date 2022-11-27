#include <iostream>
#include<fstream>
#include<string>
using namespace std;



 class shopping{

 private:
     int pcode;
     float price;
     float dis;
     string pname;

 public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

 };

 void shopping :: menu ()
 {

 start:
 int choice;
 string email;
 string password;

 cout << "\t\t\t________________________________________________\n";
 cout << "\t\t\t                                                \n";
 cout << "\t\t\t                                                \n";
 cout << "\t\t\t            Supermarket Main Menu               \n";
 cout << "\t\t\t________________________________________________\n";
 cout << "\t\t\t                                                \n";
 cout << "\t\t\t 1) Administrator                               \n";
 cout << "\t\t\t                                                \n";
 cout << "\t\t\t 2) Buyer                                       \n";
 cout << "\t\t\t                                                \n";
 cout << "\t\t\t 3) Exit                                        \n";
 cout << "\t\t\t                                                \n";
 cout << "\t\t\t  please choose from the above                  \n";
 cin >> choice;

 switch(choice){

 case 1:
{


     string email, password;
     cout << "please login \n";
     cout << "enter email: ";
     cin >> email;
     cout << "enter password: ";
     cin >> password;

     if(email == "robby@email.com" && password == "robby@123"){

        administrator();
     }
    else
        {
          cout << "invalid account \n";

        }
 break;
}

 case 2:
    {
        buyer();

    }
 case 3:
    {

        exit(0);

    }
 default :
     {


    cout << "error choice, please select from the given options \n";

     }

 }

 goto start;

 }

 void shopping :: administrator(){

 start:
 int choice;
 cout << "\t\t  Administrator   \n";
 cout << "\t\t                  \n";
 cout << " 1) Add product       \n";
 cout << " 2) Modify product    \n";
 cout << " 3) Back to main menu \n";
 cout << " 4) Delete product    \n";
 cout << "please choose from the above \n";
 cin >> choice;

 switch(choice)
 {
 case 1:
    add();
    break;

 case 2:
    edit();
    break;

 case 3:
    menu();
    break;

 case 4:
    rem();
    break;

 default:{
    cout << "invalid choice";

     }

 }
 goto start;

 }

 void shopping :: buyer()
 {
     m:
     int choice;
     cout << "\t\t  Buyer   \n";
     cout << " 1) Buy       \n";
     cout << " 2) Back to menu \n";
     cout << "please choice from the above \n";
     cin >> choice;

     switch(choice)
     {
     case 1:
        receipt();
        break;

     case 2:
        menu();
        break;

     default:
        cout << "invalid choice \n";
     }

     goto m;
 }

 void shopping :: add()
 {
     m:
     fstream data;
     int c;
     float d;
     float p;
     int token = 0;
     string n;

     cout << "\t\t Add  \n";
     cout << "product code: \n";
     cin >> pcode;
     cout << "product name:  \n";
     cin >> pname;
     cout << "price of product: \n";
     cin >> price;
     cout << "product discount: \n";
     cin >> dis;

     data.open("database.txt", ios::in);

     if(!data)
     {
         data.open("database.txt", ios::app|ios::out);
         data<<pcode<<" "<<pname << " "<<price << " "<<dis << "\n";
         data.close();
     }
     else
        {

        data >>c>>n>>p>>d;
     while(!data.eof()){

        if(c == pcode){

                token++;

        }
        data >>c>>n>>p>>d;
     }
     data.close();
      }

      if(token == 1)
        goto m;

        else
            {
             data.open("database.txt", ios::app|ios::out);
         data<<pcode<<" "<<pname << " "<<price << " "<<dis << "\n";
         data.close();
        }
        cout << "record is inserted !\n";

 }

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int c;
    float p;
    float d;
    int token = 0;
    string n;

    cout << "\t\t        Modifying   \n";
    cout << "product code \n";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout << "\n\n file does not exit \n";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        while(!data1.eof()){
                if(pkey == pcode){

                    cout << "product new code \n";
                    cin >> c;
                    cout << "product price \n";
                    cin >> p;
                    cout << "product name \n";
                    cin >> n;
                    cout << "product discount \n";
                    cin >> d;

                    data1 << c << " " << n << " " << p << " " << d << "\n";
                    cout << "product edited \n";
                    token++;
                }
            else
                {

                data1<<" " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data<<pcode<<pname<<price<<dis<<"\n";
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout << "record is not found \n";
        }
    }

}
void shopping:: rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\t\t Delete product \n";
    cout << "product code \n";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout << "file does not exit \n";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data << pcode<<pname<<price<<dis<<"\n";
         while(!data.eof())
         {
             if(pcode == pkey)
             {
                 cout << "product deleted successfully \n";
                 token++;
             }
             else
                {
                data1<<pcode<<" "<< pname << " " << price << " " << dis << "\n";

                }
             data>>pcode>>pname>>price>>dis;
         }
         data.close();
         data1.close();
         remove("database.txt" );
         rename("database1.txt", "database.txt");

         if(token == 0)
         {
             cout << "record not found \n";
         }

    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\t prono \t\t name \t\t price \n";
    data >> pcode >> pname >> price >> dis;

    while(!data.eof())
    {
        cout << pcode << " " << pname << " " << price << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping :: receipt()
{
  m:
  fstream data;
  int arr[100];
  int arrq[100];
  int c = 0;
  string choice;
  int amount = 0;
  float dis = 0;
  float total = 0;

  data.open("database.txt", ios::in);
  cout << "\t\t\t\t  Receipt \n\n";
  if(!data)
  {
      cout << "file is empty \n";
  }
  else
  {
      data.close();

      list();
      cout << "\t\t|_______________________________|\n";
      cout << "\t\t\t\t  please place the order \n\n\n";
      cout << "\t\t|                               |\n";
      cout << "\t\t|                               |\n";
      cout << "\t\t|_______________________________|\n";
      do{
      cout << "enter product code \n";
      cin >> arr[c];
      cout << "enter produce quantity \n";
      cin >> arrq[c];

      for(int i = 0 ;i < c ; i++){

        if(arr[c] == arr[i]){
            cout << "duplicate product, try again \n";
            goto m;
        }
      }
      c++;
      cout << "it you want to buy another product press y else press no \n";
      cin >> choice;
      }
      while (choice == "y");
      {
          cout << "\t\t\t\t_________________Receipt______________________\n";

          cout << "\t product no \t name \t quantity \t price \t amount \t discount \t amount with discount \n";

          for(int i = 0; i < c; i++)
          {
              data.open("database.txt", ios::in);
              data>>pcode>>pname>>price>>dis;

              while(!data.eof())
              {
                  if(pcode == arr[i])
                  {
                      amount = price * arrq[i];
                      dis = amount - (amount*dis / 100);
                      total += dis;
                      cout << pcode << "\t" << pname << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\t" << dis << endl;

                  }
                  data>>pcode>>pname>>price>>dis;
              }

          }
          data.close();
      }
      cout << "\n\n total amount: " << total << endl;
  }
  }
int main()
{
    shopping s;
    s.menu();
}
