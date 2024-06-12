
import time

tupla = tuple()

tupla = (1)

tupla = (1,)

tupla = 1, 2, 3

print(tupla)
print(tupla[1])

# tupla[0] = 100 erro pois tuplas são imutáveis

print(tupla[0])

# manipulando dicionário

dic = {"semmundial" : "palmeiras", "1mundial" : "corinthians", "2mundiais" : "sãopaulo"}

print(dic)

print(dic["semmundial"])

notas = {"mat":5,"lp":10,"ef":8}

print(notas)
print(notas["lp"])
# print(notas["bio"])
print(len(notas)) #imprime a quantidade de itens no 'dic'
print(dir(notas)) # imprime todoas funções para dic
print(notas.values()) # imprime os valores
print(notas.keys())# imprime as chaves

for disciplina in notas.keys():
    print(disciplina)

time.sleep(3)