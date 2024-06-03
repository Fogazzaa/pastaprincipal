
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

print("")
numero1 = float(input('digite um número: '))
print("")
numero2 = float(input('digite um número: '))

print("")
print(somar3(numero1, numero2))
print("")

time.sleep(2)