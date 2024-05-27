

import time

my_list = [] # Criando uma lista vazia

for i in range(5):
    my_list.append(i+1)

print("")
print("====== ====== ====== ====== ======")
print("")
print("Lista [1]: ", my_list)
print("")
print("====== ====== ====== ====== ======")
print("")

# Lista Vazia 2

my_list2 = []

for i in range(5):
    my_list2.insert(0, i + 1)

print("Lista [2]: ", my_list2)
print("")
print("====== ====== ====== ====== ======")
print("")

# Lista Vazia 3

my_list3 = [10, 1 , 8, 3, 5]
total = 0

for i in range(len(my_list3)):
    total = total + my_list3[i]

print("Soma da Lista [3]: ", total)
print("")
print("====== ====== ====== ====== ======")
print("")

total = 0

for i in my_list3:
    total += i

print("Soma da lista [4]: ",     total)

print("")
print("====== ====== ====== ====== ======")
print("")

# Reordenandoa a lista

# my_list3[0], my_list3[4] = my_list3[4], my_list3[0]
# my_list3[1], my_list3[3] = my_list3[3], my_list3[1]
# my_list3[3], my_list3[0] = my_list3[0], my_list3[3]
# my_list3[2], my_list3[3] = my_list3[3], my_list3[2]


# print("Lista [5]: ", my_list3)
# print("")
# print("====== ====== ====== ====== ======")
# print("")

# Reordenando sem saber o tamanho da lista

tamanho_lista = len(my_list3)

for i in range (tamanho_lista // 2):
    my_list3[i], my_list3[tamanho_lista - i - 1] = my_list3[tamanho_lista - i - 1], my_list3[i]

print(my_list3) 
print("")
print("====== ====== ====== ====== ======")
print("")

time.sleep(2)