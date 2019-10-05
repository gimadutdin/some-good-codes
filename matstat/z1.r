setwd("D:\\Documents\\УЧЕБА\\Матстат\\задание1")
getwd()

data_file = read.csv("r1z1.csv")
x = data_file$X
n = length(x)

cat("Обьем выборки = ", n, "\n")
minn = min(x)
maxx = max(x)
cat("Минимум = ", minn, "\n")
cat("Максимум = ", maxx, "\n")
cat("Размах выборки = ", maxx - minn, "\n")

mo = sum(x) / n
cat("Математическое ожидание = ", mo, "\n")

disp = sum((x - mo)^2) / n
cat("Дисперсия:", disp, "\n")

cat("Дисперсия несмещенная = ", disp*n/(n-1), "\n")

stand_otkl = sqrt(disp)
cat("Стандартное отклонение = ", stand_otkl, "\n")

ko_assim = sum((x - mo)^3) / (n*(stand_otkl^3))
cat("Коэффициент ассимметрии = ", ko_assim, "\n")

x_sorted = sort(x)

med = kvantil(0.5)
cat("Медиана = ", med, "\n")

interkvart = kvantil(0.75) - kvantil(0.25)
cat("Интерквартильная широта = ", interkvart, "\n")


kvantil <- function(q)
{
    kv = 0
    if (abs((n - 1)*q - floor((n - 1)*q)) < 0.00001)
    {
        kv = x_sorted[(n - 1)*q + 1]
    } else # <
    {
        kv = (x_sorted[floor((n - 1)*q + 1)] + x_sorted[floor((n - 1)*q + 2)]) / 2
    }
    return(kv)
}






#med = quantile(x, probs = 0.5)