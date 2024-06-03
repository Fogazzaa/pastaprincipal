
import time

# Encontrar o maior valor na lista - Exemplo 1

lista = [17, 3, 11, 5, 1 , 9, 7, 15, 18]
maiornumero = lista[0] # recebeu o número 17

for i in range(1, len(lista)):
    if lista[i] > maiornumero:
        maiornumero = lista[i]

print("")
print('maoir número: ', maiornumero)
print("")

# Exemplo 2

mylist = [14, 4, 11, 5, 6 , 9, 7, 19, 12, 999999]
maior = mylist[0]
for i in mylist:
    if i > maior:
            maior = i

print('maior da lista 2: ', maior)
print("")

# Exemplo 3

ultimalista = mylist[:]
mel = ultimalista[0]
for i in ultimalista[1:]:
    if i > mel:
        mel = i

print("maior valor da 3: ", mel)
print("")

# Encontrar a localização de um determinado elemento dentro de uma lista

frutas = ['abacaxi', 'maça', 'pera', 'mamao', 'uva', 'melancia']
elemento = 'melancia'
achado = False

for i in range(len(frutas)):
    achado = frutas[i] == elemento
    if achado == True:
        break

if achado == True: 
    print('elemento encontrado no indice: ', i)
else:
    print('não encontrado')
print("")

time.sleep(1)