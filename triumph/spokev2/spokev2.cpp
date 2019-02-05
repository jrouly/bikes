/***************************************************************************
* COPYRIGHT:    (C) 2017 << Robert Shackelford >> All Rights Reserved.
* PROJECT:      Spoke Calc v.2.0  (UPDATE of v.1.0 c. @1996)
* FILE:         << spokev2.cpp  spokev2.obj  spokev2.exe >>
* PURPOSE:      << Calculates spoke lengths for a proposed wheel assembly >>
* PROGRAMMER:   << Robert Francis Shackelford >>
* START DATE:   << 5/8/2017 >>
* USE POLICY:   This program may be compiled and used at no charge.  All that
*		this author asks is that the source code, object file, and
*		executable not be altered in any way.  This program may not
*		be sold to any party - but costs may be recovered for the
*		disk, tape, or CD used to distribute these file.
****************************************************************************/
/***** CHANGES *************************************************************
In v1.0, a spoke hole diameter of 2.0mm was assumed for all hubs.  This
forced a manual adjustment after spoke length calculation usually of -.20mm
or more depending upon how much larger than 2.0mm the hole actually was.

For holes 2.8mm to 3.0mm - taking .5mm off the final spoke length was often
required.

In v2.0, we introduce a variable "float s".  This variable is set by the
user at input time and is then divided by 2 when the main function kicks in.

As the spoke length calculation concludes "float s" is subtracted from
"float sl" for the final spoke length..

The end user in v2.0 no longer has to make post calculation adjustments for
spoke hole diameters.

***************************************************************************/

/***** DESCRIPTION *********************************************************
This program computes the spoke length for a proposed wheel assembly
for use on a bicycle. The formula is given below:

	SL = SQRT(A^2 + B^2 + C^2) - s / 2

	A = 1/2rSIN(t)
	B = 1/2R - 1/2rCOS(t)
	C = hub flange offset
	t = (360 * x crossings) / n spokes
	R = effective rim diameter
	r = hub diameter hole to hole
  s = diameter of spoke holes in the hub flange

Calculations are done for each of the two sides of a wheel. On most
front wheels though, both sides are symetrical therefore only one measurement
is needed.

  See manual for data collecting procedures.

***************************************************************************/

/***** INCLUDES *****/

#include <iostream>
#include <cstdlib>
#include <cfloat>
#include <cmath>


/***** FUNCTIONS *****/

float t_parameter(float n, float x)
/* PURPOSE:  Computes the angle in degrees to be used in a_parameter and
	     b_parameter.
   RECEIVES: The number of spokes per side (n) and crossings (x).
   RETURNS:  (t) in degrees.
   REMARKS:  none
*/
{   float t;
    t = (360.00 * x) / n;
    return t;
}

/*-------------------------------------------------------------------------*/

float a_parameter(float r, float t)
/* PURPOSE:  Computes (A) squared in the above described formula.
   RECEIVES: Hub radius (r) and (t) in degrees.
   RETURNS:  (a)
   REMARKS:  (t) is converted to radians due to compiler preferences.
*/
{   float t1_rad;
    t1_rad = (M_PI * t) / 180.00;
    float a;
    a = (0.5 * r) * sin(t1_rad);
    return a;
}

/*-------------------------------------------------------------------------*/

float b_parameter(float R, float r, float t)
/* PURPOSE:  Computes (B) squared in the above described formula.
   RECEIVES: Hub radius (r) and (t) in degrees.
   RETURNS:  (b)
   REMARKS:  (t) is converted to radians due to compiler preferences.
*/
{   float t2_rad;
    t2_rad = (M_PI * t) / 180.00;
    float b;
    b = (0.5 * R) - ((0.5 * r) * cos(t2_rad));
    return b;
}

/*-------------------------------------------------------------------------*/

float sl_parameter(float a_norm, float b_norm, float c)
/* PURPOSE:  Computes formula result before square root is taken.
   RECEIVES: (A) (a_norm) and (B) (b_norm) and (C) (c).
   RETURNS:  Result before the square root is taken.
   REMARKS:  Square root is taken in main with final adjustment for spoke
	     length.
*/
{   float sl;
    sl = (a_norm * a_norm) + (b_norm * b_norm) + (c * c);
    return sl;
}

/*-------------------------------------------------------------------------*/

int main()
{  float n;
   float x;
   float R;
   float r;
   float c;
   float s;
   std::cout << "Enter the number of spokes on one side:" "\n";
   std::cin >> n;
   std::cout << "Enter the number of crossings to be used:" "\n";
   std::cin >> x;
   std::cout << "Enter the rim diameter in millimeters:" "\n";
   std::cin >> R;
   std::cout << "Enter the hub diameter in millimeters:" "\n";
   std::cin >> r;
   std::cout << "Enter the offset in millimeters:" "\n";
   std::cin >> c;
   std::cout << "Enter the spoke hole diameter in millimeters:" "\n";
   std::cin >> s;

   float t = t_parameter(n, x);
   float a_norm = a_parameter(r, t);
   float b_norm = b_parameter(R, r, t);

   float sl_norm = sl_parameter(a_norm, b_norm, c);

   float sl = sqrt(sl_norm) - s / 2.0;

   std::cout << "Your spoke length for this side of the wheel is: " << sl;
   std::cout << "\n";

   return EXIT_SUCCESS;
}

