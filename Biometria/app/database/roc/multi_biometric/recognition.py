import numpy

def percentage(part, whole=1):
  return 100 * float(part)/float(whole)

scoreList = {}
rate = {
    'tp' : 0,
    'tn' : 0,
    'fp' : 0,
    'fn' : 0
}

safes = []
notSafes = []

negative = 0
positive = 0

SAME_USER = str(1)
DIFFERENT_USERS = str(0)

with open('merged_result', 'r') as f:
    for line in f:

        userOne = line.split()[0].split('_')[0]
        userTwo = line.split()[1].split('_')[0]
        score = float(line.split()[2])
        systemGuess = line.split()[3]

        if score in scoreList:
            scoreList[score] += 1
        else:
            scoreList[score] = 1

        if (userOne == userTwo):
            safes.append(score)
            positive += 1
        elif (userOne != userTwo):
            notSafes.append(score)
            negative += 1

        if ( # true positive
            (
                userOne == userTwo
                    and
                systemGuess == SAME_USER
            )
        ):
            rate['tp'] += 1
        elif ( # true negative
            (
                userOne != userTwo
                    and
                systemGuess == DIFFERENT_USERS
            )
        ):
            rate['tn'] += 1
        elif ( # false negative
            (
                userOne == userTwo
                    and
                systemGuess == DIFFERENT_USERS
            )
        ):
            rate['fn'] += 1
        elif ( # false positive
            (
                userOne != userTwo
                    and
                systemGuess == SAME_USER
            )
        ):
            rate['fp'] += 1

    tpr = rate['tp'] / float(positive)
    fnr = (1 - tpr)
    tnr = rate['tn'] / float(negative)
    fpr = rate['fp'] / float(negative)
    acc = (rate['tp'] + rate['tn']) / float(rate['tp'] + rate['fp'] + rate['fn'] + rate['tn'])
    error = (1 - acc)

    print "Pct de acerto: " + str(percentage(acc)) + "%"
    print "Pct de erro: " + str(percentage(error)) + "%"
    print "TP rate: " + str(percentage(tpr)) + "%"
    print "FN rate: " + str(percentage(fnr)) + "%"
    print "TN rate: " + str(percentage(tnr)) + "%"
    print "FP rate: " + str(percentage(fpr)) + "%"

    numpy.savetxt("safes", sorted(safes, key=float), delimiter=",", fmt='%f')
    numpy.savetxt("notSafes", sorted(notSafes, key=float), delimiter=",", fmt='%f')
