import random
hora = random.randint(1,24)
min = random.randint(1,4) * 15
minHora = min/60
horaTotal = hora + minHora
print("A hora total é " + str(horaTotal) + "h" )