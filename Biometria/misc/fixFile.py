import numpy


with open('scores', 'r') as f:
    for userOne in range(1, 51):
        for imageOne in range(1, 6):
            for userTwo in range(1, 51):
                for imageTwo in range(1, 6):
                    path = str(userOne)+'_'+str(imageOne) + ' ' + str(userTwo)+'_'+str(imageTwo)

                    if userOne == userTwo and imageOne == imageTwo:
                        score = 0.0
                    else:
                        line = f.readline()
                        if not line: break
                        score = float(line.split()[0])

                    print path + ' ' + str(score)
