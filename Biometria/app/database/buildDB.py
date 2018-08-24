import numpy


for user in range(1, 51):
    userMean = numpy.zeros((5))
    filename = str(user)+'/'+str(user)+'_areas'
    print filename
    with open(filename, 'r') as f:
        lineCount = 0
        for line in f:
            # print type(float(line))
            userMean[lineCount] += float(line);
            lineCount += 1
    print userMean/5
    print [numpy.mean(userMean/5), numpy.std(userMean/5)]
    name = str(user)+'/user_id'
    numpy.savetxt(name, [numpy.mean(userMean/5), numpy.std(userMean/5)], delimiter=":", fmt='%f')
# print numpy.mean(mark1 / (5*13)), numpy.std(mark1 / (5*13))
# print numpy.mean((mark2 / (5*13))), numpy.std((mark2 / (5*13)))
# print numpy.mean((mark3 / (5*13))), numpy.std((mark3 / (5*13)))
# print (mark1 / (5*13))
# print (mark2 / (5*13))
# print (markAuto / (5*13))
# print numpy.mean((markAuto / (5*13))), numpy.std((markAuto / (5*13)))
#
# numpy.savetxt("1.csv", (mark1 / (5*13)), delimiter=",", fmt='%f')
# numpy.savetxt("2.csv", (mark2 / (5*13)), delimiter=",", fmt='%f')
# numpy.savetxt("3.csv", (mark3 / (5*13)), delimiter=",", fmt='%f')
# numpy.savetxt("performance-auto.csv", (markAuto / (5*13)), delimiter=",", fmt='%f')
