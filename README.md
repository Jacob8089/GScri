   ___________           
  / ____/ ___/__________(_)
 / / __ \__ V ___/ ___/ /
/ /_/ /___/ / /__/ /  / /
\____//____/\___/_/  /_/

###Introducing GScri

This application helps a major workforce in numerically computed machineries (CNC or NC) to easily able to compute script commands to drive a robotic arm. This is a standalone application which acts as the feature in Robogram application and GRosi web application in the same repo. GScri takes in a single GCODE command and currently supports on UR Script commands. GRosi is a web version of GScri and also helps user to upload a GCODE or NC file which in turn is a feature to Robogram. Please look into the respective repos for more info.

Supported G Codes:
G 0/1 - The application automatically converts to movel and movej for respective codes.
G 20/28 - By default, the application sets unit to millimeters but enables user to make any changes by defining of the process.

Supported M Codes:
All necessary M Codes for 3D printer is currently supported in GScri.

>Note: For G0 and G1, it is recommended not to make additional numerical values adjacent to the codes. 
For example, the suggested form of GCode to be used is G0 X100 Y100 Z100 or G1 X100 Y200 Z100 (Decimal points are aceepted).

Not acceptable versions of Gcodes are: G00 X 100 Y2 00 Z 300 or G01 X 100 Y2 00 Z 300.