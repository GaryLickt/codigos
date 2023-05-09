n = int(input())
x = 1
div = 0
while x <= n:
  if n%x == 0:
    div += 1
  x += 1
if (div <= 2):
  print(str(n) + " é um numero primo")
else:
  print(str(n) + " não é um numero primo")
