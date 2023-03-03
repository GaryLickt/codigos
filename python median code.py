import random
n1 = random.randint(1,10);
n2 = random.randint(1,10);
n3 = random.randint(1,10);
soma = n1 + n2 + n3
media = round(soma/3, 2);
print("Suas notas foram " + str(n1) + ", " + str(n2) + ", " + str(n3))
print("Sua media escolar é " + str(media))
if media >= 6:
  print("Você passou!")
if media < 6:
  print("Você não passou!")