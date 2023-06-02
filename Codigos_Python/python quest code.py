start = input("Deseja iniciar a pesquisa? (sim / talvez / não)\n") #verifica (caso o usuario responda alguma das 3 alternativas) se o mesmo escolheu iniciar a pesquisa
if start == "sim":
  nome = input("Qual seu nome?\n")
  if nome != "":
    idade = int(input("Qual sua idade?\n"))
    if idade != 0:
      lugar = input("De onde você veio?\n")
      if lugar != "":
        poder = int(input("Quanto de poder você tem em rise of kingdoms?\n"))
        if poder < 50000:
          print("Maluco mó fraco, nem merece entrar na empresa kekek")
        if poder >= 50000:
          print("Obrigado, suas respostas foram armazenadas e seram enviadas para a empresa")
          email = input("UAU! quanto poder!! coloque seu email para entrar em contato com nossa empresa!!1!!1\n")
          if email != "":
            senha = input("Coloque a senha do seu email, assim podemos saber que você realmente possui esse email!\n")
            if senha != "":
              print("hackiado kekeke otario(a)")
              print("Email: " + email)
              print("Senha: " + senha)
              
                
if start == "não":
  print("Então se lasca mizera")
if start == "talvez":
  print("desgraça de talvez, é sim ou não mizera")

 
