
import time

# Função que possui muitas atribuições, parece 'método'
def somar():
    print("")
    n1 = int (input("digite o primeiro número da adição: "))
    print("")
    n2 = int (input("digite o segundo número da adição: "))
    print("")
    print('o resultado é: ', n1 + n2)
    print("")

# somar()

# Função exclusiva de soma dois números
def somar2(n1, n2):
    soma = n1 + n2
    return soma

# print("soma 2: ", somar2(22, 20))
# print("")

# Terceiro exemplo de função 

def somar3(n1, n2):
    return n1 + n2

# print("")
# numero1 = float(input('digite um número: '))
# print("")
# numero2 = float(input('digite um número: '))

# print("")
# # chamada da função
# print(somar3(numero1, numero2))
# print("")

# chamada da função por argumentos
print("")
print(somar3(n2 = 12, n1 = 5))
print("")

def somar4(n1 = 0, n2 = 0):
    return n1 +n2

# print(somar4(50,25))
# print("")
# print(somar4())
# print("")

def somar5(n1, n2 = 0):
    return n1 + n2

print(somar5(50,25)) # 75
print("")
# print(somar5()) # erro
# print("")
print(somar5(10))
print("")
print(somar5(n2 = 51, n1 = 12))
print("")

def somar6(n1, n2):
    if n1 == 1:
        return 1

print(somar6(1,3)) # true
print("")
print(somar6(13,3)) # none
print("")
print(somar6(1,2) + 10) # mostra 11
print("")
print(somar6(1,2) + 10) # mostra 'type' suportado 'str'
print("")

time.sleep(2)