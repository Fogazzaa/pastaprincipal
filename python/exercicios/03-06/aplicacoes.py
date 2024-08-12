
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

# Conferidor de apostas em loterias

sorteados = [5, 11, 9, 42, 3, 49]
apostados = [3, 7, 11, 42, 34, 49]
acertos = 0

for numero in sorteados:
    if numero in apostados:
        acertos += 1

print('acertos: ', acertos)
print('')

# Remoção de números repetidos em uma lista
lista = [1,2,4,4,1,4,2,6,2,9]
print('lista original: ', lista)
print('')

# Lista de apoio
vistos = []

# Interar pela lista original de trás para frente
for i in range(len(lista) - 1, -1, -1):
    # Se o número já está na lista 'vistos', remove-lo da lista original
    if lista[i] in vistos:
        del lista[i]
    else:
        # Caso contrário, adicionar a lista 'vistos'
        vistos.append(lista[i]) 

# Exibi a lista modificada
print('lista modificada: ', lista)
print('')

# Listas Avançadas
# 2D - listas alinhadas bidimensonais
tabela = [[":(",":)",":|",";-;"] # [0]
         ,[";-;",":|",":)",":("], # [1]
          [":|",":)",";-;",":("]] # [2]

print('tabela[0][3]: ', tabela[0][3])
print('')
print('tabela[0]: ', tabela[0])
print('')
print(tabela)
print('')

# 3D - Matriz Tridimensional

cubo = [[[':(', 'y', 'z'],
         [':)', 'y', 'z'],
         [':|', 'y', 'z']],
 
        [['amor', 'ódio', 'caridade'],
         [':paz', 'esperança', 'férias'],
         ['tina', 'prior', 'pp']],
 
        [[':restinga', 'patrcínio', 'rifaina'],
         ['amazonence', 'fluminense', 'santos'],
         ['pizza', 'lasanha', 'pastel']]]

print(cubo)
print('')
print(cubo[1])
print(" ")
print(cubo[1][0])
print(" ")
print(cubo[1][0][2])
print(" ")

time.sleep(1)