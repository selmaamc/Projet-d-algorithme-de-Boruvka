#!/usr/bin/python


import time
from numpy.random import seed
from numpy.random import randint
import matplotlib.pyplot as plt
from queue import PriorityQueue

class Graphe:
    def __init__(self,  nbr_sommets):
        #self.list_aretes = list_aretes
        #self.list_sommets = list_sommets
        #self.a = len(graph)
        self.s = nbr_sommets
        graph = []
        #self.a = len(self.graph)


    def prim(self):
        k = [99999]*self.s
        k[0] = 0
        SV = [False]*self.s #sommet visite
        for i in range (self.s):
            m = 9999
            min_index = 0
            for v in range(self.s):
                #min = 9999
                if k[v] < m and SV[v] == False:
                    min = k[v]
                    min_index = v
            SV[min_index] = True
            for j in range(len(self.graph)):
                if self.graph[j][0] == min_index:
                    if SV[self.graph[j][1]] == False and k[self.graph[j][1]] > self.graph[j][2]:
                        k[self.graph[j][1]] = self.graph[j][2]
                if self.graph[j][1] == min_index:
                    if SV[self.graph[j][0]] == False and k[self.graph[j][0]] > self.graph[j][2]:
                        k[self.graph[j][0]] = self.graph[j][2]
def main():  # fonction pour generer des Graphs
    S = 4
    L = []
    elements = list()
    times = list()
    for i in range(1,10):
            for i in range(0,S-2):
                L.append(list((i,i+1,randint(1,50))))
                L.append(list((i,i+2,randint(1,50))))
            L.append(list((S-2,S-1,randint(1,50))))
            #L[i].append(random.randint(0,3))
            #L[i].append(random.randint(1,50))
           # print(L)
            start = time.clock()
            g = Graphe(S)
            g.graph = L
            g.prim()
            end = time.clock()
            #g = Graphe(S)
            #g.graph = L
            #g.boruvka()
            #end2 = time.clock()
            #print(L, "temps:", end-start)
            elements.append(S)
            times.append(end - start)
            S += 5
    plt.xlabel('List Length')
    plt.ylabel('Time Complexity')
    #plt.plot(elements, times2, label ='Boruvka')
    plt.plot(elements, times, label ='Prim')
    plt.grid()
    plt.legend()
    plt.show()

main()



