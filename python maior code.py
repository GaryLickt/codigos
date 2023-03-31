dados = input()
n1, n2, n3 = dados.split(" ")
n1 = int(n1)
n2 = int(n2)
n3 = int(n3)
maior = int((n1 + n2 + abs(n1 - n2))/2)


if maior > n3:
    resu = maior
if maior < n3:
    resu = n3

print(str(resu) + " eh o maior")