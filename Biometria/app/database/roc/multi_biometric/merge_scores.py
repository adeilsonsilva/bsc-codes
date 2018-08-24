handScores = []
irisScores = []

MAX_HAND_SCORE = 93075.6
MIN_HAND_SCORE = 0.0

MAX_IRIS_SCORE = 80.7595
MIN_IRIS_SCORE = 0.0

def normalize(value, Max, Min):
    return float((value - Min) / (Max - Min))

def get_mean(valueOne, valueTwo):
    return float((valueOne + valueTwo) / 2)

def analyze(value):
    return 1 if value <= 0.2 else 0

with open('hand_scores') as handFile, open('iris_scores') as irisFile:
    for handLine, irisLine in zip(handFile, irisFile):
        handScore = float(handLine.split()[2])
        irisScore = float(irisLine.split()[2])

        normalizedHandScore = normalize(handScore, MAX_HAND_SCORE, MIN_HAND_SCORE)
        normalizedIrisScore = normalize(irisScore, MAX_IRIS_SCORE, MIN_IRIS_SCORE)
        meanOfScores = get_mean(normalizedHandScore, normalizedIrisScore)
        result = analyze(meanOfScores)

        # print str(normalizedHandScore) + " " + str(normalizedIrisScore)
        print str(handLine.split()[0] + " " + handLine.split()[1] + " " + str(meanOfScores) + " " + str(result))
        handScores.append(handScore)
        irisScores.append(irisScore)

# print max(handScores, key=float), min(handScores, key=float)
# print max(irisScores, key=float), min(irisScores, key=float)
