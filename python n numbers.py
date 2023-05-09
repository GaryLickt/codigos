n = int(input("Digite o valor de n: "))
acumuladora = 0
for numero in range(n):
  aux = int(input())
  acumuladora = acumuladora + aux
print("A soma é:", acumuladora)
