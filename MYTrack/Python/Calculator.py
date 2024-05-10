def calculadora():
    num1_input = input("Dame el primer numero: ")
    num2_input = input("Dame el segundo nuiero: ")
    
    try:
        num1 = float(num1_input)
        num2 = float(num2_input)
        
    except ValueError:
        print("favor de ingresar un numero correcto")
        return
        
    opertador = input("ingrese un operador matematico (+, -, *, /): ")
    
    if opertador == '+':
        print(num1 + num2)
    elif opertador == '-':
        print(num1 - num2)
    elif opertador == '*':
        print(num1 * num2)
    elif opertador == '/':
        print(num1 / num2)
    else:
        print("operador invalido favor de seleccionar otro")
        return
    
calculadora()