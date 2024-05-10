def palindrome(word):
    for i in range(0, int(len(word)/2)):
        if word[i] != word[len(word)-i-1]:
            return False
        return True


word = input("Escriba una palabra: ").lower()
print(word, 'es un paliondromo?', palindrome(word))
