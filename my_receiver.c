#include <math.h>

/**
How I wil be reading  the  value of an array containing binary values:MSB to the left(highest index) and LSB to the right(lowest index)
**/

int  raw_binary_list[1096]; 
int  raw_byte       [137 ];
char raw_char       [137 ];

char preamble     [15];
char id           [15];
char time         [10];
char computer     [10];
char power        [20];
char structure    [16];
char attitude     [10];
char payload      [20];
char communication[6 ];
char postamble    [15];

int run_receiver_program(){
result=true;/*external control for running the receiver program*/
/***
INSERT CODE HERE; IF THERE ARE CONDITIONS FOR RUNNING THE PROGRAM.
If nothing is changed here, then the program should run indefinitely
***/
return result;
}/*run_receiver_program*/

int get_rs485_ch_one_line_A(){
result=1;/***external control for retrieving bit value of channel one line A***/
/***
INSERT CODE HERE; FOR READING BIT VALUE OF SINGLE LINE (A).
***/
return result;
}/*get_rs485_ch_one_line_A*/

int get_rs485_ch_one_line_B(){
result=1;/***external control for retrieving bit value of channel one line B***/
/*
INSERT CODE HERE; FOR READING BIT VALUE OF SINGLE LINE (B).
*/
return result;
}/*get_rs485_ch_one_line_B*/:  

char number_to_char(int raw_number, int framecharindex){/*decrypt the raw numbers into actual characters*/
if(raw_number==0 ){return 'a';}
if(raw_number==1 ){return 'b';}
if(raw_number==2 ){return 'c';}
if(raw_number==3 ){return 'd';}
if(raw_number==4 ){return 'e';}
if(raw_number==5 ){return 'f';}
if(raw_number==6 ){return 'g';}
if(raw_number==7 ){return 'h';}
if(raw_number==8 ){return 'i';}
if(raw_number==9 ){return 'j';}
if(raw_number==10){return 'k';}
if(raw_number==11){return 'l';}
if(raw_number==12){return 'm';}
if(raw_number==13){return 'n';}
if(raw_number==14){return 'o';}
if(raw_number==15){return 'p';}
if(raw_number==16){return 'q';}
if(raw_number==17){return 'r';}
if(raw_number==18){return 's';}
if(raw_number==19){return 't';}
if(raw_number==20){return 'u';}
if(raw_number==21){return 'v';}
if(raw_number==22){return 'w';}
if(raw_number==23){return 'x';}
if(raw_number==24){return 'y';}
if(raw_number==25){return 'z';}
if(raw_number==26){return '0';}
if(raw_number==27){return '1';}
if(raw_number==28){return '2';}
if(raw_number==29){return '3';}
if(raw_number==30){return '4';}
if(raw_number==31){return '5';}
if(raw_number==32){return '6';}
if(raw_number==33){return '7';}
if(raw_number==34){return '8';}
if(raw_number==35){return '9';}
if(raw_number==36){return '%';}
if(raw_number==37){return '+';}
if(raw_number==38){return '-';}
if(raw_number==39){return '#';}
}/*decrypt*/

void update_raw_binary_list(int recent_binary){
for(int index=1095;index>=1;index--){raw_binary_list[index]=raw_binary_list[index-1];}
raw_binary_list[0]=recent_binary;
}/*update_raw_binary_list*/

void update_raw_byte_update_raw_char(){
int frame_characters=137;
int frame_bits      =frame_characters*8;
int max_bit_index   =frame_bits-1;
int loop_number     =0;
for(int framecharindex=136;framecharindex>=0;i--){
int starting=max_bit_index-(8*loop_number);
int ending=starting-7;
int raw_number=0;
int target_raw_binary_index=starting;
for(int mypower=7;mypower>=0;mypower--){ raw_number=raw_number+(raw_binary_list[target_raw_binary_index]*pow(2,mypower));target_raw_binary_index--; }/*for*/
raw_number_list[framecharindex]=raw_number;
raw_char       [framecharindex]=number_to_char(raw_number,framecharindex);
loop_number++;
}/*for*/
}/*update_raw_byte_update_raw_char*/

void update_section_messages(){/*NB: char order reversed for each section*/
for(int raw_char_index=136 ;int raw_char_index>=122 ;int raw_char_index--){preamble     [136-raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=121 ;int raw_char_index>=107 ;int raw_char_index--){id           [121-raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=106 ;int raw_char_index>=97  ;int raw_char_index--){time         [106-raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=96  ;int raw_char_index>=87  ;int raw_char_index--){computer     [96 -raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=86  ;int raw_char_index>=67  ;int raw_char_index--){power        [86 -raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=66  ;int raw_char_index>=51  ;int raw_char_index--){structure    [66 -raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=50  ;int raw_char_index>=41  ;int raw_char_index--){attitude     [50 -raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=40  ;int raw_char_index>=21  ;int raw_char_index--){payload      [40 -raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=20  ;int raw_char_index>=15  ;int raw_char_index--){communication[20 -raw_char_index] = raw_char[raw_char_index];}
for(int raw_char_index=14  ;int raw_char_index>=0   ;int raw_char_index--){postamble    [14 -raw_char_index] = raw_char[raw_char_index];}
}/*update_section_messages*/

int main(){
while(run_receiver_program()){
int a=get_rs485_ch_one_line_A();
int b=get_rs485_ch_one_line_B();
if(a==0 && b==0){while(get_rs485_ch_one_line_A()==0 && get_rs485_ch_one_line_B()==0){}}
if(a==0 && b==1){update_raw_binary_list(0);update_raw_byte_update_raw_char();update_section_messages();while(get_rs485_ch_one_line_A()==0 && get_rs485_ch_one_line_B()==1){}}     
if(a==1 && b==0){update_raw_binary_list(1);update_raw_byte_update_raw_char();update_section_messages();while(get_rs485_ch_one_line_A()==1 && get_rs485_ch_one_line_B()==0){}}
if(a==1 && b==1){while(get_rs485_ch_one_line_A()==1 && get_rs485_ch_one_line_B()==1){}}
}/*while*/
return 0;
}/*main*/
