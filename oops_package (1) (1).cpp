#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<unistd.h>
#define BACK 8
#define RET 13
static int tickets=100;
using namespace std;
class Customer;
fstream info;
string password();
class Customer
{
    public:

        string user_n,name,city,email,state,date;
        int mob_no,no_people,no_rooms,no_nights,pincode;
        int accmdtion,flight;

        int tour_info(string);
        void get_per_info();
        void putinfo();
        void card_details();
};
void Customer::get_per_info()
{
        cout<<"\nEnter the following details to continue Booking!\n";
        cout<<"\nName : ";
        getline(cin>>ws,name);
        cout<<"\nState : ";
        getline(cin>>ws,state);
        cout<<"\nPin Code : ";
        cin>>pincode;
        cout<<"\nCity : ";
        getline(cin>>ws,city);
        cout<<"\nEmail ID : ";
        getline(cin>>ws,email);
        cout<<"\nMobile Number : ";
        cin>>mob_no;
}
void Customer::card_details()
{
        int card_no;
        string c_name,cvv,validity,otp;
        cout<<"\nEnter the Card Number : ";
        cin>>card_no;
        cout<<"\nEnter the Card holder name : ";
        getline(cin>>ws,c_name);
        cout<<"\nEnter the Card validity date : ";
        getline(cin,validity);
        cout<<"\nEnter CVV : ";
        cvv=password();
        sleep(2);
        system("cls");
        cout<<"\n\n\t\t\t\t\t\t\tEnter OTP : ";
        otp=password();
        sleep(2);
        system("cls");
        system("color 06");

        cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        cout<<"\n\t\t\t\t\t\t\t\t\tPAYMENT SUCCESSFUL............ \n\n\t\t\t\t\t\t\t\t\tENJOY YOUR TRIP\n\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
        tickets=tickets-no_people;
        sleep(2);
        system("cls");
        system("color 07");
}
int Customer::tour_info(string user)
{
        char rebook;
        REBOOK:
        cout<<"\n\n\t\t\t\t\t\t\t\tRemaining tickets : "<<tickets<<"\n\t\t\t\t\t\t\tPlease book accordingly!!";
        user_n=user;
        cout<<"\nEnter the date you would like to start the trip (dd-mm-yyyy): ";
        getline(cin>>ws,date);
        cout<<"\nEnter the number of people joining the trip : ";
        cin>>no_people;
        if(no_people > tickets)
        {
                cout<<"\n\t\t\t\t\t\t\t\t\tSORRY WE ARE IN SHORT OF TICKETS\n\n\t\t\t\t\t\t\t\t\tBook Again ? (y/n)\n";
                cin>>rebook;
                if(rebook=='y' || rebook=='Y')
                    {
                        sleep(1);
                        system("cls");
                        goto REBOOK;
                    }
                else
                    return -1;
        }
        else
        {
                cout<<"\nEnter the number of nights you would like to spend : ";
                cin>>no_nights;
                cout<<"\nEnter the number of rooms you prefer : ";
                cin>>no_rooms;
                cout<<"\nWould you prefer\n\t\t1 . Economic Class\n\t\t2 . Business Class\n";
                cin>>flight;

                cout<<"\nWhat type of rooms do you prefer ?\n\t\t1 . Single Room\n\t\t2 . Deluxe Room\n\t\t3 . Suite Room\n";
                cin>>accmdtion;
        }
        return 0;

}
Customer c;
class Package
{
    protected:
        int pkg_ch;
        float flight_cost;
        void domestic();
        void international();
};

void Package::domestic()
{
        system("color 07");
        cout<<"\n\n\t\t\tDomestic Package list\n\n";
        cout<<"\n1  		Goa 							 4000\n2  		Delhi 						         6000\n3   		Bengaluru 						 4000\n4   		Jaipur         						 7000\n5   		Agra 							 8000\n6   		Kolkata 						 8500\n7   		Shimla 						         8000\n8   		Hyderabad 						 4,500\n9   		Manali						         8,000\n10  		Ladakh 						         12,000\n11  		Jammu Kashmir					         14,000\n12  		Pondicherry 					         4,000\n13  		Darjeeling						 15,000\n14  		Amritsar						 16,000\n";
        cout<<"\nEnter Your preferred Package from the above list : ";
        cin>>pkg_ch;
}

void Package::international()
{
        system("color 07");
        cout<<"\n\n\n\t\t\tInternation Package list\n\n";
        cout<<"\n1.EUROPIAN TOUR\t\t\t\t\t\t\t\t1,00,000\n\tFrance\n\tSpain\n\tGermany\n\tItaly\n\tRome\n\tSweden\n\tParis\n2.NORTH ASIAN TOUR\t\t\t\t\t\t\t50,000\n\tMoscow\n\tSiberia\n\tSt.petersburg\n\tSochi\n3.SOUTH ASIAN TOUR\t\t\t\t\t\t\t50,000\n\tSingapore\n\tMaldieves\n\tBali\n\tThailand\n\tPhillipines\n4.NORTH AMERICAN TOUR-I\t\t\t\t\t\t\t50,000\n\tSan Francisco\n\tNew York\n\tDallas\n\tBoston\n5.NORTH AMERICAN TOUR-II\t\t\t\t\t\t1,00,000\n\tWalt Disney world resort\n\tLos angels\n\tChicago\n\tLas vegas\n\tMiami\n6.AFRICAN TOUR\t\t\t\t\t\t\t\t50,000\n\tEgypt\n\tCapetown\n\tJohannesburg\n\tDurban\n\tWestern sahara\n7.AUSTRALIAN TOUR\t\t\t\t\t\t\t45,000\n\tSydney\n\tMelbourne\n\tGold coast\n\tSunshine coast\n\tNew castle\n";
        cout<<"\nEnter Your preferred Package from the above list : ";
        cin>>pkg_ch;
}

class Booking:public Package,public Customer
{
    public:
        int t,ch;
        int flag;
        char con_ch,fin,re;
        float tot_flight,tot_accm,tot_cost,disc,gst,service,accm,fl;


        void basic_choice(int,string);
        void confirm_booking(string);
        void discount();
        void cal_amt();
        void cancel_booking(string);
        void modify_booking(string);

};

void Booking::discount()
{
        disc=0;
        if(no_people>5)
        {
                cout<<"\nCongatulations!!! You Got 15% discount\n";
                disc=tot_cost*0.15;
        }
        else if(no_people>25)
        {
                cout<<"\nCongatulations!!! You Got 45% discount\n";
                disc=tot_cost*0.45;
        }
}

void Booking::cal_amt()
{
        float D_c[14]={4000,6000,4000,7000,8000,8500,8000,4500,8000,12000,14000,4000,15000,16000};
        float I_c[7]={100000,50000,50000,50000,100000,50000,45000};
        switch(accmdtion)
        {
                case 1:
                    accm=2500;
                    break;
                case 2:
                    accm=4000;
                    break;
                case 3:
                    accm=5700;
                    break;
        }
        fstream cost;
        if(ch==1)
        {
                fl=D_c[pkg_ch-1];
                if(flight==2)
                {
                        fl=fl+(fl*0.5);
                }
        }
        else if(ch==2)
        {
                fl=I_c[pkg_ch-1];
                if(flight==2)
                {
                        fl=fl+(fl*0.5);
                }
        }
        tot_accm=accm*(no_rooms)*no_nights;
        tot_flight=(fl*no_people);
        service=(tot_accm+tot_flight)*0.5;
        tot_cost=tot_accm+tot_flight+service;
        gst=(tot_cost)*0.5;
        discount();
        tot_cost=tot_cost-disc;
        cout<<"\n\t\t\tFl : "<<fixed<<setprecision(2)<<fl;
        cout<<"\n\t\t\tAccomodation : "<<setprecision(2)<<tot_accm;
        cout<<"\n\t\t\tFlight cost : "<<setprecision(2)<<tot_flight;
        cout<<"\n\t\t\tTAX : "<<setprecision(2)<<gst;
        cout<<"\n\t\t\tService : "<<setprecision(2)<<service;
        cout<<"\n\t\t\tDiscount : "<<setprecision(2)<<disc;
        cout<<"\n\n\t\t\tTOTAL COST : "<<setprecision(2)<<fixed<<tot_cost<<endl;

}

void Booking::confirm_booking(string user)
{

        int flag1;
        cout<<"\n\n\t\t\t\t\t\t\t\tRemaining tickets : "<<tickets;
        cout<<"\n\t\t\t\t\t\t\t\tWHAT DO YOU PREFER?\n\n\t\t\t\t\t\t\t\t1 . DOMESTIC TRIP\n\t\t\t\t\t\t\t\t2 . INTERNATIONAL TRIP\n";
        cin>>ch;
        sleep(2);
        system("cls");
        if(ch==1)
            domestic();
        else if(ch==2)
            international();
        sleep(2);
        system("cls");
        cout<<"\nEnter the Details\n";
        flag1=c.tour_info(user);
        sleep(2);
        system("cls");
        if(flag1==0)
        {
                c.get_per_info();
                sleep(2);
                system("cls");

                info.open("Customer_details.dat",ios::app  | ios::binary);
                info.write((char*)&c,sizeof(c));
                info.close();

                info.open("Customer_details.dat", ios::in | ios::binary);
                info.read((char*)&c,sizeof(c));
                while(!info.eof())
                {
                        if(c.user_n==user)
                         {
                                  user_n=c.user_n;
                                  name=c.name;
                                  city=c.city;
                                  email=c.email;
                                  state=c.state;
                                  date=c.date;
                                  mob_no=c.mob_no;
                                  no_people=c.no_people;
                                  no_rooms=c.no_rooms;
                                  no_nights=c.no_nights;
                                  pincode=c.pincode;
                                  accmdtion=c.accmdtion;
                                  flight=c.flight;
                                  break;
                         }
                         info.read((char*)&c,sizeof(c));
                }
                info.close();

                cal_amt();
                cout<<"\nDo you want to continue payment? (y/n) : ";
                cin>>con_ch;
                sleep(2);
                system("cls");
                if(con_ch=='y'|| con_ch=='Y')
                {
                        card_details();
                }
                else
                {
                        cout<<"\nPress any key to logout\n";
                        fin=getch();
                }
        }
}

void Booking::cancel_booking(string user)
{
        flag=0;
        int d_tickets;
        info.open("Customer_details.dat",ios::in | ios::binary);
        info.read((char*)&c,sizeof(c));
        while(!info.eof())
        {
            if(user==c.user_n)
            {
                    d_tickets=c.no_people;
            }
            info.read((char*)&c,sizeof(c));
        }
        info.close();
        fstream k;
        k.open("Dummy1.dat",ios::app|ios::binary);
        info.open("Customer_details.dat",ios::in | ios::binary);
        info.read((char*)&c,sizeof(c));
        while(!info.eof())
        {
            if(user!=c.user_n)
            {
                    k.write((char*)&c,sizeof(c));
            }
            else
                    flag=1;
            info.read((char*)&c,sizeof(c));
        }
        k.close();
        info.close();
        remove("Customer_details.dat");
        rename("Dummy1.dat","Customer_details.dat");
        if(flag==0)
        {
                cout<<"\nSorry No previous bookings found from the account\n";
                cout<<"\nWould you like to book a trip?\n";
                cin>>re;
                if(re=='y' | re=='Y')
                {
                        confirm_booking(user);
                }
        }
        else
        {
                tickets+=d_tickets;
                cout<<"\nSuccessfully deleted would you like to book Again?";
                cin>>re;
                if(re=='Y' | re=='y')
                        confirm_booking(user);
                else
                {
                        cout<<"\n\t\t\t\t\tThank you\n";
                        cout<<"\nPress any key to logout\n";
                        fin=getch();
                }
        }
        sleep(2);
        system("cls");
}

void Booking::modify_booking(string user)
{
        flag=0;

        info.open("Customer_details.dat", ios::in | ios::out | ios::binary);
        while(info.read((char*)&c,sizeof(c)))
        {
                if(user==c.user_n)
                {
                    flag=1;
                    float old_cost;
                          user_n=c.user_n;
                          name=c.name;
                          city=c.city;
                          email=c.email;
                          state=c.state;
                          date=c.date;
                          mob_no=c.mob_no;
                          no_people=c.no_people;
                          no_rooms=c.no_rooms;
                          no_nights=c.no_nights;
                          pincode=c.pincode;
                          accmdtion=c.accmdtion;
                          flight=c.flight;
                    cal_amt();
                    old_cost=tot_cost;
                    int m;
                    char r,rebook1;
                    int dummy;
                    REMOD:
                    cout<<"\nName : "<<c.name;
                    cout<<"\nNumber of people : "<<c.no_people<<"\nNumber of Nights : "<<c.no_nights<<"\nNumber of Rooms : "<<c.no_rooms<<endl;
                    Repeat:
                    cout<<"Modify \n1.Number of people\n2.Number of Nights\n3.Number of Rooms\n";
                    cin>>m;
                    if(m==1)
                    {
                            cout<<"\n\n\t\t\t\t\t\t\t\tRemaining tickets : "<<tickets;
                            cout<<"\nEnter the Number of people : ";
                            cin>>dummy;
                            c.no_people=dummy;
                            if(dummy > tickets)
                            {
                                    cout<<"\n\t\t\t\t\t\t\t\t\tSORRY WE ARE IN SHORT OF TICKETS\n\n\t\t\t\t\t\t\t\t\tCHANGE AGAIN ? (y/n)\n";
                                    cin>>rebook1;
                                    if(rebook1=='y' || rebook1=='Y')
                                        {
                                            sleep(1);
                                            system("cls");
                                            goto REMOD;
                                        }
                                    else
                                        return;
                            }
                    }
                    else if(m==2)
                    {
                            cout<<"\nEnter the Number of Nights : ";
                            cin>>dummy;
                            c.no_nights=dummy;
                    }
                    else if(m==3)
                    {
                            cout<<"\nEnter the Number of Rooms : ";
                            cin>>dummy;
                            c.no_rooms=dummy;
                    }
                    cout<<"\nDo you want to modify again (y/n) : ";
                    cin>>r;
                    sleep(1);
                    system("cls");
                    if(r=='y' | r=='Y')
                            goto Repeat;
                    cout<<"\nModified records : \n";
                    cout<<"\nName : "<<c.name;
                    cout<<"\nNumber of people : "<<c.no_people<<"\nNumber of Nights : "<<c.no_nights<<"\nNumber of Rooms : "<<c.no_rooms<<endl;
                          user_n=c.user_n;
                          name=c.name;
                          city=c.city;
                          email=c.email;
                          state=c.state;
                          date=c.date;
                          mob_no=c.mob_no;
                          no_people=c.no_people;
                          no_rooms=c.no_rooms;
                          no_nights=c.no_nights;
                          pincode=c.pincode;
                          accmdtion=c.accmdtion;
                          flight=c.flight;
                    cal_amt();
                    cout<<"\nYour previous Cost : "<<old_cost;
                    if(tot_cost-old_cost>0)
                    {
                            cout<<"\nThe Amount to be paid by you is : "<<tot_cost-old_cost;
                            cout<<"\nDo you want to continue payment? (y/n) : ";
                            cin>>con_ch;
                            sleep(2);
                            system("cls");
                            if(con_ch=='y'|| con_ch=='Y')
                            {
                                    card_details();
                            }
                            else
                            {
                                    cout<<"\nPress any key to logout\n";
                                    fin=getch();
                            }
                    }
                    else if(tot_cost-old_cost<0)
                    {
                            cout<<"\nThe amount to be refunded is "<<old_cost-tot_cost;
                            cout<<"\n\nYour Amount will be refunded Soon!\n";
                            cout<<"\nIf your amount is not refunded within 4 working days then contact the bank!\n";
                            cout<<"\nPress any key to logout\n";
                            fin=getch();
                    }
                    else
                    {
                            cout<<"\nYour details Modified!\n";
                            cout<<"\nPress any key to logout\n";
                            fin=getch();
                    }
                    int pos=sizeof(c);
                    info.seekp(-pos,ios::cur);
                    info.write((char*)&c,sizeof(c));
                    break;
                }
        }
        if(flag==0)
        {
                cout<<"\nSorry No previous bookings found from the account\n";
                cout<<"\nWould you like to book a trip?\n";
                cin>>re;
                if(re=='y' | re=='Y')
                {
                        confirm_booking(user);
                }
        }
        else
        {
                cout<<"\n\t\t\t\tENJOY YOUR TRIP\n";
                info.close();
                sleep(4);
                system("cls");
        }
}

void Booking::basic_choice(int n,string user)
{
        system("color 01");
        if(n==1)
        {
                cout<<"\n\n\n\n\t\t\t\t\t\t\tWELCOME TO AGENCY TOUR BOOKING!!!\n\n";
                confirm_booking(user);
        }
        if(n==2)
        {
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\tWOULD YOU LIKE TO \n\n\t\t\t\t\t\t\t\t1 . CANCELL BOOKING\n\t\t\t\t\t\t\t\t2 . MODIFY BOOKING\n";
                cin>>t;
                sleep(2);
                system("cls");
                if(t==1)
                {
                        cancel_booking(user);
                        system("cls");
                }
                if(t==2)
                {
                        modify_booking(user);
                        system("cls");
                }
        }

}



int main()
{

        string user,pass1,pass;
        int n;
        Booking b;
        while(tickets!=0)
        {
                system("color 02");
                cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"<<"\t\t\t\t\t\t\t\t\t\tWELCOME TO  AGENCY\n\n"<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
                cout<<"\n\n\t\t\t\t\t\t\t\t\t\t 1. SIGN UP\n\n\t\t\t\t\t\t\t\t\t\t 2. SIGN IN\n";
                cin>>n;
                system("cls");
                if(n==1)
                {       signup:
                        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t USER NAME : ";
                        getline(cin>>ws,user);
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t PASSWORD  : ";
                        pass1=password();
                        cout<<"\n\t\t\t\t\t\t\t\t\t CONFIRM PASSWORD : ";
                        pass=password();
                        if(pass1==pass)
                        {
                                cout<<"\n\t\t\t\t\t\t\t\t  ACCOUNT CREATED SUCCESFULLY!!!\n";

                                sleep(2);
                                system("cls");
                        }
                        else
                        {
                                cout<<"\n\t\t\t\t\t\t\tENTER VALID PASSWORD (PASSWORD DOESNOT MATCH!)";
                                sleep(3);
                                system("cls");
                                goto signup;
                        }

                }
                if(n==2)
                {
                        cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t USER NAME : ";
                        getline(cin>>ws,user);
                        cout<<"\n\t\t\t\t\t\t\t\t\t\t PASSWORD  : ";
                        pass=password();
                        cout<<"\n\t\t\t\t\t\t\t\t\t\tWELCOME BACK "<<user<<"!!!\n";

                        sleep(2);
                        system("cls");
                }


                b.basic_choice(n,user);


        }
        if(tickets==0)
        {
                cout<<"\n\t\t\t\t\t\t\t\t\tSORRY WE ARE OUT OF TICKETS\n\n\t\t\t\t\t\t\t\t\tVISIT AGAIN!!!!!!\n";
        }



}
string password()
{
        string psswd = "";
        char p_c;
        while (true)
        {

            p_c = getch();
            if (p_c == RET)
            {
                cout << endl;
                return psswd;
            }
            else if (p_c == BACK && psswd.length() != 0)
            {
                psswd.pop_back();
                cout << "\b \b";

                continue;
            }
            else if (p_c == BACK && psswd.length() == 0)
            {
                continue;
            }
            psswd.push_back(p_c);
            cout << "*";
        }
}

