#include <math.h>

"""MSB left and LSB right"""
//preamble_string ="briansatelliteA"
//postamble_string="briansatelliteB"

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
result=true;/******external control for running the receiver program*********/
return result;
}/*run_receiver_program*/

int get_rs485_ch_one_line_A(){
result=1;/***external control for retrieving bit value of channel one line A***/
return result;
}/*get_rs485_ch_one_line_A*/

int get_rs485_ch_one_line_B(){
result=1;/***external control for retrieving bit value of channel one line B***/
return result;
}/*get_rs485_ch_one_line_B*/:  

void decrypt(int raw_number, int framecharindex){
if(raw_number==0 ){raw_char[framecharindex]='a';}
if(raw_number==1 ){raw_char[framecharindex]='b';}
if(raw_number==2 ){raw_char[framecharindex]='c';}
if(raw_number==3 ){raw_char[framecharindex]='d';}
if(raw_number==4 ){raw_char[framecharindex]='e';}
if(raw_number==5 ){raw_char[framecharindex]='f';}
if(raw_number==6 ){raw_char[framecharindex]='g';}
if(raw_number==7 ){raw_char[framecharindex]='h';}
if(raw_number==8 ){raw_char[framecharindex]='i';}
if(raw_number==9 ){raw_char[framecharindex]='j';}
if(raw_number==10){raw_char[framecharindex]='k';}
if(raw_number==11){raw_char[framecharindex]='l';}
if(raw_number==12){raw_char[framecharindex]='m';}
if(raw_number==13){raw_char[framecharindex]='n';}
if(raw_number==14){raw_char[framecharindex]='o';}
if(raw_number==15){raw_char[framecharindex]='p';}
if(raw_number==16){raw_char[framecharindex]='q';}
if(raw_number==17){raw_char[framecharindex]='r';}
if(raw_number==18){raw_char[framecharindex]='s';}
if(raw_number==19){raw_char[framecharindex]='t';}
if(raw_number==20){raw_char[framecharindex]='u';}
if(raw_number==21){raw_char[framecharindex]='v';}
if(raw_number==22){raw_char[framecharindex]='w';}
if(raw_number==23){raw_char[framecharindex]='x';}
if(raw_number==24){raw_char[framecharindex]='y';}
if(raw_number==25){raw_char[framecharindex]='z';}
if(raw_number==26){raw_char[framecharindex]='0';}
if(raw_number==27){raw_char[framecharindex]='1';}
if(raw_number==28){raw_char[framecharindex]='2';}
if(raw_number==29){raw_char[framecharindex]='3';}
if(raw_number==30){raw_char[framecharindex]='4';}
if(raw_number==31){raw_char[framecharindex]='5';}
if(raw_number==32){raw_char[framecharindex]='6';}
if(raw_number==33){raw_char[framecharindex]='7';}
if(raw_number==34){raw_char[framecharindex]='8';}
if(raw_number==35){raw_char[framecharindex]='9';}
if(raw_number==36){raw_char[framecharindex]='%';}
if(raw_number==37){raw_char[framecharindex]='+';}
if(raw_number==38){raw_char[framecharindex]='-';}
if(raw_number==39){raw_char[framecharindex]='#';}
}

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
decrypt(raw_number,framecharindex);
loop_number++;
}/*for*/
}/**/

int main(){
while(run_receiver_program()){
int a=get_rs485_ch_one_line_A();
int b=get_rs485_ch_one_line_B();
if(a==0 and b==0){while(get_rs485_ch_one_line_A()==0 && get_rs485_ch_one_line_B()==0){}}
if(a==0 and b==1){update_raw_binary_list(0);update_raw_byte_update_raw_char();while(get_rs485_ch_one_line_A()==0 && get_rs485_ch_one_line_B()==1){}}     
if(a==1 and b==0){update_raw_binary_list(1);update_raw_byte_update_raw_char();while(get_rs485_ch_one_line_A()==1 && get_rs485_ch_one_line_B()==0){}}
if(a==1 and b==1){while(get_rs485_ch_one_line_A()==1 && get_rs485_ch_one_line_B()==1){}}
}/*while*/
return 0;
}/*main*/
