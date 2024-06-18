def cifra_de_cesar(texto, chave):
    texto_cifrado = ''
    for char in texto:
        if char.isalpha():  # Verifica se o caractere é uma letra
            # Mantém a caixa (maiúscula ou minúscula) após a cifragem
            base = ord('A') if char.isupper() else ord('a')
            # Aplica a cifragem de César usando a fórmula (char + chave - base) % 26 + base
            novo_char = chr((ord(char) - base + chave) % 26 + base)
            texto_cifrado += novo_char
        else:
            texto_cifrado += char  # Mantém caracteres que não são letras inalterados
    return texto_cifrado

# Exemplo de uso:
texto_original = "Hello, World!"
chave = 3
texto_cifrado = cifra_de_cesar(texto_original, chave)
print("Texto original:", texto_original)
print("Texto cifrado:", texto_cifrado)
