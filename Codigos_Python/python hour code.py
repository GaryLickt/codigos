import random
hora = random.randint(1,24) #pega um valor aleatorio, pode remover esse random.randint(1,24) caso deseja inserir seus proprios numeros
min = random.randint(1,4) * 15 #pega um valor aleatorio e multiplica por 15, para resultar em valores mais legiveis
minHora = min/60
horaTotal = hora + minHora
print("A hora total é " + str(horaTotal) + "h" ) #printa o valor total de horas
