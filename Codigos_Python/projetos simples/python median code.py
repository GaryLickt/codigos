import random
n1 = random.randint(1,10); #pega um numero aleatorio, pode remover/alterar os valores de random.randint para fins alternativos
n2 = random.randint(1,10);
n3 = random.randint(1,10);
soma = n1 + n2 + n3
media = round(soma/3, 3); #pega a soma das medias, e divide por 3 (a quantidade de medias)
print("Suas notas foram " + str(n1) + ", " + str(n2) + ", " + str(n3))
print("Sua media escolar é " + str(media))
if media >= 6: #verifica se com as notas, você passaria em alguma instituição cuja media seria 6
  print("Você passou!")
if media < 6:
  print("Você não passou!")
