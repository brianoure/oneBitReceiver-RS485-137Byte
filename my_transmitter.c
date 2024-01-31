#include <math.h>
char raw_char  [137 ];
int  raw_int   [137 ];
int  raw_binary[1096];

int my_encode(mychar){/*my_encode*/
if(myinteger=='a'){return  0;}
if(myinteger=='b'){return  1;}
if(myinteger=='c'){return  2;}
if(myinteger=='d'){return  3;}
if(myinteger=='e'){return  4;}
if(myinteger=='f'){return  5;}
if(myinteger=='g'){return  6;}
if(myinteger=='h'){return  7;}
if(myinteger=='i'){return  8;}
if(myinteger=='j'){return  9;}
if(myinteger=='k'){return 10;}
if(myinteger=='l'){return 11;}
if(myinteger=='m'){return 12;}
if(myinteger=='n'){return 13;}
if(myinteger=='o'){return 14;}
if(myinteger=='p'){return 15;}
if(myinteger=='q'){return 16;}
if(myinteger=='r'){return 17;}
if(myinteger=='s'){return 18;}
if(myinteger=='t'){return 19;}
if(myinteger=='u'){return 20;}
if(myinteger=='v'){return 21;}
if(myinteger=='w'){return 22;}
if(myinteger=='x'){return 23;}
if(myinteger=='y'){return 24;}
if(myinteger=='z'){return 25;}
if(myinteger=='0'){return 26;}
if(myinteger=='1'){return 27;}
if(myinteger=='2'){return 28;}
if(myinteger=='3'){return 29;}
if(myinteger=='4'){return 30;}
if(myinteger=='5'){return 31;}
if(myinteger=='6'){return 32;}
if(myinteger=='7'){return 33;}
if(myinteger=='8'){return 34;}
if(myinteger=='9'){return 35;}
if(myinteger=='.'){return 36;}
if(myinteger=='%'){return 37;}
if(myinteger==';'){return 38;}
if(myinteger=='#'){return 39;}
if(myinteger=='+'){return 40;}
if(myinteger=='-'){return 41;}
return 42;
}/*my_encode*/
  
int construct_binary_frame(){/*construct_binary_frame*/
raw_binary_index_marker=0
for (int  raw_char_index=0;raw_char_index<=136;raw_char_index++){/*for*/
raw_int[raw_char_index] = my_encode(raw_char[raw_char_index])
for (int position=0;position<=7;position++){/*for*/
raw_binary[raw_binary_index_marker+position]=(int)(raw_int[raw_char_index] & pow(2,(7-position)));
}/*for*/
raw_binary_index_marker=raw_binary_index_marker+1;
}/*for*/
return 0;
}/*construct_binary_frame*/
  
int run_transmitter(){/*run_transmitter*/
# controls for toggling program run
return true;
}/*run_transmitter*/

int transmitter_set(bit_value_A,bit_value_B){/*transmitter_set*/
/*Set transmitter circuits to indicate  bit_value transmission*/
if(bit_value_A==0 and bit_value_B==0){/*do nothing!*/}
if(bit_value_A==0 and bit_value_B==1){/*TURN ON  A, TURN OFF B*/}
if(bit_value_A==1 and bit_value_B==0){/*TURN OFF B, TURN ON  A*/}
if(bit_value_A==1 and bit_value_B==1){/*TURN ON  A, TURN ON  B*/}
return 0;
}/*transmitter_set*/

int update_raw_char(){
/*external means of acquiring the binary frame and introducing it to this program*/
return 0;
}/*update_raw_char*/
  
int main(){
while (run_transmitter()){
update_raw_char();
construct_binary_frame();
for(int binary_index=0;binary_index<=1095;binary_index++){/*for*/
actual_bit = raw_binary[binary_index];
transmitter_set(actual_bit, not(actual_bit));
for (int pause=0;pause<=10000;pause++){}/*for*/
transmitter_set(1,1); 
for (int pause=0;pause<=10000;pause++){}/*for*/
}/*for*/      
}/*while*/
return 0;
}/*main*/
