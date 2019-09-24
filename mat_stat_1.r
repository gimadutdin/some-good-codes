setwd("C:\\Users\\RMGimadutdinov\\Downloads")
getwd()

arr <- read.csv(file = "r1z1.csv", header = TRUE)
minn = min(arr[,1])
maxx = max(arr[,1])
#print(arr[2, 1]) #stroka, stolb
print(paste("minimum = ", minn))
print(paste("maximum = ", maxx))
print(paste("razmah vyborki = ", maxx - minn))
N = length(arr[,1])
mat_o = sum(arr[,1])/N
print(paste("Mat ojidanie = ", mat_o))
sum_of_squares = 0
for (num in arr[,1])
{
sum_of_squares = sum_of_squares + num*num
}
#print(paste(sum_of_squares))
disp = sum_of_squares/N - mat_o*mat_o
print(paste("dispersia = ", disp))
stand_otkl = sqrt(disp)
print(paste("stand otkl = ", stand_otkl))
