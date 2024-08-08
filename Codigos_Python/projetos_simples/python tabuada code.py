#esse codigo tem duas versões, uma gera a tabuada do numero ate 10, ja a de baixo gera 2 fileiras de numeros, uma vai ate 20, e a outra ate 40

#primeira versão ----------------------
numb = int(input("Digite um numero: \n")) #recebe um numero inteiro dado pelo usuario, e armazena ele em uma variavel chamada numb
max = (numb * 10) + 1 #pega o numero dado, e calcula um maximo para ser usado como limite na tabuada
print("==================================")
for x in range(numb, max, numb): 
  print(str(numb) + " x " + str(x/numb) + " = " + str(x)) #usando o for, e o range, conseguimos fazer um loop no print aonde toda linha ele vai printar "<numero dado> x <numero> = <valor>" ate chegar no maximo
print("==================================")

#segunda versão ------------------------
n1 = int(input("Digite um numero: \n")) #recebe um numero inteiro dado pelo usuario, e armazena ele em uma variavel chamada n1
maxn = (n1 * 20) + 1 #pega o numero dado, e calcula um maximo para ser usado como limite na tabuada
print("===================")
print("--Tabuada do " + str(n1) + "--")
print("========================")
for x in range(n1, maxn, n1):
  print(str(n1) + " x " + str(x//n1) + " = " + str(x) + " | " + str(n1) + " x " + str((x//n1)+20) + " = " + str(x + (n1 * 20))) #usando o for, e o range, conseguimos fazer um loop no print aonde toda linha ele vai printar "<numero dado> x <numero> = <valor>" ate chegar no maximo
print("=============================")
