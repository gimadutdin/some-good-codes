setwd("D:\\Documents\\�����\\�������\\�������1")
getwd()

data_file = read.csv("r1z1.csv")
x = data_file$X
n = length(x)

hist(x, main = "��������� �����������", xlab = "��������", ylab = "�������", xlim = c(105, 130), breaks = 20, col = "lightblue")