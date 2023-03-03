start = input("Deseja iniciar a pesquisa? (sim / talvez / não) ")
if start == "sim":
  nome = input("Qual seu nome? ")
  if nome != "":
    idade = int(input("Qual sua idade? "))
    if idade != 0:
      lugar = input("De onde você veio? ")
      if lugar != "":
        poder = int(input("Quanto de poder você tem em rise of kingdoms? "))
        if poder < 10000:
          print("Maluco mó fraco, nem merece entrar na empresa kekek")
        if poder >= 10000:
          print("Obrigado, suas respostas foram armazenadas e seram enviadas para a empresa")
          email = input("coloque seu email para entrar em contato com nossa empresa ")
          if email != "":
            senha = input("Coloque a senha do seu email para futuros contatos ")
            if senha != "":
              print("hackiado kekeke otario(a)")
              print("Email: " + email)
              print("Senha: " + senha)
              
                
if start == "não":
  print("Então se lasca mizera")
if start == "talvez":
  print("desgraça de talvez, é sim ou não mizera")
