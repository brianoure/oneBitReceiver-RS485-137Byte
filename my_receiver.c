"""MSB left and LSB right"""
//preamble_string ="briansatelliteA"
//postamble_string="briansatelliteB"
int raw_binary_list[1096]; 
int raw_byte[137]; 

preamble_binary_list     =[0]*120
id_binary_list           =[0]*120
time_binary_list         =[0]*80
computer_binary_list     =[0]*80
power_binary_list        =[0]*160
structure_binary_list    =[0]*128
attitude_binary_list     =[0]*80
payload_binary_list      =[0]*160
communication_binary_list=[0]*48
postamble_binary_list    =[0]*120

preamble_integer_list     =[0]*15
id_integer_list           =[0]*15
time_integer_list         =[0]*10
computer_integer_list     =[0]*10
power_integer_list        =[0]*20
structure_integer_list    =[0]*16
attitude_integer_list     =[0]*10
payload_integer_list      =[0]*20
communication_integer_list=[0]*6
postamble_integer_list    =[0]*15

def integer_to_character(integer):
    if(integer==0 ):return "a"
    if(integer==1 ):return "b"
    if(integer==2 ):return "c"
    if(integer==3 ):return "d"
    if(integer==4 ):return "e"
    if(integer==5 ):return "f"
    if(integer==6 ):return "g"
    if(integer==7 ):return "h"
    if(integer==8 ):return "i"
    if(integer==9 ):return "j"
    if(integer==10):return "k"
    if(integer==11):return "l"
    if(integer==12):return "m"
    if(integer==13):return "n"
    if(integer==14):return "o"
    if(integer==15):return "p"
    if(integer==16):return "q"
    if(integer==17):return "r"
    if(integer==18):return "s"
    if(integer==19):return "t"
    if(integer==20):return "u"
    if(integer==21):return "v"
    if(integer==22):return "w"
    if(integer==23):return "x"
    if(integer==24):return "y"
    if(integer==25):return "z"
    if(integer==26):return "0"
    if(integer==27):return "1"
    if(integer==28):return "2"
    if(integer==29):return "3"
    if(integer==30):return "4"
    if(integer==31):return "5"
    if(integer==32):return "6"
    if(integer==33):return "7"
    if(integer==34):return "8"
    if(integer==35):return "9"
    if(integer==36):return "."
    if(integer==37):return "%"
    if(integer==38):return ";"
    if(integer==39):return "#"
    if(integer==40):return "+"
    if(integer==41):return "-"
    return "!"
        
def update_raw_binary_list(recent_binary):#void
    for index in range(1095):
        #0 to 1094
        raw_binary_list[index]=raw_binary_list[index+1]
    raw_binary_list[1095]=recent_binary#most recent bit input into raw_binary
    
def update_preamble_binary_list_from_raw_list():#void
    for index in range(0,120):
        #0 to 119
        preamble_binary_list[index]=raw_binary_list[index]

def update_id_binary_list_from_raw_list():#void
    for index in range(120,240):
        #120 to 239
        id_binary_list[index]=raw_binary_list[index]

def update_time_binary_list_from_raw_list():#void
    for index in range(240,320):
        #240 to 319
        time_binary_list[index]=raw_binary_list[index]

def update_computer_binary_list_from_raw_list():#void
    for index in range(320,400):
        #320 to 399
        computer_binary_list[index]=raw_binary_list[index]

def update_power_binary_list_from_raw_list():#void
    for index in range(400,560):
        #400 to 559
        power_binary_list[index]=raw_binary_list[index]

def update_structure_binary_list_from_raw_list():#void
    for index in range(560,688):
        #560 to 687
        structure_binary_list[index]=raw_binary_list[index]

def update_attitude_binary_list_from_raw_list():#void
    for index in range(688,768):
        #688 to 767
        attitude_binary_list[index]=raw_binary_list[index]

def update_payload_binary_list_from_raw_list():#void
    for index in range(768,928):
        #768 to 927
        payload_binary_list[index]=raw_binary_list[index]

def update_communication_binary_list_from_raw_list():#void
    for index in range(928,976):
        #928 to 975
        communication_binary_list[index]= raw_binary_list[index]

def update_postamble_binary_list_from_raw_list():#void
    for index in range(976,1096):
        #976 to 1095
        postamble_binary_list[index]= raw_binary_list[index]

def get_8_bit_values_from_list(mylist,mylistlength):
    items=(int)(mylistlength/8)
    start = 0
    end = 7
    integer_value_list=[0]*items
    def integer_value(starting,ending):
        result=0
        for index in range(starting,ending+1):
            result=result+ (mylist[index]*(2**(7-index+starting)))
        return result
    for value_index in range(items):
        if value_index==0:
            integer_value_list[value_index]=integer_value(start,end)
        if not(value_index==0):
            start=start+8
            end=end+8
            integer_value_list[value_index]=integer_value(start,end)
    return( integer_value_list )

def decrypt(mylist,mylistsize):
    decrypt_result="!"*mylistsize
    for index in range(mylistsize):
        decrypt_result[index]=integer_to_character(mylist[index])
    return decrypt_result

def update_binary_frame_sections():
    update_preamble_binary_list_from_raw_list     ()
    update_id_binary_list_from_raw_list           ()
    update_time_binary_list_from_raw_list         ()
    update_computer_binary_list_from_raw_list     ()
    update_power_binary_list_from_raw_list        ()
    update_structure_binary_list_from_raw_list    ()
    update_attitude_binary_list_from_raw_list     ()
    update_payload_binary_list_from_raw_list      ()
    update_communication_binary_list_from_raw_list()
    update_postamble_binary_list_from_raw_list    ()

def get_section_messages_from_binary_lists():
    decrypt(get_8_bit_values_from_list(preamble_binary_list     ,120),15)
    decrypt(get_8_bit_values_from_list(id_binary_list           ,120),15)
    decrypt(get_8_bit_values_from_list(time_binary_list         ,80 ),10)
    decrypt(get_8_bit_values_from_list(computer_binary_list     ,80 ),10)
    decrypt(get_8_bit_values_from_list(power_binary_list        ,160),20)
    decrypt(get_8_bit_values_from_list(structure_binary_list    ,128),16)
    decrypt(get_8_bit_values_from_list(attitude_binary_list     ,80 ),10)
    decrypt(get_8_bit_values_from_list(payload_binary_list      ,160),20)
    decrypt(get_8_bit_values_from_list(communication_binary_list,48 ),6 )
    decrypt(get_8_bit_values_from_list(postamble_binary_list    ,120),15)

def run_receiver_program():
    result=True#external control for running the receiver program
    return result
    
def get_rs485_ch_one_line_A():
    result=1#external control for retrieving bit value of channel one line A
    return result

def get_rs485_ch_one_line_B():
    result=1#external control for retrieving bit value of channel one line B
    return result

def receiver_main():
    while run_receiver_program():
        a=get_rs485_ch_one_line_A()
        b=get_rs485_ch_one_line_B()
        #print(a,b)
        if(a==0 and b==0):
            #print("first")
            #update_raw_binary_list(recent_binary)
            while(get_rs485_ch_one_line_A()==0 and get_rs485_ch_one_line_B()==0):pass
        if(a==0 and b==1):
            #print("second")
            update_raw_binary_list(0)
            update_binary_frame_sections()
            while(get_rs485_ch_one_line_A()==0 and get_rs485_ch_one_line_B()==1):pass
        if(a==1 and b==0):
            #print("third")
            update_raw_binary_list(1)
            update_binary_frame_sections()
            while(get_rs485_ch_one_line_A()==1 and get_rs485_ch_one_line_B()==0):pass
        if(a==1 and b==1):
            #print("fourth")
            #update_raw_binary_list(recent_binary)
            while(get_rs485_ch_one_line_A()==1 and get_rs485_ch_one_line_B()==1):pass
