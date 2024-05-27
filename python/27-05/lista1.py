import time

numeros = [111, 7, 2, 1]

print("")
print("Tamanho da lista:", len(numeros))
print("Lista:", numeros)
print("")
print("====== ====== ====== ====== ====== ======")
print("")

numeros.append(52) # Ele pega o valor do argumento e o coloca no final da lista

print("Tipo: numeros.append(52)")
print("Tamanho da lista:", len(numeros))
print("Lista:", numeros)
print("")

numeros.insert(0, 99) # Ele pode adicionar um novo elemento em qualquer lugar na lista, não apenas no final.

print("====== ====== ====== ====== ====== ======")
print("")
print("Tipo: numeros.insert(0, 99)")
print("Tamanho da lista:", len(numeros))
print("Lista:", numeros)
print("")

numeros.insert(-1, 1000) # '-1' significa a última posição

print("====== ====== ====== ====== ====== ======")
print("")
print("Tipo: numeros.insert(-1, 1000)")
print("Tamanho da lista:", len(numeros))
print("Lista:", numeros)
print("")

numeros.insert(1, 1011)

print("====== ====== ====== ====== ====== ======")
print("")
print("Tipo: numeros.insert(1, 1011)")
print("Tamanho da lista:", len(numeros))
print("Lista:", numeros)
print("")

numeros.insert(-2, 99999)

print("====== ====== ====== ====== ====== ======")
print("")
print("Tipo: numeros.insert(-2, 99999)")
print("Tamanho da lista:", len(numeros))
print("Lista:", numeros)
print("")
print("====== ====== ====== ====== ====== ======")

time.sleep(2)