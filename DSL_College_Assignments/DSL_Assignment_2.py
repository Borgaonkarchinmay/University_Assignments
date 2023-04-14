class string:
    def length(self, exp):
        index = 0
        while True:
            try:
                ele = exp[index]
                index = index + 1
            except:
                return index

    def pallindrome(self, exp):
        len = self.length(exp)
        for i in range(len):
            if exp[i] != exp[len - 1 - i]:
                print("Expression is not palindrome!!")
                return
        print("Expression is palindrome.")

    def wordOccurence(self, exp):
        wordList = self.wordlist(exp)
        occList = []
        for i in range(self.length(wordList)):
            word = wordList[i]
            count = 0
            for j in range(self.length(wordList)):
                if wordList[j] == word:
                    count = count + 1
            occList.append(count)

        for i in range(self.length(wordList)):
            print("Word: ", wordList[i], " Occurence: ", occList[i])

    def longestword(self, exp):
        wordList = self.wordlist(exp)
        len = self.length(wordList[0])
        index = 0
        for i in range(1, self.length(wordList)):
            if self.length(wordList[i]) > len:
                len = self.length(wordList[i])
                index = i
        print("Longest word is: ", wordList[index])
        print("Length is: ", len)

    def charfreq(self, exp, tarChar):
        count = 0
        for i in range(self.length(exp)):
            if exp[i] == tarChar:
                count = count + 1
        return count

    def substring(self, exp, tarstr):
        expLen = self.length(exp)
        substrLen = self.length(tarstr)

        for i in range(expLen):
            if exp[i] == tarstr[0]:
                j = 0
                for j in range(substrLen):
                    if exp[i + j] != tarstr[j]:
                        break
                    elif j == substrLen - 1:
                        return i
        return -1


    def wordlist(self, exp):
        wordList = []
        word = []
        for i in range(self.length(exp)):
            if exp[i] == ' ':
                wordList.append(word)
                word = []
            else:
                word.append(exp[i])
        wordList.append(word)
        return wordList

expression = string()
print("Palindrome")
print("Word: MADAM")
expression.pallindrome("MADAM")
print()
print("Character frequency")
print("String: Best programmer, Character: 'r'")
print(expression.charfreq("Best programmer", 'r'))
print()
print("Longest word")
print("String: John is better programmer")
expression.longestword("John is better programmer")
print()
print("Occurence of each word in the string")
print("String: Indian premier league")
expression.wordOccurence("Indian premier league")
print()
print("Find substring and return index")
print("String: Donald trump, Substring: ld tr ")
index = expression.substring("Donald trump", "ld tr")
print("Substring found at index: ", index)
