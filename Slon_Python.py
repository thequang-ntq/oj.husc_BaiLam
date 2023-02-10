n = str (input())
p, m = map (int, input().split())
 
expr = eval(n.replace("x", str(0))) 
gap = eval(n.replace("x" , str(1))) - eval(n.replace("x" , str(0)))

for i in range (m - 1):
  if (expr == p) :
    print(i)
    break
  expr = (expr + gap) % m
