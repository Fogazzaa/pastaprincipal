
import time

# Criando uma lista dentro da outra
lista = [[x for x in range(4)]for i in range(5)]

print("")
print("====== ====== ====== ====== ====== ======")
print("")
print("Lista 1: ", lista)
print("")
print("====== ====== ====== ====== ====== ======")
print("")

lista2 = [45,12,31,17,22]

print("LIsta 2: ", lista2)
print("")
print("====== ====== ====== ====== ====== ======")
print("")

lista2.sort() # Deixa a lista crescente/alfabética

print("Lista 2 Crescente: ", lista2)
print("")
print("====== ====== ====== ====== ====== ======")
print("")

lista2.reverse() # Deixa a lista decrescente

print("Lista 2 Decrescente: ", lista2)
print("")
print("====== ====== ====== ====== ====== ======")
print("")

time.sleep(2)