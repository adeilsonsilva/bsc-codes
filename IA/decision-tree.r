entropy <- function(S) {
  e <- 0
  total <- sum(S)
  for (d in dimnames(S)) {
    Pi <- S[d]/total
    e <- e + Pi * log2(Pi)
  }
  -sum(e, na.rm=T)
}

information_gain <- function(ent, S, attr) {
  g <- ent
  n <- nrow(S)
  values = levels(S[,attr]) # Possible values for attribute
  for (v in values) {
    s <- S[S[attr] == v,]
    sv <- nrow(s)
    localEntropy <- entropy(table(s$Jogar.Tênis))
    g <- g - (sv/n) * entropy(table(s$Jogar.Tênis))
    print(paste("Valor:", v, ";", "Entropia:", localEntropy))
  }
  g
}

db = read.csv2('jogar-tenis.csv')

GlobalEntropy <- entropy(table(db$Jogar.Tênis))

for (attr in attributes(db)$names[2:5]) {
  g <- information_gain(GlobalEntropy, db, attr)
  print(paste("Atributo:", attr, ";", "Ganho:", g))
}
