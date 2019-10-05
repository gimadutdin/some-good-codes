setwd("D:\\Documents\\УЧЕБА\\Матстат\\задание1")
getwd()

data_file = read.csv("r1z1.csv")
x = data_file$X
n = length(x)

xx = sort(x)
plot(xx, (1:n)/n, type = "S", col="blue", lwd=2, main="ЭФР")