/**
Zaid H Alshareef
C00210415
25/11/2017
7.Coordinate conversion*/

/**< preprocessor directives */
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cmath>


using namespace std;


void P2C(double mag, double angle, double *XPtr, double *YPtr)
{
    *XPtr = (mag*cos(angle * M_PI / 180.0));
    *YPtr = (mag*sin(angle * M_PI / 180.0));
}

/**< main function */
int main(void)
{
    /**< variable declarations */
    char input;

    /**< function prototypes */
    char menu(void);
    void cart2Pol(void);
    void pol2Cart(void);

	cout << "Coordinate Conversion\n" << endl;

	do
	{
	    input = menu();

		switch (input)
		{
			case 'p':   cart2Pol();
						break;

			case 'c':   pol2Cart();
						break;

			case 'q':   cout << "\nGoodbye...\n" << endl;
						break;

			default:	cout << "\nInvalid input, try again...\n" << endl;

						getchar();
						getchar();
						break;
		}
	}
	while (input != 'q');

	return 0;
}


char menu(void)
{
    char choice;

    /**< Switch case */
    cout << "\nChoose from the following :\n " <<
            "\nPress p for Cartesian to Polar " <<
            "\nPress c for Polar to Cartesian " <<
            "\nPress q to quit Program \n \t";

    cin >> choice;

/**< for system("cls") */
    system("cls");


return choice;
}


void cart2Pol(void)
{
    /** declarations */
    double x, y, mag, angle;
    double *magPtr = &mag, *anglePtr = &angle;

    /**< function prototype */
    void C2P(double, double, double *, double *);

    cout << "\n Cartesian to Polar...\n" << endl;

    /**Enter a value for x*/
    cout << "\nEnter a value for x: ";
    cin >> x;

    /**Enter a value for y*/
    cout << "\nEnter a value for y: ";
    cin >> y;

    C2P(x, y, magPtr, anglePtr);

    cout << mag << " < " << angle << endl;

    return;
}


void C2P(double xVal, double yVal, double *mPtr, double *aPtr)
{
    *mPtr = sqrt( xVal * xVal + yVal * yVal );
    *aPtr = atan2(yVal, xVal) / M_PI * 180.0;
}


void pol2Cart(void)
{
    double x, y, mag, angle;
    double *xPtr = &x, *yPtr = &y;

    /**< function prototype */
    void P2C(double mag, double angle, double *XPtr, double *YPtr);

    cout << "\n Polar to Cartesian...\n" << endl;

    cout << "\n Enter a Magnitude: " << endl;
    cin >> mag;
    cout << "\n Enter Angle (r): " << endl;
    cin >> angle;

    P2C(mag, angle, xPtr, yPtr);

    cout << x << " " << y << endl;

    return;
}
