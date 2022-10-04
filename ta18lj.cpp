// Name: Tristan Arana Charlebois
// Student Number: 6680672

#include <iostream>
#include <cmath>

using namespace std;

void function(int select, int graduate, int display){

    double x = -4; // x minimum
    double temp_x = x; // current x
    double y = -12; // y minimum
    double intermediate_x = (double) 10 / graduate; // equal distanced values from x min to x max (-4 to 6) based on graduations
    double intermediate_y = (double) 17 / graduate; // equal distanced values from y min to y max (-12 to 5) based on graduations
    int full_graduate = pow(graduate, 2); // total number of values
    double graph[full_graduate + 1]; // array to hold values

    if (select == 1){ //sin(x)cos(y)
        
        for (int i = 1; i < full_graduate + 1; i++){ // loop through all values

            graph[i] = sin(temp_x) * cos(y); // calculate point
            temp_x += intermediate_x; // next x
                    
            if (i % graduate == 0){ // next row

                y += intermediate_y; // next y
                temp_x = x; //reset x for next row

            }  

        }

    } else if (select == 2){ // sin(x) + cos^2(y/2)-x/y

        for (int i = 1; i < full_graduate + 1; i++){ 

            graph[i] = sin(temp_x) + pow(cos(y/2), 2) - (temp_x/y); 
            temp_x += intermediate_x; 
                    
            if (i % graduate == 0){ 

                y += intermediate_y; 
                temp_x = x; 

            }

                    
        }

    } else if (select == 3){ // 1/2sin(x) + 1/2cos(y)
        
        for (int i = 1; i < full_graduate + 1; i++){ 

            graph[i] = ((0.5) * sin(temp_x)) + ((0.5) * cos(y)); 
            temp_x += intermediate_x; 
                    
            if (i % graduate == 0){ 

                y+= intermediate_y; 
                temp_x = x; 

            }  

        }

    } else if (select == 4){ // 1/2sin(x) + xcos(3y)

        for (int i = 1; i < full_graduate + 1; i++){ 

            graph[i] = ((0.5) * sin(temp_x)) + ((temp_x) * cos(3 * y)); 
            temp_x += intermediate_x; 
                    
            if (i % graduate == 0){ 

                y += intermediate_y; 
                temp_x = x; 

            }  

        }
    }

    if (display == 0){ // bitmap display 

        for (int i = 1; i < full_graduate + 1; i++){ // loop through all values
            
             if (graph[i] >= 0) { // positive

                cout<<"O";

            } else { // negative

                cout<<"X";

            }

            if (i % graduate == 0){ // next row

                cout<<"\n";

            }

        } 
            

    } else { // values display

        for (int i = 1; i < full_graduate + 1; i++){ // loop through values
           
                cout<<graph[i];

            if (i % graduate == 0){ // next row

                cout<<"\n";

            }

        } 
    }
    

}

int main(){

    int select; // function selection
    int graduations; // number of graduations
    int display; // graph to display

    while(true){ // loop until exit

    
        cerr<<"Select your function:\n 1. sin(x)cos(y)\n 2. sin(x)+cos^2(y/2)-x/y\n 3. 1/2 sin(x) + 1/2 cos(y)\n 4. 1/2 sin(x) + xcos(y)\n 0. Quit"<<endl;
        cin>>select;

        if (select == 0){ // exit selection

            return 0;

        }

        cerr<<"Number of graduations per axis: ";
        cin>>graduations;
        cerr<<"(0) Bitmap or (1) Values? ";
        cin>>display;

        function(select, graduations, display); // calculate and display

        cerr<<"\n";

    }

}

