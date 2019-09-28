setwd("D:\\Documents\\УЧЕБА\\Матстат\\задание1")
getwd()

data_file = read.csv("r1z1.csv")
x = data_file$X
n = length(x)

xx = sort(x)
v = seq(from = 1/n, to = 1, by = 1/n)
plot(xx, v, type = "l", col="blue", lwd=2, main="ЭФР")