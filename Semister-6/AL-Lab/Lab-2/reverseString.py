str=input("Input a string: ")
chars=list(str)
reversed_str=[]
while(len(chars)>0):
    popped_element=chars.pop()
    reversed_str.append(popped_element)
print("The reversed string is:",''.join(reversed_str))