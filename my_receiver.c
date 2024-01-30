#include <math.h>
int  raw_binary_list[1096]; 
int  raw_number       [137 ];
char raw_char       [137 ];

int run_receiver_program(){
result=true;/*external control for running the receiver program*/
/*INSERT CODE HERE; IF THERE ARE CONDITIONS FOR RUNNING THE PROGRAM*/
return result;
}/*run_receiver_program*/

int get_rs485_ch_one_line_A(){
result=1;/***external control for retrieving bit value of channel one line A***/
/*INSERT CODE HERE; FOR READING BIT VALUE OF SINGLE LINE (A)*/
return result;
}/*get_rs485_ch_one_line_A*/

int get_rs485_ch_one_line_B(){
result=1;/***external control for retrieving bit value of channel one line B***/
/*INSERT CODE HERE; FOR READING BIT VALUE OF SINGLE LINE (B)*/
return result;
}/*get_rs485_ch_one_line_B*/:  

char integer_to_character(int myinteger){/*decrypt the raw numbers into actual characters*/
if(myinteger==0 ){return 'a';}
if(myinteger==1 ){return 'b';}
if(myinteger==2 ){return 'c';}
if(myinteger==3 ){return 'd';}
if(myinteger==4 ){return 'e';}
if(myinteger==5 ){return 'f';}
if(myinteger==6 ){return 'g';}
if(myinteger==7 ){return 'h';}
if(myinteger==8 ){return 'i';}
if(myinteger==9 ){return 'j';}
if(myinteger==10){return 'k';}
if(myinteger==11){return 'l';}
if(myinteger==12){return 'm';}
if(myinteger==13){return 'n';}
if(myinteger==14){return 'o';}
if(myinteger==15){return 'p';}
if(myinteger==16){return 'q';}
if(myinteger==17){return 'r';}
if(myinteger==18){return 's';}
if(myinteger==19){return 't';}
if(myinteger==20){return 'u';}
if(myinteger==21){return 'v';}
if(myinteger==22){return 'w';}
if(myinteger==23){return 'x';}
if(myinteger==24){return 'y';}
if(myinteger==25){return 'z';}
if(myinteger==26){return '0';}
if(myinteger==27){return '1';}
if(myinteger==28){return '2';}
if(myinteger==29){return '3';}
if(myinteger==30){return '4';}
if(myinteger==31){return '5';}
if(myinteger==32){return '6';}
if(myinteger==33){return '7';}
if(myinteger==34){return '8';}
if(myinteger==35){return '9';}
if(myinteger==36){return '.';}
if(myinteger==37){return '%';}
if(myinteger==38){return ';';}
if(myinteger==39){return '#';}
if(myinteger==40){return '+';}
if(myinteger==41){return '-';}
return '!';
}/*decrypt*/

void add_new_bit_at_end_remove_old_bit_at_start(int recent_binary){
for(int index=0;index<=1094;index++){raw_binary_list[index]=raw_binary_list[index+1];}
raw_binary_list[1095]=recent_binary;
}/*update_raw_binary_list*/

void get_numbers_and_characters_from_raw_binary(){
int bit_position=0;
for (int charindex=0;charindex<=136;charindex++){/*0 to 136*/
int character_number=0;
for (int exponent=7;exponent>=0;exponent--){/*7 to 0*/
character_number=character_number+((raw_binary_list[bit_position])*pow(2,exponent));
bit_position=bit_position+1;
}/*for*/
raw_number[charindex] = character_number;
raw_char  [charindex] = integer_to_character(character_number);
bit_position=bit_position+1;
}/*for*/

int main(){
while(run_receiver_program()){
int a=get_rs485_ch_one_line_A();
int b=get_rs485_ch_one_line_B();
if(a==0 && b==0){while(get_rs485_ch_one_line_A()==0 && get_rs485_ch_one_line_B()==0){}}
if(a==0 && b==1){update_raw_binary_list(0);update_raw_number_update_raw_char();while(get_rs485_ch_one_line_A()==0 && get_rs485_ch_one_line_B()==1){}}     
if(a==1 && b==0){update_raw_binary_list(1);update_raw_number_update_raw_char();while(get_rs485_ch_one_line_A()==1 && get_rs485_ch_one_line_B()==0){}}
if(a==1 && b==1){while(get_rs485_ch_one_line_A()==1 && get_rs485_ch_one_line_B()==1){}}
}/*while*/
return 0;
}/*main*/

