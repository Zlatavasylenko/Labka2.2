#include <iostream>  
#include <cmath>  
#include <iomanip>  
#include <stdio.h>  
#include <conio.h>  
  
  
using namespace std;  
  
void aboutA();  
void putHeader();  
void putResult(double x);  
bool getAnswer();  
double getArg(double a, double b);  
double getIncr();  
double getDouble();  
double calcLib(double x);  
double calcSum(double x);  
bool processXH(double x, double h, double b);  
  
  
  
int main() {
    double a = -1; // right limit
    double b = 1; // left limit
    aboutA();

    bool first_time = true;

    while (true) {
        if (!first_time) {
            if (!(getAnswer())) {
                break;
            }
        }

        double x = getArg(a, b);
        double h = getIncr();

        if (!(processXH(x, h, b))) {
            break;
        }
        first_time = false;
    }

    std::cout << "<<<END OF WORK>>";
    return 0;
} 
  
void aboutA()  
{  
    cout << "Close function definition version 2\nK-14 Vasylenko Zlata\n";  
}  
  
double getArg(double a, double b)  
{  
    double x;  
    for (;;)  
    {  
        try  
        {  
            cout << "Enter a real number from the (-1;1) interval:\n";  
            x = getDouble();  
  
            if (x > a && x < b)  
            {  
                break;  
            }  
            else   
            {  
                cout << "Look at the limitations of the argument!!! " << x << endl;  
            }  
        }  
        catch (int exeption)  
        {  
            switch(exeption)  
                case 1:   
            {  
                 
                cin.clear(); 
                while(cin.get()!='\n'); 
                cout << "<<<GETDBL: WRONG X >>>\n";  
            }  
 
        }  
          
    }  
    return x;  
}  
  
double getIncr()  
{  
    double x;  
    for (;;)  
    {  
        try  
        {  
            cout << "Enter the value of step(positive):\n";  
            x = getDouble();  
  
            if (x > 0)  
            {  
                break;  
            }  
            else if(x<=0)  
            {  
                x = 0.01;  
                break;  
            }  
  
        }  
        catch (int exeption)  
        {  
            switch (exeption)  
            case 1:  
            {  
                cin.clear();  
                while(cin.get()!='\n'); 
                cout << "<<<GETDBL: WRONG H >>>\n";  
            }  
        }  
          
    }  
    return x;  
}  
  
double getDouble()  
{  
    double  param;  
    try   
    {  
        if (cin >> param)  
        {  
            return (param);  
        }  
        else  
        {  
              
            throw 1;  
        }  
    }  
    catch (exception){}  
}  
  
void putHeader()  
{  
     cout << setw(17) << "x" << setw(17) << "f_lib(x)" <<  
  setw(17) << "f_sum(x)"<< setw(17) << "difference" << endl;  
}  
  
  
  
void putResult( double x)   
{  
    double lib, sum;  
    lib = calcLib(x);  
    sum = calcSum(x);  
    cout << setw(17) << x << setw(17) << lib << setw(17) << sum << setw(17) << lib - sum << setw(17) << endl;  
}  
double calcLib(double x)  
{  
    return sinh(x);  
}  
  
  
  
double calcSum(double x)  
{  
    int n = 0;  
    double sum = 0;  
    double dod = x;  
    double e = 0.00000001;  
    double x2 = x * x;  
    int n2;  
    for (n = 0; abs(dod) > e; )  
    {  
        sum += dod;  
        n++;  
        n2 = 2 * n;  
        dod = (dod * x2) / ((n2) * (n2 + 1));  
    }  
      
    return sum;  
}  
  
bool processXH(double x, double h, double b) {
    bool first_time = true;
    //double epsilon = 0.00000001;

    do {
        putHeader();
        for (int n = 0; n < 10; n++) {
            if (first_time) {
                first_time = false;
            } else {
                if (x + h < b) {
                    if ((std::fabs(b - x - h) >=0.00000001)) {
                        x += h;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

           
            double lib = calcLib(x);  
             double sum = calcSum(x);
            putResult(x);
        }

        if (x + h < b) {
            if (std::fabs(b - x - h) >=0.00000001) {
                std::cout << std::endl << "(!) The table has more rows. Show the next ones? ";
                if (!(getAnswer())) {
                    return false;
                }
            } else {
                // std::cout << std::endl << "(!) End of the table. " << std::endl;
                break;
            }
        } else {
            break;
        }

        } while (true);
    std::cout << std::endl << "(!) End of the table. " << std::endl;
    return true;
}

bool getAnswer() {
    std::cout << std::endl << "Press any key to continue or [Esc] to exit the program." << std::endl << std::endl;
    int c = getch();
    if (c == 27) {
        return false;
    } else {
    return true;
    }
}
