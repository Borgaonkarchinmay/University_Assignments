import numpy as np
from numpy.linalg import norm

def cosineSim(doc1,doc2):
    words1 = doc1.split(' ')
    words2 = doc2.split(' ')
    totalwords = []
    for i in words1:
        if i not in totalwords:
            totalwords.append(i)
    for i in words2:
        if i not in totalwords:
            totalwords.append(i)
    vector1 = np.zeros(len(totalwords))
    vector2 = np.zeros(len(totalwords))

    for i in words1:
        vector1[totalwords.index(i)]=vector1[totalwords.index(i)]+1

    for i in words2:
        vector2[totalwords.index(i)]=vector2[totalwords.index(i)]+1

    

    return np.dot(vector1,vector2)/(norm(vector1)*norm(vector2))

print(cosineSim('hello world','hello omkar hello anish'))



