import numpy

mark1 = numpy.zeros((35))
mark2 = numpy.zeros((35))
mark3 = numpy.zeros((35))

media = 3.3185925787533335
desvio = 0.10930683979243797

minV = media-desvio
maxV = media + (3 * desvio)

markAuto = numpy.zeros((35))
for user in range(1, 14):
    for image in range(1, 6):
        # print str(user)+'/'+str(user)+'_'+str(image)+'_result.txt'
        with open(str(user)+'/'+str(user)+'_'+str(image)+'_result.txt', 'r') as f:
            lineCount = 0
            for line in f:
                if ( (float(line.split()[3]) <= maxV) and (float(line.split()[3]) >= 0) ):
                    markAuto[lineCount] += 1
                    # print "0 <= "+line.split()[3]+" <= "+str(maxV)
                # print line.split()[0]
                lineCount += 1

    # print markAuto/5
# print numpy.mean(mark1 / (5*13)), numpy.std(mark1 / (5*13))
# print numpy.mean((mark2 / (5*13))), numpy.std((mark2 / (5*13)))
# print numpy.mean((mark3 / (5*13))), numpy.std((mark3 / (5*13)))
# print (mark1 / (5*13))
# print (mark2 / (5*13))
print (markAuto / (5*13))
print numpy.mean((markAuto / (5*13))), numpy.std((markAuto / (5*13)))
#
# numpy.savetxt("1.csv", (mark1 / (5*13)), delimiter=",", fmt='%f')
# numpy.savetxt("2.csv", (mark2 / (5*13)), delimiter=",", fmt='%f')
# numpy.savetxt("3.csv", (mark3 / (5*13)), delimiter=",", fmt='%f')
numpy.savetxt("performance-auto.csv", (markAuto / (5*13)), delimiter=",", fmt='%f')
