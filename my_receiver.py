"""MSB left and LSB right"""
preamble_string ="briansatelliteA"
postamble_string="briansatelliteB"
raw_binary_list = [0]*1096 #137 bytes * 8 bit per byte
raw_byte = [0]*153# 137 bytes

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
        
def update_raw_binary_list(recent_binary):
    for index in range(1095):#0 to 1094
        raw_binary_list[index]=raw_binary_list[index+1]
    raw_binary_list[1095]=recent_binary#most recent bit input into raw_binary
    
def update_preamble_binary_list_from_raw_list():
    for index in range(0,120):#0 to 119
        preamble_binary_list[index]= raw_binary_list[index]

def update_id_binary_list_from_raw_list():
    for index in range(120,240):#120 to 239
        preamble_binary_list[index]= raw_binary_list[index]

def update_time_binary_list_from_raw_list():
    for index in range(240,320):#240 to 319
        preamble_binary_list[index]= raw_binary_list[index]

def update_computer_binary_list_from_raw_list():
    for index in range(320,400):#320 to 399
        preamble_binary_list[index]= raw_binary_list[index]

def update_power_binary_list_from_raw_list():
    for index in range(400,560):#400 to 559
        preamble_binary_list[index]= raw_binary_list[index]

def update_structure_binary_list_from_raw_list():
    for index in range(560,688):#560 to 687
        preamble_binary_list[index]= raw_binary_list[index]

def update_attitude_binary_list_from_raw_list():
    for index in range(688,768):#688 to 767
        preamble_binary_list[index]= raw_binary_list[index]

def update_payload_binary_list_from_raw_list():
    for index in range(768,928):#768 to 927
        preamble_binary_list[index]= raw_binary_list[index]

def update_communication_binary_list_from_raw_list():
    for index in range(928,976):#928 to 975
        preamble_binary_list[index]= raw_binary_list[index]

def update_postamble_binary_list_from_raw_list():
    for index in range(976,1096):#976 to 1095
        preamble_binary_list[index]= raw_binary_list[index]

def get_8_bit_values_from_list(mylist,mylistlength):
    integer_value_list=[0]*(mylistlength/8)
    start=0
    end=7
    def integer_value(starting,ending):
        for index in range(8):
            result=result+ (mylist[index]*(2**(7-index))) 
    for value_index in range(mylistlength/8):
        if value_index==0:
            integer_value_list[value_index]=integer_value(start,end)
        if not(value_index==0):
            start=start+8
            end=end+8
            integer_value_list[value_index]=integer_value(start,end)
    return integer_value_list

def update_frame_sections():
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

def receiver_main(receiver_main_run,write_detected):
    while receiver_main_run:
        if(write_detected and channel==0):
            write_detected=0#reset to wait for the next bit
            update_raw_binary_list(0)
            update_frame_sections()
        if(write_detected and channel==1):
            write_detected=0#reset to wait for the next bit
            update_raw_binary_list(1)
            update_frame_sections()

