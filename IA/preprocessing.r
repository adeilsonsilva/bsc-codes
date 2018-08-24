# Load bin with database
load("bancoufba.rData")

# Remove NA values from "salario" attribute
banco.ufba = banco.ufba[-which(is.na(banco.ufba$salario)),]

# Remove outliers
banco.ufba = banco.ufba[-which(banco.ufba$salario%in%(boxplot(banco.ufba$salario))$out),]

# Show boxplot
boxplot(banco.ufba$salario)


