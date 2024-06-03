
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

time.sleep(1)