numb = int(input("Digite um numero: \n")) #recebe um numero inteiro dado pelo usuario, e armazena ele em uma variavel chamada numb
max = (numb * 10) + 1 #pega o numero dado, e calcula um maximo para ser usado como limite na tabuada
print("==================================")
for x in range(numb, max, numb): 
  print(str(numb) + " x " + str(x/numb) + " = " + str(x)) #usando o for, e o range, conseguimos fazer um loop no print aonde toda linha ele vai printar "<numero dado> x <numero> = <valor>" ate chegar no maximo
print("==================================")
