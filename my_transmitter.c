#include <math.h>
char raw_char  [137 ];
int  raw_int   [137 ];
int  raw_binary[1096];

int my_encode(mychar){/*my_encode*/
if(mychar=='a'){return 1; }
if(mychar=='b'){return 2; }
if(mychar=='c'){return 3; }
if(mychar=='d'){return 4; }
if(mychar=='e'){return 5; }
if(mychar=='f'){return 6; }
if(mychar=='g'){return 7; }
if(mychar=='h'){return 8; }
if(mychar=='i'){return 9; }
if(mychar=='j'){return 10;}
if(mychar=='k'){return 11;}
if(mychar=='l'){return 12;}
if(mychar=='m'){return 13;}
if(mychar=='n'){return 14;}
if(mychar=='o'){return 15;}
if(mychar=='p'){return 16;}
if(mychar=='q'){return 17;}
if(mychar=='r'){return 18;}
if(mychar=='s'){return 19;}
if(mychar=='t'){return 20;}
if(mychar=='u'){return 21;}
if(mychar=='v'){return 22;}
if(mychar=='w'){return 23;}
if(mychar=='x'){return 24;}
if(mychar=='y'){return 25;}
if(mychar=='z'){return 26;}
if(mychar=='0'){return 27;}
if(mychar=='1'){return 28;}
if(mychar=='2'){return 29;}
if(mychar=='3'){return 30;}
if(mychar=='4'){return 31;}
if(mychar=='5'){return 32;}
if(mychar=='6'){return 33;}
if(mychar=='7'){return 34;}
if(mychar=='8'){return 35;}
if(mychar=='9'){return 36;}
if(mychar=='s'){return 37;}
if(mychar=='t'){return 38;}
if(mychar=='t'){return 39;}
if(mychar=='t'){return 40;}
if(mychar=='t'){return 41;}
if(mychar=='t'){return 42;}
if(mychar=='t'){return 43;}
return 58;
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
}/*ME*/
  
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
