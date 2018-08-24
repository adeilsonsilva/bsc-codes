# curvaRoc = read.csv("irisRoc.txt", header=F, sep=" ")
fileBuffer <- ""
# flag = 1
# for(i in 1:50) {
#     for(j in 1:5) {
#         for(x in 1:50) {
#             for(y in 1:5) {
#                 cat("ainda ta no ",i,j,x,y,"\n")
#                 if(!( (x==i) && (y==j) )) {
#                         fileBuffer = paste(fileBuffer, i," ",j, " ", x," ",y," ",sep="")
#                         fileBuffer = paste(fileBuffer, curvaRoc[flag,2], "\n",sep="")
#                         flag = flag + 1
#                 }
#             }
#         }
#     }
# }
fileConn<-file("IrisFormatoDesnecessario.txt")
writeLines(fileBuffer, fileConn)
close(fileConn)

# curvaRoc = read.csv("true.txt", header=F, sep=" ")
# fileBuffer <- ""
# len = length(curvaRoc[,1])
# for(i in seq(1, len, by=2)) {
#     cat("ta no",i,"de",len,"\n")
#     if(curvaRoc[i,1]==curvaRoc[i,3])
#         fileBuffer = paste(fileBuffer, "1", " ", curvaRoc[i+1,1],"\n",sep="")
#     else
#         fileBuffer = paste(fileBuffer, "-1", " ", curvaRoc[i+1,1],"\n",sep="")
# }
# fileConn<-file("impressaoFormatoCorreto.txt")
# writeLines(fileBuffer, fileConn)
# close(fileConn)
