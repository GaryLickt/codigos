dados = input()
n1, n2, n3 = dados.split(" ") #pega 3 numeros dados na mesma linha, e os divide por espaços, logo depois armazena eles em variaveis e converte para numero
n1 = int(n1)
n2 = int(n2)
n3 = int(n3)
maior = int((n1 + n2 + abs(n1 - n2))/2) #usa de uma formula para ver entre os numeros n1 e n2 qual é o maior


if maior > n3: #compara o maior numero entre n1 e n2, com n3, o maior dos 2 sera armazenado como resultado
    resu = maior
if maior < n3:
    resu = n3

print(str(resu) + " eh o maior") #imprime o maior numero
