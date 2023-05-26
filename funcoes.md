# Estrutura de uma função (Oque cada coisa é):
__def__ = usado para determinar que a pessoa esta criando uma função</br>
__nome__ = nome da função (não pode conter nenhum acento e nenhum espaço, caso queria dar espaço, use "______")</br>
__[argumento0, argumento1,...]__ = argumentos usados na função, geralmente usados para permitir que o usuario insira um valor de fora, Ex: soma(numero1,numero2) // algumas funções (dependendo da intenção do programador) podem não ter nenhum argumento</br>
__[codigo]__ = o codigo que sera executado dentro da função</br>
__return [resultado]__ = é como a função "retorna" um valor, seja para ser armazenado, ou imprimido, Ex: "return 1+1" (a função iria retornar "2")</br>


AVISO: os "[]" estão sendo usados para indicar coisas obrigatorias (ou não) na estrutura, não precisa adicionar os "[]" quando for escrever algo na função

# Estrutura da função (Como programar uma):

> __def nome(argumento0, argumento1, ... , argumentox):__</br>
> [codigo]</br>
> return [resultado] (pode ser uma variavel, ou pode ser direto // as vezes a função não usa o return):</br>

  # atribuindo o resultado a uma variavel
  
  > soma = 1 + 1</br>
  > return soma</br>

  # indo direto

  > return 1 + 1</br>

# Como chamar uma função:
para chamar a função, você pode usar uma variavel para armazenar o valor dela</br>
e depois imprimir ou chamar a função diretamente no print</br>

# usando uma variavel

> r = nome(argumento0, argumento1, ... , argumentox)</br>
> print(r)</br>

# indo direto

> print(nome(argumento0, argumento1, ... , argumentox))</br>

# Exemplos de funções aplicadas:

> __def soma(x,y):__</br>
>   return x + y</br>
> </br>
> r = soma(3,5)</br>
> print(r)</br>

__Output (Saida) = "8"__
