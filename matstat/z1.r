setwd("D:\\Documents\\�����\\�������\\�������1")
getwd()

data_file = read.csv("r1z1.csv")
x = data_file$X
n = length(x)

cat("����� ������� = ", n, "\n")
minn = min(x)
maxx = max(x)
cat("������� = ", minn, "\n")
cat("�������� = ", maxx, "\n")
cat("������ ������� = ", maxx - minn, "\n")

mo = sum(x) / n
cat("�������������� �������� = ", mo, "\n")

disp = sum((x - mo)^2) / n
cat("���������:", disp, "\n")

cat("��������� ����������� = ", disp*n/(n-1), "\n")

stand_otkl = sqrt(disp)
cat("����������� ���������� = ", stand_otkl, "\n")

ko_assim = sum((x - mo)^3) / (n*(stand_otkl^3))
cat("����������� ����������� = ", ko_assim, "\n")

x_sorted = sort(x)

med = kvantil(0.5)
cat("������� = ", med, "\n")

interkvart = kvantil(0.75) - kvantil(0.25)
cat("���������������� ������ = ", interkvart, "\n")


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