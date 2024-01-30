raw_number       = [0]*137#137 bytes
raw_char         = [0]*137#137 bytes
raw_bit          = 1096   #raw frame bits

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

def get_numbers_and_characters_from_raw_binary():
    bit_position=0
    for charindex in range(137):
        #0 to 136
        character_number=0
        for exponent in range(7,-1,-1):
            #7 to 0
            character_number=character_number+((raw_bit[bit_position])*(2**exponent))
            bit_position=bit_position+1
        character_number=0
        raw_char[charindex] = integer_to_character(character_number)
        bit_position=bit_position+1

def add_new_bit_at_end_remove_old_bit_at_start(new_bit):
    for index in range(0,1095):
        raw_bit[index]=raw_bit[index+1]
    raw_bit[1095]=new_bit

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
        if(a==0 and b==0):           
            while(get_rs485_ch_one_line_A()==0 and get_rs485_ch_one_line_B()==0):pass
        if(a==0 and b==1):
            add_new_bit_at_end_remove_old_bit_at_start(0)
            get_numbers_and_characters_from_raw_binary()
            while(get_rs485_ch_one_line_A()==0 and get_rs485_ch_one_line_B()==1):pass
        if(a==1 and b==0):
            add_new_bit_at_end_remove_old_bit_at_start(1)
            get_numbers_and_characters_from_raw_binary()
            while(get_rs485_ch_one_line_A()==1 and get_rs485_ch_one_line_B()==0):pass
        if(a==1 and b==1):
            while(get_rs485_ch_one_line_A()==1 and get_rs485_ch_one_line_B()==1):pass

receiver_main()#ACTION!
