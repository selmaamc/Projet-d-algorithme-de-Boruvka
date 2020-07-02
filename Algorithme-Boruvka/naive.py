#!/usr/bin/python

import time
from numpy.random import randint
import matplotlib.pyplot as plt

###  cette solution ne donne pas le MST mais elle a un temps d'execution proche de la solution naive (en calculons tous les 'spanning trees' dans un graph



class Graph(): 
    def __init__(self, vertices): 
        self.s = vertices 
        self.graph = [[0 for column in range(vertices)]  
                    for row in range(vertices)]

    
    def calculPath(self, i, dest, visited):
        if (i == dest):
            return 1
        total = 0
        #L = []
        for j in range(self.s):
            if (self.graph[i][j] != 1 and not visited[j]):
                visited[j] = True;
         #       L[i].append((j))
                total += self.calculPath(j, dest, visited);
                visited[j] = False;
        return total

    def totalPath(self, src, dest):
        visited = [False]*self.s
        for i in range(self.s):
            visited[i] = False
        visited[src] = True;
        return self.calculPath( src, dest,visited)
    

    def naive(self):
        #L = []
        for i in range (self.s):
            for j in range (i,self.s):
                self.totalPath(i,j)
def graph(n): #generer des matrice adj
    graph = [[randint(0, 50) for i in range(n)] for j in range(n)]
    for i in range(n):
        graph[i][i] = 0
    for i in range(n):
        for j in range(n):
            graph[j][i] = graph[i][j]
    return graph

def main():
    S = 2
    L = []
    elements = list()
    times = list()
    #times2 = list()
    for i in range(1,6):
            L = graph(S)
            start = time.clock()
            g = Graph(S)
            g.graph = L
            g.naive()
            end = time.clock()
            #start2 = time.clock()
            #g.boruv()
            #end2 = time.clock()
            elements.append(S)
            times.append(end - start)
            #times2.append(end2 - start2)
            S += 1
    plt.xlabel('List Length')
    plt.ylabel('Time Complexity')
    #plt.plot(elements, times2, label ='Boruv')
    plt.plot(elements, times, label ='Naive')
    plt.grid()
    plt.legend()
    plt.show()

main()






#g = Graph(5) 
#g.graph = [ [0, 2, 0, 6, 0], 
#            [2, 0, 3, 8, 5], 
#            [0, 3, 0, 0, 7], 
#            [6, 8, 0, 0, 9], 
#            [0, 5, 7, 9, 0]]
#print g.totalWays(0,4)
