# Lista Compreensiva
pares = [i for i in range(0, 50) if i%2==0]
print(pares)

pares = [i*2 for i in range(0, 50) if i%2==0]
print(pares)

pares = map(lambda x: x*2, filter(lambda x: not x%2, range(0,50)))
for x in pares:
    print(x, end=' ')