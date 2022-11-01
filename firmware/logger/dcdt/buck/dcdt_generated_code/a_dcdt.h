/**
  Summary:
  This header file was created using Microchip Digital Compensator Design Tool (DCDT)
  and includes system summary and digital compensator coefficients. This file
  should be included in the MPLAB X project directory.

  File Name:     a_dcdt.h
  Project Name:  buck
  Date:          3/5/2016
  Time:          23:04.51

  Software License Agreement

  Copyright © 2016 Microchip Technology Inc.  All rights reserved.
  Microchip licenses to you the right to use, modify, copy and distribute
  Software only when embedded on a Microchip microcontroller or digital
  signal controller, which is integrated into your product or third party
  product (pursuant to the sublicense terms in the accompanying license
  agreement).

  You should refer to the license agreement accompanying this Software
  for additional information regarding your rights and obligations.

  SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
  OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
  PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
  OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
  BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
  DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
  INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
  COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
  CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
  OR OTHER SIMILAR COSTS.
 **/
#ifndef _A_DCDT_DEFINES_H
#define _A_DCDT_DEFINES_H

/**
  Compensator Type:  3P3Z
      Entry                Value  
    ---------            ---------
  Pole 0                 8.3300e+02 Hz
  Pole 2                 1.9700e+04 Hz
  Pole 3                 1.0000e+05 Hz
  Zero 1                 1.8880e+03 Hz
  Zero 2                 1.4160e+03 Hz
  Gain(Kdc)              1.000
  Warp                   false
  PWM Frequency          2.0000e+05
  PWM Sampling Ratio     1
  Sampling Frequency     2.0000e+05
  PWM Max Resolution     1.0600e-09
  Computational Delay    1.5000e-06
  Gate Drive Delay       1.5000e-07
  Control Output Min.    0
  Control Output Max.    32767
  Kuc Gain               2.5259e+01
  Use Kuc Gain           false


  PWM Calculations
      Name                Value  
    ---------           ---------
  Bits of Resolution    12.204
  Gain                  2.120e-04


  s-domain transfer function

               Wp0   Wp2(Wp3)(Wz1 + s)(Wz2 + s)
  H(s) = Kdc X --- X --------------------------
                s    Wz1(Wz2)(Wp2 + s)(Wp3 + s)

                 5.23e+03   1.24e+05(6.28e+05)(1.19e+04 + s)(8.90e+03 + s)
  H(s) = 1.000 X -------- X ----------------------------------------------
                    s       1.19e+04(8.90e+03)(1.24e+05 + s)(6.28e+05 + s)



  Digital Compensator Coefficients

  Name    Value     Normalized    Q15      Hex
  ----    -----     ----------    ---      ---
  a1      1.305     0.433         14186    0x376A
  a2      -0.188    -0.062        -2045    0xF803
  a3      -0.117    -0.039        -1272    0xFB08
  b0      3.015     1.000         32764    0x7FFC
  b1      -2.710    -0.899        -29451   0x8CF5
  b2      -3.007    -0.997        -32682   0x8056
  b3      2.717     0.901         29533    0x735D


  z-domain transfer function

         u(z)  B0 + B1z^(-1) + B2z^(-2) + B3z^(-3)
  H(z) = --- = -----------------------------------
         e(z)  A0 - A1z^(-1) - A2z^(-2) - A3z^(-3)

          (3.015) + (-2.710)z^(-1) + (-3.007)z^(-2) + (2.717)z^(-3)
  H(z) = -----------------------------------------------------------
          1 - (1.305)z^(-1) - (-0.188)z^(-2) - (-0.117)z^(-3)

**/


// Compensator Coefficient Defines
#define A_COMP_3P3Z_COEFF_A1      0x376A
#define A_COMP_3P3Z_COEFF_A2      0xF803
#define A_COMP_3P3Z_COEFF_A3      0xFB08
#define A_COMP_3P3Z_COEFF_B0      0x7FFC
#define A_COMP_3P3Z_COEFF_B1      0x8CF5
#define A_COMP_3P3Z_COEFF_B2      0x8056
#define A_COMP_3P3Z_COEFF_B3      0x735D
#define A_COMP_3P3Z_POSTSCALER    0x607B
#define A_COMP_3P3Z_POSTSHIFT     0xFFFE
#define A_COMP_3P3Z_PRESHIFT      0x0000


// Compensator Clamp Limits
#define A_COMP_3P3Z_MIN_CLAMP    0x0000
#define A_COMP_3P3Z_MAX_CLAMP    0x7FFF


#endif
