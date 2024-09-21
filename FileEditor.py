options = ["1. Write A File","2. Append Text To A File","3. Read A File","4. Quit File Editor "]

# Fuction Definitions
def command():
    print("Pick A Command : ")
    print("---------------------------------------------")
    index = 0
    for i in options:
        print(options[index])
        index += 1
    
    print("---------------------------------------------\n")
    
def action(): # Actions Command
    while True:
        try :
            command()
            choice = int(input("Your Command : "))
            if choice == 1 :
                write()

            elif choice == 2 :
                append()
            
            elif choice == 3 :
                read()

            elif choice == 4 :
                close()
                break

        except :
            print("Enter a Valid Command ")
            continue


def write(): # Write Command
    
    fname = input("Enter File Name : ")
    
    content = input("Enter Your Text : ")

    with open(fname,"w") as file :
        file.write(content)
    print("---------------------------------------------\n")
    print("Text Written Successfully !!")

def append(): # Append Command
    
    fname = input("Enter File Name : ")
    content = input("Enter Your Text : ")

    with open(fname,"a") as file :
        file.write(content)
    print("---------------------------------------------\n")
    print("Text Added Successfully !!")

def read(): # Read Command
    fname = input("Enter File Name : ")
    try :
        with open(fname) as file :
            print("---------------------------------------------\n")
            print(file.read())
            print("---------------------------------------------\n")

    except FileNotFoundError :
        print("File Not Found !!")

def close(): # Exit Command
    print("---------------------------------------------\n")
    print("Thank You :)")

# Main Functions
action()
                



    
    
