numb = int(input("Digite um numero: \n"))
max = (numb * 10) + 1
print("==================================")
for x in range(numb, max, numb):
  print(str(numb) + " x " + str(x/numb) + " = " + str(x))
print("==================================")