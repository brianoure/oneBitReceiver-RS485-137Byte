#include <math.h>

"""MSB left and LSB right"""
//preamble_string ="briansatelliteA"
//postamble_string="briansatelliteB"

struct stored_binary_list{int binarylist[1096];int length;};
struct stored_number_list{int numberlist[1096];int length;};

int raw_binary_list[1096]; 
int raw_byte[137]; 

int preamble_binary_list     [120];
int id_binary_list           [120];
int time_binary_list         [80 ];
int computer_binary_list     [80 ];
int power_binary_list        [160];
int structure_binary_list    [128];
int attitude_binary_list     [80 ];
int payload_binary_list      [160];
int communication_binary_list[48 ];
int postamble_binary_list    [120];

int preamble_integer_list     [15];
int id_integer_list           [15];
int time_integer_list         [10];
int computer_integer_list     [10];
int power_integer_list        [20];
int structure_integer_list    [16];
int attitude_integer_list     [10];
int payload_integer_list      [20];
int communication_integer_list[6 ];
int postamble_integer_list    [15];

char integer_to_character(integer){
if(integer==0 ){return "a";}if(integer==1 ){return "b";}if(integer==2 ){return "c";}if(integer==3 ){return "d";}if(integer==4 ){return "e";}if(integer==5 ){return "f";}
if(integer==6 ){return "g";}if(integer==7 ){return "h";}if(integer==8 ){return "i";}if(integer==9 ){return "j";}if(integer==10){return "k";}if(integer==11){return "l";}
if(integer==12){return "m";}if(integer==13){return "n";}if(integer==14){return "o";}if(integer==15){return "p";}if(integer==16){return "q";}if(integer==17){return "r";}
if(integer==18){return "s";}if(integer==19){return "t";}if(integer==20){return "u";}if(integer==21){return "v";}if(integer==22){return "w";}if(integer==23){return "x";}
if(integer==24){return "y";}if(integer==25){return "z";}if(integer==26){return "0";}if(integer==27){return "1";}if(integer==28){return "2";}if(integer==29){return "3";}
if(integer==30){return "4";}if(integer==31){return "5";}if(integer==32){return "6";}if(integer==33){return "7";}if(integer==34){return "8";}if(integer==35){return "9";}
if(integer==36){return ".";}if(integer==37){return "%";}if(integer==38){return ";";}if(integer==39){return "#";}if(integer==40){return "+";}if(integer==41){return "-";}
return "!";
}//integer_to_character
        
void update_raw_binary_list(recent_binary){
for(int index=0;index<=1094;index++){raw_binary_list[index]=raw_binary_list[index+1];}
raw_binary_list[1095]=recent_binary;
}/*update_raw_binary_list*/

void update_preamble_binary_list_from_raw_list     (){for(int index=0  ;index<=119 ;index++){ preamble_binary_list     [index]= raw_binary_list[index];}}/*update_preamble_binary_list_from_raw_list*/        
void update_id_binary_list_from_raw_list           (){for(int index=120;index<=239 ;index++){ preamble_binary_list     [index]= raw_binary_list[index];}}/*update_id_binary_list_from_raw_list*/  
void update_time_binary_list_from_raw_list         (){for(int index=240;index<=319 ;index++){ time_binary_list         [index]= raw_binary_list[index];}}/*update_time_binary_list_from_raw_list*/
void update_computer_binary_list_from_raw_list     (){for(int index=320;index<=399 ;index++){ computer_binary_list     [index]= raw_binary_list[index];}}/*update_computer_binary_list_from_raw_list*/
void update_power_binary_list_from_raw_list        (){for(int index=400;index<=559 ;index++){ power_binary_list        [index]= raw_binary_list[index];}}/*update_power_binary_list_from_raw_list*/
void update_structure_binary_list_from_raw_list    (){for(int index=560;index<=687 ;index++){ structure_binary_list    [index]= raw_binary_list[index];}}/*update_structure_binary_list_from_raw_list*/
void update_attitude_binary_list_from_raw_list     (){for(int index=688;index<=767 ;index++){ attitude_binary_list     [index]= raw_binary_list[index];}}/*update_attitude_binary_list_from_raw_list*/
void update_payload_binary_list_from_raw_list      (){for(int index=768;index<=927 ;index++){ payload_binary_list      [index]= raw_binary_list[index];}}/*update_payload_binary_list_from_raw_list*/    
void update_communication_binary_list_from_raw_list(){for(int index=928;index<=975 ;index++){ communication_binary_list[index]= raw_binary_list[index];}}/*update_communication_binary_list_from_raw_list*/
void update_postamble_binary_list_from_raw_list    (){for(int index=976;index<=1095;index++){ postamble_binary_list    [index]= raw_binary_list[index];}}/*update_postamble_binary_list_from_raw_list*/:#void

struct stored_number_list get_8_bit_values_from_list(mylist,mylistlength){
int items=(int)(mylistlength/8);
int start = 0;
int end = 7;
int integer_value_list[items];
int integer_value(starting,ending){
int result=0;
for(int index=starting;index<=ending;index++){result=result+(mylist[index]*pow(2,(7-index+starting)));}/***************************************************/
return result;
}/*integer_value*/
for(int value_index=starting;value_index<=ending;value_index++){
if(value_index==0){integer_value_list[value_index]=integer_value(start,end);}
if(value_index!=0){start=start+8;end=end+8;integer_value_list[value_index]=integer_value(start,end);}/****************************************************/
}
return( integer_value_list );
}/*get_8_bit_values_from_list*/

char decrypt(mylist,mylistsize){
char decrypt_result[mylistsize];
for(int index=0;index<=mylistsize;index++){decrypt_result[index]=integer_to_character(mylist[index]);}
return decrypt_result;
}/*decrypt*/

void update_binary_frame_sections(){
update_preamble_binary_list_from_raw_list     ();
update_id_binary_list_from_raw_list           ();
update_time_binary_list_from_raw_list         ();
update_computer_binary_list_from_raw_list     ();
update_power_binary_list_from_raw_list        ();
update_structure_binary_list_from_raw_list    ();
update_attitude_binary_list_from_raw_list     ();
update_payload_binary_list_from_raw_list      ();
update_communication_binary_list_from_raw_list();
update_postamble_binary_list_from_raw_list    ();
}/*update_binary_frame_sections*/

void get_section_messages_from_binary_lists(){
decrypt(get_8_bit_values_from_list(preamble_binary_list     ,120),15);
decrypt(get_8_bit_values_from_list(id_binary_list           ,120),15);
decrypt(get_8_bit_values_from_list(time_binary_list         ,80 ),10);
decrypt(get_8_bit_values_from_list(computer_binary_list     ,80 ),10);
decrypt(get_8_bit_values_from_list(power_binary_list        ,160),20);
decrypt(get_8_bit_values_from_list(structure_binary_list    ,128),16);
decrypt(get_8_bit_values_from_list(attitude_binary_list     ,80 ),10);
decrypt(get_8_bit_values_from_list(payload_binary_list      ,160),20);
decrypt(get_8_bit_values_from_list(communication_binary_list,48 ),6 );
decrypt(get_8_bit_values_from_list(postamble_binary_list    ,120),15);
}/*get_section_messages_from_binary_lists*/

void run_receiver_program(){
result=true;/******external control for running the receiver program*********/
return result;
}/*run_receiver_program*/

void get_rs485_ch_one_line_A(){
result=1;/***external control for retrieving bit value of channel one line A***/
return result;
}/*get_rs485_ch_one_line_A*/

void get_rs485_ch_one_line_B(){
result=1;/***external control for retrieving bit value of channel one line B***/
return result;
}/*get_rs485_ch_one_line_B*/:  

int receiver_main():
while(run_receiver_program()){
int a=get_rs485_ch_one_line_A();
int b=get_rs485_ch_one_line_B();
if(a==0 and b==0){while(get_rs485_ch_one_line_A()==0 && get_rs485_ch_one_line_B()==0){}}
if(a==0 and b==1){update_raw_binary_list(0);update_binary_frame_sections();while(get_rs485_ch_one_line_A()==0 && get_rs485_ch_one_line_B()==1){}}     
if(a==1 and b==0){update_raw_binary_list(1);update_binary_frame_sections();while(get_rs485_ch_one_line_A()==1 && get_rs485_ch_one_line_B()==0){}}
if(a==1 and b==1){while(get_rs485_ch_one_line_A()==1 && get_rs485_ch_one_line_B()==1){}}
}
return 0;
}/*receiver_main*/
