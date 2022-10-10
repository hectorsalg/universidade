def printDecorator(func):
 
    def dentro():
        print("Isto é antes da função ser executada!")
 
        func()
 
        print("Isto é depois da função ser executada!")
         
    return dentro

def funcaoExemplo():
    print("Isto está dentro da função!!")

funcaoExemplo = printDecorator(funcaoExemplo)

funcaoExemplo()
