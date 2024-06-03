
import time

# Biblioteca para retornar um númer inteiro e aleatório
from random import randint as rd # 'rd' é o nome da variável

sorteado = rd(-100, 100) # Sorteia um número de -100 a 100

# # Criando uma lista de inteiros aleatórios
# lista = [rd(1, 6) for i in range(1,11)] # 'range(1,11)' conta 10 posições (a partir do 1), mas não começa na posição '1', e sim na '0'
# lista2 = [x for x in range (1, 11)]
# lista3 = ["Rolo Compressor!!!" for f in range(1,5)]

# print(lista)
# print(lista2)
# print(lista3)

# # Criando lista par

# par = [i for i in range(10) if i % 2 == 0]
# # print(par)

# # Povoando uma lista com 'input'

# # listausuario = [input("Digite um número: ") for p in range(5)]
# # print(listausuario)

# # Utilizando o método 'split' (Cada palavra se torna um elemento da lista)
# # nome = "Mickey Mouse"
# # print(nome)
# # print(nome.split())

# # Aplicando o 'split' com o 'input'

# # notas = [n for n in input("Notas: ").split()]
# # print(notas)

# # notas2 = [float(n) for n in input("Notas: ").split(",")]
# # print(notas2)

# # Lista com diferentes tipos de informação

# listamista = [17, 70.5, "Sem mundial!", True]
# # print(listamista)

# # Manipulação / Fatiamento de Listas

# veiculos1 = ['carro', 'bicicleta', 'moto']
# print('')
# print('veiculos1: ', veiculos1)
# print('')

# # Copiando o conteúdo da lista 'veiculos1', para 'veiculos2'
# veiculos2 = veiculos1[:]
# del veiculos1[0]
# print('veiculos2: ', veiculos2)
# print('')
# print('veiculos1: ', veiculos1)

# # Copiando o conteúdo da lista 'veiculos1', para 'veiculos2'

# veiculos3 = veiculos2[0:1] # copia o conteúdo da posição 0 a 1 (ou seja somente a 0)
# print('')
# print('veiculos3: ', veiculos3)

# # Copiando parte do conteúdo, incluindo o último elemento

# veiculos4 = veiculos2[0:-1]
# print('')
# print('veiculos4: ', veiculos4)
# print('')

# veiculos5 = veiculos2[-1:1]
# print('veiculos5: ', veiculos5)
# print('')

# Outras maneiras de Fatiamento (omissão do 'start' ou 'end')

# mylist = ["a", "b", "c", "d", "e", "f"]
# print('')
# print('mylist: ', mylist)
# print('')

# newlist  = mylist[:3] # começa do 0 e vai até 3
# print('newlist: ', newlist)
# print('')

# newlistfim = mylist[3:] # começa do 3 e vai até o final
# print('newlistfim: ', newlistfim)
# print('')

# # Apagando contepudo de listas

# del mylist[1:3] # apaga itens 1 e 2 (a = 0 e d = 3)
# print('mylist (sem 1 e 2): ', mylist)
# print('')

# del mylist[:]# apaga todo conteúdo da lista
# print('mylist (sem nada): ', mylist)
# print('')

# Testando se alguns itens existem em uma lista ou não, para isso, usamos palavras chave 'in' e 'not in'

naosei = ['a', 'b', 18, 15]
print('')
print('a in naosei: ', "a" in naosei)
print('')
print('c not in naosei: ', "c" not in naosei)
print('')
print('15 not in naosei: ', 15 not in naosei)
print('')

time.sleep(3)