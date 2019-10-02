setwd("D:\\Documents\\УЧЕБА\\Матстат\\задание1")
getwd()

data_file = read.csv("r1z1.csv")
x = data_file$X
n = length(x)

hist(x, main = "Гистограмма выборки", xlab = "Значение", ylab = "Вер-ть", xlim = c(105, 130), breaks = 20, col = "lightblue", freq = FALSE)
lines(density(x), col = "red", lwd = 3)