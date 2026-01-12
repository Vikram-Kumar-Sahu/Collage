num1=input("Enter first number: ")
num2=input("Enter second number: ")
operation=input("Enter operation (+, -, *, /): ")

if operation == '+':
    result = float(num1) + float(num2)
    print("The sum is:", result)    
elif operation == '-':
    result = float(num1) - float(num2)
    print("The difference is:", result)
elif operation == '*':
    result = float(num1) * float(num2)
    print("The product is:", result)
elif operation == '/':
    result = float(num1) / float(num2)
    print("The quotient is:", result)
else:
    print("Invalid operation")