
import time

beatles = [ ]

beatles.append("John Lennon")
beatles.append("Paul McCartney")
beatles.append("George Harrison")

for i in range(2):
    print("")
    print("====== ====== ====== ====== ====== ======")
    print("")
    beatles.append(input("Digite o nome dos cantores: "))

print("")
print("====== ====== ====== ====== ====== ======")
print("")
print("Lista: ", beatles)

del beatles[-2]
del beatles[-1]

beatles.insert(0, "Ringo Starr")

print("")
print("====== ====== ====== ====== ====== ======")
print("")
print("Lista Final: ", beatles)
print("")
print("====== ====== ====== ====== ====== ======")
print("")

time.sleep(2)