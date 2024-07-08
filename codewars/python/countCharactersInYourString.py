# The main idea is to count all the occurring characters in a string. If you have a string like aba, then the result should be {'a': 2, 'b': 1}.

# What if the string is empty? Then the result should be empty object literal, {}.
#  link : https://www.codewars.com/kata/52efefcbcdf57161d4000091/train/python



def  count(s):
    counter = {}
    for i in s :
        currentCount = counter.get(i)
        if currentCount is None :
            counter.update({str(i) : 1})
        else :
            currentCount = currentCount +1 
            counter.update({i:currentCount})

    return counter


c =   count("abssdavas")
print(c)
