# chats.py
# Usage: python3 chats.py
#
# This command processes a series of lines of text, looking for
# contiguous runs of alphabetic characters treating them each as a
# word. For each such word, it keeps a count of the number of its
# occurrences in the text.
#
# To end text entry hit RETURN and then CTRL-d.  It then generates
# a random text that tries to mimic the text it just processed.
#
#
# Alternative usage: python3 chats.py < textfile.txt
#
# The above instead processes the text of the file in 'textfile.txt'.
#

import sys
import random

STOPPERS = [".", "!", "?"]
WHITESPACE = [" ", "\n", "\r", "\t"]


def simplifyWord(word):
    """Returns the given string with only certain chars and lowercase.

    This "simplifies" a word so that it only contains a sequence of
    lower case letters and apostrophes, making uppercase letters
    lowercase, and skipping others.  It returns the "simplified" word.
    If, upon simplifying a word, all the characters are skipped, the 
    function returns None.
    
    In normal use, this would convert a word like "Ain't" into the
    word "ain't" and return it. It also would take a text string like
    "it105%s" and give back the string "its".

    This particular function behavior is somewhat arbitrary, written
    to be "good enough" just to handle the spurious other characters
    that might arise in the kinds of free texts from things like
    Project Gutenberg. Sadly, this also strips out accented characters
    and non-Roman alphabetic characters.
    """

    # Scan the word for a-z or ' characters.
    convertedWord = "";
    for c in word:
        if 'A' <= c and c <= 'Z':
            c = c.lower()
        if ('a' <= c and c <= 'z') or c == '\'':
            convertedWord += c;

    # If we added any such characters, return that word.
    if len(convertedWord) > 0:
        return convertedWord
    else:
        # Otherwise, return None.
        return None


def readWordsFromInput():
    """Returns the contents of console input as a list of words.

    Process the console input as consisting of lines of words. Return
    a list of all the words along with the strings that are "stoppers." 
    Each non-stopper word in the list will be lowercase consisting only
    of the letters 'a'-'z' and also apostrophe. All other characters are
    stripped from the input. Stopper words are specified by the variable
    STOPPERS.
    """

    def spacedAround(text, c):
        """Returns modified text with spaces around any occurrence of c.

        Helper function that replaces any string `text` that has the
        character `c` so that all the occurrences of `c` are replaced
        with the substring " c ".
        """

        splits = text.split(c)
        return (" " + c + " ").join(splits)

    def spaceInsteadOf(text, c):
        """Returns modified text with space replacing any c.

        Helper function that replaces any string `text` that has the
        character `c` so that all the occurrences of `c` are replaced
        with a space.
        """

        splits = text.split(c)
        return (" ").join(splits)

    # Read the text into one (big) string.
    textChars = sys.stdin.read()

    # Add spaces around each "stopper" character.
    for stopper in STOPPERS:
        textChars = spacedAround(textChars, stopper)

    # Replace each whitespace character with a space.
    for character in WHITESPACE:
        textChars = spaceInsteadOf(textChars, character)

    # Split the text according to whitespace.
    rawWords = textChars.split(" ")

    # Process the raw words, simplifying them in the process by
    # skipping any characters that we don't currently handle.
    # We treat the "end of sentence"/"stopper" words specially,
    # including them in the list as their own strings.
    words = []
    for word in rawWords:
        if word not in STOPPERS:
            word = simplifyWord(word)
        if word is not None:
            words.append(word)
    return words


# helper function to decide whether to append a new element with frequency 1 or make the frequency of the existing
# element to add 1
def append_procedure(index, input_str, input_dict, input_list):
    # set an index to detect situation
    a = 0

    # for every element in input_dict[input_str]...
    for elem in input_dict[input_str]:
        # if the next element in the input list is equal to word...(forming bigrams)
        if input_list[index + 1] == elem[0]:
            # the frequency of input_str +=1
            elem[1] += 1
            # set the index to 1 to separate situation
            a = 1
        # else, do nothing
        else:
            pass

    # check the index, if the next element doesn't equal to any existing string in that input_dict[input_str]
    if a == 0:
        input_dict[input_str].append([input_list[index + 1], 1])


def trainBetter(theWords):
    # set the output dict with words and frequency
    output_dict = {}

    # set the index
    i = 0

    # if the word list is empty, return the empty dict
    if not theWords:
        return output_dict

    else:
        # if the last item in the word list is not a stopper, add a '.' to that word list
        if theWords[-1] not in STOPPERS:
            theWords.append('.')
        else:
            pass

        # 1. dealing with bigrams
        # for every item in the word list...
        for item in theWords:
            # count until to the last word in the word list
            if i == len(theWords) - 1:
                pass
            else:
                # if item is already a key in the output dict...
                if item in output_dict:
                    # forming function to check situations. setting i as we need to collect the word
                    # in the word list which is next to 'item', so the input_list[index + 1] in append_procedure
                    # function can satisfy the condition.
                    append_procedure(i, item, output_dict, theWords)
                    # increase the index while moving to next word
                    i += 1
                # if item not in output dict..
                else:
                    # create a key with its next word and frequency 1
                    output_dict[item] = [[theWords[i + 1], 1]]
                    i += 1

        # 2. For the stoppers, we need to add the first word to '.','!','?'
        for i in STOPPERS:
            # if that stopper already exists in output_dict...
            if i in output_dict:
                # applying the helper function to separate situations.(set index = 0, so input_list[-1 + 1] equals
                # to the first word in the word list.
                append_procedure(-1, i, output_dict, theWords)
            else:
                # if not exist in output_dict, create one
                output_dict[i] = [[theWords[0], 1]]

        # 3. Basically the same procedure for trigrams by using helper function.
        x = 0
        # as we are not forming bigrams of the last two words or symbol, so we stop at 2 words before.
        while x < len(theWords) - 2:
            if (theWords[x] + ' ' + theWords[x + 1]) in output_dict:

                # need to find out the word after the next word of theWoods[x], so we use index + 1 + 1 as
                # input_list[x + 1 + 1] in the helper function to find the word to form trigram.
                append_procedure(x + 1, (theWords[x] + ' ' + theWords[x + 1]), output_dict, theWords)
                x += 1

            else:
                output_dict[(theWords[x] + ' ' + theWords[x + 1])] = [[theWords[x + 2], 1]]
                x += 1
    print(output_dict)
    return output_dict


# helper function to pick words from biTriDict[input_str] by using random.choice and frequency of words collected
# by trainBetter
def pick_words(input_str):
    # initial condition
    count = 0

    # fot every element in the value of BiTriDict[input_str]
    for elem in biTriDict[input_str]:
        # make count add that word's frequency
        count += elem[1]

    # make a choice (int) between 1 to count
    choice = random.choice(list(range(1, count + 1)))

    # for every element in BiTriDict[input_str]...
    for elem in biTriDict[input_str]:
        # if choice is greater than the frequency of this word, subtract frequency from the choice
        if choice > elem[1]:
            choice -= elem[1]

        # if smaller than the frequency of this word, then return this word. Break the for loop.
        else:
            result = elem[0]
            break

    return result

# helper function to check if the output string surplus the numWidth
def check(stri, limit):
    # if str1 is smaller or equal to limitation, return True. Longer, return False.
    if len(stri) <= limit:
        return True
    else:
        return False


def chatBetter(biTriDict, numLines, lineWidth):
    # empty dict return empty string
    if biTriDict == {}:
        return ''

    # set the initial condition as w1 to '.' and w2 a word from '.'
    w1 = '.'
    w2 = pick_words('.')
    i = 0
    output_str = w2

    # while we print less or equal to numLines limits...
    while i <= numLines:
        # check whether trigram is in Dict...
        if (w1 + ' ' + w2) in biTriDict:
            # select words from trigram from BiTriDict
            temp = pick_words(w1 + ' ' + w2)
            # if the selected word is a stopper
            if temp in STOPPERS:
                # check whether adding this stopper surplus the lineWidth limitation
                if check(output_str + temp, lineWidth) == True:
                    # if not, output string add that stopper
                    output_str += temp
                # if go beyond that limit...
                else:
                    # print that string first and add that stopper to the next line
                    print(output_str)
                    output_str = temp
                    # linenumber + 1
                    i += 1
            # similarly, check with word(with space), basically same procedure
            else:
                if check(output_str + ' ' + temp, lineWidth) == True:
                    output_str += ' ' + temp
                else:
                    print(output_str)
                    output_str = temp
                    i += 1
            # make the w1 = w2 and w2 = the word that has been selected(setting next bigram we need to search)
            w1 = w2
            w2 = temp

        # same procedure with bigram
        elif w2 in biTriDict:
            temp = pick_words(w2)
            if temp in STOPPERS:
                if check(output_str + temp, lineWidth) == True:
                    output_str += temp
                else:
                    print(output_str)
                    output_str = temp
                    i += 1
            else:
                if check(output_str + ' ' + temp, lineWidth) == True:
                    output_str += ' ' + temp
                else:
                    print(output_str)
                    output_str = temp
                    i += 1
            w1 = w2
            w2 = temp

        # if not in trigram or bigram, pick a random follower of '.'
        else:
            temp = pick_words('.')
            if temp in STOPPERS:
                if check(output_str + temp, lineWidth) == True:
                    output_str += temp
                else:
                    print(output_str)
                    output_str = temp
                    i += 1
            else:
                if check(output_str + ' ' + temp, lineWidth) == True:
                    output_str += ' ' + temp
                else:
                    print(output_str)
                    output_str = temp
                    i += 1
            w1 = w2
            w2 = temp

    # for the lines pass the numLine, we need to stop when the first stopper shows up.
    while i > numLines:
        # same procedure
        if (w1 + ' ' + w2) in biTriDict:
            temp = pick_words(w1 + ' ' + w2)
            # break when encountering a stopper, else is the same
            if temp in STOPPERS:
                if check(output_str + temp, lineWidth) == True:
                    output_str += temp
                    print(output_str)
                    break
                else:
                    print(output_str)
                    output_str = temp
                    print(output_str)
                    break
            else:
                if check(output_str + ' ' + temp, lineWidth) == True:
                    output_str += ' ' + temp
                else:
                    print(output_str)
                    output_str = temp
                    i += 1
            w1 = w2
            w2 = temp

        # same thing with bigram
        elif w2 in biTriDict:
            temp = pick_words(w2)
            if temp in STOPPERS:
                # break when encountering a stopper, else is the same
                if check(output_str + temp, lineWidth) == True:
                    output_str += temp
                    print(output_str)
                    break
                else:
                    print(output_str)
                    output_str = temp
                    print(output_str)
                    break
            else:
                if check(output_str + ' ' + temp, lineWidth) == True:
                    output_str += ' ' + temp
                else:
                    print(output_str)
                    output_str = temp
                    i += 1
            w1 = w2
            w2 = temp

        # and same thing for the situations besides bigrams and trigrams.
        else:
            temp = pick_words('.')
            if temp in STOPPERS:
                if check(output_str + temp, lineWidth) == True:
                    output_str += temp
                    print(output_str)
                    break
                else:
                    print(output_str)
                    output_str = temp
                    print(output_str)
                    break
            else:
                if check(output_str + ' ' + temp, lineWidth) == True:
                    output_str += ' ' + temp
                else:
                    print(output_str)
                    output_str = temp
                    i += 1
            w1 = w2
            w2 = temp


#
# The main script. This script does the following:
#
# * Processes a series of lines of text input into the console.
#      => The words of the text are put in the list `textWords`
#
# * Scans the text to compute statistics about bi-grams and tri-
# grams that occur in the text. This uses the function `train`.
#
# • Generates a random text from the bi-/tri-gram dictionary
#   using a stochastic process. This uses the procedure 'chat'.
#

if __name__ == "__main__":
    # Read the words of a text (including ".", "!", and "?") into a list.
    print("READING text from STDIN. Hit ctrl-d when done entering text.")
    textWords = readWordsFromInput()
    print("DONE.")

    # Process the words, computing a dictionary.
    biTriDict = trainBetter(textWords)
    chatBetter(biTriDict, 30, 70)
