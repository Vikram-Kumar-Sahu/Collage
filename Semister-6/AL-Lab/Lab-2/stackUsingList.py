list=[]
num=int(input("Enter a number if you want else type -1: "))
while(num!=-1):
    list.append(num)
    num=int(input("Enter a number if you want else type -1: "))
print("The stack is:",list)
if len(list)==0:
    print("Stack is empty, cannot perform pop operation")

else:
    print("if you want to pop element type 1 else type -1")
    if(int(input())==1):
        popped_element=list.pop()
        print("The popped element is:",popped_element)
        print("The stack after pop operation is:",list)
